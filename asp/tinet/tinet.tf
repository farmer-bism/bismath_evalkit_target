$ ======================================================================
$ 
$   TINET (TCP/IP Protocol Stack)
$ 
$   Copyright (C) 2001-2007 by Dep. of Computer Science and Engineering
$                    Tomakomai National College of Technology, JAPAN
$  
$   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$       ����������˴ޤޤ�Ƥ��뤳�ȡ�
$   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$       �ȡ�
$     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$       ���դ��뤳�ȡ�
$  
$   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$   ����Ǥ�����ʤ���
$ 
$   @(#) $Id: $
$  
$ =====================================================================

$ =====================================================================
$ tinet_cfg.h ������
$ =====================================================================

$FILE "tinet_cfg.h"$
/* tinet_cfg.h */$NL$
#ifndef _TINET_CFG_H_$NL$
#define _TINET_CFG_H_$NL$
$NL$
$FOREACH id TCP4_REP.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id TCP6_REP.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id TCP4_CEP.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id TCP6_CEP.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id UDP4_CEP.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id UDP6_CEP.ID_LIST$
	#define $id$	$+id$$NL$
$END$
$FOREACH id VRID_TCP4_REP.ID_LIST$
	#define $id$	$+id + LENGTH(TCP4_REP.ID_LIST)$$NL$
$END$
$FOREACH id VRID_TCP4_CEP.ID_LIST$
	#define $id$	$+id + LENGTH(TCP4_CEP.ID_LIST)$$NL$
$END$
$FOREACH id VRID_TCP6_REP.ID_LIST$
	#define $id$	$+id + LENGTH(TCP6_REP.ID_LIST)$$NL$
$END$
$FOREACH id VRID_TCP6_CEP.ID_LIST$
	#define $id$	$+id + LENGTH(TCP6_CEP.ID_LIST)$$NL$
$END$
$FOREACH id VRID_UDP4_CEP.ID_LIST$
	#define $id$	$+id + LENGTH(UDP4_CEP.ID_LIST)$$NL$
$END$
$FOREACH id VRID_UDP6_CEP.ID_LIST$
	#define $id$	$+id + LENGTH(UDP6_CEP.ID_LIST)$$NL$
$END$
$NL$
#endif /* _TINET_CFG_H_ */$NL$

$ =====================================================================
$ tinet_cfg.c ������
$ =====================================================================

$FILE "tinet_cfg.c"$
/* tinet_cfg.c */$NL$
$NL$
#include <kernel.h>$NL$
#include <sil.h>$NL$
#include "kernel_cfg.h"$NL$
#include "tinet_cfg.h"$NL$
#include <tinet_defs.h>$NL$
#include <tinet_config.h>$NL$
#include <net/if.h>$NL$
#include <net/if_ppp.h>$NL$
#include <net/if_loop.h>$NL$
#include <net/ethernet.h>$NL$
#include <net/net.h>$NL$
#include <net/net_buf.h>$NL$
#include <netinet/in.h>$NL$
#include <netinet/in_itron.h>$NL$
#include <netinet/ip.h>$NL$
#include <netinet/ip6.h>$NL$
#include <netinet/tcp.h>$NL$
#include <netinet/tcp_timer.h>$NL$
#include <netinet/tcp_var.h>$NL$
#include <netinet/tcp_fsm.h>$NL$
#include <netinet/udp_var.h>$NL$

$ 
$  ���󥯥롼�ɥǥ��쥯�ƥ��֡�#include��
$ 
$NL$
/*$NL$
$SPC$*  Include Directives (#include)$NL$
$SPC$*/$NL$
$NL$
$INCLUDES$

$	// TCP (IPv4) ���ո�
$IF LENGTH(TCP4_REP.ID_LIST) + LENGTH(VRID_TCP4_REP.ID_LIST)$
	$NL$
	#define TNUM_TCP_REPID	$LENGTH(TCP4_REP.ID_LIST) + LENGTH(VRID_TCP4_REP.ID_LIST)$$NL$
	$NL$
	const ID tmax_tcp_repid = (TMIN_TCP_REPID + TNUM_TCP_REPID - 1);$NL$
	$NL$
	T_TCP4_REP tcp_rep[TNUM_TCP_REPID] = {$NL$
	$FOREACH id TCP4_REP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$$TCP4_REP.TCP4_REPATR[id]$,$NL$
			$TAB$$TAB${ $TCP4_REP.IPV4ADDR[id]$, $TCP4_REP.PORTNO[id]$ },$NL$
	#if defined(TCP_CFG_EXTENTIONS)$NL$
			$TAB$$TAB$TCP_REP_FLG_VALID,$NL$
			$TAB$$TAB$SEM_TCP_REP_LOCK$+id$,$NL$
	#endif$NL$
			$TAB$$TAB$},$NL$
	$END$
	$FOREACH id VRID_TCP4_REP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB${ IPV4_ADDRANY, TCP_PORTANY },$NL$
	#if defined(TCP_CFG_EXTENTIONS)$NL$
			$TAB$$TAB$TCP_REP_FLG_DYNAMIC,$NL$
			$TAB$$TAB$SEM_TCP_REP_LOCK$+id + LENGTH(TCP4_REP.ID_LIST)$,$NL$
	#endif$NL$
			$TAB$$TAB$},$NL$
	$END$
		$TAB$};$NL$
