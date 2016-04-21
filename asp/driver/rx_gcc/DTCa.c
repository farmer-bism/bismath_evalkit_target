/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include "kernel.h"
#include "DTCa.h"

//DTC register define
//#define DID_DTCA     //defined in target_device_id.h
#define DTC_DTCCR_OFFSET 0x0
#define DTC_DTCVBR_OFFSET 0x4
#define DTC_DTCADMOD_OFFSET 0x8
#define DTC_DTCST_OFFSET 0xC
#define DTC_DTCSTS_OFFSET 0xE

inline void set_vecter_table(uint8_t intno, dtca_table *vecter){
  dtca_table[intno] = vecter;
}

//
// DTCA Macro Controll
//
#define DTCA_MODE_ENABLE 0x1
#define DTCA_MODE_DISABLE 0x0

void dtca_enable(){
  uint32_t dtcst_addr;
  dtcst_addr = GET_DEV_INFO(DEV_DTCA0)->baddr + DTC_DTCST_OFFSET;
  sil_wrb_mem((uint8_t*)dtcst_addr, DTCA_MODE_ENABLE);
}
  
void dtca_disable(){
  uint32_t dtcst_addr;
  dtcst_addr = GET_DEV_INFO(DEV_DTCA0)->baddr + DTC_DTCST_OFFSET;
  sil_wrb_mem((uint8_t*)dtcst_addr, DTCA_MODE_DISABLE);
}

//Set DTCER to accept irq.
inline void dtcer_irq_enable(uint8_t intno){
  ENABLE_ICU_DTCER(intno);
}

inline void dtcer_irq_disable(uint8_t intno){
  DISABLE_ICU_DTCER(intno);
}
