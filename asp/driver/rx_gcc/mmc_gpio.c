/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#include <driver/rx_gcc/mmc_gpio.h>

//return sdcard status
//  not 0 : card is inserted
//  0     : card isn't inserted

uint8_t check_ins_sw(void *v_gpio_stat){
  mmc_gpio_dstat *gpio_stat;
  gpio_stat = (mmc_gpio_dstat*)v_gpio_stat;
  return sil_reb_mem(gpio_stat->pdr_baddr) & gpio_stat->chip_bit_mask;
}
