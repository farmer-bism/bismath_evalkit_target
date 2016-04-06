/*
 * Copyright (c) 2015- Hisashi Hata       
 * Released under the toppers license     
 * https://www.toppers.jp/license.html    
 */

#ifdef TARGET_./TARGET_DEVICE_ID_H
#define TARGET_./TARGET_DEVICE_ID_H

#include "./use_device.h"

enum use_device_id{
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
}

#endif
