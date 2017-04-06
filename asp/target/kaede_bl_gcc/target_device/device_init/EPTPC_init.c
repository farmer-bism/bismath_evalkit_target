/*
 * Copyright (c) 2016- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */
#include <kernel_cfg.h>
#include <kernel_impl.h>
#include <target_device/target_device.h>

#ifdef USE_EPTPC_0
#include <driver/rx_gcc/EPTPC.h>

extern uint8_t target_ptp_mode;
extern uint8_t mac_addr[6];

dev_node_t eptpc_node_0 = {
  NULL,
  NULL
};

PTPINI ptp_conf ={
  NULL,
  {
    EPTPC_MODE_E2E | EPTPC_MODE_MASTER | EPTPC_MODE_PORT0,
    {0x100203FF,0xFE040506}, //self clk id
	{0x100203FF,0xFE040506}, //master clk id
	{0x100203FF,0xFE040506}, //gramd master clk id
    0x0,
    {0x10,2,3,4,5,6},
    TSLATR_EGP_RMII100_STCA20
    }
};
    

void target_dev_ini_eptpc_0(){
/*
  eptpc_target_config(mac_addr,
                     EPTPC_STCSELR_SCLKDIV_DIV6|EPTPC_STCSELR_SCLKSEL_PCLKA_DIV_1_6,
                     EPTPC_STCFR_STCF_20M,
                     //EPTPC_MODE_PORT0|EPTPC_MODE_MASTER
                     target_ptp_mode
                     ) ;
  eptpc_init(&ptp_conf);
  */
}

#endif
