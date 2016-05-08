/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include <driver/rx_gcc/mmc_gpio.h>


#ifdef USE_MMC_GPIO_0
mmc_gpio_dstat mmc_gpio_st_0 = {
  (uint8_t*)PORT1_PDR_ADDR,
  PORT_PDR_B5_BIT
};

dev_node_t mmc_sdcard_gpio_node_0 = {
  NULL,
  &mmc_gpio_st_0
};

//GPIO Port 1-Bit 5 is Chip detect switch of SDCARD SROT
//  Set input gpio port
void target_dev_ini_mmc_sdcard_gpio_0(){
  uint8_t rd;
  //set input port
  rd = sil_reb_mem(PORT1_PDR_ADDR);
  sil_wrb_mem(PORT1_PDR_ADDR, rd&~PORT_PDR_B5_BIT);
  //set gpio
  rd = sil_reb_mem(PORT1_PMR_ADDR);
  sil_wrb_mem(PORT1_PMR_ADDR, rd&~PORT_PDR_B5_BIT);
}
  
#endif
