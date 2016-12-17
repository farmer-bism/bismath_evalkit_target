/* kernel_cfg.c */
#include "kernel/kernel_int.h"
#include "kernel_cfg.h"

#if TKERNEL_PRID != 0x07u
#error The kernel does not match this configuration file.
#endif

/*
 *  Include Directives (#include)
 */

#include "target_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_syssvc.h"
#include <target_serial.h>
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "target_sil.h"
#include <itron.h>
#include <tinet_defs.h>
#include <tinet_config.h>
#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_timer.h>
#include <net/ppp_var.h>
#include <net/ether_var.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_timer.h>
#include <netinet/tcp_var.h>
#include <netinet/udp_var.h>
#include <netinet6/in6.h>
#include <netinet6/ip6_var.h>
#include "tinet_cfg.h"
#include "if_rx62nreg.h"
#include "middleware/tinet_ftpd/ftpd_config.h"
#include <target_board.h>
#include <driver/rx_gcc/mmc_rspi.h>
#include <driver/rx_gcc/RSPI.h>

/*
 *  Default Definitions of Trace Log Macros
 */

#ifndef LOG_ISR_ENTER
#define LOG_ISR_ENTER(intno)
#endif /* LOG_ISR_ENTER */

#ifndef LOG_ISR_LEAVE
#define LOG_ISR_LEAVE(intno)
#endif /* LOG_ISR_LEAVE */

/*
 *  Task Management Functions
 */

const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);

static STK_T _kernel_stack_LOGTASK[COUNT_STK_T(LOGTASK_STACK_SIZE)];
static STK_T _kernel_stack_NET_TIMER_TASK[COUNT_STK_T(NET_TIMER_STACK_SIZE)];
static STK_T _kernel_stack_ETHER_OUTPUT_TASK[COUNT_STK_T(ETHER_OUTPUT_STACK_SIZE)];
static STK_T _kernel_stack_ETHER_INPUT_TASK[COUNT_STK_T(ETHER_INPUT_STACK_SIZE)];
static STK_T _kernel_stack_TCP_OUTPUT_TASK[COUNT_STK_T(TCP_OUT_TASK_STACK_SIZE)];
static STK_T _kernel_stack_TCP_FTPD_CONTROL_TASK[COUNT_STK_T(TCP_FTPD_CONTROL_STACK_SIZE)];
static STK_T _kernel_stack_TCP_FTPD_DATA_TASK[COUNT_STK_T(TCP_FTPD_DATA_STACK_SIZE)];

const TINIB _kernel_tinib_table[TNUM_TSKID] = {
	{ (TA_ACT), (intptr_t)(LOGTASK_PORTID), ((TASK)(logtask_main)), INT_PRIORITY(LOGTASK_PRIORITY), ROUND_STK_T(LOGTASK_STACK_SIZE), _kernel_stack_LOGTASK, (TA_NULL), (NULL) },
	{ (TA_HLNG), (intptr_t)(0), ((TASK)(net_timer_task)), INT_PRIORITY(NET_TIMER_PRIORITY), ROUND_STK_T(NET_TIMER_STACK_SIZE), _kernel_stack_NET_TIMER_TASK, (TA_NULL), (NULL) },
	{ (TA_HLNG), (intptr_t)(0), ((TASK)(ether_output_task)), INT_PRIORITY(ETHER_OUTPUT_PRIORITY), ROUND_STK_T(ETHER_OUTPUT_STACK_SIZE), _kernel_stack_ETHER_OUTPUT_TASK, (TA_NULL), (NULL) },
	{ (TA_HLNG|TA_ACT), (intptr_t)(0), ((TASK)(ether_input_task)), INT_PRIORITY(ETHER_INPUT_PRIORITY), ROUND_STK_T(ETHER_INPUT_STACK_SIZE), _kernel_stack_ETHER_INPUT_TASK, (TA_NULL), (NULL) },
	{ (TA_HLNG), (intptr_t)(0), ((TASK)(tcp_output_task)), INT_PRIORITY(TCP_OUT_TASK_PRIORITY), ROUND_STK_T(TCP_OUT_TASK_STACK_SIZE), _kernel_stack_TCP_OUTPUT_TASK, (TA_NULL), (NULL) },
	{ (TA_ACT), (intptr_t)(FTPD_CH_ID), ((TASK)(tcp_ftpd_control_srv_task)), INT_PRIORITY(TCP_FTPD_CONTROL_PRIORITY), ROUND_STK_T(TCP_FTPD_CONTROL_STACK_SIZE), _kernel_stack_TCP_FTPD_CONTROL_TASK, (TA_NULL), (NULL) },
	{ (0), (intptr_t)(FTPD_CH_ID), ((TASK)(tcp_ftpd_data_srv_task)), INT_PRIORITY(TCP_FTPD_DATA_PRIORITY), ROUND_STK_T(TCP_FTPD_DATA_STACK_SIZE), _kernel_stack_TCP_FTPD_DATA_TASK, (TA_NULL), (NULL) }
};

