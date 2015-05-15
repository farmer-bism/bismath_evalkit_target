/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2010 by Witz Corporation, JAPAN
 * 
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 */

/*
 *		プロセッサ依存モジュール（RX63n用）
 */

#include "kernel_impl.h"


/*
 *  割込み要因プライオリティレジスタアドレステーブル
 */
volatile uint8_t * const ipr_reg_addr[ INHNO_MAX ] = {
	NULL, NULL, NULL, NULL, NULL,	/* No.0 - 4   予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.5 - 9   予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.10 - 14 予約 */
	NULL,							/* No.15  予約 */
	ICU_IPR00_ADDR,					/* No.16   バスエラー BUSERR  */
	NULL, NULL, NULL, NULL,			/* No.17 - 20 予約 */
	ICU_IPR01_ADDR,					/* No.21   FCU FIFERR  */
	NULL,							/* No.22  予約 */
	ICU_IPR02_ADDR,					/* No.23   FCU FRDYI  */
	NULL, NULL, NULL,		        /* No.24 -26  予約 */
	ICU_IPR03_ADDR,                 /* No.27  ICU SWINT  */
	ICU_IPR04_ADDR,					/* No.28   CMTユニット0 CMT0  */
	ICU_IPR05_ADDR,					/* No.29   CMTユニット0 CMT1  */
	ICU_IPR06_ADDR,					/* No.30   CMTユニット1 CMT2  */
	ICU_IPR07_ADDR,					/* No.31   CMTユニット1 CMT3  */
	ICU_IPR20_ADDR,                 /* No.32   Ether EINT  */
	ICU_IPR21_ADDR,                 /* No.33   USB D0FIFO0  */
	ICU_IPR22_ADDR,                 /* No.34   USB D1FIFO0  */
	ICU_IPR23_ADDR,                 /* No.35   USB USBI0  */
	ICU_IPR24_ADDR,                 /* No.36   USB D0FIFO1  */
	ICU_IPR25_ADDR,                 /* No.37   USB D1FIFO1  */
	ICU_IPR26_ADDR,                 /* No.38   USB USBI1  */
	ICU_IPR27_ADDR,                 /* No.39   RSPI0 SPRI0  */
	ICU_IPR27_ADDR,                 /* No.40   RSPI0 SPTI0  */
	ICU_IPR27_ADDR,                 /* No.41   RSPI0 SPII0  */
	ICU_IPR2A_ADDR,                 /* No.42   RSPI1 SPRI0  */
	ICU_IPR2A_ADDR,                 /* No.43   RSPI1 SPTI0  */
	ICU_IPR2A_ADDR,                 /* No.44   RSPI1 SPII0  */
	ICU_IPR2D_ADDR,                 /* No.45   RSPI1 SPRI0  */
	ICU_IPR2D_ADDR,                 /* No.46   RSPI1 SPTI0  */
	ICU_IPR2D_ADDR,                 /* No.47   RSPI1 SPII0  */
	ICU_IPR30_ADDR,                 /* NO.48  CAN0 RXF0*/
	ICU_IPR30_ADDR,                 /* NO.49  CAN0 TXF0*/
	ICU_IPR30_ADDR,                 /* NO.50  CAN0 RXM0*/
	ICU_IPR30_ADDR,                 /* NO.51  CAN0 TXM0*/
	ICU_IPR34_ADDR,                 /* NO.52  CAN1 RXF1*/
	ICU_IPR34_ADDR,                 /* NO.53  CAN1 TXF1*/
	ICU_IPR34_ADDR,                 /* NO.54  CAN1 RXM1*/
	ICU_IPR34_ADDR,                 /* NO.55  CAN1 TXM1*/
	ICU_IPR38_ADDR,                 /* NO.56  CAN2 RXF2*/
	ICU_IPR38_ADDR,                 /* NO.57  CAN2 TXF2*/
	ICU_IPR38_ADDR,                 /* NO.58  CAN2 RXM2*/
	ICU_IPR38_ADDR,                 /* NO.59  CAN2 TXM2*/
	NULL, NULL,                     /* No.60 - 61 予約 */
	ICU_IPR3E_ADDR,                 /* NO 62 RTC CUP */
	NULL,						    /* No.63 予約 */
	ICU_IPR40_ADDR,					/* No.64   外部端子 IRQ0  */
	ICU_IPR41_ADDR,					/* No.65   外部端子 IRQ1  */
	ICU_IPR42_ADDR,					/* No.66   外部端子 IRQ2  */
	ICU_IPR43_ADDR,					/* No.67   外部端子 IRQ3  */
	ICU_IPR44_ADDR,					/* No.68   外部端子 IRQ4  */
	ICU_IPR45_ADDR,					/* No.69   外部端子 IRQ5  */
	ICU_IPR46_ADDR,					/* No.70   外部端子 IRQ6  */
	ICU_IPR47_ADDR,					/* No.71   外部端子 IRQ7  */
	ICU_IPR48_ADDR,					/* No.72   外部端子 IRQ8  */
	ICU_IPR49_ADDR,					/* No.73   外部端子 IRQ9  */
	ICU_IPR4A_ADDR,					/* No.74   外部端子 IRQ10  */
	ICU_IPR4B_ADDR,					/* No.75   外部端子 IRQ11  */
	ICU_IPR4C_ADDR,					/* No.76   外部端子 IRQ12  */
	ICU_IPR4D_ADDR,					/* No.77   外部端子 IRQ13  */
	ICU_IPR4E_ADDR,					/* No.78   外部端子 IRQ14  */
	ICU_IPR4F_ADDR,					/* No.79   外部端子 IRQ15  */
	NULL, NULL, NULL, NULL, NULL,	/* No.80 - 84 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.85 - 89 予約 */
    ICU_IPR5A_ADDR,                 /* No.90  USB USBR0  */
	ICU_IPR5B_ADDR,                 /* No.91  USB USBR1  */
	ICU_IPR5C_ADDR,                 /* No.92  RTC ALM  */
	ICU_IPR5D_ADDR,                 /* No.93  RTC PRD  */
	NULL, NULL, NULL, NULL,         /* No.94 - 97  予約 */
	ICU_IPR62_ADDR,					/* No.98   AD0 ADI0  */
    NULL, NULL, NULL,               /* No.99 - 101 予約 */
	ICU_IPR66_ADDR,					/* No.102  S12AD S12ADI0  */
	NULL, NULL, NULL,               /* No.103 - 105 予約 */
	ICU_IPR6A_ADDR,					/* No.106  ICU GROUP0  */
	ICU_IPR6B_ADDR,					/* No.107  ICU GROUP1  */
	ICU_IPR6C_ADDR,					/* No.108  ICU GROUP2  */
	ICU_IPR6D_ADDR,					/* No.109  ICU GROUP3  */
	ICU_IPR6E_ADDR,					/* No.110  ICU GROUP4  */
	ICU_IPR6F_ADDR,					/* No.111  ICU GROUP5  */
	ICU_IPR70_ADDR,					/* No.112  ICU GROUP6  */
	NULL,                           /* No.113 予約 */
	ICU_IPR72_ADDR,                 /* No.114  ICU Group12  */
	NULL, NULL, NULL, NULL, NULL,   /* No.115 - 119 予約 */
	NULL, NULL,                     /* No.120 - 121 予約 */
	ICU_IPR7A_ADDR,                 /* No.122  SCI12 SCIX0  */
	ICU_IPR7A_ADDR,                 /* No.123  SCI12 SCIX1  */
	ICU_IPR7A_ADDR,                 /* No.124  SCI12 SCIX2  */
	ICU_IPR7A_ADDR,                 /* No.125  SCI12 SCIX3  */
	ICU_IPR7E_ADDR,                 /* No.126  TPU0 TGI0A  */
	ICU_IPR7E_ADDR,                 /* No.127  TPU0 TGI0B  */
	ICU_IPR7E_ADDR,                 /* No.128  TPU0 TGI0C  */
	ICU_IPR7E_ADDR,                 /* No.129  TPU0 TGI0D  */
	ICU_IPR82_ADDR,                 /* No.130  TPU1 TGI1A  */
	ICU_IPR82_ADDR,                 /* No.131  TPU1 TGI1B  */
    ICU_IPR84_ADDR,                 /* No.132  TPU2 TGI2A  */
    ICU_IPR84_ADDR,                 /* No.133  TPU2 TGI2B  */
    ICU_IPR86_ADDR,                 /* No.134  TPU3 TGI3A  */
    ICU_IPR86_ADDR,                 /* No.135  TPU3 TGI3B  */
    ICU_IPR86_ADDR,                 /* No.136  TPU3 TGI3C  */
    ICU_IPR86_ADDR,                 /* No.137  TPU3 TGI3D  */
    ICU_IPR8A_ADDR,                 /* No.138  TPU4 TGI4A  */
    ICU_IPR8A_ADDR,                 /* No.139  TPU4 TGI4B  */
    ICU_IPR8C_ADDR,                 /* No.140  TPU5 TGI5A  */
    ICU_IPR8C_ADDR,                 /* No.141  TPU5 TGI5B  */
    ICU_IPR8E_ADDR,                 /* No.142  TPU6 TGI6A, MTU0 TGIA0  */
    ICU_IPR8E_ADDR,                 /* No.143  TPU6 TGI6B, MTU0 TGIB0  */
    ICU_IPR8E_ADDR,                 /* No.144  TPU6 TGI6C, MTU0 TGIC0  */
    ICU_IPR8E_ADDR,                 /* No.145  TPU6 TGI6D, MTU0 TGID0  */
    ICU_IPR92_ADDR,                 /* No.146  MTU0 TGIE0  */
    ICU_IPR92_ADDR,                 /* No.147  MTU0 TGIF0  */
    ICU_IPR94_ADDR,                 /* No.148  TPU7 TGI7A, MTU1 TGIA1  */
    ICU_IPR94_ADDR,                 /* No.149  TPU7 TGI7B, MTU1 TGIB1  */
    ICU_IPR96_ADDR,                 /* No.150  TPU8 TGI8A, MTU2 TGIA2  */
    ICU_IPR96_ADDR,                 /* No.151  TPU8 TGI8B, MTU2 TGIB2  */
    ICU_IPR98_ADDR,                 /* No.152  TPU9 TGI9A, MTU3 TGIA3  */
    ICU_IPR98_ADDR,                 /* No.153  TPU9 TGI9B, MTU3 TGIB3  */
    ICU_IPR98_ADDR,                 /* No.154  TPU9 TGI9C, MTU3 TGIC3  */
    ICU_IPR98_ADDR,                 /* No.155  TPU9 TGI9D, MTU3 TGID3  */
    ICU_IPR9C_ADDR,                 /* No.156  TPU10 TGI10A, MTU4 TGIA4  */
    ICU_IPR9C_ADDR,                 /* No.157  TPU10 TGI10B, MTU4 TGIB4  */
    ICU_IPR9C_ADDR,                 /* No.158  MTU4 TGIC4  */
    ICU_IPR9C_ADDR,                 /* No.159  MTU4 TGID4  */
    ICU_IPRA0_ADDR,                 /* No.160  MTU4 TGIV4  */
    ICU_IPRA1_ADDR,                 /* No.161  MTU5 TGIU5  */
    ICU_IPRA1_ADDR,                 /* No.162  MTU5 TGIV5  */
    ICU_IPRA1_ADDR,                 /* No.163  MTU5 TGIW5  */
    ICU_IPRA4_ADDR,                 /* No.164  TPU11 TGI11A  */
    ICU_IPRA4_ADDR,                 /* No.165  TPU11 TGI11B  */
    ICU_IPRA6_ADDR,                 /* No.166  POE OEI1  */
    ICU_IPRA6_ADDR,                 /* No.167  POE OEI2  */
	NULL, NULL,                     /* No.168 - 169 予約 */
    ICU_IPRAA_ADDR,                 /* No.170  TMR0 CMIA0  */
    ICU_IPRAA_ADDR,                 /* No.171  TMR0 CMIB0  */
    ICU_IPRAA_ADDR,                 /* No.172  TMR0 OVI0  */
    ICU_IPRAD_ADDR,                 /* No.173  TMR1 CMIA1  */
    ICU_IPRAD_ADDR,                 /* No.174  TMR1 CMIB1  */
    ICU_IPRAD_ADDR,                 /* No.175  TMR1 OVI1  */
    ICU_IPRB0_ADDR,                 /* No.176  TMR2 CMIA2  */
    ICU_IPRB0_ADDR,                 /* No.177  TMR2 CMIB2  */
    ICU_IPRB0_ADDR,                 /* No.178  TMR2 OVI2  */
    ICU_IPRB3_ADDR,                 /* No.179  TMR3 CMIA3  */
    ICU_IPRB3_ADDR,                 /* No.180  TMR3 CMIB3  */
    ICU_IPRB3_ADDR,                 /* No.181  TMR3 OVI3  */
    ICU_IPRB6_ADDR,                 /* No.182  RIIC0 EEI0  */
    ICU_IPRB7_ADDR,                 /* No.183  RIIC0 RXI0  */
    ICU_IPRB8_ADDR,                 /* No.184  RIIC0 TXI0  */
    ICU_IPRB9_ADDR,                 /* No.185  RIIC0 TEI0  */
    ICU_IPRBA_ADDR,                 /* No.186  RIIC1 EEI1  */
    ICU_IPRBB_ADDR,                 /* No.187  RIIC1 RXI1  */
    ICU_IPRBC_ADDR,                 /* No.188  RIIC1 TXI1  */
    ICU_IPRBD_ADDR,                 /* No.189  RIIC1 TEI1  */
    ICU_IPRBE_ADDR,                 /* No.190  RIIC2 EEI2  */
    ICU_IPRBF_ADDR,                 /* No.191  RIIC2 RXI2  */
    ICU_IPRC0_ADDR,                 /* No.192  RIIC2 TXI2  */
    ICU_IPRC1_ADDR,                 /* No.193  RIIC2 TEI2  */
    ICU_IPRC2_ADDR,                 /* No.194  RIIC3 EEI3  */
    ICU_IPRC3_ADDR,                 /* No.195  RIIC3 RXI3  */
    ICU_IPRC4_ADDR,                 /* No.196  RIIC3 TXI3  */
    ICU_IPRC5_ADDR,                 /* No.197  RIIC3 TEI3  */
    ICU_IPRC6_ADDR,                 /* No.198  DMAC DMAC0I  */
    ICU_IPRC7_ADDR,                 /* No.199  DMAC DMAC1I  */
    ICU_IPRC8_ADDR,                 /* No.200  DMAC DMAC2I  */
    ICU_IPRC9_ADDR,                 /* No.201  DMAC DMAC3I  */
    ICU_IPRCA_ADDR,                 /* No.202  EXDMAC EXDMAC0I  */
    ICU_IPRCB_ADDR,                 /* No.203  EXDMAC EXDMAC1I  */
	NULL, NULL,                     /* No.204 - 205 予約 */
    ICU_IPRCE_ADDR,                 /* No.206  DEU DEU0  */
    ICU_IPRCF_ADDR,                 /* No.207  DEU DEU0  */
    ICU_IPRD0_ADDR,                 /* No.208  PDC PCDFI  */
    ICU_IPRD1_ADDR,                 /* No.209  PDC PCFEI  */
    ICU_IPRD2_ADDR,                 /* No.210  PDC PCERI  */
	NULL, NULL, NULL,               /* No.211 - 213 予約 */
    ICU_IPRD6_ADDR,                 /* No.214  SCI0 RXI0  */
    ICU_IPRD6_ADDR,                 /* No.215  SCI0 TXI0  */
    ICU_IPRD6_ADDR,                 /* No.216  SCI0 TEI0  */
    ICU_IPRD9_ADDR,                 /* No.217  SCI1 RXI1  */
    ICU_IPRD9_ADDR,                 /* No.218  SCI1 TXI1  */
    ICU_IPRD9_ADDR,                 /* No.219  SCI1 TEI1  */
    ICU_IPRDC_ADDR,                 /* No.220  SCI2 RXI2  */
    ICU_IPRDC_ADDR,                 /* No.221  SCI2 TXI2  */
    ICU_IPRDC_ADDR,                 /* No.222  SCI2 TEI2  */
    ICU_IPRDF_ADDR,                 /* No.223  SCI3 RXI3  */
    ICU_IPRDF_ADDR,                 /* No.224  SCI3 TXI3  */
    ICU_IPRDF_ADDR,                 /* No.225  SCI3 TEI3  */
    ICU_IPRE2_ADDR,                 /* No.226  SCI4 RXI4  */
    ICU_IPRE2_ADDR,                 /* No.227  SCI4 TXI4  */
    ICU_IPRE2_ADDR,                 /* No.228  SCI4 TEI4  */
    ICU_IPRE5_ADDR,                 /* No.229  SCI5 RXI5  */
    ICU_IPRE5_ADDR,                 /* No.230  SCI5 TXI5  */
    ICU_IPRE5_ADDR,                 /* No.231  SCI5 TEI5  */
    ICU_IPRE8_ADDR,                 /* No.232  SCI6 RXI6  */
    ICU_IPRE8_ADDR,                 /* No.233  SCI6 TXI6  */
    ICU_IPRE8_ADDR,                 /* No.234  SCI6 TEI6  */
    ICU_IPREB_ADDR,                 /* No.235  SCI7 RXI7  */
    ICU_IPREB_ADDR,                 /* No.236  SCI7 TXI7  */
    ICU_IPREB_ADDR,                 /* No.237  SCI7 TEI7  */
    ICU_IPREE_ADDR,                 /* No.238  SCI8 RXI8  */
    ICU_IPREE_ADDR,                 /* No.239  SCI8 TXI8  */
    ICU_IPREE_ADDR,                 /* No.240  SCI8 TEI8  */
    ICU_IPRF1_ADDR,                 /* No.241  SCI9 RXI9  */
    ICU_IPRF1_ADDR,                 /* No.242  SCI9 TXI9  */
    ICU_IPRF1_ADDR,                 /* No.243  SCI9 TEI9  */
    ICU_IPRF4_ADDR,                 /* No.244  SCI10 RXI10  */
    ICU_IPRF4_ADDR,                 /* No.245  SCI10 TXI10  */
    ICU_IPRF4_ADDR,                 /* No.246  SCI10 TEI10  */
    ICU_IPRF7_ADDR,                 /* No.247  SCI11 RXI11  */
    ICU_IPRF7_ADDR,                 /* No.248  SCI11 TXI11  */
    ICU_IPRF7_ADDR,                 /* No.249  SCI11 TEI11  */
    ICU_IPRFA_ADDR,                 /* No.250  SCI12 RXI12  */
    ICU_IPRFA_ADDR,                 /* No.251  SCI12 TXI12  */
    ICU_IPRFA_ADDR,                 /* No.252  SCI12 TEI12  */
    ICU_IPRFD_ADDR,                 /* No.253  IEB IEBINT  */
	NULL, NULL,						/* No.254 - 255 予約 */
};


