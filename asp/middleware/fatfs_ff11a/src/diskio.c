/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#include "diskio.h"



DSTATUS disk_initialize (BYTE pdrv){
  mmc_func_t *mmc_func;
  dnode_id mmc_did;

  mmc_did = pdrv_to_dev[pdrv];
  mmc_func = GET_DEV_FUNC(mmc_did);
  return (*mmc_func->mmc_disk_initialize)(GET_DEV_STAT(mmc_did));
}
  
  
DSTATUS disk_status (BYTE pdrv){
  mmc_func_t *mmc_func;
  dnode_id mmc_did;

  mmc_did = pdrv_to_dev[pdrv];
  mmc_func = GET_DEV_FUNC(mmc_did);
  return (*mmc_func->mmc_disk_status)(GET_DEV_STAT(mmc_did));
}

DRESULT disk_read (BYTE pdrv, BYTE* buff, DWORD sector, UINT count){
  mmc_func_t *mmc_func;
  dnode_id mmc_did;
  
  mmc_did = pdrv_to_dev[pdrv];
  mmc_func = GET_DEV_FUNC(mmc_did);
  return (*mmc_func->mmc_disk_read)(GET_DEV_STAT(mmc_did), buff, sector, count);
}

DRESULT disk_write (BYTE pdrv, const BYTE* buff, DWORD sector, UINT count){
  mmc_func_t *mmc_func;
  dnode_id mmc_did;
  
  mmc_did = pdrv_to_dev[pdrv];
  mmc_func = GET_DEV_FUNC(mmc_did);
  return (*mmc_func->mmc_disk_write)(GET_DEV_STAT(mmc_did), buff, sector, count);
}

DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff){
  mmc_func_t *mmc_func;
  dnode_id mmc_did;
  
  mmc_did = pdrv_to_dev[pdrv];
  mmc_func = GET_DEV_FUNC(mmc_did);
  return (*mmc_func->mmc_disk_write)(GET_DEV_STAT(mmc_did), cmd, buff);
}
