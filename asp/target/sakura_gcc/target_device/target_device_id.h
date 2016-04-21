/*
 * Copyright (c) 2015- Hisashi Hata       
 * Released under the toppers license     
 * https://www.toppers.jp/license.html    
 */

#ifndef TARGET_TARGET_DEVICE_ID_H
#define TARGET_TARGET_DEVICE_ID_H

#include "use_device.h"

typedef enum device_node_id_t{
#ifdef USE_MMC_RSPI_0
  DEV_MMC_RSPI0,
#endif
#ifdef USE_DTCA_0
  DEV_DTCA0,
#endif
#ifdef USE_LED_0
  DEV_LED0,
#endif
  NUM_TARGET_DEVICE
}dnode_id;

#endif