TCB _kernel_tcb_table[TNUM_TSKID];

const ID _kernel_torder_table[TNUM_TSKID] = {
	LOGTASK, NET_TIMER_TASK, ETHER_OUTPUT_TASK, ETHER_INPUT_TASK, TCP_OUTPUT_TASK, TCP_FTPD_CONTROL_TASK, TCP_FTPD_DATA_TASK
};

/*
 *  Semaphore Functions
 */

const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);

const SEMINIB _kernel_seminib_table[TNUM_SEMID] = {
	{ (TA_TPRI), (0), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (0), (NUM_IF_RX62N_RXBUF) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (0), (NUM_NET_CALLOUT) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (0), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (0), (1) }
};

SEMCB _kernel_semcb_table[TNUM_SEMID];

/*
 *  Eventflag Functions
 */

const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);

const FLGINIB _kernel_flginib_table[TNUM_FLGID] = {
	{ (TA_TFIFO|TA_WSGL), (TCP_CEP_EVT_CLOSED) },
	{ (TA_TFIFO|TA_WSGL), (TCP_CEP_EVT_SWBUF_READY) },
	{ (TA_TFIFO|TA_WSGL), (0) },
	{ (TA_TFIFO|TA_WSGL), (TCP_CEP_EVT_CLOSED) },
	{ (TA_TFIFO|TA_WSGL), (TCP_CEP_EVT_SWBUF_READY) },
	{ (TA_TFIFO|TA_WSGL), (0) }
};

FLGCB _kernel_flgcb_table[TNUM_FLGID];

/*
 *  Dataqueue Functions
 */

const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);

static DTQMB _kernel_dtqmb_DTQ_ETHER_OUTPUT[NUM_DTQ_ETHER_OUTPUT];
const DTQINIB _kernel_dtqinib_table[TNUM_DTQID] = {
	{ (TA_TFIFO), (NUM_DTQ_ETHER_OUTPUT), (_kernel_dtqmb_DTQ_ETHER_OUTPUT) }
};

DTQCB _kernel_dtqcb_table[TNUM_DTQID];

/*
 *  Priority Dataqueue Functions
 */

const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);

TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);
TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);

/*
 *  Mailbox Functions
 */

const ID _kernel_tmax_mbxid = (TMIN_MBXID + TNUM_MBXID - 1);

TOPPERS_EMPTY_LABEL(const MBXINIB, _kernel_mbxinib_table);
TOPPERS_EMPTY_LABEL(MBXCB, _kernel_mbxcb_table);

/*
 *  Fixed-sized Memorypool Functions
 */

const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);

