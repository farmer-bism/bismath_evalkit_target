/*
 bism.c
 Copyright (c) 2016 Hisashi Hata

 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
*/
#include <kernel_t.h>
#include "bism_bbf_ring.h"

bism_bbf_ring bism_buff;
FILE *fp;

void bism_init(){
  bism_bbf_ring_init(&bism_buff);
  fp = fopen("test.dat", "wb");
}

uint32_t bism_write(uint8_t* w_dat, uint8_t len){
  uint8_t buff_st;
  uint32_t writed;
  bism_blk_buff *buff_blk;
  wai_sem(BISM_WRITE_FUNC_SEM);
  writed = bism_bbf_write(w_dat, len, &buff_st, &bism_buff);
  if(buff_st == BBF_LOCK_BLK_HAS){
    buff_blk = bism_bbf_read_blk(&bism_buff, &buff_st);
    snd_dtq(BISM_STOR_DTQ, buff_blk);
  }
  sig_sem(BISM_WRITE_FUNC_SEM);
  return writed;
}


void bism_log_store_task(void *exif){
  bism_blk_buff *qued_buff;
    
  while(1){
    rcv_dtq(BISM_STOR_DTQ, &qued_buff);
    fwrite(qued_buff->buff, 1, qued_buff->write_pos, fp);
    qued_buff->write_pos = 0;
    bism_blk_set_state(qued_buff, BISM_BUF_IDLE);
  }
}

