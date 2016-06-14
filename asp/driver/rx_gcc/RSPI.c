/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#include <kernel.h>
#include <sil.h>
#include <target_board.h>
#include <driver/rx_gcc/RSPI.h>

#define SPCR_OFFSET 0x0
#define SSLP_OFFSET 0x1
#define SPPCR_OFFSET 0x2
#define SPSR_OFFSET 0x3
#define SPDR_OFFSET 0x4
#define SPSCR_OFFSET 0x8
#define SPSSR_OFFSET 0x9
#define SPBR_OFFSET 0xA
#define SPDCR_OFFSET 0xB
#define SPCKD_OFFSET 0xC
#define SSLND_OFFSET 0xD
#define SPND_OFFSET 0xE
#define SPCR2_OFFSET 0xF
#define SPCMD_OFFSET 0x10

#define SPRI_IRQ 0
#define SPTI_IRQ 1
#define SPII_IRQ 2

void rspi_slave_select(void *v_rspi_stat, uint8_t sel){
  uint8_t st;
  uint32_t base_addr;
  rspi_dstat *rspi_stat;
  rspi_stat = v_rspi_stat;
  
  base_addr = rspi_stat->baddr;
  st = DEV_REB(base_addr, SSLP_OFFSET);
  DEV_WRB(base_addr, SSLP_OFFSET, st & ~sel);
}
  

void rspi_slave_unselect(void *v_rspi_stat, uint8_t unsel){
  uint8_t st;
  uint32_t base_addr;
  rspi_dstat *rspi_stat;
  rspi_stat = v_rspi_stat;
  
  base_addr = rspi_stat->baddr;
  st = DEV_REB(base_addr, SSLP_OFFSET);
  DEV_WRB(base_addr, SSLP_OFFSET, st | unsel);
}

//
//trs_freq is bit rate
//if bit rate is 400 khz, set 400000;
void rspi_init(void *v_rspi_stat, rspi_param_t* params){
  uint32_t base_addr;
  rspi_dstat *rspi_stat;
  rspi_stat = v_rspi_stat;
  
  base_addr = rspi_stat->baddr;
  DEV_WRB(base_addr, SPCR_OFFSET, 0); //disable RSPI
  DEV_WRB(base_addr, SSLP_OFFSET, params->sslp);
  DEV_WRB(base_addr, SPPCR_OFFSET, params->sppcr);
  DEV_WRB(base_addr, SPSCR_OFFSET, params->spscr);
  DEV_WRB(base_addr, SPDCR_OFFSET, params->spdcr);
  DEV_WRH(base_addr, SPCMD_OFFSET, params->spcmd0);  //Set Transfar length 8bit
  DEV_WRB(base_addr, SPBR_OFFSET, (F_PCLKB/2/(params->bit_rate) -1));
  DEV_WRB(base_addr, SPCR_OFFSET, params->spcr); //Enable RSPI 
}

void rspi_disable(void *v_rspi_stat){
  uint32_t base_addr;
  rspi_dstat *rspi_stat;
  uint8_t rd;
  rspi_stat = v_rspi_stat;
  
  base_addr = rspi_stat->baddr;
  rd = DEV_REB(base_addr, SPCR_OFFSET);
  DEV_WRB(base_addr, SPCR_OFFSET, rd & ~SPCR_SPE); //disable RSPI
}
  
void rspi_enable(void *v_rspi_stat){
  uint32_t base_addr;
  uint8_t rd;
  rspi_dstat *rspi_stat;
  rspi_stat = v_rspi_stat;
  
  base_addr = rspi_stat->baddr;
  rd = DEV_REB(base_addr, SPCR_OFFSET);
  DEV_WRB(base_addr, SPCR_OFFSET, rd | SPCR_SPE); //disable RSPI
}

//Bit rate controll register
void rspi_chg_bit_rate(void *v_rspi_stat, uint8_t bit_rate){
  rspi_dstat *rspi_stat;
  rspi_stat = v_rspi_stat;

  DEV_WRB(rspi_stat->baddr, SPBR_OFFSET, bit_rate);
}


//SEND/RECIVE DATA REGISTER
/*
void rspi_dtc_send_w();
void rspi_dtc_send_b();
void rspi_dtc_send_clock();
*/

void rspi_send_w(void *v_rspi_stat, uint32_t dat){
  DEV_WRW(((rspi_dstat*)v_rspi_stat)->baddr, SPDR_OFFSET, dat);
}

void rspi_send_h(void *v_rspi_stat, uint16_t dat){
  DEV_WRW(((rspi_dstat*)v_rspi_stat)->baddr, SPDR_OFFSET, (uint32_t)dat);
}

void rspi_send_b(void *v_rspi_stat, uint8_t dat){
  DEV_WRW(((rspi_dstat*)v_rspi_stat)->baddr, SPDR_OFFSET, (uint32_t)dat);
}

void rspi_send_clock();

void rcv_w_with_dtc();
void rcv_b_with_dtc();

uint32_t rspi_rcv_w(void *v_rspi_stat){
  return DEV_REW(((rspi_dstat*)v_rspi_stat)->baddr, SPDR_OFFSET);
}

uint16_t rspi_rcv_h(void *v_rspi_stat){
  return (uint16_t)DEV_REW(((rspi_dstat*)v_rspi_stat)->baddr, SPDR_OFFSET);
}

uint8_t rspi_rcv_b(void *v_rspi_stat){
  return (uint8_t) DEV_REW(((rspi_dstat*)v_rspi_stat)->baddr, SPDR_OFFSET);
};

uint8_t rspi_status(void *v_rspi_stat){
  return DEV_REB(((rspi_dstat*)v_rspi_stat)->baddr, SPSR_OFFSET);
}

void rspi_set_cmd(void *v_rspi_stat, uint8_t cmd_buff_num, uint8_t cmd){
  DEV_WRB(((rspi_dstat*)v_rspi_stat)->baddr, SPCMD_OFFSET+(cmd_buff_num<<1), cmd );
}

void rspi_chg_dwidth(void *v_rspi_stat, uint8_t cmd_buff_num, uint32_t width){
  uint16_t current;
  uint32_t cmd_offset;
  uint32_t base_addr;
  rspi_dstat *rspi_stat;
  rspi_stat = v_rspi_stat;

  cmd_offset = SPCMD_OFFSET+(cmd_buff_num<<1);
  base_addr = rspi_stat->baddr;
  current = DEV_REB(base_addr, cmd_offset);
  DEV_WRH(base_addr, cmd_offset, (current & ~SPCMD_SPB_MASK)|width);
}