static MPF_T _kernel_mpf_MPF_NET_BUF_64[(NUM_MPF_NET_BUF_64) * COUNT_MPF_T(sizeof(T_NET_BUF_64))];
static MPFMB _kernel_mpfmb_MPF_NET_BUF_64[NUM_MPF_NET_BUF_64];
static MPF_T _kernel_mpf_MPF_NET_BUF_128[(NUM_MPF_NET_BUF_128) * COUNT_MPF_T(sizeof(T_NET_BUF_128))];
static MPFMB _kernel_mpfmb_MPF_NET_BUF_128[NUM_MPF_NET_BUF_128];
static MPF_T _kernel_mpf_MPF_NET_BUF_256[(NUM_MPF_NET_BUF_256) * COUNT_MPF_T(sizeof(T_NET_BUF_256))];
static MPFMB _kernel_mpfmb_MPF_NET_BUF_256[NUM_MPF_NET_BUF_256];
static MPF_T _kernel_mpf_MPF_NET_BUF_512[(NUM_MPF_NET_BUF_512) * COUNT_MPF_T(sizeof(T_NET_BUF_512))];
static MPFMB _kernel_mpfmb_MPF_NET_BUF_512[NUM_MPF_NET_BUF_512];
static MPF_T _kernel_mpf_MPF_NET_BUF_1024[(NUM_MPF_NET_BUF_1024) * COUNT_MPF_T(sizeof(T_NET_BUF_1024))];
static MPFMB _kernel_mpfmb_MPF_NET_BUF_1024[NUM_MPF_NET_BUF_1024];
static MPF_T _kernel_mpf_MPF_NET_BUF_IF_PDU[(NUM_MPF_NET_BUF_IF_PDU) * COUNT_MPF_T(sizeof(T_NET_BUF_IF_PDU))];
static MPFMB _kernel_mpfmb_MPF_NET_BUF_IF_PDU[NUM_MPF_NET_BUF_IF_PDU];
const MPFINIB _kernel_mpfinib_table[TNUM_MPFID] = {
	{ (TA_TFIFO), (NUM_MPF_NET_BUF_64), ROUND_MPF_T(sizeof(T_NET_BUF_64)), (_kernel_mpf_MPF_NET_BUF_64), (_kernel_mpfmb_MPF_NET_BUF_64) },
	{ (TA_TFIFO), (NUM_MPF_NET_BUF_128), ROUND_MPF_T(sizeof(T_NET_BUF_128)), (_kernel_mpf_MPF_NET_BUF_128), (_kernel_mpfmb_MPF_NET_BUF_128) },
	{ (TA_TFIFO), (NUM_MPF_NET_BUF_256), ROUND_MPF_T(sizeof(T_NET_BUF_256)), (_kernel_mpf_MPF_NET_BUF_256), (_kernel_mpfmb_MPF_NET_BUF_256) },
	{ (TA_TFIFO), (NUM_MPF_NET_BUF_512), ROUND_MPF_T(sizeof(T_NET_BUF_512)), (_kernel_mpf_MPF_NET_BUF_512), (_kernel_mpfmb_MPF_NET_BUF_512) },
	{ (TA_TFIFO), (NUM_MPF_NET_BUF_1024), ROUND_MPF_T(sizeof(T_NET_BUF_1024)), (_kernel_mpf_MPF_NET_BUF_1024), (_kernel_mpfmb_MPF_NET_BUF_1024) },
	{ (TA_TFIFO), (NUM_MPF_NET_BUF_IF_PDU), ROUND_MPF_T(sizeof(T_NET_BUF_IF_PDU)), (_kernel_mpf_MPF_NET_BUF_IF_PDU), (_kernel_mpfmb_MPF_NET_BUF_IF_PDU) }
};

MPFCB _kernel_mpfcb_table[TNUM_MPFID];

/*
 *  Cyclic Handler Functions
 */

const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);

const CYCINIB _kernel_cycinib_table[TNUM_CYCID] = {
	{ (TA_HLNG | TA_ACT), (intptr_t)(0), (net_timer_handler), (NET_TIMER_CYCLE), (1) }
};

CYCCB _kernel_cyccb_table[TNUM_CYCID];

/*
 *  Alarm Handler Functions
 */

const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);

const ALMINIB _kernel_alminib_table[TNUM_ALMID] = {
	{ (TA_NULL), (intptr_t)(DEV_MMC_RSPI0), (mmc_rspi_tout0_handler) },
	{ (TA_NULL), (intptr_t)(DEV_MMC_RSPI0), (mmc_rspi_tout1_handler) }
};

ALMCB _kernel_almcb_table[TNUM_ALMID];

/*
 *  Interrupt Management Functions
 */

void
_kernel_inthdr_39(void)
{
	i_begin_int(39);
	LOG_ISR_ENTER(39);
	((ISR)(rspi_rx_int_handler))((intptr_t)(DEV_RSPI0));
	LOG_ISR_LEAVE(39);
	i_end_int(39);
}
void
_kernel_inthdr_40(void)
{
	i_begin_int(40);
	LOG_ISR_ENTER(40);
	((ISR)(rspi_tx_int_handler))((intptr_t)(DEV_RSPI0));
	LOG_ISR_LEAVE(40);
	i_end_int(40);
}
void
_kernel_inthdr_214(void)
{
	i_begin_int(214);
	LOG_ISR_ENTER(214);
	((ISR)(sio_rx_isr))((intptr_t)(SIO_PORTID));
	LOG_ISR_LEAVE(214);
	i_end_int(214);
}
void
_kernel_inthdr_216(void)
{
	i_begin_int(216);
	LOG_ISR_ENTER(216);
	((ISR)(sio_tx_isr))((intptr_t)(SIO_PORTID));
	LOG_ISR_LEAVE(216);
	i_end_int(216);
}

