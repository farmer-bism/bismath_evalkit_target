/* cfg1_out.c */
#define TOPPERS_CFG1_OUT  1
#include "kernel/kernel_int.h"
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


#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include "target_cfg1_out.h"

const uint32_t TOPPERS_cfg_magic_number = 0x12345678;
const uint32_t TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);
const uint32_t TOPPERS_cfg_sizeof_pointer = sizeof(const volatile void*);
const unsigned_t TOPPERS_cfg_CHAR_BIT = ((unsigned char)~0u == 0xff ? 8 : 16);
const unsigned_t TOPPERS_cfg_CHAR_MAX = ((char)-1 < 0 ? (char)((unsigned char)~0u >> 1) : (unsigned char)~0u);
const unsigned_t TOPPERS_cfg_CHAR_MIN = (unsigned_t)((char)-1 < 0 ? -((unsigned char)~0u >> 1) - 1 : 0);
const unsigned_t TOPPERS_cfg_SCHAR_MAX = (signed char)((unsigned char)~0u >> 1);
const unsigned_t TOPPERS_cfg_SHRT_MAX = (short)((unsigned short)~0u >> 1);
const unsigned_t TOPPERS_cfg_INT_MAX = (int)(~0u >> 1);
const unsigned_t TOPPERS_cfg_LONG_MAX = (long)(~0ul >> 1);

