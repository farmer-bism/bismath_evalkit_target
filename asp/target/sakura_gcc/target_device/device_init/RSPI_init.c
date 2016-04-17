/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include "target_board.h"
#include "driver/rx/RSPI.h"

#define RSPI_CH0_BASE 0x00088380
#define RSPI_CH1_BASE 0x000883A0
#define RSPI_CH2_BASE 0x000883C0

#ifdef USE_RSPI_0
//device info define
const uint8_t rspi0_irq[3] = {INT_RSPI0_SPRI0, INT_RSPI0_SPTI0, INT_RSPI0_SPII0};

dev_node_t rspi_node_0 = {
  RSPI_CH0_BASE,
  rspi0_irq
};

void target_dev_init_rspi_0(){
	/* MPC setting */
	/* unlock PFS write protection */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSWE_BIT);
	/* pC0 is set as SPI mode */
	sil_wrb_mem((void *)(MPC_PC0PFS_ADDR),
                MPC_PFS_PSEL0|MPC_PFS_PSEL5|MPC_PFS_PSEL6|MPC_PFS_PSEL7);
    
	/* lock PFS write */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_B0WI_BIT);
}
#endif

#ifdef USE_RSPI_1
//device info define
const uint8_t rspi1_irq[3] = {INT_RSPI1_SPRI1, INT_RSPI1_SPTI1, INT_RSPI0_SPII1};

dev_node_t rspi_node_1 = {
  RSPI_CH1_BASE,
  rspi1_irq
};

void target_dev_init_rspi_1(){
	/* MPC setting */
	/* unlock PFS write protection */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSWE_BIT);

    rspi_1 not implemented
    
	/* lock PFS write */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_B0WI_BIT);

}
#endif


#ifdef USE_RSPI_2
//device info define
const uint8_t rspi2_irq[3] = {INT_RSPI2_SPRI2, INT_RSPI2_SPTI2, INT_RSPI0_SPII2};

dev_node_t rspi_node_2 = {
  RSPI_CH2_BASE,
  rspi2_irq
};

void target_dev_init_rspi_2(){
	/* MPC setting */
	/* unlock PFS write protection */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSWE_BIT);

    rspi 2 not implemented
    
	/* lock PFS write */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_B0WI_BIT);

}
#endif