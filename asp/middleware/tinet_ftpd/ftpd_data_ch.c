/*
 * Copyright 2016 Hisashi Hata
 * Copyright (c) 2002 Florian Schulze.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the authors nor the names of the contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * ftpd.c - This file is part of the FTP daemon for lwIP
 *
 */

#include <string.h>

#include <kernel.h>
#include <tinet_defs.h>
#include "kernel_cfg.h"
#include "tinet_cfg.h"

#include <netinet/in.h>
#include <netinet/in_itron.h>
#include <netinet/tcp.h>

#include "ftpd_init.h"
#include "ftpd_config.h"
#include "vfs.h"

#include "ftpd_state.h"
#include "ftpd_messeage.h"
#include <t_syslog.h>

//data port define

T_IPV4EP data_dst;

void ftpd_dataclose(ID data_cep_id, struct ftpd_datastate *fsd)
{
	fsd->msgfs->datafs = NULL;
	sfifo_close(&fsd->fifo);
	tcp_cls_cep(data_cep_id, 1000);
}

static void send_data(ID data_cep_id, struct ftpd_datastate *fsd)
{
	ER err;
	uint16_t len;
	if (sfifo_used(&fsd->fifo) > 0) {
		/* We cannot send more data than space available in the send
		   buffer. */
        len = (uint16_t) sfifo_used(&fsd->fifo);
		err = tcp_snd_dat(data_cep_id, fsd->fifo.buffer, len, 1000);
		if (err < 0) {
          //dbg_printf("send_data: error writing!\n");
          return;
		}
		fsd->fifo.writepos = 0;
		fsd->fifo.readpos = 0;
	}
}

#define FTPD_DSEND_SIZE 512
static void send_file(struct ftpd_datastate *fsd, ID data_cep_id)
{
  uint32_t len;
  struct ftpd_msgstate *fsm;
  ID msg_cep_id;
  
  if (!fsd->connected)
    return;
  fsm = fsd->msgfs;
  msg_cep_id = fsm->msg_cep_id;
  
  if (fsd->vfs_file) {

    while((len = vfs_read(fsd->fifo.buffer, 1, FTPD_DSEND_SIZE, fsd->vfs_file)) >0){
      fsd->fifo.writepos = len;
      send_data(data_cep_id, fsd);
    }
    if (len == 0) {
      if (vfs_eof(fsd->vfs_file) == 0){
        vfs_close(fsd->vfs_file);
        fsd->vfs_file = NULL;
        ftpd_dataclose(data_cep_id, fsd);
        fsm->datafs = NULL;
        fsm->state = FTPD_IDLE;
        send_msg(msg_cep_id, fsm, msg451);
        return;
      }
    }
  }

  vfs_close(fsd->vfs_file);
  fsd->vfs_file = NULL;
  ftpd_dataclose(data_cep_id, fsd);
  fsm->datafs = NULL;
  fsm->state = FTPD_IDLE;
  send_msg(msg_cep_id, fsm, msg226);
  return;
}

#if FTPD_ENABLE_FF_DIR

static const char *month_table[12] = {
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dez"
};

static void send_next_directory(struct ftpd_datastate *fsd, ID data_cep_id, int shortlist)
{
  uint32_t len, wr_pos;
  
  while (1) {
	if (fsd->vfs_dirent == NULL)
      fsd->vfs_dirent = vfs_readdir(fsd->vfs_dir);
	if (fsd->vfs_dirent) {
      if (shortlist) {

        len = strlen(fsd->vfs_dirent->name);
        if (sfifo_space(&fsd->fifo) < (len+3)) {
          send_data(data_cep_id, fsd);
        }
        wr_pos = fsd->fifo.writepos;
        strcpy(fsd->fifo.buffer+wr_pos, fsd->vfs_dirent->name);
        strcpy(fsd->fifo.buffer+wr_pos+len, "\r\n");
        fsd->fifo.writepos += len+2;
        fsd->vfs_dirent = NULL;
      }
      /*
        else {
        vfs_stat_t st;
        vfs_time_t current_time;
        int current_year;
        struct tm *s_time;
        
        time(&current_time);
        s_time = gmtime(&current_time);
        current_year = s_time->tm_year;
        
        vfs_stat(fsd->msgfs->vfs, fsd->vfs_dirent->name, &st);
        s_time = gmtime(&st.st_mtime);
        if (s_time->tm_year == current_year)
          len = sprintf(buffer, "-rw-rw-rw-   1 user     ftp  %11ld %s %02i %02i:%02i %s\r\n", st.st_size, month_table[s_time->tm_mon], s_time->tm_mday, s_time->tm_hour, s_time->tm_min, fsd->vfs_dirent->name);
        else
          len = sprintf(buffer, "-rw-rw-rw-   1 user     ftp  %11ld %s %02i %5i %s\r\n", st.st_size, month_table[s_time->tm_mon], s_time->tm_mday, s_time->tm_year + 1900, fsd->vfs_dirent->name);
        if (VFS_ISDIR(st.st_mode))
          buffer[0] = 'd';
        if (sfifo_space(&fsd->fifo) < len) {
          send_data(data_cep_id, fsd);
          return;
        }
        sfifo_write(&fsd->fifo, buffer, len);
        fsd->vfs_dirent = NULL;
      }
      */
	} else {
      struct ftpd_msgstate *fsm;
      ID msg_cep_id;
      
      if (sfifo_used(&fsd->fifo) > 0) {
        send_data(data_cep_id, fsd);
        return;
      }
      fsm = fsd->msgfs;
      msg_cep_id = fsm->msg_cep_id;
      
      vfs_closedir(fsd->vfs_dir);
      fsd->vfs_dir = NULL;
      ftpd_dataclose(data_cep_id, fsd);
      fsm->datafs = NULL;
      fsm->state = FTPD_IDLE;
      send_msg(msg_cep_id, fsm, msg226);
      return;
	}
  }
}
#endif


