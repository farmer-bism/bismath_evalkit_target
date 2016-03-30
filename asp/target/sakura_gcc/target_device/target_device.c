/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#include "target_device.h"
#include "target_device_id.h"

//include device infomation value
#include "driver/DTCa.h"

//device infomation define
const uint32_t dtca_base_addr = RX63N_DTC_BASEADDR; //DTCa

dev_info_t dev_info[NUM_TARGET_DEVICE} = {
  {0x0, (uint32_t)() },  //ID 0 TIMER
  {0x0, (uint32_t)(dtca_base_addr) },  //ID 1 DTCA
  {0x0, (uint32_t)() }   //ID 2 SIP0
};

uint32_t get_dev_info(uint16_t device_id){
  return dev_info[device_id].dinfo;
}
