/*
 bism.c
 Copyright (c) 2016 Hisashi Hata

 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
*/

#ifndef BUILD_IN_SELF_MONITOR_H
#define BUILD_IN_SELF_MONITOR_H


void bism_init();
uint32_t bism_write(uint8_t* w_dat, uint8_t len);
void bism_log_store_task(void exif);
#endif
