/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
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
 *  RX63Nに依存する定義
 */
#ifndef TOPPERS_RX63N_H
#define TOPPERS_RX63N_H

#include <sil.h>
/*
 *  CPU例外ハンドラ番号の定義(固定ベクタテーブル)
 *
 *  番号の範囲は0 - 31
 */
#define INT_PRIVILEGED_INSTRUNCTION		20		/* 特権命令例外 */
#define INT_UNDEF_INSTRUNCTION			23		/* 未定義命令例外 */
#define INT_FLOATINGPOINT_INSTRUCTION	25		/* 浮動小数点例外 */
#define INT_NMI							30		/* ノンマスカブル割り込み */
#define INT_RESET						31		/* リセット */

/*
 *  割込み番号の定義(可変ベクタテーブル)
 */
#define INT_BUSERR			16
#define INT_FCU_FCUERR		21
#define INT_FCU_FRDYI		23
#define INT_ICU_SWINT       27
#define INT_CMT0_CMI0		28
#define INT_CMT1_CMI1		29
#define INT_CMT2_CMI2		30
#define INT_CMT3_CMI3		31
#define INT_ETHER_EINT      32
#define INT_USB0_D0FIFO0    33
#define INT_USB0_D1FIFO0    34
#define INT_USB0_USBI0      35
#define INT_USB1_D0FIFO1    36
#define INT_USB1_D1FIFO1    37
#define INT_USB1_USBI1      38
#define INT_RSPI0_SPRI0     39
#define INT_RSPI0_SPTI0     40
#define INT_RSPI0_SPII0     41
#define INT_RSPI1_SPRI1     42
#define INT_RSPI1_SPTI1     43
#define INT_RSPI1_SPII1     44
#define INT_RSPI2_SPRI2     45
#define INT_RSPI2_SPTI2     46
#define INT_RSPI2_SPII2     47
#define INT_CAN0_RXF0       48
#define INT_CAN0_TXF0       49
#define INT_CAN0_RXM0       50
#define INT_CAN0_TXM0       51
#define INT_CAN1_RXF1       52
#define INT_CAN1_TXF1       53
#define INT_CAN1_RXM1       54
#define INT_CAN1_TXM1       55
#define INT_CAN2_RXF2       56
#define INT_CAN2_TXF2       57
#define INT_CAN2_RXM2       58
#define INT_CAN2_TXM2       59
#define INT_RTC_CUP         62
#define INT_IRQ0			64
#define INT_IRQ1			65
#define INT_IRQ2			66
#define INT_IRQ3			67
#define INT_IRQ4			68
#define INT_IRQ5			69
#define INT_IRQ6			70
#define INT_IRQ7			71
#define INT_IRQ8			72
#define INT_IRQ9			73
#define INT_IRQ10			74
#define INT_IRQ11			75
#define INT_IRQ12			76
#define INT_IRQ13			77
#define INT_IRQ14			78
#define INT_IRQ15			79
#define INT_USB_USBR0       90
#define INT_USB_USBR1       91
#define INT_RTC_ALM         92
#define INT_RTC_PRD         93
#define INT_AD_ADI0         98
#define INT_S12AD_S12ADI0   102
#define INT_ICU_GROUP0      106
#define INT_ICU_GROUP1      107
#define INT_ICU_GROUP2      108
#define INT_ICU_GROUP3      109
#define INT_ICU_GROUP4      110
#define INT_ICU_GROUP5      111
#define INT_ICU_GROUP6      112
#define INT_ICU_GROUP12     114
#define INT_SCI12_SCIX0     122
#define INT_SCI12_SCIX1     123
#define INT_SCI12_SCIX2     124
#define INT_SCI12_SCIX3     125
//TPU and MTU are sheared irq.
//TPU define
#define INT_TPU0_TGI0A		126
#define INT_TPU0_TGI0B		127
#define INT_TPU0_TGI0C		128
#define INT_TPU0_TGI0D		129
#define INT_TPU1_TGI1A		130
#define INT_TPU1_TGI1B		131
#define INT_TPU2_TGI2A		132
#define INT_TPU2_TGI2B		133
#define INT_TPU3_TGI3A		134
#define INT_TPU3_TGI3B		135
#define INT_TPU3_TGI3C		136
#define INT_TPU3_TGI3D		137
#define INT_TPU4_TGI4A		138
#define INT_TPU4_TGI4B		139
#define INT_TPU5_TGI5A		140
#define INT_TPU5_TGI5B		141
#define INT_TPU6_TGI6A		142
#define INT_TPU6_TGI6B		143
#define INT_TPU6_TGI6C		144
#define INT_TPU7_TGI7A		148
#define INT_TPU7_TGI7B		149
#define INT_TPU8_TGI8A		150
#define INT_TPU8_TGI8B		151
#define INT_TPU9_TGI9A		152
#define INT_TPU9_TGI9B		153
#define INT_TPU9_TGI9C		154
#define INT_TPU9_TGI9D		155
#define INT_TPU10_TGI10A	156
#define INT_TPU10_TGI10B	157
#define INT_TPU11_TGI11A	164
#define INT_TPU11_TGI11B	165
//MTU define
#define INT_MTU0_TGIA0      142
#define INT_MTU0_TGIB0      143
#define INT_MTU0_TGIC0      144
#define INT_MTU0_TGID0      145
#define INT_MTU0_TGIE0      146
#define INT_MTU0_TGIF0      147
#define INT_MTU1_TGIA1      148
#define INT_MTU1_TGIB1      149
#define INT_MTU2_TGIA2      150
#define INT_MTU2_TGIB2      151
#define INT_MTU3_TGIA3      152
#define INT_MTU3_TGIB3      153
#define INT_MTU3_TGIC3      154
#define INT_MTU3_TGID3      155
#define INT_MTU4_TGIA4      156
#define INT_MTU4_TGIB4      157
#define INT_MTU4_TGIC4      158
#define INT_MTU4_TGID4      159
#define INT_MTU4_TGIV4      160
#define INT_MTU5_TGIU5      161
#define INT_MTU5_TGIV5      162
#define INT_MTU5_TGIW5      163
#define INT_POE_OEI1        166
#define INT_POE_OEI2        167
#define INT_TMR0_CMIA0		170
#define INT_TMR0_CMIB0		171
#define INT_TMR0_OVI0		172
#define INT_TMR1_CMIA1		173
#define INT_TMR1_CMIB1		174
#define INT_TMR1_OVI1		175
#define INT_TMR2_CMIA2		176
#define INT_TMR2_CMIB2		177
#define INT_TMR2_OVI2		178
#define INT_TMR3_CMIA3		179
#define INT_TMR3_CMIB3		180
#define INT_TMR3_OVI3		181
#define INT_RIIC0_EEI0      182
#define INT_RIIC0_RXI0      183
#define INT_RIIC0_TXI0      184
#define INT_RIIC0_TEI0      185
#define INT_RIIC1_EEI1      186
#define INT_RIIC1_RXI1      187
#define INT_RIIC1_TXI1      188
#define INT_RIIC1_TEI1      189
#define INT_RIIC2_EEI2      190
#define INT_RIIC2_RXI2      191
#define INT_RIIC2_TXI2      192
#define INT_RIIC2_TEI2      193
#define INT_RIIC3_EEI3      194
#define INT_RIIC3_RXI3      195
#define INT_RIIC3_TXI3      196
#define INT_RIIC3_TEI3      197
#define INT_DMAC_DMAC0I     198
#define INT_DMAC_DMAC1I     199
#define INT_DMAC_DMAC2I     200
#define INT_DMAC_DMAC3I     201
#define INT_EXDMAC_EXDMAC0I 202 
#define INT_EXDMAC_EXDMAC1I 203
#define INT_DEU_DEU0        206
#define INT_DEU_DEU1        207
#define INT_PDC_PCDFI       208
#define INT_PDC_PCFEI       209
#define INT_PDC_PCERI       210
#define INT_SCI0_RXI0		214
#define INT_SCI0_TXI0		215
#define INT_SCI0_TEI0		216
#define INT_SCI1_RXI1		217
#define INT_SCI1_TXI1		218
#define INT_SCI1_TEI1		219
#define INT_SCI2_RXI2		220
#define INT_SCI2_TXI2		221
#define INT_SCI2_TEI2		222
#define INT_SCI3_RXI3		223
#define INT_SCI3_TXI3		224
#define INT_SCI3_TEI3		225
#define INT_SCI4_RXI4		226
#define INT_SCI4_TXI4		227
#define INT_SCI4_TEI4		228
#define INT_SCI5_RXI5		229
#define INT_SCI5_TXI5		230
#define INT_SCI5_TEI5		231
#define INT_SCI6_RXI6		232
#define INT_SCI6_TXI6		233
#define INT_SCI6_TEI6		234
#define INT_SCI7_RXI7		235
#define INT_SCI7_TXI7		236
#define INT_SCI7_TEI7		237
#define INT_SCI8_RXI8		238
#define INT_SCI8_TXI8		239
#define INT_SCI8_TEI8		240
#define INT_SCI9_RXI9		241
#define INT_SCI9_TXI9		242
#define INT_SCI9_TEI9		243
#define INT_SCI10_RXI10		244
#define INT_SCI10_TXI10		245
#define INT_SCI10_TEI10		246
#define INT_SCI11_RXI11		247
#define INT_SCI11_TXI11		248
#define INT_SCI11_TEI11		249
#define INT_SCI12_RXI12		250
#define INT_SCI12_TXI12		251
#define INT_SCI12_TEI12		252
#define INT_IEB_IEBINT		253

