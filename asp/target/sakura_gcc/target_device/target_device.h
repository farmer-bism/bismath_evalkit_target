/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#ifndef SAURA_GCC_TARGET_DEVICE
#define SAURA_GCC_TARGET_DEVICE

#include "target_device_id.h"

typedef struct device_info_t{
  uitn32_t status
  uint32_t dinfo;
}dev_info_t;

extern dev_info_t dev_info[NUM_TARGET_DEVICE};

static inline uint32_t get_dev_info(enum use_device_id device_id){
  return dev_info[device_id].dinfo;
}

void target_device_init();


#endif
