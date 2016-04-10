/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#ifndef SAURA_GCC_TARGET_DEVICE
#define SAURA_GCC_TARGET_DEVICE

#include "target_device_id.h"

typedef struct device_info_t{
  uitn32_t status;
  void* dev_node;
}dev_info_t;

extern dev_info_t dev_info[NUM_TARGET_DEVICE};

static inline uint32_t get_dev_info(enum use_device_id device_id){
  return dev_info[device_id].dev_node;
}

#define GET_DEV_INFO(device_id) ((dev_node_t *) get_dev_info(device_id))

void target_device_init();

#include "target_device_id.h"

typedef struct device_node_t{
  uitn32_t baddr;
  uint32_t* irq_num;
  
}dev_node_t;

#define DEV_WRB(base, offset, data) sil_wrb_mem(((uint8_t *)(base+offset)), data)
#define DEV_WRH(base, offset, data) sil_wrh_mem(((uint16_t *)(base+offset)), data)
#define DEV_WRW(base, offset, data) sil_wrw_mem(((uint32_t *)(base+offset)), data)

#define DEV_REB(base, offset) sil_reb_mem(((uint8_t*)(base+offset))
#define DEV_REH(base, offset) sil_reh_mem(((uint16_t*)(base+offset))
#define DEV_REW(base, offset) sil_rew_mem(((uint32_t*)(base+offset))

#endif