/*
 *  各モジュールのレジスタ及び設定ビット情報
 */

/*
 *  Register write protection 
 */ 
#define SYSTEM_PRCR_ADDR ( ( volatile uint16_t *)0x000803FE )
#define SYSTEM_PRKEY  0xA500
#define SYSTEM_PRC0	( 1UL << 0U )
#define SYSTEM_PRC1	( 1UL << 1U )
#define SYSTEM_PRC3	( 1UL << 3U )

/*
 * Clock generater 
 */
//SCKCR define
#define CKG_SCKCR_ADDR ( ( volatile uint32_t *)0x00080020 )
#define CKG_SCKCR_RESERVE 0x11
#define CKG_SCKCR_PB_DIV01 ( 0UL << 8 )
#define CKG_SCKCR_PB_DIV02 ( 1UL << 8 )
#define CKG_SCKCR_PB_DIV04 ( 2UL << 8 )
#define CKG_SCKCR_PB_DIV08 ( 3UL << 8 )
#define CKG_SCKCR_PB_DIV16 ( 4UL << 8 )
#define CKG_SCKCR_PB_DIV32 ( 5UL << 8 )
#define CKG_SCKCR_PB_DIV64 ( 6UL << 8 )
#define CKG_SCKCR_PA_DIV01 ( 0UL << 12 )
#define CKG_SCKCR_PA_DIV02 ( 1UL << 12 )
#define CKG_SCKCR_PA_DIV04 ( 2UL << 12 )
#define CKG_SCKCR_PA_DIV08 ( 3UL << 12 )
#define CKG_SCKCR_PA_DIV16 ( 4UL << 12 )
#define CKG_SCKCR_PA_DIV32 ( 5UL << 12 )
#define CKG_SCKCR_PA_DIV64 ( 6UL << 12 )
#define CKG_SCKCR_BCK_DIV01 ( 0UL << 16 )
#define CKG_SCKCR_BCK_DIV02 ( 1UL << 16 )
#define CKG_SCKCR_BCK_DIV04 ( 2UL << 16 )
#define CKG_SCKCR_BCK_DIV08 ( 3UL << 16 )
#define CKG_SCKCR_BCK_DIV16 ( 4UL << 16 )
#define CKG_SCKCR_BCK_DIV32 ( 5UL << 16 )
#define CKG_SCKCR_BCK_DIV64 ( 6UL << 16 )
#define CKG_SCKCR_PSTOP0 ( 1UL << 22 )
#define CKG_SCKCR_PSTOP1 ( 1UL << 23 )
#define CKG_SCKCR_ICK_DIV01  ( 0UL << 24 )
#define CKG_SCKCR_ICK_DIV02  ( 1UL << 24 )
#define CKG_SCKCR_ICK_DIV04  ( 2UL << 24 )
#define CKG_SCKCR_ICK_DIV08  ( 3UL << 24 )
#define CKG_SCKCR_ICK_DIV16  ( 4UL << 24 )
#define CKG_SCKCR_ICK_DIV32  ( 5UL << 24 )
#define CKG_SCKCR_ICK_DIV64  ( 6UL << 24 )
#define CKG_SCKCR_FCK_DIV01  ( 0UL << 28 )
#define CKG_SCKCR_FCK_DIV02  ( 1UL << 28 )
#define CKG_SCKCR_FCK_DIV04  ( 2UL << 28 )
#define CKG_SCKCR_FCK_DIV08  ( 3UL << 28 )
#define CKG_SCKCR_FCK_DIV16  ( 4UL << 28 )
#define CKG_SCKCR_FCK_DIV32  ( 5UL << 28 )
#define CKG_SCKCR_FCK_DIV64  ( 6UL << 28 )

#define CKG_SCKCR2_ADDR ( ( volatile uint16_t *)0x00080024 )
#define CKG_SCKCR2_IEBCK_DIV2   1UL
#define CKG_SCKCR2_IEBCK_DIV4   2UL
#define CKG_SCKCR2_IEBCK_DIV8   3UL
#define CKG_SCKCR2_IEBCK_DIV16  4UL
#define CKG_SCKCR2_IEBCK_DIV32  5UL
#define CKG_SCKCR2_IEBCK_DIV64  6UL
#define CKG_SCKCR2_IEBCK_DIV6   12UL
#define CKG_SCKCR2_UCK_NOT_USE (1UL << 4)
#define CKG_SCKCR2_UCK_DIV3 (2UL << 4)
#define CKG_SCKCR2_UCK_DIV4 (3UL << 4)


