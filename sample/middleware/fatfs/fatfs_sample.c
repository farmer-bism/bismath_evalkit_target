/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include <middleware/include/ff.h>

FATFS FatFs;

uint32_t buf[128];

void main_task(intptr_t exinf)
{
  FIL fil;
  uint32_t i, res_b, comp_result;
  FRESULT fr;

  //create mount point
  for(i=0; i<128;i++) buf[i] = i;
  f_mount(&FatFs, "", 0);

  //write test
  //open test file
  fr = f_open(&fil, "test.bin", FA_CREATE_ALWAYS|FA_WRITE);
  if (fr) return (int)fr;
  //write data
  f_write(&fil, buf, 512, res_b);
  
  //read test
  for(i=0; i<128; i++) buf[i] = 0;
  f_read(&fil, buf, 512, res_b);

  f_close(&fil);
  // release mount point
  f_mount(NULL, "", 0);

  comp_result=0;
  for(i=0;i<128;i++)
    if(buf[i] != i)
      comp_result = -1;

  if(comp_result)
    assert(0);
}
