/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include "target_board.h"
#include <mmc_sdcard.h>

dnode_id pdrv_to_dev[1] ={DEV_MMC0};

#ifdef USE_MMC_SDCARD_RSPI_0
mmc_stat_t mmc_sdcard_rspi0_stat={
  USE_MMC_RSPI_0,
  USE_MMC_GPIO_0
};

device_node_t mmc_sdcard_rspi0_node = {
  mmc_rspi_func,
  mmc_sdcard_0_stat
};
  
void target_dev_ini_mmc_sdcard_rspi_0(){
}

#endif
