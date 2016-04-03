/*
 * Copyright (c) 2015- Hisashi Hata       
 * Released under the toppers license     
 * https://www.toppers.jp/license.html    
 */

#include "target_device.h"

#ifdef USE_MMC_RSPI_0
  extern dev_mmc_rspi MMC_RSPI_0;
#endif
#ifdef USE_DTCA_0
  extern dev_dtca DTCA_0;
#endif
#ifdef USE_LED_0
  extern dev_led LED_0;
#endif

dev_info_t dev_info[NUM_TARGET_DEVICE]{
#ifdef USE_MMC_RSPI_0
  {0x0, (uint32_t*)(&MMC_RSPI_0)},
#endif
#ifdef USE_DTCA_0
  {0x0, (uint32_t*)(&DTCA_0)},
#endif
#ifdef USE_LED_0
  {0x0, (uint32_t*)(&LED_0)}
#endif
}

void target_device_init(){
#ifdef USE_MMC_RSPI_0
  target_dev_init_mmc_spi_0();
#endif
#ifdef USE_DTCA_0
  target_dev_init_dtia_0();
#endif
#ifdef USE_LED_0
  target_dev_init_led_0();
#endif
}