//CLock Select register
#define CKG_SCKCR3_ADDR ( ( volatile uint16_t *)0x00080026 )
#define CKG_SCKCR3_LOCO ( 0UL << 8 )
#define CKG_SCKCR3_HOCO ( 1UL << 8 )
#define CKG_SCKCR3_MAIN ( 2UL << 8 )
#define CKG_SCKCR3_SUB ( 3UL << 8 )
#define CKG_SCKCR3_PLL ( 4UL << 8 )
//PLL freq setting
#define CKG_PLLCR_ADDR ( ( volatile uint16_t *)0x00080028 )
#define CKG_PLLCR_PLIDIV1 ( 0UL << 0U )
#define CKG_PLLCR_PLIDIV2 ( 1UL << 0U )
#define CKG_PLLCR_PLIDIV4 ( 2UL << 0U )
#define CKG_PLLCR_STC8  ( 0x07UL << 8U )
#define CKG_PLLCR_STC10 ( 0x09UL << 8U )
#define CKG_PLLCR_STC12 ( 0x0BUL << 8U )
#define CKG_PLLCR_STC16 ( 0x0FUL << 8U )
#define CKG_PLLCR_STC20 ( 0x13UL << 8U )
#define CKG_PLLCR_STC24 ( 0x17UL << 8U )
#define CKG_PLLCR_STC25 ( 0x18UL << 8U )
#define CKG_PLLCR_STC50 ( 0x19UL << 8U )
//Clock enable setting
#define CKG_PLLCR2_ADDR ( ( volatile uint16_t *)0x0008002A )
#define CKG_MOSCCR_ADDR ( ( volatile uint8_t *)0x00080032 )
#define CKG_SOSCCR_ADDR ( ( volatile uint8_t *)0x00080033 )
#define CKG_LOSCCR_ADDR ( ( volatile uint8_t *)0x00080034 )
#define CKG_ILOCOCR_ADDR ( ( volatile uint8_t *)0x00080035 )
#define CKG_HOCOCR_ADDR ( ( volatile uint8_t *)0x00080036 )

#define CKG_CLOCK_ENABLE  0UL
#define CKG_COCCK_DISABLE 1UL




/*
 * モジュールストップコントロールレジスタA（MSTPCRA）
 */
#define SYSTEM_MSTPCRA_ADDR			( ( volatile uint32_t  * )0x00080010 )
#define SYSTEM_MSTPCRA_MSTPA4_BIT	( 1UL << 4U )
#define SYSTEM_MSTPCRA_MSTPA5_BIT	( 1UL << 5U )
#define SYSTEM_MSTPCRA_MSTPA9_BIT	( 1UL << 9U )
#define SYSTEM_MSTPCRA_MSTPA10_BIT	( 1UL << 10U )
#define SYSTEM_MSTPCRA_MSTPA11_BIT	( 1UL << 11U )
#define SYSTEM_MSTPCRA_MSTPA12_BIT	( 1UL << 12U )
#define SYSTEM_MSTPCRA_MSTPA13_BIT	( 1UL << 13U )
#define SYSTEM_MSTPCRA_MSTPA14_BIT	( 1UL << 14U )
#define SYSTEM_MSTPCRA_MSTPA15_BIT	( 1UL << 15U )
#define SYSTEM_MSTPCRA_MSTPA17_BIT	( 1UL << 17U )
#define SYSTEM_MSTPCRA_MSTPA19_BIT	( 1UL << 19U )
#define SYSTEM_MSTPCRA_MSTPA23_BIT	( 1UL << 23U )
#define SYSTEM_MSTPCRA_MSTPA24_BIT	( 1UL << 24U )
#define SYSTEM_MSTPCRA_MSTPA27_BIT	( 1UL << 27U )
#define SYSTEM_MSTPCRA_MSTPA28_BIT	( 1UL << 28U )
#define SYSTEM_MSTPCRA_MSTPA29_BIT	( 1UL << 29U )
#define SYSTEM_MSTPCRA_ACSE_BIT		( 1UL << 31U)

/*
 * モジュールストップコントロールレジスタB（MSTPCRB）
 */
#define SYSTEM_MSTPCRB_ADDR			( ( volatile uint32_t  * )0x00080014 )
#define SYSTEM_MSTPCRB_MSTPB0_BIT	( 1UL << 0U )
#define SYSTEM_MSTPCRB_MSTPB1_BIT	( 1UL << 1U )
#define SYSTEM_MSTPCRB_MSTPB2_BIT	( 1UL << 2U )
#define SYSTEM_MSTPCRB_MSTPB4_BIT	( 1UL << 4U )
#define SYSTEM_MSTPCRB_MSTPB8_BIT	( 1UL << 8U )
#define SYSTEM_MSTPCRB_MSTPB15_BIT	( 1UL << 15U )
#define SYSTEM_MSTPCRB_MSTPB16_BIT	( 1UL << 16U )
#define SYSTEM_MSTPCRB_MSTPB17_BIT	( 1UL << 17U )
#define SYSTEM_MSTPCRB_MSTPB18_BIT	( 1UL << 18U )
#define SYSTEM_MSTPCRB_MSTPB19_BIT	( 1UL << 19U )
#define SYSTEM_MSTPCRB_MSTPB20_BIT	( 1UL << 20U )
#define SYSTEM_MSTPCRB_MSTPB21_BIT	( 1UL << 21U )
#define SYSTEM_MSTPCRB_MSTPB22_BIT	( 1UL << 22U )
#define SYSTEM_MSTPCRB_MSTPB23_BIT	( 1UL << 23U )
#define SYSTEM_MSTPCRB_MSTPB24_BIT	( 1UL << 24U )
#define SYSTEM_MSTPCRB_MSTPB25_BIT	( 1UL << 25U )
#define SYSTEM_MSTPCRB_MSTPB26_BIT	( 1UL << 26U )
#define SYSTEM_MSTPCRB_MSTPB27_BIT	( 1UL << 27U )
#define SYSTEM_MSTPCRB_MSTPB28_BIT	( 1UL << 28U )
#define SYSTEM_MSTPCRB_MSTPB29_BIT	( 1UL << 29U )
#define SYSTEM_MSTPCRB_MSTPB30_BIT	( 1UL << 30U )
#define SYSTEM_MSTPCRB_MSTPB31_BIT	( 1UL << 31U )

/*
 * モジュールストップコントロールレジスタC（MSTPCRC）
 */
