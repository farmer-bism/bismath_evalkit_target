/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */


#define SPCR_OFFSET 0x0
#define SSLP_OFFSET 0x1
#define SPPCR_OFFSET 0x2
#define SPSR_OFFSET 0x4
#define SPDR_OFFSET 0x5
#define SPSCR_OFFSET 0x8
#define SPSSR_OFFSET 0x9
#define SPBR_OFFSET 0xA
#define SPDCR_OFFSET 0xB
#define SPCKD_OFFSET 0xC
#define SSLND_OFFSET 0xD
#define SPND_OFFSET 0xE
#define SPCR2_OFFSET 0xF
#define SPCMD0_OFFSET 0x10
#define SPCMD1_OFFSET 0x12
#define SPCMD2_OFFSET 0x14
#define SPCMD3_OFFSET 0x16
#define SPCMD4_OFFSET 0x18
#define SPCMD5_OFFSET 0x1A
#define SPCMD6_OFFSET 0x1C
#define SPCMD7_OFFSET 0x1E

#define SPRI_IRQ 0
#define SPTI_IRQ 1
#define SPII_IRQ 2

void rspi_slave_select(dev_node_t *dnode, uint8_t sel){
  uint8_t st;
  uint32_t base_addr;
  
  base_addr = dnode->baddr;
  st = DEV_REB(base_addr, SSLP_OFFSET);
  DEV_WRB(base_addr, SSLP_OFFSET, st | sel);
}
  

void rspi_slave_unselect(dev_node_t *dnode, uint8_t unsel){
  uint8_t st;
  uint32_t base_addr;
  
  base_addr = dnode->baddr;
  st = DEV_REB(base_addr, SSLP_OFFSET);
  DEV_WRB(base_addr, SSLP_OFFSET, st & ~unsel);
}

//
//trs_freq is bit rate
//if bit rate is 400 khz, set 400000;
void rspi_init(dev_node_t *dnode, rspi_param_t* params){
  uint32_t base_addr;
  
  base_addr = dnode->baddr;
  DEV_WRB(base_addr, SPCR_OFFSET, 0); //disable RSPI
  DEV_WRB(base_addr, SSLP_OFFSET, params->sslp);
  DEV_WRB(base_addr, SPPCR_OFFSET, params->sppcr);
  DEV_WRB(base_addr, SPSCR_OFFSET, params->spscr);
  DEV_WRB(base_addr, SPDCR_OFFSET, params->spdcr);
  DEV_WRH(base_addr, SPCMD0_OFFSET, params->spcmd0);  //Set Transfar length 8bit
  DEV_WRB(base_addr, SPBR_OFFSET, (F_PCLK/2/(params->bit_rate) -1));
  DEV_WRB(base_addr, SPCR_OFFSET, params->spcr); //Enable RSPI 
}

void disable_rspi(dev_node_t *dnode){
  uint32_t base_addr;
  
  base_addr = dnode->baddr;
  DEV_WRB(base_addr, SPCR_OFFSET, 0); //disable RSPI
}
  
void send_w_with_dtc();
void send_b_with_dtc();
void send_clock_with_dtc();

void rcv_w_with_dtc();
void rcv_b_with_dtc();
