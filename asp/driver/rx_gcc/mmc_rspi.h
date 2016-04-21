/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include "target_board.h"
#include <mmc_sdcard.h>

//rspi_mmc_node's status
typedef struct mmc_rspi_dev_status_type{
  uint32_t rspi_id;
  uint32_t cs_val;
  DSTATUS Stat;
  uint8_t CardType;
  uint8_t tout_flg;
} mmc_rspi_dstat;
