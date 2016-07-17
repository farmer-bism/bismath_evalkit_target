/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include "target_board.h"
#include "driver/rx_gcc/DTCa.h"

#ifdef USE_DTCA_0

void target_dev_ini_dtca_0(){
  //unlock register access 
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY | SYSTEM_PRC1);
  *SYSTEM_MSTPCRA_ADDR &= ~(SYSTEM_MSTPCRA_MSTPA28_BIT); /* DTCa */
  //lock register access
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY );

  //set dtc vecter base
  sil_wrw_lem((uint32_t *)DTC_DTCCR, dtca_table);
}


#endif