/*
 *  割込み要求許可レジスタアドレステーブル
 */
const IER_INFO ier_reg_addr[ INHNO_MAX ] = {
	{ NULL, INVALID_OFFSET },			/* No.0   予約 */
	{ NULL, INVALID_OFFSET },			/* No.1   予約 */
	{ NULL, INVALID_OFFSET },			/* No.2   予約 */
	{ NULL, INVALID_OFFSET },			/* No.3   予約 */
	{ NULL, INVALID_OFFSET },			/* No.4   予約 */
	{ NULL, INVALID_OFFSET },			/* No.5   予約 */
	{ NULL, INVALID_OFFSET },			/* No.6   予約 */
	{ NULL, INVALID_OFFSET },			/* No.7   予約 */
	{ NULL, INVALID_OFFSET },			/* No.8   予約 */
	{ NULL, INVALID_OFFSET },			/* No.9   予約 */
	{ NULL, INVALID_OFFSET },			/* No.10  予約 */
	{ NULL, INVALID_OFFSET },			/* No.11  予約 */
	{ NULL, INVALID_OFFSET },			/* No.12  予約 */
	{ NULL, INVALID_OFFSET },			/* No.13  予約 */
	{ NULL, INVALID_OFFSET },			/* No.14  予約 */
	{ NULL, INVALID_OFFSET },			/* No.15  予約 */
	{ ICU_IER02_ADDR, ICU_IEN0_BIT },	/* No.16   バスエラー BUSERR  */
	{ NULL, INVALID_OFFSET },			/* No.17  予約 */
	{ NULL, INVALID_OFFSET },			/* No.18  予約 */
	{ NULL, INVALID_OFFSET },			/* No.19  予約 */
	{ NULL, INVALID_OFFSET },			/* No.20  予約 */
	{ ICU_IER02_ADDR, ICU_IEN5_BIT },	/* No.21   FCU FIFERR  */
	{ NULL, INVALID_OFFSET },			/* No.22  予約 */
	{ ICU_IER02_ADDR, ICU_IEN7_BIT },	/* No.23   FCU FRDYI  */
	{ NULL, INVALID_OFFSET },			/* No.24  予約 */
	{ NULL, INVALID_OFFSET },			/* No.25  予約 */
	{ NULL, INVALID_OFFSET },			/* No.26  予約 */
	{ ICU_IER03_ADDR, ICU_IEN3_BIT },	/* No.27  ICU SWINT  */
	{ ICU_IER03_ADDR, ICU_IEN4_BIT },	/* No.28   CMTユニット0 CMT0  */
	{ ICU_IER03_ADDR, ICU_IEN5_BIT },	/* No.29   CMTユニット0 CMT1  */
	{ ICU_IER03_ADDR, ICU_IEN6_BIT },	/* No.30   CMTユニット1 CMT2  */
	{ ICU_IER03_ADDR, ICU_IEN7_BIT },	/* No.31   CMTユニット1 CMT3  */
	{ ICU_IER04_ADDR, ICU_IEN0_BIT },	/* No.32   Ether EINT  */
	{ ICU_IER04_ADDR, ICU_IEN1_BIT },	/* No.33   USB D0FIFO0  */
	{ ICU_IER04_ADDR, ICU_IEN2_BIT },	/* No.34   USB D1FIFO0  */
	{ ICU_IER04_ADDR, ICU_IEN3_BIT },	/* No.35   USB USBI0  */
	{ ICU_IER04_ADDR, ICU_IEN4_BIT },	/* No.36   USB D0FIFO1  */
	{ ICU_IER04_ADDR, ICU_IEN5_BIT },	/* No.37   USB D1FIFO1  */
	{ ICU_IER04_ADDR, ICU_IEN6_BIT },	/* No.38   USB USBI1  */
	{ ICU_IER04_ADDR, ICU_IEN7_BIT },	/* No.39   RSPI0 SPRI0  */
	{ ICU_IER05_ADDR, ICU_IEN0_BIT },	/* No.40   RSPI0 SPTI0  */
	{ ICU_IER05_ADDR, ICU_IEN1_BIT },	/* No.41   RSPI0 SPII0  */
	{ ICU_IER05_ADDR, ICU_IEN2_BIT },	/* No.42   RSPI1 SPRI0  */
	{ ICU_IER05_ADDR, ICU_IEN3_BIT },	/* No.43   RSPI1 SPTI0  */
	{ ICU_IER05_ADDR, ICU_IEN4_BIT },	/* No.44   RSPI1 SPII0  */
	{ ICU_IER05_ADDR, ICU_IEN5_BIT },	/* No.45   RSPI1 SPRI0  */
	{ ICU_IER05_ADDR, ICU_IEN6_BIT },	/* No.46   RSPI1 SPTI0  */
	{ ICU_IER05_ADDR, ICU_IEN7_BIT },	/* No.47   RSPI1 SPII0  */
	{ ICU_IER06_ADDR, ICU_IEN0_BIT },	/* No.48  予約 */
	{ ICU_IER06_ADDR, ICU_IEN1_BIT },	/* No.49  予約 */
	{ ICU_IER06_ADDR, ICU_IEN2_BIT },	/* No.50  予約 */
	{ ICU_IER06_ADDR, ICU_IEN3_BIT },	/* No.51  予約 */
	{ ICU_IER06_ADDR, ICU_IEN4_BIT },	/* No.52  予約 */
	{ ICU_IER06_ADDR, ICU_IEN5_BIT },	/* No.53  予約 */
	{ ICU_IER06_ADDR, ICU_IEN6_BIT },	/* No.54  予約 */
	{ ICU_IER06_ADDR, ICU_IEN7_BIT},	/* No.55  予約 */
	{ ICU_IER07_ADDR, ICU_IEN0_BIT},	/* No.56  予約 */
	{ ICU_IER07_ADDR, ICU_IEN1_BIT},	/* No.57  予約 */
	{ ICU_IER07_ADDR, ICU_IEN2_BIT },	/* No.58  予約 */
	{ ICU_IER07_ADDR, ICU_IEN3_BIT },	/* No.59  予約 */
	{ NULL, INVALID_OFFSET },			/* No.60  予約 */
	{ NULL, INVALID_OFFSET },			/* No.61  予約 */
	{ ICU_IER07_ADDR, ICU_IEN6_BIT },	/* No.62  RTC CUP */
	{ NULL, INVALID_OFFSET },			/* No.63  予約 */
	{ ICU_IER08_ADDR, ICU_IEN0_BIT },	/* No.64   外部端子 IRQ0  */
	{ ICU_IER08_ADDR, ICU_IEN1_BIT },	/* No.65   外部端子 IRQ1  */
	{ ICU_IER08_ADDR, ICU_IEN2_BIT },	/* No.66   外部端子 IRQ2  */
	{ ICU_IER08_ADDR, ICU_IEN3_BIT },	/* No.67   外部端子 IRQ3  */
	{ ICU_IER08_ADDR, ICU_IEN4_BIT },	/* No.68   外部端子 IRQ4  */
	{ ICU_IER08_ADDR, ICU_IEN5_BIT },	/* No.69   外部端子 IRQ5  */
	{ ICU_IER08_ADDR, ICU_IEN6_BIT },	/* No.70   外部端子 IRQ6  */
	{ ICU_IER08_ADDR, ICU_IEN7_BIT },	/* No.71   外部端子 IRQ7  */
	{ ICU_IER09_ADDR, ICU_IEN0_BIT },	/* No.72   外部端子 IRQ8  */
	{ ICU_IER09_ADDR, ICU_IEN1_BIT },	/* No.73   外部端子 IRQ9  */
	{ ICU_IER09_ADDR, ICU_IEN2_BIT },	/* No.74   外部端子 IRQ10  */
	{ ICU_IER09_ADDR, ICU_IEN3_BIT },	/* No.75   外部端子 IRQ11  */
	{ ICU_IER09_ADDR, ICU_IEN4_BIT },	/* No.76   外部端子 IRQ12  */
	{ ICU_IER09_ADDR, ICU_IEN5_BIT },	/* No.77   外部端子 IRQ13  */
	{ ICU_IER09_ADDR, ICU_IEN6_BIT },	/* No.78   外部端子 IRQ14  */
	{ ICU_IER09_ADDR, ICU_IEN7_BIT },	/* No.79   外部端子 IRQ15  */
	{ NULL, INVALID_OFFSET },			/* No.80  予約 */
	{ NULL, INVALID_OFFSET },			/* No.81  予約 */
	{ NULL, INVALID_OFFSET },			/* No.82  予約 */
	{ NULL, INVALID_OFFSET },			/* No.83  予約 */
	{ NULL, INVALID_OFFSET },			/* No.84  予約 */
	{ NULL, INVALID_OFFSET },			/* No.85  予約 */
	{ NULL, INVALID_OFFSET },			/* No.86  予約 */
	{ NULL, INVALID_OFFSET },			/* No.87  予約 */
	{ NULL, INVALID_OFFSET },			/* No.88  予約 */
	{ NULL, INVALID_OFFSET },			/* No.89  予約 */
	{ ICU_IER0B_ADDR, ICU_IEN2_BIT },	/* No.90  USB USBR0  */
	{ ICU_IER0B_ADDR, ICU_IEN3_BIT },	/* No.91  USB USBR1  */
	{ ICU_IER0B_ADDR, ICU_IEN4_BIT },	/* No.92  RTC ALM  */
	{ ICU_IER0B_ADDR, ICU_IEN5_BIT },	/* No.93  RTC PRD  */
	{ NULL, INVALID_OFFSET },			/* No.94  予約 */
	{ NULL, INVALID_OFFSET },			/* No.95  予約 */
	{ NULL, INVALID_OFFSET },			/* No.96  予約 */
	{ NULL, INVALID_OFFSET },			/* No.97  予約 */
	{ ICU_IER0C_ADDR, ICU_IEN2_BIT },	/* No.98   AD0 ADI0  */
	{ NULL, INVALID_OFFSET },			/* No.99   予約 */
	{ NULL, INVALID_OFFSET },			/* No.100  予約 */
	{ NULL, INVALID_OFFSET },			/* No.101  予約 */
	{ ICU_IER0C_ADDR, ICU_IEN6_BIT },	/* No.102  S12AD S12ADI0  */
	{ NULL, INVALID_OFFSET },			/* No.103  予約 */
	{ NULL, INVALID_OFFSET },			/* No.104  予約 */
	{ NULL, INVALID_OFFSET },			/* No.105  予約 */
	{ ICU_IER0D_ADDR, ICU_IEN2_BIT },	/* No.106  ICU GROUP0  */
	{ ICU_IER0D_ADDR, ICU_IEN3_BIT },	/* No.107  ICU GROUP1  */
	{ ICU_IER0D_ADDR, ICU_IEN4_BIT },	/* No.108  ICU GROUP2  */
	{ ICU_IER0D_ADDR, ICU_IEN5_BIT },	/* No.109  ICU GROUP3  */
	{ ICU_IER0D_ADDR, ICU_IEN6_BIT },	/* No.110  ICU GROUP4  */
	{ ICU_IER0D_ADDR, ICU_IEN7_BIT },	/* No.111  ICU GROUP5  */
	{ ICU_IER0E_ADDR, ICU_IEN0_BIT },	/* No.112  ICU GROUP6  */
	{ NULL, INVALID_OFFSET },			/* No.113  予約 */
	{ ICU_IER0E_ADDR, ICU_IEN2_BIT },	/* No.114  ICU Group12  */
	{ NULL, INVALID_OFFSET },			/* No.115  予約 */
	{ NULL, INVALID_OFFSET },			/* No.116  予約 */
	{ NULL, INVALID_OFFSET },			/* No.117  予約 */
	{ NULL, INVALID_OFFSET },			/* No.118  予約 */
	{ NULL, INVALID_OFFSET },			/* No.119  予約 */
	{ NULL, INVALID_OFFSET },			/* No.120  予約 */
	{ NULL, INVALID_OFFSET },			/* No.121  予約 */
	{ ICU_IER0F_ADDR, ICU_IEN2_BIT },	/* No.122  SCI12 SCIX0  */
	{ ICU_IER0F_ADDR, ICU_IEN3_BIT },	/* No.123  SCI12 SCIX1  */
	{ ICU_IER0F_ADDR, ICU_IEN4_BIT },	/* No.124  SCI12 SCIX2  */
	{ ICU_IER0F_ADDR, ICU_IEN5_BIT },	/* No.125  SCI12 SCIX3  */
	{ ICU_IER0F_ADDR, ICU_IEN6_BIT },	/* No.126  TPU0 TGI0A  */
	{ ICU_IER0F_ADDR, ICU_IEN7_BIT },	/* No.127  TPU0 TGI0B  */
	{ ICU_IER10_ADDR, ICU_IEN0_BIT },	/* No.128  TPU0 TGI0C  */
	{ ICU_IER10_ADDR, ICU_IEN1_BIT },	/* No.129  TPU0 TGI0D  */
	{ ICU_IER10_ADDR, ICU_IEN2_BIT },	/* No.130  TPU1 TGI1A  */
	{ ICU_IER10_ADDR, ICU_IEN3_BIT },	/* No.131  TPU1 TGI1B  */
	{ ICU_IER10_ADDR, ICU_IEN4_BIT },	/* No.132  TPU2 TGI2A  */
	{ ICU_IER10_ADDR, ICU_IEN5_BIT },	/* No.133  TPU2 TGI2B  */
	{ ICU_IER10_ADDR, ICU_IEN6_BIT },	/* No.134  TPU3 TGI3A  */
	{ ICU_IER10_ADDR, ICU_IEN7_BIT },	/* No.135  TPU3 TGI3B  */
	{ ICU_IER11_ADDR, ICU_IEN0_BIT },	/* No.136  TPU3 TGI3C  */
	{ ICU_IER11_ADDR, ICU_IEN1_BIT },	/* No.137  TPU3 TGI3D  */
	{ ICU_IER11_ADDR, ICU_IEN2_BIT },	/* No.138  TPU4 TGI4A  */
	{ ICU_IER11_ADDR, ICU_IEN3_BIT },	/* No.139  TPU4 TGI4B  */
	{ ICU_IER11_ADDR, ICU_IEN4_BIT },	/* No.140  TPU5 TGI5A  */
	{ ICU_IER11_ADDR, ICU_IEN5_BIT },	/* No.141  TPU5 TGI5B  */
	{ ICU_IER11_ADDR, ICU_IEN6_BIT },	/* No.142  TPU6 TGI6A, MTU0 TGIA0  */
	{ ICU_IER11_ADDR, ICU_IEN7_BIT },	/* No.143  TPU6 TGI6B, MTU0 TGIB0  */
	{ ICU_IER12_ADDR, ICU_IEN0_BIT },	/* No.144  TPU6 TGI6C, MTU0 TGIC0  */
	{ ICU_IER12_ADDR, ICU_IEN1_BIT },	/* No.145  TPU6 TGI6D, MTU0 TGID0  */
	{ ICU_IER12_ADDR, ICU_IEN2_BIT },	/* No.146  MTU0 TGIE0  */
	{ ICU_IER12_ADDR, ICU_IEN3_BIT },	/* No.147  MTU0 TGIF0  */
	{ ICU_IER12_ADDR, ICU_IEN4_BIT },	/* No.148  TPU7 TGI7A, MTU1 TGIA1  */
	{ ICU_IER12_ADDR, ICU_IEN5_BIT },	/* No.149  TPU7 TGI7B, MTU1 TGIB1  */
	{ ICU_IER12_ADDR, ICU_IEN6_BIT },	/* No.150  TPU8 TGI8A, MTU2 TGIA2  */
	{ ICU_IER12_ADDR, ICU_IEN7_BIT },	/* No.151  TPU8 TGI8B, MTU2 TGIB2  */
	{ ICU_IER13_ADDR, ICU_IEN0_BIT },	/* No.152  TPU9 TGI9A, MTU3 TGIA3  */
	{ ICU_IER13_ADDR, ICU_IEN1_BIT },	/* No.153  TPU9 TGI9B, MTU3 TGIB3  */
	{ ICU_IER13_ADDR, ICU_IEN2_BIT },	/* No.154  TPU9 TGI9C, MTU3 TGIC3  */
	{ ICU_IER13_ADDR, ICU_IEN3_BIT },	/* No.155  TPU9 TGI9D, MTU3 TGID3  */
	{ ICU_IER13_ADDR, ICU_IEN4_BIT },	/* No.156  TPU10 TGI10A, MTU4 TGIA4  */
	{ ICU_IER13_ADDR, ICU_IEN5_BIT },	/* No.157  TPU10 TGI10B, MTU4 TGIB4  */
	{ ICU_IER13_ADDR, ICU_IEN6_BIT },	/* No.158  MTU4 TGIC4  */
	{ ICU_IER13_ADDR, ICU_IEN7_BIT },	/* No.159  MTU4 TGID4  */
	{ ICU_IER14_ADDR, ICU_IEN0_BIT },	/* No.160  MTU4 TGIV4  */
	{ ICU_IER14_ADDR, ICU_IEN1_BIT },	/* No.161  MTU5 TGIU5  */
	{ ICU_IER14_ADDR, ICU_IEN2_BIT },	/* No.162  MTU5 TGIV5  */
	{ ICU_IER14_ADDR, ICU_IEN3_BIT },	/* No.163  MTU5 TGIW5  */
	{ ICU_IER14_ADDR, ICU_IEN4_BIT },	/* No.164  TPU11 TGI11A  */
	{ ICU_IER14_ADDR, ICU_IEN5_BIT },	/* No.165  TPU11 TGI11B  */
	{ ICU_IER14_ADDR, ICU_IEN6_BIT },	/* No.166  POE OEI1  */
	{ ICU_IER14_ADDR, ICU_IEN7_BIT },	/* No.167  POE OEI2  */
	{ NULL, INVALID_OFFSET },			/* No.168  予約 */
	{ NULL, INVALID_OFFSET },			/* No.169  予約 */
	{ ICU_IER15_ADDR, ICU_IEN2_BIT },	/* No.170  TMR0 CMIA0  */
	{ ICU_IER15_ADDR, ICU_IEN3_BIT },	/* No.171  TMR0 CMIB0  */
	{ ICU_IER15_ADDR, ICU_IEN4_BIT },	/* No.172  TMR0 OVI0  */
	{ ICU_IER15_ADDR, ICU_IEN5_BIT },	/* No.173  TMR1 CMIA1  */
	{ ICU_IER15_ADDR, ICU_IEN6_BIT },	/* No.174  TMR1 CMIB1  */
	{ ICU_IER15_ADDR, ICU_IEN7_BIT },	/* No.175  TMR1 OVI1  */
	{ ICU_IER16_ADDR, ICU_IEN0_BIT },	/* No.176  TMR2 CMIA2  */
	{ ICU_IER16_ADDR, ICU_IEN1_BIT },	/* No.177  TMR2 CMIB2  */
	{ ICU_IER16_ADDR, ICU_IEN2_BIT },	/* No.178  TMR2 OVI2  */
	{ ICU_IER16_ADDR, ICU_IEN3_BIT },	/* No.179  TMR3 CMIA3  */
	{ ICU_IER16_ADDR, ICU_IEN4_BIT },	/* No.180  TMR3 CMIB3  */
	{ ICU_IER16_ADDR, ICU_IEN5_BIT },	/* No.181  TMR3 OVI3  */
	{ ICU_IER16_ADDR, ICU_IEN6_BIT },	/* No.182  RIIC0 EEI0  */
	{ ICU_IER16_ADDR, ICU_IEN7_BIT },	/* No.183  RIIC0 RXI0  */
	{ ICU_IER17_ADDR, ICU_IEN0_BIT },	/* No.184  RIIC0 TXI0  */
	{ ICU_IER17_ADDR, ICU_IEN1_BIT },	/* No.185  RIIC0 TEI0  */
	{ ICU_IER17_ADDR, ICU_IEN2_BIT },	/* No.186  RIIC1 EEI1  */
	{ ICU_IER17_ADDR, ICU_IEN3_BIT },	/* No.187  RIIC1 RXI1  */
	{ ICU_IER17_ADDR, ICU_IEN4_BIT },	/* No.188  RIIC1 TXI1  */
	{ ICU_IER17_ADDR, ICU_IEN5_BIT },	/* No.189  RIIC1 TEI1  */
	{ ICU_IER17_ADDR, ICU_IEN6_BIT },	/* No.190  RIIC2 EEI2  */
	{ ICU_IER17_ADDR, ICU_IEN7_BIT },	/* No.191  RIIC2 RXI2  */
	{ ICU_IER18_ADDR, ICU_IEN0_BIT },	/* No.192  RIIC2 TXI2  */
	{ ICU_IER18_ADDR, ICU_IEN1_BIT },	/* No.193  RIIC2 TEI2  */
	{ ICU_IER18_ADDR, ICU_IEN2_BIT },	/* No.194  RIIC3 EEI3  */
	{ ICU_IER18_ADDR, ICU_IEN3_BIT },	/* No.195  RIIC3 RXI3  */
	{ ICU_IER18_ADDR, ICU_IEN4_BIT },	/* No.196  RIIC3 TXI3  */
	{ ICU_IER18_ADDR, ICU_IEN5_BIT },	/* No.197  RIIC3 TEI3  */
	{ ICU_IER18_ADDR, ICU_IEN6_BIT },	/* No.198  DMAC DMAC0I  */
	{ ICU_IER18_ADDR, ICU_IEN7_BIT },	/* No.199  DMAC DMAC1I  */
	{ ICU_IER19_ADDR, ICU_IEN0_BIT },	/* No.200  DMAC DMAC2I  */
	{ ICU_IER19_ADDR, ICU_IEN1_BIT },	/* No.201  DMAC DMAC3I  */
	{ ICU_IER19_ADDR, ICU_IEN2_BIT },	/* No.202  EXDMAC EXDMAC0I  */
	{ ICU_IER19_ADDR, ICU_IEN3_BIT },	/* No.203  EXDMAC EXDMAC1I  */
	{ NULL, INVALID_OFFSET },			/* No.204  予約 */
	{ NULL, INVALID_OFFSET },			/* No.205  予約 */
	{ ICU_IER19_ADDR, ICU_IEN6_BIT },	/* No.206  DEU DEU0  */
	{ ICU_IER19_ADDR, ICU_IEN7_BIT },	/* No.207  DEU DEU0  */
	{ ICU_IER1A_ADDR, ICU_IEN0_BIT },	/* No.208  PDC PCDFI  */
	{ ICU_IER1A_ADDR, ICU_IEN1_BIT },	/* No.209  PDC PCFEI  */
	{ ICU_IER1A_ADDR, ICU_IEN2_BIT },	/* No.210  PDC PCERI  */
	{ NULL, INVALID_OFFSET },			/* No.211  予約 */
	{ NULL, INVALID_OFFSET },			/* No.212  予約 */
	{ NULL, INVALID_OFFSET },			/* No.213  予約 */
	{ ICU_IER1A_ADDR, ICU_IEN6_BIT },	/* No.214  SCI0 RXI0  */
	{ ICU_IER1A_ADDR, ICU_IEN7_BIT },	/* No.215  SCI0 TXI0  */
	{ ICU_IER1B_ADDR, ICU_IEN0_BIT },	/* No.216  SCI0 TEI0  */
	{ ICU_IER1B_ADDR, ICU_IEN1_BIT },	/* No.217  SCI1 RXI1  */
	{ ICU_IER1B_ADDR, ICU_IEN2_BIT },	/* No.218  SCI1 TXI1  */
	{ ICU_IER1B_ADDR, ICU_IEN3_BIT },	/* No.219  SCI1 TEI1  */
	{ ICU_IER1B_ADDR, ICU_IEN4_BIT },	/* No.220  SCI2 RXI2  */
	{ ICU_IER1B_ADDR, ICU_IEN5_BIT },	/* No.221  SCI2 TXI2  */
	{ ICU_IER1B_ADDR, ICU_IEN6_BIT },	/* No.222  SCI2 TEI2  */
	{ ICU_IER1B_ADDR, ICU_IEN7_BIT },	/* No.223  SCI3 RXI3  */
	{ ICU_IER1C_ADDR, ICU_IEN0_BIT },	/* No.224  SCI3 TXI3  */
	{ ICU_IER1C_ADDR, ICU_IEN1_BIT },	/* No.225  SCI3 TEI3  */
	{ ICU_IER1C_ADDR, ICU_IEN2_BIT },	/* No.226  SCI4 RXI4  */
	{ ICU_IER1C_ADDR, ICU_IEN3_BIT },	/* No.227  SCI4 TXI4  */
	{ ICU_IER1C_ADDR, ICU_IEN4_BIT },	/* No.228  SCI4 TEI4  */
	{ ICU_IER1C_ADDR, ICU_IEN5_BIT },	/* No.229  SCI5 RXI5  */
	{ ICU_IER1C_ADDR, ICU_IEN6_BIT },	/* No.230  SCI5 TXI5  */
	{ ICU_IER1C_ADDR, ICU_IEN7_BIT },	/* No.231  SCI5 TEI5  */
	{ ICU_IER1D_ADDR, ICU_IEN0_BIT },	/* No.232  SCI6 RXI6  */
	{ ICU_IER1D_ADDR, ICU_IEN1_BIT },	/* No.233  SCI6 TXI6  */
	{ ICU_IER1D_ADDR, ICU_IEN2_BIT },	/* No.234  SCI6 TEI6  */
	{ ICU_IER1D_ADDR, ICU_IEN3_BIT },	/* No.235  SCI7 RXI7  */
	{ ICU_IER1D_ADDR, ICU_IEN4_BIT },	/* No.236  SCI7 TXI7  */
	{ ICU_IER1D_ADDR, ICU_IEN5_BIT },	/* No.237  SCI7 TEI7  */
	{ ICU_IER1D_ADDR, ICU_IEN6_BIT },	/* No.238  SCI8 RXI8  */
	{ ICU_IER1D_ADDR, ICU_IEN7_BIT },	/* No.239  SCI8 TXI8  */
	{ ICU_IER1E_ADDR, ICU_IEN0_BIT },	/* No.240  SCI8 TEI8  */
	{ ICU_IER1E_ADDR, ICU_IEN1_BIT },	/* No.241  SCI9 RXI9  */
	{ ICU_IER1E_ADDR, ICU_IEN2_BIT },	/* No.242  SCI9 TXI9  */
	{ ICU_IER1E_ADDR, ICU_IEN3_BIT },	/* No.243  SCI9 TEI9  */
	{ ICU_IER1E_ADDR, ICU_IEN4_BIT },	/* No.244  SCI10 RXI10  */
	{ ICU_IER1E_ADDR, ICU_IEN5_BIT },	/* No.245  SCI10 TXI10  */
	{ ICU_IER1E_ADDR, ICU_IEN6_BIT },	/* No.246  SCI10 TEI10  */
	{ ICU_IER1E_ADDR, ICU_IEN7_BIT },	/* No.247  SCI11 RXI11  */
	{ ICU_IER1F_ADDR, ICU_IEN0_BIT },	/* No.248  SCI11 TXI11  */
	{ ICU_IER1F_ADDR, ICU_IEN1_BIT },	/* No.249  SCI11 TEI11  */
	{ ICU_IER1F_ADDR, ICU_IEN2_BIT },	/* No.250  SCI12 RXI12  */
	{ ICU_IER1F_ADDR, ICU_IEN3_BIT },	/* No.251  SCI12 TXI12  */
	{ ICU_IER1F_ADDR, ICU_IEN4_BIT },	/* No.252  SCI12 TEI12  */
	{ ICU_IER1F_ADDR, ICU_IEN5_BIT },	/* No.253  IEB IEBINT  */
	{ NULL, INVALID_OFFSET },			/* No.254 予約 */
	{ NULL, INVALID_OFFSET },			/* No.255 予約 */
};


