/*
 * Copyright (c) 2015- Hisashi Hata       
 * Released under the toppers license     
 * https://www.toppers.jp/license.html    
 */

#include "target_device.h"

#ifdef USE_MMC_RSPI_0
  extern dev_node_t mmc_rspi_node_0;
#endif
#ifdef USE_DTCA_0
  extern dev_node_t dtca_node_0;
#endif
#ifdef USE_LED_0
  extern dev_node_t led_node_0;
#endif

dev_info_t dev_info[NUM_TARGET_DEVICE]{
#ifdef USE_MMC_RSPI_0
  {0x0, (void*)(&MMC_RSPI_0_FUNC), (void*)(&MMC_RSPI_0_STATUS)},
#endif
#ifdef USE_DTCA_0
  {0x0, (void*)(&DTCA_0), NULL},
#endif
#ifdef USE_LED_0
  {0x0, (void*)(&LED_0), NULL}
#endif
}

void target_device_init(){
#ifdef USE_MMC_RSPI_0
  target_dev_init_mmc_spi_0();
#endif
#ifdef USE_DTCA_0
  target_dev_init_dtca_0();
#endif
#ifdef USE_LED_0
  target_dev_init_led_0();
#endif
}