#define SYSTEM_MSTPCRC_ADDR			( ( volatile uint32_t  * )0x00080018 )
#define SYSTEM_MSTPCRC_MSTPC0_BIT	( 1UL << 0U )
#define SYSTEM_MSTPCRC_MSTPC1_BIT	( 1UL << 1U )
#define SYSTEM_MSTPCRC_MSTPC16_BIT	( 1UL << 16U )
#define SYSTEM_MSTPCRC_MSTPC17_BIT	( 1UL << 17U )
#define SYSTEM_MSTPCRC_MSTPC18_BIT	( 1UL << 18U )
#define SYSTEM_MSTPCRC_MSTPC19_BIT	( 1UL << 19U )
#define SYSTEM_MSTPCRC_MSTPC24_BIT	( 1UL << 24U )
#define SYSTEM_MSTPCRC_MSTPC25_BIT	( 1UL << 25U )
#define SYSTEM_MSTPCRC_MSTPC26_BIT	( 1UL << 26U )
#define SYSTEM_MSTPCRC_MSTPC27_BIT	( 1UL << 27U )

/*
 * モジュールストップコントロールレジスタD（MSTPCRD）
 */
#define SYSTEM_MSTPCRD_ADDR			( ( volatile uint32_t  * )0x0008001C )
#define SYSTEM_MSTPCRD_MSTPD31_BIT	( 1UL << 31U )

/*
 * clock wait control register
 */
#define SYSTEM_MOSCWTR_ADDR         ( ( volatile uint32_t  * )0x000800A2 )
#define SYSTEM_PLLWTCR_ADDR         ( ( volatile uint32_t  * )0x000800A6 )
#define SYSTEM_CLKWAIT_H0   0x0
#define SYSTEM_CLKWAIT_H1   0x1
#define SYSTEM_CLKWAIT_H2   0x2
#define SYSTEM_CLKWAIT_H3   0x3
#define SYSTEM_CLKWAIT_H4   0x4
#define SYSTEM_CLKWAIT_H5   0x5
#define SYSTEM_CLKWAIT_H6   0x6
#define SYSTEM_CLKWAIT_H7   0x7
#define SYSTEM_CLKWAIT_H8   0x8
#define SYSTEM_CLKWAIT_H9   0x9
#define SYSTEM_CLKWAIT_HA   0xA
#define SYSTEM_CLKWAIT_HB   0xB
#define SYSTEM_CLKWAIT_HC   0xC
#define SYSTEM_CLKWAIT_HD   0xD
#define SYSTEM_CLKWAIT_HE   0xE
#define SYSTEM_CLKWAIT_HF   0xF

/*
 * 割り込み要求レジスタ
 */
#define ICU_IR_BASE 0x00087000
#define ICU_IR_BIT				( 1U << 0U )

/*
 * 割り込み要求許可レジスタ
 */
#define ICU_IER_BASE 0x00087202

/* 
 * 割り込み要因プライオリティレジスタi(i=00h～8Fh)の設定
 */
#define ICU_IPR_BASE 0x00087300


#define SET_ICU_IPR(intno, pri_num)  ((*((volatile uint8_t *)(ICU_IPR_BASE | intno))) = pri_num)
/*
 *  DTCERコントロールレジスタ
 */
#define ICU_DTCER_BASE 0x00087100
#define EN_ICU_DTCER_BIT 0x1
#define DIS_ICU_DTCER_BIT 0x0

#ifndef TOPPERS_MACRO_ONLY
#define ENABLE_ICU_DTCER(intno)  (*((volatile uint8_t *)(ICU_IPR_BASE | intno)) = EN_ICU_DTCER_BIT)

#define DISABLE_ICU_DTCER(intno) (*((volatile uint8_t *)(ICU_IPR_BASE | intno)) = DIS_ICU_DTCER_BIT)
#endif

/*
 *  IRQコントロールレジスタ
 */
#define ICU_IRQCR_BASE 0x00087500
#define SET_ICU_IRQCR(intno, sel_edge) (*((volatile uint8_t *)(ICU_IRQCR_BASE | intno)) = sel_edge)

/*
 *  各チャンネルのレジスタ及び設定ビット情報
 */
#define CMT_CMSTR0_ADDR			( ( volatile uint16_t  * )0x00088000 )
#define CMT_CMSTR0_STR0_BIT		( 1U << 0U )
#define CMT_CMSTR0_STR1_BIT		( 1U << 1U )
#define CMT_CMSTR1_ADDR			( ( volatile uint16_t  * )0x00088010 )
#define CMT_CMSTR1_STR2_BIT		( 1U << 0U )
#define CMT_CMSTR1_STR3_BIT		( 1U << 1U )
#define CMT0_CMCR_ADDR			( ( volatile uint16_t  * )0x00088002 )
#define CMT0_CMCR_CKS_BIT		( 3U )
#define CMT0_CMCR_CMIE_BIT		( 1U << 6U )
#define CMT1_CMCR_ADDR			( ( volatile uint16_t  * )0x00088008 )
#define CMT1_CMCR_CKS_BIT		( 3U )
#define CMT1_CMCR_CMIE_BIT		( 1U << 6U )
#define CMT2_CMCR_ADDR			( ( volatile uint16_t  * )0x00088012 )
#define CMT2_CMCR_CKS_BIT		( 3U)
#define CMT2_CMCR_CMIE_BIT		( 1U << 6U )
#define CMT3_CMCR_ADDR			( ( volatile uint16_t  * )0x00088018 )
#define CMT3_CMCR_CKS_BIT		( 3U )
#define CMT3_CMCR_CMIE_BIT		( 1U << 6U )
#define CMT0_CMCNT_ADDR			( ( volatile uint16_t  * )0x00088004 )
#define CMT1_CMCNT_ADDR			( ( volatile uint16_t  * )0x0008800A )
#define CMT2_CMCNT_ADDR			( ( volatile uint16_t  * )0x00088014 )
#define CMT3_CMCNT_ADDR			( ( volatile uint16_t  * )0x0008801A )
#define CMT0_CMCOR_ADDR			( ( volatile uint16_t  * )0x00088006 )
#define CMT1_CMCOR_ADDR			( ( volatile uint16_t  * )0x0008800C )
#define CMT2_CMCOR_ADDR			( ( volatile uint16_t  * )0x00088016 )
#define CMT3_CMCOR_ADDR			( ( volatile uint16_t  * )0x0008801C )

