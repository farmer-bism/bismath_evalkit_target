/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#ifndef RENESAS_RX_DTCA_DRIVER
#define RENESAS_RX_DTCA_DRIVER

#include "target_device/target_device_id.h"

//DTC register define
//#define DID_DTCA     //defined in target_device_id.h
#define DTC_DTCCR_OFFSET 0x0
#define DTC_DTCVBR_OFFSET 0x4
#define DTC_DTCADMOD_OFFSET 0x8
#define DTC_DTCST_OFFSET 0xC
#define DTC_DTCSTS_OFFSET 0xE

//DTC discripeter table
typedef struct dtca_discripter_t {
  uitn16_t reserv;
  uint8_t mrb;
  uint8_t mra;
  uint32_t sar;
  volatile uint32_t sar;
  volatile uint32_t dar;
  volatile uint16_t crb;
  volatile uint16_t cra;
}dtca_disc;

//DTC vecter base array
extern uint32_t dtca_table[256];

#endif
