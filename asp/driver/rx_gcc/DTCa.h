/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#ifndef RENESAS_RX_DTCA_DRIVER
#define RENESAS_RX_DTCA_DRIVER

#include "target_device/target_device.h"

//DTC discripeter table
typedef struct dtca_discripter_table {
  uitn16_t reserv;
  uint8_t mrb;
  uint8_t mra;
  uint32_t sar;
  volatile uint32_t sar;
  volatile uint32_t dar;
  volatile uint16_t crb;
  volatile uint16_t cra;
}dtca_table;

//DTC vecter base array
extern uint32_t dtca_table[256];

inline void set_vecter_table(uint8_t intno, dtca_table *vecter);

//
// DTCA Macro Controll
//
void dtca_enable();
void dtca_disable();

//Set DTCER to accept irq.
inline void dtcer_irq_enable(uint8_t intno);
inline void dtcer_irq_disable(uint8_t intno);

#endif