#define SCI0_SMR_ADDR			( ( volatile uint8_t  * )0x0008A000 )
#define SCI0_BRR_ADDR			( ( volatile uint8_t  * )0x0008A001 )
#define SCI0_SCR_ADDR			( ( volatile uint8_t  * )0x0008A002 )
#define SCI0_TDR_ADDR			( ( volatile uint8_t  * )0x0008A003 )
#define SCI0_SSR_ADDR			( ( volatile uint8_t  * )0x0008A004 )
#define SCI0_RDR_ADDR			( ( volatile uint8_t  * )0x0008A005 )
#define SCI0_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A006 )
#define SCI0_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A007 )
#define SCI1_SMR_ADDR			( ( volatile uint8_t  * )0x0008A020 )
#define SCI1_BRR_ADDR			( ( volatile uint8_t  * )0x0008A021 )
#define SCI1_SCR_ADDR			( ( volatile uint8_t  * )0x0008A022 )
#define SCI1_TDR_ADDR			( ( volatile uint8_t  * )0x0008A023 )
#define SCI1_SSR_ADDR			( ( volatile uint8_t  * )0x0008A024 )
#define SCI1_RDR_ADDR			( ( volatile uint8_t  * )0x0008A025 )
#define SCI1_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A026 )
#define SCI1_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A027 )
#define SCI2_SMR_ADDR			( ( volatile uint8_t  * )0x0008A040 )
#define SCI2_BRR_ADDR			( ( volatile uint8_t  * )0x0008A041 )
#define SCI2_SCR_ADDR			( ( volatile uint8_t  * )0x0008A042 )
#define SCI2_TDR_ADDR			( ( volatile uint8_t  * )0x0008A043 )
#define SCI2_SSR_ADDR			( ( volatile uint8_t  * )0x0008A044 )
#define SCI2_RDR_ADDR			( ( volatile uint8_t  * )0x0008A045 )
#define SCI2_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A046 )
#define SCI2_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A047 )
#define SCI3_SMR_ADDR			( ( volatile uint8_t  * )0x0008A060 )
#define SCI3_BRR_ADDR			( ( volatile uint8_t  * )0x0008A061 )
#define SCI3_SCR_ADDR			( ( volatile uint8_t  * )0x0008A062 )
#define SCI3_TDR_ADDR			( ( volatile uint8_t  * )0x0008A063 )
#define SCI3_SSR_ADDR			( ( volatile uint8_t  * )0x0008A064 )
#define SCI3_RDR_ADDR			( ( volatile uint8_t  * )0x0008A065 )
#define SCI3_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A066 )
#define SCI3_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A067 )
#define SCI4_SMR_ADDR			( ( volatile uint8_t  * )0x0008A080 )
#define SCI4_BRR_ADDR			( ( volatile uint8_t  * )0x0008A081 )
#define SCI4_SCR_ADDR			( ( volatile uint8_t  * )0x0008A082 )
#define SCI4_TDR_ADDR			( ( volatile uint8_t  * )0x0008A083 )
#define SCI4_SSR_ADDR			( ( volatile uint8_t  * )0x0008A084 )
#define SCI4_RDR_ADDR			( ( volatile uint8_t  * )0x0008A085 )
#define SCI4_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A086 )
#define SCI4_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A087 )
#define SCI5_SMR_ADDR			( ( volatile uint8_t  * )0x0008A0A0 )
#define SCI5_BRR_ADDR			( ( volatile uint8_t  * )0x0008A0A1 )
#define SCI5_SCR_ADDR			( ( volatile uint8_t  * )0x0008A0A2 )
#define SCI5_TDR_ADDR			( ( volatile uint8_t  * )0x0008A0A3 )
#define SCI5_SSR_ADDR			( ( volatile uint8_t  * )0x0008A0A4 )
#define SCI5_RDR_ADDR			( ( volatile uint8_t  * )0x0008A0A5 )
#define SCI5_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A0A6 )
#define SCI5_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A0A7 )
#define SCI6_SMR_ADDR			( ( volatile uint8_t  * )0x0008A0C0 )
#define SCI6_BRR_ADDR			( ( volatile uint8_t  * )0x0008A0C1 )
#define SCI6_SCR_ADDR			( ( volatile uint8_t  * )0x0008A0C2 )
#define SCI6_TDR_ADDR			( ( volatile uint8_t  * )0x0008A0C3 )
#define SCI6_SSR_ADDR			( ( volatile uint8_t  * )0x0008A0C4 )
#define SCI6_RDR_ADDR			( ( volatile uint8_t  * )0x0008A0C5 )
#define SCI6_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A0C6 )
#define SCI6_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A0C7 )
#define SCI7_SMR_ADDR			( ( volatile uint8_t  * )0x0008A0E0 )
#define SCI7_BRR_ADDR			( ( volatile uint8_t  * )0x0008A0E1 )
#define SCI7_SCR_ADDR			( ( volatile uint8_t  * )0x0008A0E2 )
#define SCI7_TDR_ADDR			( ( volatile uint8_t  * )0x0008A0E3 )
#define SCI7_SSR_ADDR			( ( volatile uint8_t  * )0x0008A0E4 )
#define SCI7_RDR_ADDR			( ( volatile uint8_t  * )0x0008A0E5 )
#define SCI7_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A0E6 )
#define SCI7_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A0E7 )
#define SCI8_SMR_ADDR			( ( volatile uint8_t  * )0x0008A100 )
#define SCI8_BRR_ADDR			( ( volatile uint8_t  * )0x0008A101 )
#define SCI8_SCR_ADDR			( ( volatile uint8_t  * )0x0008A102 )
#define SCI8_TDR_ADDR			( ( volatile uint8_t  * )0x0008A103 )
#define SCI8_SSR_ADDR			( ( volatile uint8_t  * )0x0008A104 )
#define SCI8_RDR_ADDR			( ( volatile uint8_t  * )0x0008A105 )
#define SCI8_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A106 )
#define SCI8_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A107 )
#define SCI9_SMR_ADDR			( ( volatile uint8_t  * )0x0008A120 )
#define SCI9_BRR_ADDR			( ( volatile uint8_t  * )0x0008A121 )
#define SCI9_SCR_ADDR			( ( volatile uint8_t  * )0x0008A122 )
#define SCI9_TDR_ADDR			( ( volatile uint8_t  * )0x0008A123 )
#define SCI9_SSR_ADDR			( ( volatile uint8_t  * )0x0008A124 )
#define SCI9_RDR_ADDR			( ( volatile uint8_t  * )0x0008A125 )
#define SCI9_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A126 )
#define SCI9_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A127 )
#define SCI10_SMR_ADDR			( ( volatile uint8_t  * )0x0008A140 )
#define SCI10_BRR_ADDR			( ( volatile uint8_t  * )0x0008A141 )
#define SCI10_SCR_ADDR			( ( volatile uint8_t  * )0x0008A142 )
#define SCI10_TDR_ADDR			( ( volatile uint8_t  * )0x0008A143 )
#define SCI10_SSR_ADDR			( ( volatile uint8_t  * )0x0008A144 )
#define SCI10_RDR_ADDR			( ( volatile uint8_t  * )0x0008A145 )
#define SCI10_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A146 )
#define SCI10_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A147 )
#define SCI11_SMR_ADDR			( ( volatile uint8_t  * )0x0008A160 )
#define SCI11_BRR_ADDR			( ( volatile uint8_t  * )0x0008A161 )
#define SCI11_SCR_ADDR			( ( volatile uint8_t  * )0x0008A162 )
#define SCI11_TDR_ADDR			( ( volatile uint8_t  * )0x0008A163 )
#define SCI11_SSR_ADDR			( ( volatile uint8_t  * )0x0008A164 )
#define SCI11_RDR_ADDR			( ( volatile uint8_t  * )0x0008A165 )
#define SCI11_SCMR_ADDR			( ( volatile uint8_t  * )0x0008A166 )
#define SCI11_SEMR_ADDR			( ( volatile uint8_t  * )0x0008A167 )
#define SCI_SMR_CKS_BIT			( 3U << 0U )
#define SCI_SMR_MP_BIT	        ( 1U << 2U )
#define SCI_SMR_STOP_BIT		( 1U << 3U )
#define SCI_SMR_PM_BIT			( 1U << 4U )
#define SCI_SMR_PE_BIT			( 1U << 5U )
#define SCI_SMR_CHR_BIT			( 1U << 6U )
#define SCI_SMR_CM_BIT			( 1U << 7U )
#define SCI_SCR_CKE_BIT			( 3U << 0U )
#define SCI_SCR_TEIE_BIT		( 1U << 2U )
#define SCI_SCR_MPIE_BIT		( 1U << 3U )
#define SCI_SCR_RE_BIT			( 1U << 4U )
#define SCI_SCR_TE_BIT			( 1U << 5U )
#define SCI_SCR_RIE_BIT			( 1U << 6U )
#define SCI_SCR_TIE_BIT			( 1U << 7U )
#define SCI_SSR_MPBT_BIT		( 1U << 0U )
#define SCI_SSR_MPB_BIT 		( 1U << 1U )
#define SCI_SSR_TEND_BIT		( 1U << 2U )
#define SCI_SSR_PER_BIT			( 1U << 3U )
#define SCI_SSR_FER_BIT			( 1U << 4U )
#define SCI_SSR_ORER_BIT		( 1U << 5U )
#define SCI_SCMR_SMIF_BIT		( 1U << 0U )
#define SCI_SCMR_SINV_BIT		( 1U << 2U )
#define SCI_SCMR_SDIR_BIT		( 1U << 3U )
#define SCI_SCMR_BCP2_BIT		( 1U << 7U )
#define SCI_SEMR_ACS0_BIT		( 1U << 0U )
#define SCI_SEMR_ABCS_BIT		( 1U << 4U )
#define SCI_SEMR_NFEN_BIT		( 1U << 5U )