/*
 *  割込み要求レジスタアドレステーブル
 */
volatile uint8_t  * const ir_reg_addr[ INHNO_MAX ] = {
  	NULL, NULL, NULL, NULL, NULL,	/* No.0 - 4   予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.5 - 9   予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.10 - 14 予約 */
	NULL,							/* No.15  予約 */
	ICU_IR016_ADDR,					/* No.16   バスエラー BUSERR  */
	NULL, NULL, NULL, NULL,			/* No.17 - 20 予約 */
	ICU_IR021_ADDR,					/* No.21   FCU FIFERR  */
	NULL,							/* No.22  予約 */
	ICU_IR023_ADDR,					/* No.23   FCU FRDYI  */
	NULL, NULL, NULL,		        /* No.24 -26  予約 */
	ICU_IR027_ADDR,					/* No.27  ICU SWINT  */
	ICU_IR028_ADDR,					/* No.28   CMTユニット0 CMT0  */
	ICU_IR029_ADDR,					/* No.29   CMTユニット0 CMT1  */
	ICU_IR030_ADDR,					/* No.30   CMTユニット1 CMT2  */
	ICU_IR031_ADDR,					/* No.31   CMTユニット1 CMT3  */
	ICU_IR032_ADDR,					/* No.32   Ether EINT  */
	ICU_IR033_ADDR,					/* No.33   USB D0FIFO0  */
	ICU_IR034_ADDR,					/* No.34   USB D1FIFO0  */
	ICU_IR035_ADDR,					/* No.35   USB USBI0  */
	ICU_IR036_ADDR,					/* No.36   USB D0FIFO1  */
	ICU_IR037_ADDR,					/* No.37   USB D1FIFO1  */
	ICU_IR038_ADDR,					/* No.38   USB USBI1  */
	ICU_IR039_ADDR,					/* No.39   RSPI0 SPRI0  */
	ICU_IR040_ADDR,					/* No.40   RSPI0 SPTI0  */
	ICU_IR041_ADDR,					/* No.41   RSPI0 SPII0  */
	ICU_IR042_ADDR,					/* No.42   RSPI1 SPRI0  */
	ICU_IR043_ADDR,					/* No.43   RSPI1 SPTI0  */
	ICU_IR044_ADDR,					/* No.44   RSPI1 SPII0  */
	ICU_IR045_ADDR,					/* No.45   RSPI1 SPRI0  */
	ICU_IR046_ADDR,					/* No.46   RSPI1 SPTI0  */
	ICU_IR047_ADDR,					/* No.47   RSPI1 SPII0  */
	ICU_IR048_ADDR,                 /* NO.48  CAN0 RXF0*/
	ICU_IR049_ADDR,                 /* NO.49  CAN0 TXF0*/
	ICU_IR050_ADDR,                 /* NO.50  CAN0 RXM0*/
	ICU_IR051_ADDR,                 /* NO.51  CAN0 TXM0*/
	ICU_IR052_ADDR,                 /* NO.52  CAN1 RXF1*/
	ICU_IR053_ADDR,                 /* NO.53  CAN1 TXF1*/
	ICU_IR054_ADDR,                 /* NO.54  CAN1 RXM1*/
	ICU_IR055_ADDR,                 /* NO.55  CAN1 TXM1*/
	ICU_IR056_ADDR,                 /* NO.56  CAN2 RXF2*/
	ICU_IR057_ADDR,                 /* NO.57  CAN2 TXF2*/
	ICU_IR058_ADDR,                 /* NO.58  CAN2 RXM2*/
	ICU_IR059_ADDR,                 /* NO.59  CAN2 TXM2*/
    NULL, NULL,                     /* No.60 - 61 予約 */
	ICU_IR062_ADDR,                 /* NO 62 RTC CUP */
	NULL,						    /* No.63 予約 */
	ICU_IR064_ADDR,					/* No.64   外部端子 IRQ0  */
	ICU_IR065_ADDR,					/* No.65   外部端子 IRQ1  */
	ICU_IR066_ADDR,					/* No.66   外部端子 IRQ2  */
	ICU_IR067_ADDR,					/* No.67   外部端子 IRQ3  */
	ICU_IR068_ADDR,					/* No.68   外部端子 IRQ4  */
	ICU_IR069_ADDR,					/* No.69   外部端子 IRQ5  */
	ICU_IR070_ADDR,					/* No.70   外部端子 IRQ6  */
	ICU_IR071_ADDR,					/* No.71   外部端子 IRQ7  */
	ICU_IR072_ADDR,					/* No.72   外部端子 IRQ8  */
	ICU_IR073_ADDR,					/* No.73   外部端子 IRQ9  */
	ICU_IR074_ADDR,					/* No.74   外部端子 IRQ10  */
	ICU_IR075_ADDR,					/* No.75   外部端子 IRQ11  */
	ICU_IR076_ADDR,					/* No.76   外部端子 IRQ12  */
	ICU_IR077_ADDR,					/* No.77   外部端子 IRQ13  */
	ICU_IR078_ADDR,					/* No.78   外部端子 IRQ14  */
	ICU_IR079_ADDR,					/* No.79   外部端子 IRQ15  */
	NULL, NULL, NULL, NULL, NULL,	/* No.80 - 84 予約 */
	NULL, NULL, NULL, NULL, NULL,	/* No.85 - 89 予約 */
	ICU_IR090_ADDR,					/* No.90  USB USBR0  */
	ICU_IR091_ADDR,					/* No.91  USB USBR1  */
	ICU_IR092_ADDR,					/* No.92  RTC ALM  */
	ICU_IR093_ADDR,					/* No.93  RTC PRD  */
	NULL, NULL, NULL, NULL,         /* No.94 - 97  予約 */
	ICU_IR098_ADDR,					/* No.98   AD0 ADI0  */
    NULL, NULL, NULL,               /* No.99 - 101 予約 */
	ICU_IR102_ADDR,					/* No.102  S12AD S12ADI0  */
	NULL, NULL, NULL,               /* No.103 - 105 予約 */
	ICU_IR106_ADDR,					/* No.106  ICU GROUP0  */
	ICU_IR107_ADDR,					/* No.107  ICU GROUP1  */
	ICU_IR108_ADDR,					/* No.108  ICU GROUP2  */
	ICU_IR109_ADDR,					/* No.109  ICU GROUP3  */
	ICU_IR110_ADDR,					/* No.110  ICU GROUP4  */
	ICU_IR111_ADDR,					/* No.111  ICU GROUP5  */
	ICU_IR112_ADDR,					/* No.112  ICU GROUP6  */
	NULL,                           /* No.113 予約 */
	ICU_IR114_ADDR,					/* No.114  ICU Group12  */
	NULL, NULL, NULL, NULL, NULL,   /* No.115 - 119 予約 */
	NULL, NULL,                     /* No.120 - 121 予約 */
	ICU_IR122_ADDR,					/* No.122  SCI12 SCIX0  */
	ICU_IR123_ADDR,					/* No.123  SCI12 SCIX1  */
	ICU_IR124_ADDR,					/* No.124  SCI12 SCIX2  */
	ICU_IR125_ADDR,					/* No.125  SCI12 SCIX3  */
	ICU_IR126_ADDR,					/* No.126  TPU0 TGI0A  */
	ICU_IR127_ADDR,					/* No.127  TPU0 TGI0B  */
	ICU_IR128_ADDR,					/* No.128  TPU0 TGI0C  */
	ICU_IR129_ADDR,					/* No.129  TPU0 TGI0D  */
	ICU_IR130_ADDR,					/* No.130  TPU1 TGI1A  */
	ICU_IR131_ADDR,					/* No.131  TPU1 TGI1B  */
	ICU_IR132_ADDR,					/* No.132  TPU2 TGI2A  */
	ICU_IR133_ADDR,					/* No.133  TPU2 TGI2B  */
	ICU_IR134_ADDR,					/* No.134  TPU3 TGI3A  */
	ICU_IR135_ADDR,					/* No.135  TPU3 TGI3B  */
	ICU_IR136_ADDR,					/* No.136  TPU3 TGI3C  */
	ICU_IR137_ADDR,					/* No.137  TPU3 TGI3D  */
	ICU_IR138_ADDR,					/* No.138  TPU4 TGI4A  */
	ICU_IR139_ADDR,					/* No.139  TPU4 TGI4B  */
	ICU_IR140_ADDR,					/* No.140  TPU5 TGI5A  */
	ICU_IR141_ADDR,					/* No.141  TPU5 TGI5B  */
	ICU_IR142_ADDR,					/* No.142  TPU6 TGI6A, MTU0 TGIA0  */
	ICU_IR143_ADDR,					/* No.143  TPU6 TGI6B, MTU0 TGIB0  */
	ICU_IR144_ADDR,					/* No.144  TPU6 TGI6C, MTU0 TGIC0  */
	ICU_IR145_ADDR,					/* No.145  TPU6 TGI6D, MTU0 TGID0  */
	ICU_IR146_ADDR,					/* No.146  MTU0 TGIE0  */
	ICU_IR147_ADDR,					/* No.147  MTU0 TGIF0  */
	ICU_IR148_ADDR,					/* No.148  TPU7 TGI7A, MTU1 TGIA1  */
	ICU_IR149_ADDR,					/* No.149  TPU7 TGI7B, MTU1 TGIB1  */
	ICU_IR150_ADDR,					/* No.150  TPU8 TGI8A, MTU2 TGIA2  */
	ICU_IR151_ADDR,					/* No.151  TPU8 TGI8B, MTU2 TGIB2  */
	ICU_IR152_ADDR,					/* No.152  TPU9 TGI9A, MTU3 TGIA3  */
	ICU_IR153_ADDR,					/* No.153  TPU9 TGI9B, MTU3 TGIB3  */
	ICU_IR154_ADDR,					/* No.154  TPU9 TGI9C, MTU3 TGIC3  */
	ICU_IR155_ADDR,					/* No.155  TPU9 TGI9D, MTU3 TGID3  */
	ICU_IR156_ADDR,					/* No.156  TPU10 TGI10A, MTU4 TGIA4  */
	ICU_IR157_ADDR,					/* No.157  TPU10 TGI10B, MTU4 TGIB4  */
	ICU_IR158_ADDR,					/* No.158  MTU4 TGIC4  */
	ICU_IR159_ADDR,					/* No.159  MTU4 TGID4  */
	ICU_IR160_ADDR,					/* No.160  MTU4 TGIV4  */
	ICU_IR161_ADDR,					/* No.161  MTU5 TGIU5  */
	ICU_IR162_ADDR,					/* No.162  MTU5 TGIV5  */
	ICU_IR163_ADDR,					/* No.163  MTU5 TGIW5  */
	ICU_IR164_ADDR,					/* No.164  TPU11 TGI11A  */
	ICU_IR165_ADDR,					/* No.165  TPU11 TGI11B  */
	ICU_IR166_ADDR,					/* No.166  POE OEI1  */
	ICU_IR167_ADDR,					/* No.167  POE OEI2  */
	NULL, NULL,                     /* No.168 - 169 予約 */
	ICU_IR170_ADDR,					/* No.170  TMR0 CMIA0  */
	ICU_IR171_ADDR,					/* No.171  TMR0 CMIB0  */
	ICU_IR172_ADDR,					/* No.172  TMR0 OVI0  */
	ICU_IR173_ADDR,					/* No.173  TMR1 CMIA1  */
	ICU_IR174_ADDR,					/* No.174  TMR1 CMIB1  */
	ICU_IR175_ADDR,					/* No.175  TMR1 OVI1  */
	ICU_IR176_ADDR,					/* No.176  TMR2 CMIA2  */
	ICU_IR177_ADDR,					/* No.177  TMR2 CMIB2  */
	ICU_IR178_ADDR,					/* No.178  TMR2 OVI2  */
	ICU_IR179_ADDR,					/* No.179  TMR3 CMIA3  */
	ICU_IR180_ADDR,					/* No.180  TMR3 CMIB3  */
	ICU_IR181_ADDR,					/* No.181  TMR3 OVI3  */
	ICU_IR182_ADDR,					/* No.182  RIIC0 EEI0  */
	ICU_IR183_ADDR,					/* No.183  RIIC0 RXI0  */
	ICU_IR184_ADDR,					/* No.184  RIIC0 TXI0  */
	ICU_IR185_ADDR,					/* No.185  RIIC0 TEI0  */
	ICU_IR186_ADDR,					/* No.186  RIIC1 EEI1  */
	ICU_IR187_ADDR,					/* No.187  RIIC1 RXI1  */
	ICU_IR188_ADDR,					/* No.188  RIIC1 TXI1  */
	ICU_IR189_ADDR,					/* No.189  RIIC1 TEI1  */
	ICU_IR190_ADDR,					/* No.190  RIIC2 EEI2  */
	ICU_IR191_ADDR,					/* No.191  RIIC2 RXI2  */
	ICU_IR192_ADDR,					/* No.192  RIIC2 TXI2  */
	ICU_IR193_ADDR,					/* No.193  RIIC2 TEI2  */
	ICU_IR194_ADDR,					/* No.194  RIIC3 EEI3  */
	ICU_IR195_ADDR,					/* No.195  RIIC3 RXI3  */
	ICU_IR196_ADDR,					/* No.196  RIIC3 TXI3  */
	ICU_IR197_ADDR,					/* No.197  RIIC3 TEI3  */
	ICU_IR198_ADDR,					/* No.198  DMAC DMAC0I  */
	ICU_IR199_ADDR,					/* No.199  DMAC DMAC1I  */
	ICU_IR200_ADDR,					/* No.200  DMAC DMAC2I  */
	ICU_IR201_ADDR,					/* No.201  DMAC DMAC3I  */
	ICU_IR202_ADDR,					/* No.202  EXDMAC EXDMAC0I  */
	ICU_IR203_ADDR,					/* No.203  EXDMAC EXDMAC1I  */
	NULL, NULL,                     /* No.204 - 205 予約 */
	ICU_IR206_ADDR,					/* No.206  DEU DEU0  */
	ICU_IR207_ADDR,					/* No.207  DEU DEU0  */
	ICU_IR208_ADDR,					/* No.208  PDC PCDFI  */
	ICU_IR209_ADDR,					/* No.209  PDC PCFEI  */
	ICU_IR210_ADDR,					/* No.210  PDC PCERI  */
	NULL, NULL, NULL,                /* No.211 - 213 予約 */
	ICU_IR214_ADDR,					/* No.214  SCI0 RXI0  */
	ICU_IR215_ADDR,					/* No.215  SCI0 TXI0  */
	ICU_IR216_ADDR,					/* No.216  SCI0 TEI0  */
	ICU_IR217_ADDR,					/* No.217  SCI1 RXI1  */
	ICU_IR218_ADDR,					/* No.218  SCI1 TXI1  */
	ICU_IR219_ADDR,					/* No.219  SCI1 TEI1  */
	ICU_IR220_ADDR,					/* No.220  SCI2 RXI2  */
	ICU_IR221_ADDR,					/* No.221  SCI2 TXI2  */
	ICU_IR222_ADDR,					/* No.222  SCI2 TEI2  */
	ICU_IR223_ADDR,					/* No.223  SCI3 RXI3  */
	ICU_IR224_ADDR,					/* No.224  SCI3 TXI3  */
	ICU_IR225_ADDR,					/* No.225  SCI3 TEI3  */
	ICU_IR226_ADDR,					/* No.226  SCI4 RXI4  */
	ICU_IR227_ADDR,					/* No.227  SCI4 TXI4  */
	ICU_IR228_ADDR,					/* No.228  SCI4 TEI4  */
	ICU_IR229_ADDR,					/* No.229  SCI5 RXI5  */
	ICU_IR230_ADDR,					/* No.230  SCI5 TXI5  */
	ICU_IR231_ADDR,					/* No.231  SCI5 TEI5  */
	ICU_IR232_ADDR,					/* No.232  SCI6 RXI6  */
	ICU_IR233_ADDR,					/* No.233  SCI6 TXI6  */
	ICU_IR234_ADDR,					/* No.234  SCI6 TEI6  */
	ICU_IR235_ADDR,					/* No.235  SCI7 RXI7  */
	ICU_IR236_ADDR,					/* No.236  SCI7 TXI7  */
	ICU_IR237_ADDR,					/* No.237  SCI7 TEI7  */
	ICU_IR238_ADDR,					/* No.238  SCI8 RXI8  */
	ICU_IR239_ADDR,					/* No.239  SCI8 TXI8  */
	ICU_IR240_ADDR,					/* No.240  SCI8 TEI8  */
	ICU_IR241_ADDR,					/* No.241  SCI9 RXI9  */
	ICU_IR242_ADDR,					/* No.242  SCI9 TXI9  */
	ICU_IR243_ADDR,					/* No.243  SCI9 TEI9  */
	ICU_IR244_ADDR,					/* No.244  SCI10 RXI10  */
	ICU_IR245_ADDR,					/* No.245  SCI10 TXI10  */
	ICU_IR246_ADDR,					/* No.246  SCI10 TEI10  */
	ICU_IR247_ADDR,					/* No.247  SCI11 RXI11  */
	ICU_IR248_ADDR,					/* No.248  SCI11 TXI11  */
	ICU_IR249_ADDR,					/* No.249  SCI11 TEI11  */
	ICU_IR250_ADDR,					/* No.250  SCI12 RXI12  */
	ICU_IR251_ADDR,					/* No.251  SCI12 TXI12  */
	ICU_IR252_ADDR,					/* No.252  SCI12 TEI12  */
	ICU_IR253_ADDR,					/* No.253  IEB IEBINT  */
	NULL, NULL,						/* No.254 - 255 予約 */
};


/*
 *  IRQコントロールレジスタアドレステーブル
 */
volatile uint8_t  * const irqcr_reg_addr[ IRQ_MAX ] = {
	ICU_IRQ0_ADDR,
	ICU_IRQ1_ADDR,
	ICU_IRQ2_ADDR,
	ICU_IRQ3_ADDR,
	ICU_IRQ4_ADDR,
	ICU_IRQ5_ADDR,
	ICU_IRQ6_ADDR,
	ICU_IRQ7_ADDR,
	ICU_IRQ8_ADDR,
	ICU_IRQ9_ADDR,
	ICU_IRQ10_ADDR,
	ICU_IRQ11_ADDR,
	ICU_IRQ12_ADDR,
	ICU_IRQ13_ADDR,
	ICU_IRQ14_ADDR,
	ICU_IRQ15_ADDR,
};