$END$

$	// TCP (IPv6) ���ո�
$IF LENGTH(TCP6_REP.ID_LIST) + LENGTH(VRID_TCP6_REP.ID_LIST)$
	$NL$
	#define TNUM_TCP_REPID	$LENGTH(TCP6_REP.ID_LIST) + LENGTH(VRID_TCP6_REP.ID_LIST)$$NL$
	$NL$
	const ID tmax_tcp_repid = (TMIN_TCP_REPID + TNUM_TCP_REPID - 1);$NL$
	$NL$
	T_TCP6_REP tcp_rep[TNUM_TCP_REPID] = {$NL$
	$FOREACH id TCP6_REP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$$TCP6_REP.TCP6_REPATR[id]$,$NL$
			$TAB$$TAB${ $TCP6_REP.IPV6ADDR[id]$, $TCP6_REP.PORTNO[id]$ },$NL$
	#if defined(TCP_CFG_EXTENTIONS)$NL$
			$TAB$$TAB$TCP_REP_FLG_VALID,$NL$
			$TAB$$TAB$SEM_TCP_REP_LOCK$+id$,$NL$
	#endif$NL$
			$TAB$$TAB$},$NL$
	$END$
	$FOREACH id VRID_TCP6_REP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB${ IPV6_ADDRANY, TCP_PORTANY },$NL$
	#if defined(TCP_CFG_EXTENTIONS)$NL$
			$TAB$$TAB$TCP_REP_FLG_DYNAMIC,$NL$
			$TAB$$TAB$SEM_TCP_REP_LOCK$+id + LENGTH(TCP6_REP.ID_LIST)$,$NL$
	#endif$NL$
			$TAB$$TAB$},$NL$
	$END$
		$TAB$};$NL$
$END$