#define TNUM_INHNO	6
const uint_t _kernel_tnum_inhno = TNUM_INHNO;

INTHDR_ENTRY(INHNO_TIMER, 28, target_timer_handler)
INTHDR_ENTRY(INHNO_IF_RX62N_TRX, 32, if_rx62n_trx_handler)
INTHDR_ENTRY(39, 39, _kernel_inthdr_39)
INTHDR_ENTRY(40, 40, _kernel_inthdr_40)
INTHDR_ENTRY(214, 214, _kernel_inthdr_214)
INTHDR_ENTRY(216, 216, _kernel_inthdr_216)

const INHINIB _kernel_inhinib_table[TNUM_INHNO] = {
	{ (INHNO_TIMER), (TA_NULL), (FP)(INT_ENTRY(INHNO_TIMER, target_timer_handler)) },
	{ (INHNO_IF_RX62N_TRX), (TA_NULL), (FP)(INT_ENTRY(INHNO_IF_RX62N_TRX, if_rx62n_trx_handler)) },
	{ (39), (TA_NULL), (FP)(INT_ENTRY(39, _kernel_inthdr_39)) },
	{ (40), (TA_NULL), (FP)(INT_ENTRY(40, _kernel_inthdr_40)) },
	{ (214), (TA_NULL), (FP)(INT_ENTRY(214, _kernel_inthdr_214)) },
	{ (216), (TA_NULL), (FP)(INT_ENTRY(216, _kernel_inthdr_216)) }
};

#define TNUM_INTNO	6
const uint_t _kernel_tnum_intno = TNUM_INTNO;

const INTINIB _kernel_intinib_table[TNUM_INTNO] = {
	{ (INTNO_TIMER), (INTATR_TIMER), (INTPRI_TIMER) },
	{ (INTNO_SIO_TX), (INTATR_SIO), (INTPRI_SIO) },
	{ (INTNO_SIO_RX), (INTATR_SIO), (INTPRI_SIO) },
	{ (INTNO_IF_RX62N_TRX), (INTATR_IF_RX62N_TRX), (INTPRI_IF_RX62N_TRX) },
	{ (RSPI_0_TX_INT_NO), (RSPI_INT_ATR), (-6) },
	{ (RSPI_0_RX_INT_NO), (RSPI_INT_ATR), (-6) }
};

/*
 *  CPU Exception Management Functions
 */

#define TNUM_EXCNO	0
const uint_t _kernel_tnum_excno = TNUM_EXCNO;


TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);

/*
 *  Stack Area for Non-task Context
 */

#ifdef DEFAULT_ISTK

#define TOPPERS_ISTKSZ		DEFAULT_ISTKSZ
#define TOPPERS_ISTK		DEFAULT_ISTK

#else /* DEAULT_ISTK */

static STK_T _kernel_istack[COUNT_STK_T(DEFAULT_ISTKSZ)];

#define TOPPERS_ISTKSZ		ROUND_STK_T(DEFAULT_ISTKSZ)
#define TOPPERS_ISTK		_kernel_istack

#endif /* DEAULT_ISTK */

const SIZE		_kernel_istksz = TOPPERS_ISTKSZ;
STK_T *const	_kernel_istk = TOPPERS_ISTK;

#ifdef TOPPERS_ISTKPT
STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ);
#endif /* TOPPERS_ISTKPT */

/*
 *  Time Event Management
 */

TMEVTN   _kernel_tmevt_heap[TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];

/*
 *  Module Initialization Function
 */

void
_kernel_initialize_object(void)
{
	_kernel_initialize_task();
	_kernel_initialize_semaphore();
	_kernel_initialize_eventflag();
	_kernel_initialize_dataqueue();
	_kernel_initialize_mempfix();
	_kernel_initialize_cyclic();
	_kernel_initialize_alarm();
	_kernel_initialize_interrupt();
	_kernel_initialize_exception();
}

/*
 *  Initialization Routine
 */

void
_kernel_call_inirtn(void)
{
	((INIRTN)(target_timer_initialize))((intptr_t)(0));
	((INIRTN)(syslog_initialize))((intptr_t)(0));
	((INIRTN)(print_banner))((intptr_t)(0));
	((INIRTN)(serial_initialize))((intptr_t)(0));
}

/*
 *  Termination Routine
 */

void
_kernel_call_terrtn(void)
{
	((TERRTN)(logtask_terminate))((intptr_t)(0));
	((TERRTN)(target_timer_terminate))((intptr_t)(0));
}







































































































































































































































