/*
 * Multi function Pin Controler configration define
 */
#define MPC_PWPR_ADDR          ( ( volatile uint8_t  * )0x0008C11F )
#define MPC_PWPR_PFSWE_BIT     ( 1U << 6 )
#define MPC_PWPR_B0WI_BIT      ( 1U << 7 )
#define MPC_PWPR_PFSW_CLEAR    0U

#define MPC_P00PFS_ADDR        ( ( volatile uint8_t  * )0x0008C140 )
#define MPC_P01PFS_ADDR        ( ( volatile uint8_t  * )0x0008C141 )
#define MPC_P02PFS_ADDR        ( ( volatile uint8_t  * )0x0008C142 )
#define MPC_P03PFS_ADDR        ( ( volatile uint8_t  * )0x0008C143 )
#define MPC_P05PFS_ADDR        ( ( volatile uint8_t  * )0x0008C145 )
#define MPC_P07PFS_ADDR        ( ( volatile uint8_t  * )0x0008C147 )
#define MPC_P10PFS_ADDR        ( ( volatile uint8_t  * )0x0008C148 )
#define MPC_P11PFS_ADDR        ( ( volatile uint8_t  * )0x0008C149 )
#define MPC_P12PFS_ADDR        ( ( volatile uint8_t  * )0x0008C14A )
#define MPC_P13PFS_ADDR        ( ( volatile uint8_t  * )0x0008C14B )
#define MPC_P14PFS_ADDR        ( ( volatile uint8_t  * )0x0008C14C )
#define MPC_P15PFS_ADDR        ( ( volatile uint8_t  * )0x0008C14D )
#define MPC_P16PFS_ADDR        ( ( volatile uint8_t  * )0x0008C14E )
#define MPC_P17PFS_ADDR        ( ( volatile uint8_t  * )0x0008C14F )
#define MPC_P20PFS_ADDR        ( ( volatile uint8_t  * )0x0008C150 )
#define MPC_P21PFS_ADDR        ( ( volatile uint8_t  * )0x0008C151 )
#define MPC_P22PFS_ADDR        ( ( volatile uint8_t  * )0x0008C152 )
#define MPC_P23PFS_ADDR        ( ( volatile uint8_t  * )0x0008C153 )
#define MPC_P24PFS_ADDR        ( ( volatile uint8_t  * )0x0008C154 )
#define MPC_P25PFS_ADDR        ( ( volatile uint8_t  * )0x0008C155 )
#define MPC_P26PFS_ADDR        ( ( volatile uint8_t  * )0x0008C156 )
#define MPC_P27PFS_ADDR        ( ( volatile uint8_t  * )0x0008C157 )
#define MPC_P30PFS_ADDR        ( ( volatile uint8_t  * )0x0008C158 )
#define MPC_P31PFS_ADDR        ( ( volatile uint8_t  * )0x0008C159 )
#define MPC_P32PFS_ADDR        ( ( volatile uint8_t  * )0x0008C15A )
#define MPC_P33PFS_ADDR        ( ( volatile uint8_t  * )0x0008C15B )
#define MPC_P34PFS_ADDR        ( ( volatile uint8_t  * )0x0008C15C )
#define MPC_P40PFS_ADDR        ( ( volatile uint8_t  * )0x0008C160 )
#define MPC_P41PFS_ADDR        ( ( volatile uint8_t  * )0x0008C161 )
#define MPC_P42PFS_ADDR        ( ( volatile uint8_t  * )0x0008C162 )
#define MPC_P43PFS_ADDR        ( ( volatile uint8_t  * )0x0008C163 )
#define MPC_P44PFS_ADDR        ( ( volatile uint8_t  * )0x0008C164 )
#define MPC_P45PFS_ADDR        ( ( volatile uint8_t  * )0x0008C165 )
#define MPC_P46PFS_ADDR        ( ( volatile uint8_t  * )0x0008C166 )
#define MPC_P47PFS_ADDR        ( ( volatile uint8_t  * )0x0008C167 )
#define MPC_P50PFS_ADDR        ( ( volatile uint8_t  * )0x0008C168 )
#define MPC_P51PFS_ADDR        ( ( volatile uint8_t  * )0x0008C169 )
#define MPC_P52PFS_ADDR        ( ( volatile uint8_t  * )0x0008C16A )
#define MPC_P54PFS_ADDR        ( ( volatile uint8_t  * )0x0008C16C )
#define MPC_P55PFS_ADDR        ( ( volatile uint8_t  * )0x0008C16D )
#define MPC_P56PFS_ADDR        ( ( volatile uint8_t  * )0x0008C16E )
#define MPC_P57PFS_ADDR        ( ( volatile uint8_t  * )0x0008C16F )
#define MPC_P60PFS_ADDR        ( ( volatile uint8_t  * )0x0008C170 )
#define MPC_P61PFS_ADDR        ( ( volatile uint8_t  * )0x0008C171 )
#define MPC_P66PFS_ADDR        ( ( volatile uint8_t  * )0x0008C176 )
#define MPC_P67PFS_ADDR        ( ( volatile uint8_t  * )0x0008C177 )
#define MPC_P70PFS_ADDR        ( ( volatile uint8_t  * )0x0008C178 )
#define MPC_P71PFS_ADDR        ( ( volatile uint8_t  * )0x0008C179 )
#define MPC_P72PFS_ADDR        ( ( volatile uint8_t  * )0x0008C17A )
#define MPC_P73PFS_ADDR        ( ( volatile uint8_t  * )0x0008C17B )
#define MPC_P74PFS_ADDR        ( ( volatile uint8_t  * )0x0008C17C )
#define MPC_P75PFS_ADDR        ( ( volatile uint8_t  * )0x0008C17D )
#define MPC_P76PFS_ADDR        ( ( volatile uint8_t  * )0x0008C17E )
#define MPC_P77PFS_ADDR        ( ( volatile uint8_t  * )0x0008C17F )
#define MPC_P80PFS_ADDR        ( ( volatile uint8_t  * )0x0008C180 )
#define MPC_P81PFS_ADDR        ( ( volatile uint8_t  * )0x0008C181 )
#define MPC_P82PFS_ADDR        ( ( volatile uint8_t  * )0x0008C182 )
#define MPC_P83PFS_ADDR        ( ( volatile uint8_t  * )0x0008C183 )
#define MPC_P86PFS_ADDR        ( ( volatile uint8_t  * )0x0008C186 )
#define MPC_P87PFS_ADDR        ( ( volatile uint8_t  * )0x0008C187 )
#define MPC_P90PFS_ADDR        ( ( volatile uint8_t  * )0x0008C188 )
#define MPC_P91PFS_ADDR        ( ( volatile uint8_t  * )0x0008C189 )
#define MPC_P92PFS_ADDR        ( ( volatile uint8_t  * )0x0008C18A )
#define MPC_P93PFS_ADDR        ( ( volatile uint8_t  * )0x0008C18B )
#define MPC_PA0PFS_ADDR        ( ( volatile uint8_t  * )0x0008C190 )
#define MPC_PA1PFS_ADDR        ( ( volatile uint8_t  * )0x0008C191 )
#define MPC_PA2PFS_ADDR        ( ( volatile uint8_t  * )0x0008C192 )
#define MPC_PA3PFS_ADDR        ( ( volatile uint8_t  * )0x0008C193 )
#define MPC_PA4PFS_ADDR        ( ( volatile uint8_t  * )0x0008C194 )
#define MPC_PA5PFS_ADDR        ( ( volatile uint8_t  * )0x0008C195 )
#define MPC_PA6PFS_ADDR        ( ( volatile uint8_t  * )0x0008C196 )
#define MPC_PA7PFS_ADDR        ( ( volatile uint8_t  * )0x0008C197 )
#define MPC_PB0PFS_ADDR        ( ( volatile uint8_t  * )0x0008C198 )
#define MPC_PB1PFS_ADDR        ( ( volatile uint8_t  * )0x0008C199 )
#define MPC_PB2PFS_ADDR        ( ( volatile uint8_t  * )0x0008C19A )
#define MPC_PB3PFS_ADDR        ( ( volatile uint8_t  * )0x0008C19B )
#define MPC_PB4PFS_ADDR        ( ( volatile uint8_t  * )0x0008C19C )
#define MPC_PB5PFS_ADDR        ( ( volatile uint8_t  * )0x0008C19D )
#define MPC_PB6PFS_ADDR        ( ( volatile uint8_t  * )0x0008C19E )
#define MPC_PB7PFS_ADDR        ( ( volatile uint8_t  * )0x0008C19F )
#define MPC_PC0PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A0 )
#define MPC_PC1PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A1 )
#define MPC_PC2PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A2 )
#define MPC_PC3PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A3 )
#define MPC_PC4PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A4 )
#define MPC_PC5PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A5 )
#define MPC_PC6PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A6 )
#define MPC_PC7PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A7 )
#define MPC_PD0PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A8 )
#define MPC_PD1PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1A9 )
#define MPC_PD2PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1AA )
#define MPC_PD3PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1AB )
#define MPC_PD4PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1AC )
#define MPC_PD5PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1AD )
#define MPC_PD6PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1AE )
#define MPC_PD7PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1BF )
#define MPC_PE0PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B0 )
#define MPC_PE1PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B1 )
#define MPC_PE2PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B2 )
#define MPC_PE3PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B3 )
#define MPC_PE4PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B4 )
#define MPC_PE5PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B5 )
#define MPC_PE6PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B6 )
#define MPC_PE7PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B7 )
#define MPC_PF0PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B8 )
#define MPC_PF1PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1B9 )
#define MPC_PF2PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1BA )
#define MPC_PF5PFS_ADDR        ( ( volatile uint8_t  * )0x0008C1BD )
#define MPC_PFS_PSEL0          0x0
#define MPC_PFS_PSEL1          0x1
#define MPC_PFS_PSEL2          0x2
#define MPC_PFS_PSEL3          0x3
#define MPC_PFS_PSEL4          0x4
#define MPC_PFS_PSEL5          0x5
#define MPC_PFS_PSEL6          0x6
#define MPC_PFS_PSEL7          0x7
#define MPC_PFS_PSEL8          0x8
#define MPC_PFS_PSEL9          0x9
#define MPC_PFS_PSELA          0xA
#define MPC_PFS_PSELB          0xB
#define MPC_PFS_PSELC          0xC
#define MPC_PFS_PSELD          0xD
#define MPC_PFS_PSELE          0xE
#define MPC_PFS_PSELF          0xF
#define MPC_PFS_ISEL           ( 1U << 6 )
#define MPC_PFS_ASEL           ( 1U << 7 )

