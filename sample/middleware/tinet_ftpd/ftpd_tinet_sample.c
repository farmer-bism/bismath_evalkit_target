//test
#include "kernel.h"
#include <target_board.h>


//Ethernet mac address 
uint8_t mac_addr[6] = {0x10, 2,3,4,5,6};
//file io device
const dnode_id pdrv_to_dev[1] = {
  DEV_MMC_RSPI0 //drive 1 is mmc_rspi
};
