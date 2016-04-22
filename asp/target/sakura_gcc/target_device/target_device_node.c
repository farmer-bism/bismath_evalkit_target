/*
 * Copyright (c) 2015- Hisashi Hata       
 * Released under the toppers license     
 * https://www.toppers.jp/license.html    
 */

#include "target_device.h"

#ifdef USE_MMC_RSPI_0
  extern dev_node_t mmc_rspi_node_0;
  void target_dev_ini_mmc_sdcard_rspi_0();
#endif
#ifdef USE_RSPI_0
  extern dev_node_t rspi_node_0;
  void target_dev_ini_rspi_0();
#endif
#ifdef USE_DTCA_0
  extern dev_node_t dtca_node_0;
  void target_dev_init_dtca_0();
#endif
#ifdef USE_LED_0
  extern dev_node_t led_node_0;
  void target_dev_init_led_0();
#endif

dev_info_t dev_info[NUM_TARGET_DEVICE]{
#ifdef USE_MMC_RSPI_0
  {0x0, &MMC_RSPI_0},
#endif
#ifdef USE_RSPI_0
  {0x0, &RSPI_0},
#endif
#ifdef USE_DTCA_0
  {0x0, &DTCA_0},
#endif
#ifdef USE_LED_0
  {0x0, &LED_0}
#endif
}

void target_device_init(){
#ifdef USE_MMC_RSPI_0
  target_dev_ini_mmc_sdcard_rspi_0();
#endif
#ifdef USE_RSPI_0
  target_dev_ini_rspi_0();
#endif
#ifdef USE_DTCA_0
  target_dev_init_dtca_0();
#endif
#ifdef USE_LED_0
  target_dev_init_led_0();
#endif
}