static ER rcv_file(struct ftpd_datastate *arg, ID data_cep_id)
{
	struct ftpd_datastate *fsd ;
    uint8_t *rbuf;
    ER_UINT rblen;
    
    struct ftpd_msgstate *fsm;
    ID msg_cep_id;
    fsd = arg;
    
    while((rblen = tcp_rcv_buf(data_cep_id, (void**)&rbuf,1000)) > 0){
      vfs_write(rbuf, 1, rblen, fsd->vfs_file);
      tcp_rel_buf(data_cep_id, rblen);
    }
    fsm = fsd->msgfs;
    msg_cep_id = fsm->msg_cep_id;

    vfs_close(fsd->vfs_file);
    fsd->vfs_file = NULL;
    //ftpd_dataclose(data_cep_id, fsd);
    fsm->datafs = NULL;
    fsm->state = FTPD_IDLE;
    send_msg(msg_cep_id, fsm, msg226);

	return E_OK;
}

uint32_t open_dataconnection(ID cep_id, struct ftpd_msgstate *fsm)
{
  if (fsm->connection_mode==FTPD_CONNECT_MODE_PASIVE)
    return 0;

  ftpd_init_data_fsm(fsm);
  
  if (fsm->datafs == NULL) {
    send_msg(cep_id, fsm, msg451);
    return 1;
  }
  memset(fsm->datafs, 0, sizeof(struct ftpd_datastate));
  fsm->datafs->msgfs = fsm;
  sfifo_init(&fsm->datafs->fifo, sfifo_data_buf, FTPD_SFIFO_DATA_BUF_SIZE);
  
  if(tcp_con_cep(fsm->data_cep_id, &fsm->my_data_ip_port, &fsm->data_ip_port, 1000) != E_OK){
    return -1;
  }
  fsm->datafs->connected = 1;
  return 0;
}

void tcp_ftpd_data_srv_task(intptr_t exinf){
  struct ftpd_msgstate *msg_fsm;
  struct ftpd_datastate *data_fsm;
  ER error;
  ID data_cep_id;
  
  msg_fsm = ftpd_get_fsm((uint32_t) exinf);
  data_fsm = msg_fsm->datafs;

  if(data_fsm == NULL){
    msg_fsm->datafs = NULL;
    return;
  }

  data_cep_id = msg_fsm->data_cep_id;
  if(msg_fsm->connection_mode ==FTPD_CONNECT_MODE_PASIVE){
    if((error = tcp_acp_cep(data_cep_id, TCP_FTPD_DATA_REPID, &data_dst, TMO_FEVR)) != E_OK)
      return;
    data_fsm->connected = 1;
  }
  if (!data_fsm->connected)
    return;
  /*  else {
    if((error = tcp_con_cep(msg_fsm->data_cep_id, &msg_fsm->my_data_ip_port, &msg_fsm->data_ip_port, 1000)) != E_OK){
      return;
    }
    }*/

  switch (msg_fsm->state) {
  case FTPD_RETR: //recive data
    send_file(data_fsm, data_cep_id);
    break;
  case FTPD_STOR:
    rcv_file(data_fsm, data_cep_id);
    break;
#if FTPD_ENABLE_FF_DIR
  case FTPD_LIST:
    send_next_directory(data_fsm, data_cep_id, 0);
    break;
  case FTPD_NLST:
    send_next_directory(data_fsm, data_cep_id, 1);
    break;
#endif
  default:
    break;
  }
  ext_tsk();
}