$	// TCP (IPv4) �̿�ü��
$IF LENGTH(TCP4_CEP.ID_LIST) + LENGTH(VRID_TCP4_CEP.ID_LIST)$
	$NL$
	#define TNUM_TCP_CEPID	$LENGTH(TCP4_CEP.ID_LIST) + LENGTH(VRID_TCP4_CEP.ID_LIST)$$NL$
	$NL$
	const ID tmax_tcp_cepid = (TMIN_TCP_CEPID + TNUM_TCP_CEPID - 1);$NL$
	$NL$
	T_TCP4_CEP tcp_cep[TNUM_TCP_CEPID] = {$NL$
	$FOREACH id TCP4_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$$TCP4_CEP.TCP4_CEPATR[id]$,$NL$
			$TAB$$TAB$(void*)$TCP4_CEP.SBUF[id]$,$NL$
			$TAB$$TAB$$TCP4_CEP.SBUFSZ[id]$,$NL$
			$TAB$$TAB$(void*)$TCP4_CEP.RBUF[id]$,$NL$
			$TAB$$TAB$$TCP4_CEP.RBUFSZ[id]$,$NL$
			$TAB$$TAB$(t_tcp_callback)(FP)$TCP4_CEP.CALLBACK[id]$,$NL$
			$TAB$$TAB$TCP_CEP_FLG_VALID,$NL$
			$TAB$$TAB$SEM_TCP_CEP_LOCK$+id$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_EST$+id$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_SND$+id$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_RCV$+id$,$NL$
			$TAB$$TAB$},$NL$
	$END$
	$FOREACH id VRID_TCP4_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB$(void*)NULL,$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB$(void*)NULL,$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB$(t_tcp_callback)(FP)NULL,$NL$
			$TAB$$TAB$TCP_CEP_FLG_DYNAMIC,$NL$
			$TAB$$TAB$SEM_TCP_CEP_LOCK$+id + LENGTH(TCP4_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_EST$+id + LENGTH(TCP4_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_SND$+id + LENGTH(TCP4_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_RCV$+id + LENGTH(TCP4_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$},$NL$
	$END$
		$TAB$};$NL$
$END$

$	// TCP (IPv6) �̿�ü��
$IF LENGTH(TCP6_CEP.ID_LIST) + LENGTH(VRID_TCP6_CEP.ID_LIST)$
	$NL$
	#define TNUM_TCP_CEPID	$LENGTH(TCP6_CEP.ID_LIST) + LENGTH(VRID_TCP6_CEP.ID_LIST)$$NL$
	$NL$
	const ID tmax_tcp_cepid = (TMIN_TCP_CEPID + TNUM_TCP_CEPID - 1);$NL$
	$NL$
	T_TCP6_CEP tcp_cep[TNUM_TCP_CEPID] = {$NL$
	$FOREACH id TCP6_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$$TCP6_CEP.TCP6_CEPATR[id]$,$NL$
			$TAB$$TAB$(void*)$TCP6_CEP.SBUF[id]$,$NL$
			$TAB$$TAB$$TCP6_CEP.SBUFSZ[id]$,$NL$
			$TAB$$TAB$(void*)$TCP6_CEP.RBUF[id]$,$NL$
			$TAB$$TAB$$TCP6_CEP.RBUFSZ[id]$,$NL$
			$TAB$$TAB$(t_tcp_callback)(FP)$TCP6_CEP.CALLBACK[id]$,$NL$
			$TAB$$TAB$TCP_CEP_FLG_VALID,$NL$
			$TAB$$TAB$SEM_TCP_CEP_LOCK$+id$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_EST$+id$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_SND$+id$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_RCV$+id$,$NL$
			$TAB$$TAB$},$NL$
	$END$
	$FOREACH id VRID_TCP6_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB$(void*)NULL,$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB$(void*)NULL,$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB$(t_tcp_callback)(FP)NULL,$NL$
			$TAB$$TAB$TCP_CEP_FLG_DYNAMIC,$NL$
			$TAB$$TAB$SEM_TCP_CEP_LOCK$+id + LENGTH(TCP6_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_EST$+id + LENGTH(TCP6_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_SND$+id + LENGTH(TCP6_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$FLG_TCP_CEP_RCV$+id + LENGTH(TCP6_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$},$NL$
	$END$
		$TAB$};$NL$
$END$

$	// UDP (IPv4) �̿�ü��
$IF LENGTH(UDP4_CEP.ID_LIST) + LENGTH(VRID_UDP4_CEP.ID_LIST)$
	$NL$
	#define TNUM_UDP_CEPID	$LENGTH(UDP4_CEP.ID_LIST) + LENGTH(VRID_UDP4_CEP.ID_LIST)$$NL$
	$NL$
	const ID tmax_udp_cepid = (TMIN_UDP_CEPID + TNUM_UDP_CEPID - 1);$NL$
	$NL$
	T_UDP4_CEP udp_cep[TNUM_UDP_CEPID] = {$NL$
	$FOREACH id UDP4_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$$UDP4_CEP.UDP4_CEPATR[id]$,$NL$
			$TAB$$TAB${ $UDP4_CEP.IPV4ADDR[id]$, $UDP4_CEP.PORTNO[id]$ },$NL$
			$TAB$$TAB$(t_udp_callback)(FP)$UDP4_CEP.CALLBACK[id]$,$NL$
			$TAB$$TAB$UDP_CEP_FLG_VALID,$NL$
			$TAB$$TAB$SEM_UDP_CEP_LOCK$+id$,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$DTQ_UDP_RCVQ$+id$,$NL$
			$TAB$$TAB$},$NL$
	$END$
	$FOREACH id VRID_UDP4_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB${ IPV4_ADDRANY, UDP_PORTANY },$NL$
			$TAB$$TAB$(t_udp_callback)(FP)NULL,$NL$
			$TAB$$TAB$UDP_CEP_FLG_DYNAMIC,$NL$
			$TAB$$TAB$SEM_UDP_CEP_LOCK$+id + LENGTH(UDP4_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$DTQ_UDP_RCVQ$+id + LENGTH(UDP4_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$},$NL$
	$END$
		$TAB$};$NL$
$END$

$	// UDP (IPv6) �̿�ü��
$IF LENGTH(UDP6_CEP.ID_LIST) + LENGTH(VRID_UDP6_CEP.ID_LIST)$
	$NL$
	#define TNUM_UDP_CEPID	$LENGTH(UDP6_CEP.ID_LIST) + LENGTH(VRID_UDP6_CEP.ID_LIST)$$NL$
	$NL$
	const ID tmax_udp_cepid = (TMIN_UDP_CEPID + TNUM_UDP_CEPID - 1);$NL$
	$NL$
	T_UDP6_CEP udp_cep[TNUM_UDP_CEPID] = {$NL$
	$FOREACH id UDP6_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$$UDP6_CEP.UDP6_CEPATR[id]$,$NL$
			$TAB$$TAB${ $UDP6_CEP.IPV6ADDR[id]$, $UDP6_CEP.PORTNO[id]$ },$NL$
			$TAB$$TAB$(t_udp_callback)(FP)$UDP6_CEP.CALLBACK[id]$,$NL$
			$TAB$$TAB$UDP_CEP_FLG_VALID,$NL$
			$TAB$$TAB$SEM_UDP_CEP_LOCK$+id$,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$DTQ_UDP_RCVQ$+id$,$NL$
			$TAB$$TAB$},$NL$
	$END$
	$FOREACH id VRID_UDP6_CEP.ID_LIST$
		$TAB${$NL$
			$TAB$$TAB$0,$NL$
			$TAB$$TAB${ IPV6_ADDRANY, UDP_PORTANY },$NL$
			$TAB$$TAB$(t_udp_callback)(FP)NULL,$NL$
			$TAB$$TAB$UDP_CEP_FLG_DYNAMIC,$NL$
			$TAB$$TAB$SEM_UDP_CEP_LOCK$+id + LENGTH(UDP6_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$TA_NULL,$NL$
			$TAB$$TAB$DTQ_UDP_RCVQ$+id + LENGTH(UDP6_CEP.ID_LIST)$,$NL$
			$TAB$$TAB$},$NL$
	$END$
		$TAB$};$NL$
$END$

$ =====================================================================
$ tinet_kern.cfg ������
$ =====================================================================

$FILE "tinet_kern.cfg"$
/* tinet_kern.cfg */$NL$

$	// TCP (IPv4) ���ո�
$IF LENGTH(TCP4_REP.ID_LIST) + LENGTH(VRID_TCP4_REP.ID_LIST)$
	$NL$
	#if defined(TCP_CFG_EXTENTIONS)$NL$
	$FOREACH id TCP4_REP.ID_LIST$
		CRE_SEM(SEM_TCP_REP_LOCK$+id$, { TA_TPRI, 1, 1 });$NL$
	$END$
	$FOREACH id VRID_TCP4_REP.ID_LIST$
		CRE_SEM(SEM_TCP_REP_LOCK$+id + LENGTH(TCP4_REP.ID_LIST)$, { TA_TPRI, 1, 1 });$NL$
	$END$
	#endif$NL$
$END$

$	// TCP (IPv4) ���ո�
$IF LENGTH(TCP6_REP.ID_LIST) + LENGTH(VRID_TCP6_REP.ID_LIST)$
	$NL$
	#if defined(TCP_CFG_EXTENTIONS)$NL$
	$FOREACH id TCP6_REP.ID_LIST$
		CRE_SEM(SEM_TCP_REP_LOCK$+id$, { TA_TPRI, 1, 1 });$NL$
	$END$
	$FOREACH id VRID_TCP6_REP.ID_LIST$
		CRE_SEM(SEM_TCP_REP_LOCK$+id + LENGTH(TCP6_REP.ID_LIST)$, { TA_TPRI, 1, 1 });$NL$
	$END$
	#endif$NL$
$END$

$	// TCP (IPv4) �̿�ü��
$IF LENGTH(TCP4_CEP.ID_LIST) + LENGTH(VRID_TCP4_CEP.ID_LIST)$
	$NL$
	$FOREACH id TCP4_CEP.ID_LIST$
		$NL$
		CRE_SEM(SEM_TCP_CEP_LOCK$+id$,{ TA_TPRI, 1, 1 });$NL$
		CRE_FLG(FLG_TCP_CEP_EST$+id$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_CLOSED });$NL$
		CRE_FLG(FLG_TCP_CEP_SND$+id$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_SWBUF_READY });$NL$
		CRE_FLG(FLG_TCP_CEP_RCV$+id$,{ TA_TFIFO|TA_WSGL, 0 });$NL$
	$END$
	$FOREACH id VRID_TCP4_CEP.ID_LIST$
		$NL$
		CRE_SEM(SEM_TCP_CEP_LOCK$+id + LENGTH(TCP4_CEP.ID_LIST)$,{ TA_TPRI, 1, 1 });$NL$
		CRE_FLG(FLG_TCP_CEP_EST$+id + LENGTH(TCP4_CEP.ID_LIST)$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_CLOSED });$NL$
		CRE_FLG(FLG_TCP_CEP_SND$+id + LENGTH(TCP4_CEP.ID_LIST)$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_SWBUF_READY });$NL$
		CRE_FLG(FLG_TCP_CEP_RCV$+id + LENGTH(TCP4_CEP.ID_LIST)$,{ TA_TFIFO|TA_WSGL, 0 });$NL$
	$END$
