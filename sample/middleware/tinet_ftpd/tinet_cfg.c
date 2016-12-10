/* tinet_cfg.c */

#include <kernel.h>
#include <sil.h>
#include "kernel_cfg.h"
#include "tinet_cfg.h"
#include <tinet_defs.h>
#include <tinet_config.h>
#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <netinet/in.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <netinet/tcp_timer.h>
#include <netinet/tcp_var.h>
#include <netinet/tcp_fsm.h>
#include <netinet/udp_var.h>

/*
 *  Include Directives (#include)
 */

#include "middleware/tinet_ftpd/tinet_ftpd.h"

#define TNUM_TCP_REPID	2

const ID tmax_tcp_repid = (TMIN_TCP_REPID + TNUM_TCP_REPID - 1);

T_TCP4_REP tcp_rep[TNUM_TCP_REPID] = {
	{
		0,
		{ IPV4_ADDRANY, 20 },
#if defined(TCP_CFG_EXTENTIONS)
		TCP_REP_FLG_VALID,
		SEM_TCP_REP_LOCK1,
#endif
		},
	{
		0,
		{ IPV4_ADDRANY, 21 },
#if defined(TCP_CFG_EXTENTIONS)
		TCP_REP_FLG_VALID,
		SEM_TCP_REP_LOCK2,
#endif
		},
	};

#define TNUM_TCP_CEPID	2

const ID tmax_tcp_cepid = (TMIN_TCP_CEPID + TNUM_TCP_CEPID - 1);

T_TCP4_CEP tcp_cep[TNUM_TCP_CEPID] = {
	{
		0,
		(void*)tcp_ftpd_data_swbuf,
		TCP_FTPD_DATA_SWBUF_SIZE,
		(void*)tcp_ftpd_data_rwbuf,
		TCP_FTPD_DATA_RWBUF_SIZE,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_VALID,
		SEM_TCP_CEP_LOCK1,
		FLG_TCP_CEP_EST1,
		FLG_TCP_CEP_SND1,
		FLG_TCP_CEP_RCV1,
		},
	{
		0,
		(void*)tcp_ftpd_control_swbuf,
		TCP_FTPD_CONTROL_SWBUF_SIZE,
		(void*)tcp_ftpd_control_rwbuf,
		TCP_FTPD_CONTROL_RWBUF_SIZE,
		(t_tcp_callback)(FP)NULL,
		TCP_CEP_FLG_VALID,
		SEM_TCP_CEP_LOCK2,
		FLG_TCP_CEP_EST2,
		FLG_TCP_CEP_SND2,
		FLG_TCP_CEP_RCV2,
		},
	};

