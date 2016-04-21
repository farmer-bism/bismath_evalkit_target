/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

/* Status of Disk Functions */
typedef uint8_t DSTATUS;

/* Results of Disk Functions */
typedef enum {
	RES_OK = 0,		/* 0: Successful */
	RES_ERROR,		/* 1: R/W Error */
	RES_WRPRT,		/* 2: Write Protected */
	RES_NOTRDY,		/* 3: Not Ready */
	RES_PARERR		/* 4: Invalid Parameter */
} DRESULT;

extern mmc_ pdrv_to_dev[];


typedef struct mmc_status_t{
  dnode_id mmc_drv_id;  //mmc driver id
  dnode_id mmc_ins_id;  //mmc card detect driver id
}mmc_stat_t;

typedef struct mmc_function_t{
  DSTATUS (*mmc_disk_initialize)(void*);
  DSTATUS (*mmc_disk_status)(void*);
  DRESULT (*mmc_disk_read)(void*, uint8_t*, uint32_t, uint32_t);
  DRESULT (*mmc_disk_write)(void*, const uint8_t*, uint32_t, uint32_t);
  DRESULT (*mmc_disk_ioctl)(void*, uint8_t, void*);
}mmc_func_t;
  

extern dnode_id pdrv_to_dev[];