$END$

$	// TCP (IPv6) �̿�ü��
$IF LENGTH(TCP6_CEP.ID_LIST) + LENGTH(VRID_TCP6_CEP.ID_LIST)$
	$NL$
	$FOREACH id TCP6_CEP.ID_LIST$
		$NL$
		CRE_SEM(SEM_TCP_CEP_LOCK$+id$,{ TA_TPRI, 1, 1 });$NL$
		CRE_FLG(FLG_TCP_CEP_EST$+id$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_CLOSED });$NL$
		CRE_FLG(FLG_TCP_CEP_SND$+id$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_SWBUF_READY });$NL$
		CRE_FLG(FLG_TCP_CEP_RCV$+id$,{ TA_TFIFO|TA_WSGL, 0 });$NL$
	$END$
	$FOREACH id VRID_TCP6_CEP.ID_LIST$
		$NL$
		CRE_SEM(SEM_TCP_CEP_LOCK$+id + LENGTH(TCP6_CEP.ID_LIST)$,{ TA_TPRI, 1, 1 });$NL$
		CRE_FLG(FLG_TCP_CEP_EST$+id + LENGTH(TCP6_CEP.ID_LIST)$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_CLOSED });$NL$
		CRE_FLG(FLG_TCP_CEP_SND$+id + LENGTH(TCP6_CEP.ID_LIST)$,{ TA_TFIFO|TA_WSGL, TCP_CEP_EVT_SWBUF_READY });$NL$
		CRE_FLG(FLG_TCP_CEP_RCV$+id + LENGTH(TCP6_CEP.ID_LIST)$,{ TA_TFIFO|TA_WSGL, 0 });$NL$
	$END$