/*
 *  I/Oポートのレジスタ及び設定ビット情報
 */
#define PORT0_PDR_ADDR			( ( volatile uint8_t  * )0x0008C000 )
#define PORT1_PDR_ADDR			( ( volatile uint8_t  * )0x0008C001 )
#define PORT2_PDR_ADDR			( ( volatile uint8_t  * )0x0008C002 )
#define PORT3_PDR_ADDR			( ( volatile uint8_t  * )0x0008C003 )
#define PORT4_PDR_ADDR			( ( volatile uint8_t  * )0x0008C004 )
#define PORT5_PDR_ADDR			( ( volatile uint8_t  * )0x0008C005 )
#define PORT6_PDR_ADDR			( ( volatile uint8_t  * )0x0008C006 )
#define PORT7_PDR_ADDR			( ( volatile uint8_t  * )0x0008C007 )
#define PORT8_PDR_ADDR			( ( volatile uint8_t  * )0x0008C008 )
#define PORT9_PDR_ADDR			( ( volatile uint8_t  * )0x0008C009 )
#define PORTA_PDR_ADDR			( ( volatile uint8_t  * )0x0008C00A )
#define PORTB_PDR_ADDR			( ( volatile uint8_t  * )0x0008C00B )
#define PORTC_PDR_ADDR			( ( volatile uint8_t  * )0x0008C00C )
#define PORTD_PDR_ADDR			( ( volatile uint8_t  * )0x0008C00D )
#define PORTE_PDR_ADDR			( ( volatile uint8_t  * )0x0008C00E )
#define PORTF_PDR_ADDR			( ( volatile uint8_t  * )0x0008C00F )
#define PORTG_PDR_ADDR			( ( volatile uint8_t  * )0x0008C010 )
#define PORTH_PDR_ADDR			( ( volatile uint8_t  * )0x0008C011 )
#define PORT_PDR_B0_BIT			( 0x01U << 0U )
#define PORT_PDR_B1_BIT			( 0x01U << 1U )
#define PORT_PDR_B2_BIT			( 0x01U << 2U )
#define PORT_PDR_B3_BIT			( 0x01U << 3U )
#define PORT_PDR_B4_BIT			( 0x01U << 4U )
#define PORT_PDR_B5_BIT			( 0x01U << 5U )
#define PORT_PDR_B6_BIT			( 0x01U << 6U )
#define PORT_PDR_B7_BIT			( 0x01U << 7U )
#define PORT0_PODR_ADDR			( ( volatile uint8_t  * )0x0008C020 )
#define PORT1_PODR_ADDR			( ( volatile uint8_t  * )0x0008C021 )
#define PORT2_PODR_ADDR			( ( volatile uint8_t  * )0x0008C022 )
#define PORT3_PODR_ADDR			( ( volatile uint8_t  * )0x0008C023 )
#define PORT4_PODR_ADDR			( ( volatile uint8_t  * )0x0008C024 )
#define PORT5_PODR_ADDR			( ( volatile uint8_t  * )0x0008C025 )
#define PORT6_PODR_ADDR			( ( volatile uint8_t  * )0x0008C026 )
#define PORT7_PODR_ADDR			( ( volatile uint8_t  * )0x0008C027 )
#define PORT8_PODR_ADDR			( ( volatile uint8_t  * )0x0008C028 )
#define PORT9_PODR_ADDR			( ( volatile uint8_t  * )0x0008C029 )
#define PORTA_PODR_ADDR			( ( volatile uint8_t  * )0x0008C02A )
#define PORTB_PODR_ADDR			( ( volatile uint8_t  * )0x0008C02B )
#define PORTC_PODR_ADDR			( ( volatile uint8_t  * )0x0008C02C )
#define PORTD_PODR_ADDR			( ( volatile uint8_t  * )0x0008C02D )
#define PORTE_PODR_ADDR			( ( volatile uint8_t  * )0x0008C02E )
#define PORTF_PODR_ADDR			( ( volatile uint8_t  * )0x0008C02F )
#define PORTG_PODR_ADDR			( ( volatile uint8_t  * )0x0008C030 )
#define PORTH_PODR_ADDR			( ( volatile uint8_t  * )0x0008C031 )
#define PORT_PODR_B0_BIT			( 0x01U << 0U )
#define PORT_PODR_B1_BIT			( 0x01U << 1U )
#define PORT_PODR_B2_BIT			( 0x01U << 2U )
#define PORT_PODR_B3_BIT			( 0x01U << 3U )
#define PORT_PODR_B4_BIT			( 0x01U << 4U )
#define PORT_PODR_B5_BIT			( 0x01U << 5U )
#define PORT_PODR_B6_BIT			( 0x01U << 6U )
#define PORT_PODR_B7_BIT			( 0x01U << 7U )
#define PORT0_PMR_ADDR			( ( volatile uint8_t  * )0x0008C060 )
#define PORT1_PMR_ADDR			( ( volatile uint8_t  * )0x0008C061 )
#define PORT2_PMR_ADDR			( ( volatile uint8_t  * )0x0008C062 )
#define PORT3_PMR_ADDR			( ( volatile uint8_t  * )0x0008C063 )
#define PORT4_PMR_ADDR			( ( volatile uint8_t  * )0x0008C064 )
#define PORT5_PMR_ADDR			( ( volatile uint8_t  * )0x0008C065 )
#define PORT6_PMR_ADDR			( ( volatile uint8_t  * )0x0008C066 )
#define PORT7_PMR_ADDR			( ( volatile uint8_t  * )0x0008C067 )
#define PORT8_PMR_ADDR			( ( volatile uint8_t  * )0x0008C068 )
#define PORT9_PMR_ADDR			( ( volatile uint8_t  * )0x0008C068 )
#define PORTA_PMR_ADDR			( ( volatile uint8_t  * )0x0008C06A )
#define PORTB_PMR_ADDR			( ( volatile uint8_t  * )0x0008C06B )
#define PORTC_PMR_ADDR			( ( volatile uint8_t  * )0x0008C06C )
#define PORTD_PMR_ADDR			( ( volatile uint8_t  * )0x0008C06D )
#define PORTE_PMR_ADDR			( ( volatile uint8_t  * )0x0008C06E )
#define PORTF_PMR_ADDR			( ( volatile uint8_t  * )0x0008C06F )
#define PORTG_PMR_ADDR			( ( volatile uint8_t  * )0x0008C070 )
#define PORTH_PMR_ADDR			( ( volatile uint8_t  * )0x0008C071 )
#define PORT_PMR_B0_BIT			( 0x01U << 0U )
#define PORT_PMR_B1_BIT			( 0x01U << 1U )
#define PORT_PMR_B2_BIT			( 0x01U << 2U )
#define PORT_PMR_B3_BIT			( 0x01U << 3U )
#define PORT_PMR_B4_BIT			( 0x01U << 4U )
#define PORT_PMR_B5_BIT			( 0x01U << 5U )
#define PORT_PMR_B6_BIT			( 0x01U << 6U )
#define PORT_PMR_B7_BIT			( 0x01U << 7U )

/*
 *  UART関連の定義
 *
 *  pdicのrenesas/scic_uart.cで使用する．
 */
/*
 *  シリアルI/Oの個数
 */
#define TNUM_SIOP			( 7 )

#endif	/* TOPPERS_RX610_H */

