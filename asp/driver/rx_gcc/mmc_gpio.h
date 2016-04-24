/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#ifndef MMC_GPIO_DEF_H
#define MMC_GPIO_DEF_H

#include <target_board.h>


//rspi_mmc_node's status
typedef struct mmc_gpio_status_type{
  uint8_t *pdr_baddr;
  uint8_t chip_bit_mask;
} mmc_gpio_dstat;

uint8_t check_ins_sw(void*);

#endif