$END$

$	// UDP (IPv4) �̿�ü��
$IF LENGTH(UDP4_CEP.ID_LIST) + LENGTH(VRID_UDP4_CEP.ID_LIST)$
	$NL$
	$FOREACH id UDP4_CEP.ID_LIST$
		CRE_SEM(SEM_UDP_CEP_LOCK$+id$,{ TA_TPRI, 1, 1 });$NL$
		CRE_DTQ(DTQ_UDP_RCVQ$+id$,{ TA_TFIFO, NUM_DTQ_UDP_RCVQ, NULL });$NL$
		$NL$
	$END$
	$FOREACH id VRID_UDP4_CEP.ID_LIST$
		CRE_SEM(SEM_UDP_CEP_LOCK$+id + LENGTH(UDP4_CEP.ID_LIST)$,{ TA_TPRI, 1, 1 });$NL$
		CRE_DTQ(DTQ_UDP_RCVQ$+id + LENGTH(UDP4_CEP.ID_LIST)$,{ TA_TFIFO, NUM_DTQ_UDP_RCVQ, NULL });$NL$
		$NL$
	$END$
$END$

$	// UDP (IPv6) �̿�ü��
$IF LENGTH(UDP6_CEP.ID_LIST) + LENGTH(VRID_UDP6_CEP.ID_LIST)$
	$NL$
	$FOREACH id UDP6_CEP.ID_LIST$
		CRE_SEM(SEM_UDP_CEP_LOCK$+id$,{ TA_TPRI, 1, 1 });$NL$
		CRE_DTQ(DTQ_UDP_RCVQ$+id$,{ TA_TFIFO, NUM_DTQ_UDP_RCVQ, NULL });$NL$
		$NL$
	$END$
	$FOREACH id VRID_UDP6_CEP.ID_LIST$
		CRE_SEM(SEM_UDP_CEP_LOCK$+id + LENGTH(UDP6_CEP.ID_LIST)$,{ TA_TPRI, 1, 1 });$NL$
		CRE_DTQ(DTQ_UDP_RCVQ$+id + LENGTH(UDP6_CEP.ID_LIST)$,{ TA_TFIFO, NUM_DTQ_UDP_RCVQ, NULL });$NL$
		$NL$
	$END$
$END$