const unsigned_t TOPPERS_cfg_SIL_ENDIAN_BIG = 
#if defined(SIL_ENDIAN_BIG)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_SIL_ENDIAN_LITTLE = 
#if defined(SIL_ENDIAN_LITTLE)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TA_NULL = ( unsigned_t )TA_NULL;
const unsigned_t TOPPERS_cfg_TA_ACT = ( unsigned_t )TA_ACT;
const unsigned_t TOPPERS_cfg_TA_TPRI = ( unsigned_t )TA_TPRI;
const unsigned_t TOPPERS_cfg_TA_MPRI = ( unsigned_t )TA_MPRI;
const unsigned_t TOPPERS_cfg_TA_WMUL = ( unsigned_t )TA_WMUL;
const unsigned_t TOPPERS_cfg_TA_CLR = ( unsigned_t )TA_CLR;
const unsigned_t TOPPERS_cfg_TA_STA = ( unsigned_t )TA_STA;
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = ( unsigned_t )TA_NONKERNEL;
const unsigned_t TOPPERS_cfg_TA_ENAINT = ( unsigned_t )TA_ENAINT;
const unsigned_t TOPPERS_cfg_TA_EDGE = ( unsigned_t )TA_EDGE;
const signed_t TOPPERS_cfg_TMIN_TPRI = ( signed_t )TMIN_TPRI;
const signed_t TOPPERS_cfg_TMAX_TPRI = ( signed_t )TMAX_TPRI;
const signed_t TOPPERS_cfg_TMIN_DPRI = ( signed_t )TMIN_DPRI;
const signed_t TOPPERS_cfg_TMAX_DPRI = ( signed_t )TMAX_DPRI;
const signed_t TOPPERS_cfg_TMIN_MPRI = ( signed_t )TMIN_MPRI;
const signed_t TOPPERS_cfg_TMAX_MPRI = ( signed_t )TMAX_MPRI;
const signed_t TOPPERS_cfg_TMIN_ISRPRI = ( signed_t )TMIN_ISRPRI;
const signed_t TOPPERS_cfg_TMAX_ISRPRI = ( signed_t )TMAX_ISRPRI;
const unsigned_t TOPPERS_cfg_TBIT_TEXPTN = ( unsigned_t )TBIT_TEXPTN;
const unsigned_t TOPPERS_cfg_TBIT_FLGPTN = ( unsigned_t )TBIT_FLGPTN;
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = ( unsigned_t )TMAX_MAXSEM;
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = ( unsigned_t )TMAX_RELTIM;
const signed_t TOPPERS_cfg_TMIN_INTPRI = ( signed_t )TMIN_INTPRI;
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = 
#if defined(OMIT_INITIALIZE_INTERRUPT)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = 
#if defined(OMIT_INITIALIZE_EXCEPTION)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_USE_TSKINICTXB = 
#if defined(USE_TSKINICTXB)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = 
#if defined(TARGET_TSKATR)
(TARGET_TSKATR);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_INTATR = 
#if defined(TARGET_INTATR)
(TARGET_INTATR);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_INHATR = 
#if defined(TARGET_INHATR)
(TARGET_INHATR);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = 
#if defined(TARGET_ISRATR)
(TARGET_ISRATR);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = 
#if defined(TARGET_EXCATR)
(TARGET_EXCATR);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = 
#if defined(TARGET_MIN_STKSZ)
(TARGET_MIN_STKSZ);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = 
#if defined(TARGET_MIN_ISTKSZ)
(TARGET_MIN_ISTKSZ);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = 
#if defined(CHECK_STKSZ_ALIGN)
(CHECK_STKSZ_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = 
#if defined(CHECK_FUNC_ALIGN)
(CHECK_FUNC_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_FUNC_NONNULL = 
#if defined(CHECK_FUNC_NONNULL)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = 
#if defined(CHECK_STACK_ALIGN)
(CHECK_STACK_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_STACK_NONNULL = 
#if defined(CHECK_STACK_NONNULL)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = 
#if defined(CHECK_MPF_ALIGN)
(CHECK_MPF_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_MPF_NONNULL = 
#if defined(CHECK_MPF_NONNULL)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_sizeof_ID = ( unsigned_t )sizeof(ID);
const unsigned_t TOPPERS_cfg_sizeof_uint_t = ( unsigned_t )sizeof(uint_t);
const unsigned_t TOPPERS_cfg_sizeof_SIZE = ( unsigned_t )sizeof(SIZE);
const unsigned_t TOPPERS_cfg_sizeof_ATR = ( unsigned_t )sizeof(ATR);
const unsigned_t TOPPERS_cfg_sizeof_PRI = ( unsigned_t )sizeof(PRI);
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = ( unsigned_t )sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_VP = ( unsigned_t )sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = ( unsigned_t )sizeof(intptr_t);
const unsigned_t TOPPERS_cfg_sizeof_FP = ( unsigned_t )sizeof(FP);
const unsigned_t TOPPERS_cfg_sizeof_INHNO = ( unsigned_t )sizeof(INHNO);
const unsigned_t TOPPERS_cfg_sizeof_INTNO = ( unsigned_t )sizeof(INTNO);
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = ( unsigned_t )sizeof(EXCNO);
const unsigned_t TOPPERS_cfg_sizeof_TINIB = ( unsigned_t )sizeof(TINIB);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = ( unsigned_t )offsetof(TINIB,tskatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = ( unsigned_t )offsetof(TINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = ( unsigned_t )offsetof(TINIB,task);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = ( unsigned_t )offsetof(TINIB,ipriority);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = 
#if !defined(USE_TSKINICTXB)
(offsetof(TINIB,stksz));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = 
#if !defined(USE_TSKINICTXB)
(offsetof(TINIB,stk));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texatr = ( unsigned_t )offsetof(TINIB,texatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texrtn = ( unsigned_t )offsetof(TINIB,texrtn);
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = ( unsigned_t )sizeof(SEMINIB);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = ( unsigned_t )offsetof(SEMINIB,sematr);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = ( unsigned_t )offsetof(SEMINIB,isemcnt);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = ( unsigned_t )offsetof(SEMINIB,maxsem);
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = ( unsigned_t )sizeof(FLGPTN);
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = ( unsigned_t )sizeof(FLGINIB);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = ( unsigned_t )offsetof(FLGINIB,flgatr);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = ( unsigned_t )offsetof(FLGINIB,iflgptn);
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = ( unsigned_t )sizeof(DTQINIB);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = ( unsigned_t )offsetof(DTQINIB,dtqatr);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = ( unsigned_t )offsetof(DTQINIB,dtqcnt);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = ( unsigned_t )offsetof(DTQINIB,p_dtqmb);
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = ( unsigned_t )sizeof(PDQINIB);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = ( unsigned_t )offsetof(PDQINIB,pdqatr);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = ( unsigned_t )offsetof(PDQINIB,pdqcnt);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = ( unsigned_t )offsetof(PDQINIB,maxdpri);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = ( unsigned_t )offsetof(PDQINIB,p_pdqmb);
const unsigned_t TOPPERS_cfg_sizeof_MBXINIB = ( unsigned_t )sizeof(MBXINIB);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_mbxatr = ( unsigned_t )offsetof(MBXINIB,mbxatr);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_maxmpri = ( unsigned_t )offsetof(MBXINIB,maxmpri);
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = ( unsigned_t )sizeof(MPFINIB);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = ( unsigned_t )offsetof(MPFINIB,mpfatr);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = ( unsigned_t )offsetof(MPFINIB,blkcnt);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = ( unsigned_t )offsetof(MPFINIB,blksz);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = ( unsigned_t )offsetof(MPFINIB,mpf);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = ( unsigned_t )offsetof(MPFINIB,p_mpfmb);
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = ( unsigned_t )sizeof(CYCINIB);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = ( unsigned_t )offsetof(CYCINIB,cycatr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = ( unsigned_t )offsetof(CYCINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cychdr = ( unsigned_t )offsetof(CYCINIB,cychdr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = ( unsigned_t )offsetof(CYCINIB,cyctim);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = ( unsigned_t )offsetof(CYCINIB,cycphs);
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = ( unsigned_t )sizeof(ALMINIB);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = ( unsigned_t )offsetof(ALMINIB,almatr);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = ( unsigned_t )offsetof(ALMINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almhdr = ( unsigned_t )offsetof(ALMINIB,almhdr);
const unsigned_t TOPPERS_cfg_sizeof_INHINIB = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(sizeof(INHINIB));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_INHINIB_inhno = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(offsetof(INHINIB,inhno));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_INHINIB_inhatr = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(offsetof(INHINIB,inhatr));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_INHINIB_int_entry = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(offsetof(INHINIB,int_entry));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_sizeof_INTINIB = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(sizeof(INTINIB));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_INTINIB_intno = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(offsetof(INTINIB,intno));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_INTINIB_intatr = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(offsetof(INTINIB,intatr));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_INTINIB_intpri = 
#if !defined(OMIT_INITIALIZE_INTERRUPT)
(offsetof(INTINIB,intpri));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_sizeof_EXCINIB = 
#if !defined(OMIT_INITIALIZE_EXCEPTION)
(sizeof(EXCINIB));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_EXCINIB_excno = 
#if !defined(OMIT_INITIALIZE_EXCEPTION)
(offsetof(EXCINIB,excno));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_EXCINIB_excatr = 
#if !defined(OMIT_INITIALIZE_EXCEPTION)
(offsetof(EXCINIB,excatr));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offset_EXCINIB_exc_entry = 
#if !defined(OMIT_INITIALIZE_EXCEPTION)
(offsetof(EXCINIB,exc_entry));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_LOG_DSP_ENTER = ( unsigned_t )LOG_DSP_ENTER;
const unsigned_t TOPPERS_cfg_LOG_DSP_LEAVE = ( unsigned_t )LOG_DSP_LEAVE;
const unsigned_t TOPPERS_cfg_LOG_INH_ENTER = ( unsigned_t )LOG_INH_ENTER;
const unsigned_t TOPPERS_cfg_LOG_INH_LEAVE = ( unsigned_t )LOG_INH_LEAVE;
const unsigned_t TOPPERS_cfg_LOG_EXC_ENTER = ( unsigned_t )LOG_EXC_ENTER;
const unsigned_t TOPPERS_cfg_LOG_EXC_LEAVE = ( unsigned_t )LOG_EXC_LEAVE;
const unsigned_t TOPPERS_cfg_SIL_DLY_TIM1 = ( unsigned_t )SIL_DLY_TIM1;
const unsigned_t TOPPERS_cfg_SIL_DLY_TIM2 = ( unsigned_t )SIL_DLY_TIM2;
const unsigned_t TOPPERS_cfg_TA_LOWLEVEL = ( unsigned_t )TA_LOWLEVEL;
const unsigned_t TOPPERS_cfg_TA_BOTHEDGE = ( unsigned_t )TA_BOTHEDGE;
const unsigned_t TOPPERS_cfg_TA_NEGEDGE = ( unsigned_t )TA_NEGEDGE;
const unsigned_t TOPPERS_cfg_TIPM_LOCK = ( unsigned_t )TIPM_LOCK;
const unsigned_t TOPPERS_cfg_IPL_LOCK = ( unsigned_t )IPL_LOCK;
const unsigned_t TOPPERS_cfg_PSW_I_MASK = ( unsigned_t )PSW_I_MASK;
const unsigned_t TOPPERS_cfg_PSW_IPL_MASK = ( unsigned_t )PSW_IPL_MASK;
const unsigned_t TOPPERS_cfg_EXC_GET_PSW_OFFSET = ( unsigned_t )EXC_GET_PSW_OFFSET;
const unsigned_t TOPPERS_cfg_sizeof_TCB = ( unsigned_t )sizeof(TCB);
const unsigned_t TOPPERS_cfg_offsetof_TCB_p_tinib = ( unsigned_t )offsetof(TCB,p_tinib);
const unsigned_t TOPPERS_cfg_offsetof_TCB_texptn = ( unsigned_t )offsetof(TCB,texptn);
const unsigned_t TOPPERS_cfg_offsetof_TCB_sp = ( unsigned_t )offsetof(TCB,tskctxb.sp);
const unsigned_t TOPPERS_cfg_offsetof_TCB_pc = ( unsigned_t )offsetof(TCB,tskctxb.pc);


/* #include "target_timer.h" */

#line 6 "../../../asp/target/sakura_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_0 = 0;
const unsigned_t TOPPERS_cfg_valueof_iniatr_0 = ( unsigned_t )( TA_NULL ); 
#line 7 "../../../asp/target/sakura_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
const unsigned_t TOPPERS_cfg_valueof_teratr_1 = ( unsigned_t )( TA_NULL ); 
#line 8 "../../../asp/target/sakura_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
const unsigned_t TOPPERS_cfg_valueof_inhno_2 = ( unsigned_t )( INHNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_inhatr_2 = ( unsigned_t )( TA_NULL ); 
#line 9 "../../../asp/target/sakura_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
const unsigned_t TOPPERS_cfg_valueof_intno_3 = ( unsigned_t )( INTNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_intatr_3 = ( unsigned_t )( INTATR_TIMER ); const signed_t TOPPERS_cfg_valueof_intpri_3 = ( signed_t )( INTPRI_TIMER ); /* #include "syssvc/syslog.h" */

#line 10 "../../../asp/syssvc/syslog.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
const unsigned_t TOPPERS_cfg_valueof_iniatr_4 = ( unsigned_t )( TA_NULL ); /* #include "syssvc/banner.h" */

#line 10 "../../../asp/syssvc/banner.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
const unsigned_t TOPPERS_cfg_valueof_iniatr_5 = ( unsigned_t )( TA_NULL ); /* #include "target_syssvc.h" */
/* #include <target_serial.h> */

#line 6 "../../../asp/target/sakura_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
const unsigned_t TOPPERS_cfg_valueof_intno_6 = ( unsigned_t )( INTNO_SIO_TX ); const unsigned_t TOPPERS_cfg_valueof_intatr_6 = ( unsigned_t )( INTATR_SIO ); const signed_t TOPPERS_cfg_valueof_intpri_6 = ( signed_t )( INTPRI_SIO ); 
#line 7 "../../../asp/target/sakura_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
const unsigned_t TOPPERS_cfg_valueof_intno_7 = ( unsigned_t )( INTNO_SIO_RX ); const unsigned_t TOPPERS_cfg_valueof_intatr_7 = ( unsigned_t )( INTATR_SIO ); const signed_t TOPPERS_cfg_valueof_intpri_7 = ( signed_t )( INTPRI_SIO ); 
#line 9 "../../../asp/target/sakura_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
const unsigned_t TOPPERS_cfg_valueof_isratr_8 = ( unsigned_t )( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_8 = ( unsigned_t )( INTNO_SIO_TX ); const signed_t TOPPERS_cfg_valueof_isrpri_8 = ( signed_t )( 1 ); 
#line 10 "../../../asp/target/sakura_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
const unsigned_t TOPPERS_cfg_valueof_isratr_9 = ( unsigned_t )( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_9 = ( unsigned_t )( INTNO_SIO_RX ); const signed_t TOPPERS_cfg_valueof_isrpri_9 = ( signed_t )( 1 ); /* #include "syssvc/serial.h" */

#line 13 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
const unsigned_t TOPPERS_cfg_valueof_iniatr_10 = ( unsigned_t )( TA_NULL ); 
#line 15 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#define SERIAL_RCV_SEM1	(<>)

#line 15 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_11 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_11 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_11 = ( unsigned_t )( 1 ); 
#line 16 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#define SERIAL_SND_SEM1	(<>)

#line 16 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_12 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_12 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_12 = ( unsigned_t )( 1 ); 
#if TNUM_PORT >= 2

#line 18 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
#define SERIAL_RCV_SEM2	(<>)

#line 18 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_13 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_13 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_13 = ( unsigned_t )( 1 ); 
#line 19 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
#define SERIAL_SND_SEM2	(<>)

#line 19 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_14 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_14 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_14 = ( unsigned_t )( 1 ); 
#endif 

#if TNUM_PORT >= 3

#line 22 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
#define SERIAL_RCV_SEM3	(<>)

#line 22 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_15 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_15 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_15 = ( unsigned_t )( 1 ); 
#line 23 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
#define SERIAL_SND_SEM3	(<>)

#line 23 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_16 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_16 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_16 = ( unsigned_t )( 1 ); 
#endif 

#if TNUM_PORT >= 4

#line 26 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
#define SERIAL_RCV_SEM4	(<>)

#line 26 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_17 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_17 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_17 = ( unsigned_t )( 1 ); 
#line 27 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#define SERIAL_SND_SEM4	(<>)

#line 27 "../../../asp/syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_18 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_18 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_18 = ( unsigned_t )( 1 ); 
#endif 
/* #include "syssvc/logtask.h" */

#line 10 "../../../asp/syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_19 = 19;
#define LOGTASK	(<>)

#line 10 "../../../asp/syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_19 = ( unsigned_t )( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_19 = ( signed_t )( LOGTASK_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_19 = ( unsigned_t )( LOGTASK_STACK_SIZE ); 
#line 12 "../../../asp/syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_20 = 20;
const unsigned_t TOPPERS_cfg_valueof_teratr_20 = ( unsigned_t )( TA_NULL ); /* #include "target_sil.h" */
/* #include <itron.h> */
/* #include <tinet_defs.h> */
/* #include <tinet_config.h> */
/* #include <net/if.h> */
/* #include <net/if_ppp.h> */
/* #include <net/if_loop.h> */
/* #include <net/ethernet.h> */
/* #include <net/if_arp.h> */
/* #include <net/net.h> */
/* #include <net/net_buf.h> */
/* #include <net/net_timer.h> */
/* #include <net/ppp_var.h> */
/* #include <net/ether_var.h> */
/* #include <netinet/in.h> */
/* #include <netinet/ip.h> */
/* #include <netinet/ip6.h> */
/* #include <netinet/ip_var.h> */
/* #include <netinet/tcp.h> */
/* #include <netinet/tcp_timer.h> */
/* #include <netinet/tcp_var.h> */
/* #include <netinet/udp_var.h> */
/* #include <netinet6/in6.h> */
/* #include <netinet6/ip6_var.h> */
/* #include "tinet_cfg.h" */

#if defined(TCP_CFG_EXTENTIONS)

#line 4 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_21 = 21;
#define SEM_TCP_REP_LOCK1	(<>)

#line 4 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_21 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_21 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_21 = ( unsigned_t )( 1 ); 
#line 5 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_22 = 22;
#define SEM_TCP_REP_LOCK2	(<>)

#line 5 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_22 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_22 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_22 = ( unsigned_t )( 1 ); 
#endif

#line 9 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_23 = 23;
#define SEM_TCP_CEP_LOCK1	(<>)

#line 9 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_23 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_23 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_23 = ( unsigned_t )( 1 ); 
#line 10 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_24 = 24;
#define FLG_TCP_CEP_EST1	(<>)

#line 10 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_24 = ( unsigned_t )( TA_TFIFO|TA_WSGL ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_24 = ( unsigned_t )( TCP_CEP_EVT_CLOSED ); 
#line 11 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_25 = 25;
#define FLG_TCP_CEP_SND1	(<>)

#line 11 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_25 = ( unsigned_t )( TA_TFIFO|TA_WSGL ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_25 = ( unsigned_t )( TCP_CEP_EVT_SWBUF_READY ); 
#line 12 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_26 = 26;
#define FLG_TCP_CEP_RCV1	(<>)

#line 12 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_26 = ( unsigned_t )( TA_TFIFO|TA_WSGL ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_26 = ( unsigned_t )( 0 ); 
#line 14 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_27 = 27;
#define SEM_TCP_CEP_LOCK2	(<>)

#line 14 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_27 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_27 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_27 = ( unsigned_t )( 1 ); 
#line 15 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_28 = 28;
#define FLG_TCP_CEP_EST2	(<>)

#line 15 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_28 = ( unsigned_t )( TA_TFIFO|TA_WSGL ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_28 = ( unsigned_t )( TCP_CEP_EVT_CLOSED ); 
#line 16 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_29 = 29;
#define FLG_TCP_CEP_SND2	(<>)

#line 16 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_29 = ( unsigned_t )( TA_TFIFO|TA_WSGL ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_29 = ( unsigned_t )( TCP_CEP_EVT_SWBUF_READY ); 
#line 17 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_static_api_30 = 30;
#define FLG_TCP_CEP_RCV2	(<>)

#line 17 "tinet_kern.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_30 = ( unsigned_t )( TA_TFIFO|TA_WSGL ); const unsigned_t TOPPERS_cfg_valueof_iflgptn_30 = ( unsigned_t )( 0 ); 
#ifdef SUPPORT_ETHER
/* #include "if_rx62nreg.h" */

#line 50 "../../../asp/tinet/netdev/if_rx62n/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_31 = 31;
const unsigned_t TOPPERS_cfg_valueof_inhno_31 = ( unsigned_t )( INHNO_IF_RX62N_TRX ); const unsigned_t TOPPERS_cfg_valueof_inhatr_31 = ( unsigned_t )( TA_NULL ); 
#line 51 "../../../asp/tinet/netdev/if_rx62n/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_32 = 32;
const unsigned_t TOPPERS_cfg_valueof_intno_32 = ( unsigned_t )( INTNO_IF_RX62N_TRX ); const unsigned_t TOPPERS_cfg_valueof_intatr_32 = ( unsigned_t )( INTATR_IF_RX62N_TRX ); const signed_t TOPPERS_cfg_valueof_intpri_32 = ( signed_t )( INTPRI_IF_RX62N_TRX ); 
#line 55 "../../../asp/tinet/netdev/if_rx62n/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_33 = 33;
#define SEM_IF_RX62N_SBUF_READY	(<>)

#line 55 "../../../asp/tinet/netdev/if_rx62n/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_33 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_33 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_33 = ( unsigned_t )( 1 ); 
#line 56 "../../../asp/tinet/netdev/if_rx62n/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_34 = 34;
#define SEM_IF_RX62N_RBUF_READY	(<>)

#line 56 "../../../asp/tinet/netdev/if_rx62n/nic_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_34 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_34 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_34 = ( unsigned_t )( NUM_IF_RX62N_RXBUF ); 
#endif	

#line 42 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_35 = 35;
#define NET_TIMER_TASK	(<>)

#line 42 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_35 = ( unsigned_t )( TA_HLNG ); const signed_t TOPPERS_cfg_valueof_itskpri_35 = ( signed_t )( NET_TIMER_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_35 = ( unsigned_t )( NET_TIMER_STACK_SIZE ); 
#line 51 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_36 = 36;
#define NET_TIMER_HANDLER	(<>)

#line 51 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_36 = ( unsigned_t )( TA_HLNG | TA_ACT ); const unsigned_t TOPPERS_cfg_valueof_cyctim_36 = ( unsigned_t )( NET_TIMER_CYCLE ); const unsigned_t TOPPERS_cfg_valueof_cycphs_36 = ( unsigned_t )( 1 ); 
#line 61 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_37 = 37;
#define SEM_CALL_OUT_LOCK	(<>)

#line 61 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_37 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_37 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_37 = ( unsigned_t )( 1 ); 
#line 62 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_38 = 38;
#define SEM_CALL_OUT_TIMEOUT	(<>)

#line 62 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_38 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_38 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_38 = ( unsigned_t )( NUM_NET_CALLOUT ); 
#line 66 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_static_api_39 = 39;
#define SEM_IP2STR_BUFF_LOCK	(<>)

#line 66 "../../../asp/tinet/net/net.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_39 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_39 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_39 = ( unsigned_t )( 1 ); 
#if defined(NUM_MPF_NET_BUF_CSEG) && NUM_MPF_NET_BUF_CSEG > 0

#line 49 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_40 = 40;
#define MPF_NET_BUF_CSEG	(<>)

#line 49 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_40 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_40 = ( unsigned_t )( NUM_MPF_NET_BUF_CSEG ); const unsigned_t TOPPERS_cfg_valueof_blksz_40 = ( unsigned_t )( sizeof(T_NET_BUF_CSEG) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_64) && NUM_MPF_NET_BUF_64 > 0

#line 59 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_41 = 41;
#define MPF_NET_BUF_64	(<>)

#line 59 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_41 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_41 = ( unsigned_t )( NUM_MPF_NET_BUF_64 ); const unsigned_t TOPPERS_cfg_valueof_blksz_41 = ( unsigned_t )( sizeof(T_NET_BUF_64) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_128) && NUM_MPF_NET_BUF_128 > 0

#line 68 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_42 = 42;
#define MPF_NET_BUF_128	(<>)

#line 68 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_42 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_42 = ( unsigned_t )( NUM_MPF_NET_BUF_128 ); const unsigned_t TOPPERS_cfg_valueof_blksz_42 = ( unsigned_t )( sizeof(T_NET_BUF_128) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_256) && NUM_MPF_NET_BUF_256 > 0

#line 78 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_43 = 43;
#define MPF_NET_BUF_256	(<>)

#line 78 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_43 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_43 = ( unsigned_t )( NUM_MPF_NET_BUF_256 ); const unsigned_t TOPPERS_cfg_valueof_blksz_43 = ( unsigned_t )( sizeof(T_NET_BUF_256) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_512) && NUM_MPF_NET_BUF_512 > 0

#line 88 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_44 = 44;
#define MPF_NET_BUF_512	(<>)

#line 88 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_44 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_44 = ( unsigned_t )( NUM_MPF_NET_BUF_512 ); const unsigned_t TOPPERS_cfg_valueof_blksz_44 = ( unsigned_t )( sizeof(T_NET_BUF_512) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_IP_MSS) && NUM_MPF_NET_BUF_IP_MSS > 0

#line 98 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_45 = 45;
#define MPF_NET_BUF_IP_MSS	(<>)

#line 98 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_45 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_45 = ( unsigned_t )( NUM_MPF_NET_BUF_IP_MSS ); const unsigned_t TOPPERS_cfg_valueof_blksz_45 = ( unsigned_t )( sizeof(T_NET_BUF_IP_MSS) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_1024) && NUM_MPF_NET_BUF_1024 > 0

#line 108 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_46 = 46;
#define MPF_NET_BUF_1024	(<>)

#line 108 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_46 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_46 = ( unsigned_t )( NUM_MPF_NET_BUF_1024 ); const unsigned_t TOPPERS_cfg_valueof_blksz_46 = ( unsigned_t )( sizeof(T_NET_BUF_1024) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_IPV6_MMTU) && NUM_MPF_NET_BUF_IPV6_MMTU > 0

#line 118 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_47 = 47;
#define MPF_NET_BUF_IPV6_MMTU	(<>)

#line 118 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_47 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_47 = ( unsigned_t )( NUM_MPF_NET_BUF_IPV6_MMTU ); const unsigned_t TOPPERS_cfg_valueof_blksz_47 = ( unsigned_t )( sizeof(T_NET_BUF_IPV6_MMTU) ); 
#endif	

#if defined(NUM_MPF_NET_BUF_IF_PDU) && NUM_MPF_NET_BUF_IF_PDU > 0

#line 128 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_48 = 48;
#define MPF_NET_BUF_IF_PDU	(<>)

#line 128 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_48 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_48 = ( unsigned_t )( NUM_MPF_NET_BUF_IF_PDU ); const unsigned_t TOPPERS_cfg_valueof_blksz_48 = ( unsigned_t )( sizeof(T_NET_BUF_IF_PDU) ); 
#endif	

#if defined(NUM_MPF_NET_BUF4_REASSM) && NUM_MPF_NET_BUF4_REASSM > 0

#line 138 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_49 = 49;
#define MPF_NET_BUF_REASSM	(<>)

#line 138 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_49 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_49 = ( unsigned_t )( NUM_MPF_NET_BUF4_REASSM ); const unsigned_t TOPPERS_cfg_valueof_blksz_49 = ( unsigned_t )( sizeof(T_NET_BUF4_REASSM) ); 
#endif	

#if defined(NUM_MPF_NET_BUF6_REASSM) && NUM_MPF_NET_BUF6_REASSM > 0

#line 148 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_50 = 50;
#define MPF_NET_BUF_REASSM	(<>)

#line 148 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_50 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_50 = ( unsigned_t )( NUM_MPF_NET_BUF6_REASSM ); const unsigned_t TOPPERS_cfg_valueof_blksz_50 = ( unsigned_t )( sizeof(T_NET_BUF6_REASSM) ); 
#endif	

#if defined(NUM_MPF_NET_BUF6_65536) && NUM_MPF_NET_BUF6_65536 > 0

#line 158 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_static_api_51 = 51;
#define MPF_NET_BUF6_65536	(<>)

#line 158 "../../../asp/tinet/net/net_asp.cfg"
const unsigned_t TOPPERS_cfg_valueof_mpfatr_51 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_blkcnt_51 = ( unsigned_t )( NUM_MPF_NET_BUF6_65536 ); const unsigned_t TOPPERS_cfg_valueof_blksz_51 = ( unsigned_t )( sizeof(T_NET_BUF6_65536) ); 
#endif	

#ifdef SUPPORT_ETHER

#line 40 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_52 = 52;
#define ETHER_OUTPUT_TASK	(<>)

#line 40 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_52 = ( unsigned_t )( TA_HLNG ); const signed_t TOPPERS_cfg_valueof_itskpri_52 = ( signed_t )( ETHER_OUTPUT_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_52 = ( unsigned_t )( ETHER_OUTPUT_STACK_SIZE ); 
#line 41 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_53 = 53;
#define ETHER_INPUT_TASK	(<>)

#line 41 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_53 = ( unsigned_t )( TA_HLNG|TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_53 = ( signed_t )( ETHER_INPUT_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_53 = ( unsigned_t )( ETHER_INPUT_STACK_SIZE ); 
#line 43 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_54 = 54;
#define DTQ_ETHER_OUTPUT	(<>)

#line 43 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_dtqatr_54 = ( unsigned_t )( TA_TFIFO ); const unsigned_t TOPPERS_cfg_valueof_dtqcnt_54 = ( unsigned_t )( NUM_DTQ_ETHER_OUTPUT ); 
#line 47 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_static_api_55 = 55;
#define SEM_MAC2STR_BUFF_LOCK	(<>)

#line 47 "../../../asp/tinet/net/ethernet.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_55 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_55 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_55 = ( unsigned_t )( 1 ); 
#endif	

#ifdef SUPPORT_ETHER

#line 42 "../../../asp/tinet/netinet/if_ether.cfg"
const unsigned_t TOPPERS_cfg_static_api_56 = 56;
#define SEM_ARP_CACHE_LOCK	(<>)

#line 42 "../../../asp/tinet/netinet/if_ether.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_56 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_56 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_56 = ( unsigned_t )( 1 ); 
#endif	

#if defined(SUPPORT_INET4)

#ifdef IP4_CFG_FRAGMENT

#line 44 "../../../asp/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_static_api_57 = 57;
#define SEM_IP4_FRAG_QUEUE	(<>)

#line 44 "../../../asp/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_57 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_57 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_57 = ( unsigned_t )( 1 ); 
#endif	

#if NUM_REDIRECT_ROUTE_ENTRY > 0

#line 52 "../../../asp/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_static_api_58 = 58;
#define SEM_IN_ROUTING_TBL	(<>)

#line 52 "../../../asp/tinet/netinet/ip.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_58 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_58 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_58 = ( unsigned_t )( 1 ); 
#endif	

#endif	

#ifdef SUPPORT_TCP

#line 42 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_59 = 59;
#define TCP_OUTPUT_TASK	(<>)

#line 42 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_59 = ( unsigned_t )( TA_HLNG ); const signed_t TOPPERS_cfg_valueof_itskpri_59 = ( signed_t )( TCP_OUT_TASK_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_59 = ( unsigned_t )( TCP_OUT_TASK_STACK_SIZE ); 
#line 53 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_60 = 60;
#define SEM_TCP_POST_OUTPUT	(<>)

#line 53 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_60 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_60 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_60 = ( unsigned_t )( 1 ); 
#line 54 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_61 = 61;
#define SEM_TCP_CEP	(<>)

#line 54 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_61 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_61 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_61 = ( unsigned_t )( 1 ); 
#ifdef TCP_CFG_TRACE

#line 57 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_static_api_62 = 62;
#define SEM_TCP_TRACE	(<>)

#line 57 "../../../asp/tinet/netinet/tcp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_62 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_62 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_62 = ( unsigned_t )( 1 ); 
#endif	

#endif	

#ifdef SUPPORT_UDP

#ifdef UDP_CFG_NON_BLOCKING

#line 46 "../../../asp/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_63 = 63;
#define UDP_OUTPUT_TASK	(<>)

#line 46 "../../../asp/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_63 = ( unsigned_t )( TA_HLNG ); const signed_t TOPPERS_cfg_valueof_itskpri_63 = ( signed_t )( UDP_OUT_TASK_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_63 = ( unsigned_t )( UDP_OUT_TASK_STACK_SIZE ); 
#line 57 "../../../asp/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_64 = 64;
#define SEM_UDP_POST_OUTPUT	(<>)

#line 57 "../../../asp/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_64 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_64 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_64 = ( unsigned_t )( 1 ); 
#endif	

#line 61 "../../../asp/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_static_api_65 = 65;
#define SEM_UDP_CEP	(<>)

#line 61 "../../../asp/tinet/netinet/udp.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_65 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_65 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_65 = ( unsigned_t )( 1 ); 
#endif	

#ifdef SUPPORT_INET6

#line 42 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_66 = 66;
#define SEM_ND6_CACHE	(<>)

#line 42 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_66 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_66 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_66 = ( unsigned_t )( 1 ); 
#if NUM_ND6_DEF_RTR_ENTRY > 0

#line 48 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_67 = 67;
#define SEM_ND6_DEFRTRLIST	(<>)

#line 48 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_67 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_67 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_67 = ( unsigned_t )( 1 ); 
#endif	

#ifdef IP6_CFG_FRAGMENT

#line 56 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_68 = 68;
#define SEM_IP6_FRAG_QUEUE	(<>)

#line 56 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_68 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_68 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_68 = ( unsigned_t )( 1 ); 
#endif	

#if NUM_REDIRECT_ROUTE_ENTRY > 0

#line 64 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_static_api_69 = 69;
#define SEM_IN_ROUTING_TBL	(<>)

#line 64 "../../../asp/tinet/netinet6/ip6.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_69 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_69 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_69 = ( unsigned_t )( 1 ); 
#endif	

#endif	
/* #include "middleware/tinet_ftpd/ftpd_config.h" */

#line 36 "../../../asp/middleware/tinet_ftpd/ftpd.cfg"
const unsigned_t TOPPERS_cfg_static_api_70 = 70;
#define TCP_FTPD_CONTROL_TASK	(<>)

#line 36 "../../../asp/middleware/tinet_ftpd/ftpd.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_70 = ( unsigned_t )( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_70 = ( signed_t )( TCP_FTPD_CONTROL_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_70 = ( unsigned_t )( TCP_FTPD_CONTROL_STACK_SIZE ); 
#line 46 "../../../asp/middleware/tinet_ftpd/ftpd.cfg"
const unsigned_t TOPPERS_cfg_static_api_71 = 71;
#define TCP_FTPD_DATA_TASK	(<>)

#line 46 "../../../asp/middleware/tinet_ftpd/ftpd.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_71 = ( unsigned_t )( 0 ); const signed_t TOPPERS_cfg_valueof_itskpri_71 = ( signed_t )( TCP_FTPD_DATA_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_71 = ( unsigned_t )( TCP_FTPD_DATA_STACK_SIZE ); /* #include <target_board.h> */
/* #include <driver/rx_gcc/mmc_rspi.h> */

#ifdef USE_MMC_RSPI_0

#line 15 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_72 = 72;
#define MMC_RSPI0_ALMHDR_0	(<>)

#line 15 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_72 = ( unsigned_t )( TA_NULL ); 
#line 16 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_73 = 73;
#define MMC_RSPI0_ALMHDR_1	(<>)

#line 16 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_73 = ( unsigned_t )( TA_NULL ); 
#endif

#ifdef USE_MMC_RSPI_1

#line 20 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_74 = 74;
#define MMC_RSPI1_ALMHDR_0	(<>)

#line 20 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_74 = ( unsigned_t )( TA_NULL ); 
#line 21 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_75 = 75;
#define MMC_RSPI1_ALMHDR_1	(<>)

#line 21 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_75 = ( unsigned_t )( TA_NULL ); 
#endif

#ifdef USE_MMC_RSPI_2

#line 25 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_76 = 76;
#define MMC_RSPI2_ALMHDR_0	(<>)

#line 25 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_76 = ( unsigned_t )( TA_NULL ); 
#line 26 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_77 = 77;
#define MMC_RSPI2_ALMHDR_1	(<>)

#line 26 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_77 = ( unsigned_t )( TA_NULL ); 
#endif

#ifdef USE_MMC_RSPI_3

#line 30 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_78 = 78;
#define MMC_RSPI3_ALMHDR_0	(<>)

#line 30 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_78 = ( unsigned_t )( TA_NULL ); 
#line 31 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_static_api_79 = 79;
#define MMC_RSPI3_ALMHDR_1	(<>)

#line 31 "../../../asp/driver/rx_gcc/mmc_rspi.cfg"
const unsigned_t TOPPERS_cfg_valueof_almatr_79 = ( unsigned_t )( TA_NULL ); 
#endif
/* #include <driver/rx_gcc/RSPI.h> */

#ifdef USE_RSPI_0

#line 6 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_static_api_80 = 80;
#define RSPI_0_IP_LOCK_SEM	(<>)

#line 6 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_80 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_80 = ( unsigned_t )( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_80 = ( unsigned_t )( 1 ); 
#line 8 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_static_api_81 = 81;
#define RSPI_0_INT_SYNC_SEM	(<>)

#line 8 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_81 = ( unsigned_t )( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_81 = ( unsigned_t )( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_81 = ( unsigned_t )( 1 ); 
#line 11 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_static_api_82 = 82;
const unsigned_t TOPPERS_cfg_valueof_isratr_82 = ( unsigned_t )( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_82 = ( unsigned_t )( RSPI_0_TX_INT_NO ); const signed_t TOPPERS_cfg_valueof_isrpri_82 = ( signed_t )( 6 ); 
#line 12 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_static_api_83 = 83;
const unsigned_t TOPPERS_cfg_valueof_intno_83 = ( unsigned_t )( RSPI_0_TX_INT_NO ); const unsigned_t TOPPERS_cfg_valueof_intatr_83 = ( unsigned_t )( RSPI_INT_ATR ); const signed_t TOPPERS_cfg_valueof_intpri_83 = ( signed_t )( -6 ); 
#line 15 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_static_api_84 = 84;
const unsigned_t TOPPERS_cfg_valueof_isratr_84 = ( unsigned_t )( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_84 = ( unsigned_t )( RSPI_0_RX_INT_NO ); const signed_t TOPPERS_cfg_valueof_isrpri_84 = ( signed_t )( 6 ); 
#line 16 "../../../asp/driver/rx_gcc/RSPI.cfg"
const unsigned_t TOPPERS_cfg_static_api_85 = 85;
const unsigned_t TOPPERS_cfg_valueof_intno_85 = ( unsigned_t )( RSPI_0_RX_INT_NO ); const unsigned_t TOPPERS_cfg_valueof_intatr_85 = ( unsigned_t )( RSPI_INT_ATR ); const signed_t TOPPERS_cfg_valueof_intpri_85 = ( signed_t )( -6 ); 
#endif

