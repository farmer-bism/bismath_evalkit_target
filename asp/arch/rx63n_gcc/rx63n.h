/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *  RX63n�Ɉˑ������`
 */
#ifndef TOPPERS_RX63N_H
#define TOPPERS_RX63N_H

#include <sil.h>


/*
 *  CPU��O�n���h���ԍ��̒�`(�Œ�x�N�^�e�[�u��)
 *
 *  �ԍ��͈̔͂�0 - 31
 */
#define INT_PRIVILEGED_INSTRUNCTION		20		/* �������ߗ�O */
#define INT_UNDEF_INSTRUNCTION			23		/* ����`���ߗ�O */
#define INT_FLOATINGPOINT_INSTRUCTION	25		/* ���������_��O */
#define INT_NMI							30		/* �m���}�X�J�u�����荞�� */
#define INT_RESET						31		/* ���Z�b�g */

/*
 *  �����ݔԍ��̒�`(�σx�N�^�e�[�u��)
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
 *  �e���W���[���̃��W�X�^�y�ѐݒ�r�b�g���
 */

/*
 *  Register write protection 
 */ 
#define SYSTEM_PRCR_ADDR ( 0x000803FE )
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
 * ���W���[���X�g�b�v�R���g���[�����W�X�^A�iMSTPCRA�j
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
 * ���W���[���X�g�b�v�R���g���[�����W�X�^B�iMSTPCRB�j
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
 * ���W���[���X�g�b�v�R���g���[�����W�X�^C�iMSTPCRC�j
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
 * ���荞�ݗv�����W�X�^
 */

#define ICU_IR_BASE 0x00087000
#define ICU_IR_BIT				( 1U << 0U )


/*
 * ���荞�ݗv�������W�X�^
 */
#define ICU_IER_BASE 0x00087200


/* 
 * ���荞�ݗv���v���C�I���e�B���W�X�^i(i=00h�`8Fh)�̐ݒ�
 */
#define ICU_IPR00_ADDR			( ( volatile uint8_t  * )0x00087300 ) /* IPR000 */
#define ICU_IPR01_ADDR			( ( volatile uint8_t  * )0x00087301 ) /* IPR001 */
#define ICU_IPR02_ADDR			( ( volatile uint8_t  * )0x00087302 ) /* IPR002 */
#define ICU_IPR03_ADDR			( ( volatile uint8_t  * )0x00087303 ) /* IPR003 */
#define ICU_IPR04_ADDR			( ( volatile uint8_t  * )0x00087304 ) /* IPR004 */
#define ICU_IPR05_ADDR			( ( volatile uint8_t  * )0x00087305 ) /* IPR005 */
#define ICU_IPR06_ADDR			( ( volatile uint8_t  * )0x00087306 ) /* IPR006 */
#define ICU_IPR07_ADDR			( ( volatile uint8_t  * )0x00087307 ) /* IPR007 */
#define ICU_IPR20_ADDR			( ( volatile uint8_t  * )0x00087320 ) /* IPR032 */
#define ICU_IPR21_ADDR			( ( volatile uint8_t  * )0x00087321 ) /* IPR033 */
#define ICU_IPR22_ADDR			( ( volatile uint8_t  * )0x00087322 ) /* IPR034 */
#define ICU_IPR23_ADDR			( ( volatile uint8_t  * )0x00087323 ) /* IPR035 */
#define ICU_IPR24_ADDR			( ( volatile uint8_t  * )0x00087324 ) /* IPR036 */
#define ICU_IPR25_ADDR			( ( volatile uint8_t  * )0x00087325 ) /* IPR037 */
#define ICU_IPR26_ADDR			( ( volatile uint8_t  * )0x00087326 ) /* IPR038 */
#define ICU_IPR27_ADDR			( ( volatile uint8_t  * )0x00087327 ) /* IPR039 */
#define ICU_IPR2A_ADDR			( ( volatile uint8_t  * )0x0008732A ) /* IPR042 */
#define ICU_IPR2D_ADDR			( ( volatile uint8_t  * )0x0008732D ) /* IPR045 */
#define ICU_IPR30_ADDR			( ( volatile uint8_t  * )0x00087330 ) /* IPR048 */
#define ICU_IPR34_ADDR			( ( volatile uint8_t  * )0x00087334 ) /* IPR052 */
#define ICU_IPR38_ADDR			( ( volatile uint8_t  * )0x00087338 ) /* IPR056 */
#define ICU_IPR3E_ADDR			( ( volatile uint8_t  * )0x0008733E ) /* IPR062 */
#define ICU_IPR40_ADDR			( ( volatile uint8_t  * )0x00087340 ) /* IPR064 */
#define ICU_IPR41_ADDR			( ( volatile uint8_t  * )0x00087341 ) /* IPR065 */
#define ICU_IPR42_ADDR			( ( volatile uint8_t  * )0x00087342 ) /* IPR066 */
#define ICU_IPR43_ADDR			( ( volatile uint8_t  * )0x00087343 ) /* IPR067 */
#define ICU_IPR44_ADDR			( ( volatile uint8_t  * )0x00087344 ) /* IPR068 */
#define ICU_IPR45_ADDR			( ( volatile uint8_t  * )0x00087345 ) /* IPR069 */
#define ICU_IPR46_ADDR			( ( volatile uint8_t  * )0x00087346 ) /* IPR070 */
#define ICU_IPR47_ADDR			( ( volatile uint8_t  * )0x00087347 ) /* IPR071 */
#define ICU_IPR48_ADDR			( ( volatile uint8_t  * )0x00087348 ) /* IPR072 */
#define ICU_IPR49_ADDR			( ( volatile uint8_t  * )0x00087349 ) /* IPR073 */
#define ICU_IPR4A_ADDR			( ( volatile uint8_t  * )0x0008734A ) /* IPR074 */
#define ICU_IPR4B_ADDR			( ( volatile uint8_t  * )0x0008734B ) /* IPR075 */
#define ICU_IPR4C_ADDR			( ( volatile uint8_t  * )0x0008734C ) /* IPR076 */
#define ICU_IPR4D_ADDR			( ( volatile uint8_t  * )0x0008734D ) /* IPR077 */
#define ICU_IPR4E_ADDR			( ( volatile uint8_t  * )0x0008734E ) /* IPR078 */
#define ICU_IPR4F_ADDR			( ( volatile uint8_t  * )0x0008734F ) /* IPR079 */
#define ICU_IPR5A_ADDR			( ( volatile uint8_t  * )0x0008735A ) /* IPR090 */
#define ICU_IPR5B_ADDR			( ( volatile uint8_t  * )0x0008735B ) /* IPR091 */
#define ICU_IPR5C_ADDR			( ( volatile uint8_t  * )0x0008735C ) /* IPR092 */
#define ICU_IPR5D_ADDR			( ( volatile uint8_t  * )0x0008735D ) /* IPR093 */
#define ICU_IPR62_ADDR			( ( volatile uint8_t  * )0x00087362 ) /* IPR098 */
#define ICU_IPR66_ADDR			( ( volatile uint8_t  * )0x00087366 ) /* IPR102 */
#define ICU_IPR6A_ADDR			( ( volatile uint8_t  * )0x0008736A ) /* IPR106 */
#define ICU_IPR6B_ADDR			( ( volatile uint8_t  * )0x0008736B ) /* IPR107 */
#define ICU_IPR6C_ADDR			( ( volatile uint8_t  * )0x0008736C ) /* IPR108 */
#define ICU_IPR6D_ADDR			( ( volatile uint8_t  * )0x0008736D ) /* IPR109 */
#define ICU_IPR6E_ADDR			( ( volatile uint8_t  * )0x0008736E ) /* IPR110 */
#define ICU_IPR6F_ADDR			( ( volatile uint8_t  * )0x0008736F ) /* IPR111 */
#define ICU_IPR70_ADDR			( ( volatile uint8_t  * )0x00087370 ) /* IPR112 */
#define ICU_IPR72_ADDR			( ( volatile uint8_t  * )0x00087372 ) /* IPR114 */
#define ICU_IPR7A_ADDR			( ( volatile uint8_t  * )0x0008737A ) /* IPR122 */
#define ICU_IPR7E_ADDR			( ( volatile uint8_t  * )0x0008737E ) /* IPR126 */
#define ICU_IPR82_ADDR			( ( volatile uint8_t  * )0x00087382 ) /* IPR130 */
#define ICU_IPR84_ADDR			( ( volatile uint8_t  * )0x00087384 ) /* IPR132 */
#define ICU_IPR86_ADDR			( ( volatile uint8_t  * )0x00087386 ) /* IPR134 */
#define ICU_IPR8A_ADDR			( ( volatile uint8_t  * )0x0008738A ) /* IPR138 */
#define ICU_IPR8C_ADDR			( ( volatile uint8_t  * )0x0008738C ) /* IPR140 */
#define ICU_IPR8E_ADDR			( ( volatile uint8_t  * )0x0008738E ) /* IPR142 */
#define ICU_IPR92_ADDR			( ( volatile uint8_t  * )0x00087392 ) /* IPR146 */
#define ICU_IPR94_ADDR			( ( volatile uint8_t  * )0x00087394 ) /* IPR148 */
#define ICU_IPR96_ADDR			( ( volatile uint8_t  * )0x00087396 ) /* IPR150 */
#define ICU_IPR98_ADDR			( ( volatile uint8_t  * )0x00087398 ) /* IPR152 */
#define ICU_IPR9C_ADDR			( ( volatile uint8_t  * )0x0008739C ) /* IPR156 */
#define ICU_IPRA0_ADDR			( ( volatile uint8_t  * )0x000873A0 ) /* IPR160 */
#define ICU_IPRA1_ADDR			( ( volatile uint8_t  * )0x000873A1 ) /* IPR161 */
#define ICU_IPRA4_ADDR			( ( volatile uint8_t  * )0x000873A4 ) /* IPR164 */
#define ICU_IPRA6_ADDR			( ( volatile uint8_t  * )0x000873A6 ) /* IPR166 */
#define ICU_IPRAA_ADDR			( ( volatile uint8_t  * )0x000873AA ) /* IPR170 */
#define ICU_IPRAD_ADDR			( ( volatile uint8_t  * )0x000873AD ) /* IPR173 */
#define ICU_IPRB0_ADDR			( ( volatile uint8_t  * )0x000873B0 ) /* IPR176 */
#define ICU_IPRB3_ADDR			( ( volatile uint8_t  * )0x000873B3 ) /* IPR179 */
#define ICU_IPRB6_ADDR			( ( volatile uint8_t  * )0x000873B6 ) /* IPR182 */
#define ICU_IPRB7_ADDR			( ( volatile uint8_t  * )0x000873B7 ) /* IPR183 */
#define ICU_IPRB8_ADDR			( ( volatile uint8_t  * )0x000873B8 ) /* IPR184 */
#define ICU_IPRB9_ADDR			( ( volatile uint8_t  * )0x000873B9 ) /* IPR185 */
#define ICU_IPRBA_ADDR			( ( volatile uint8_t  * )0x000873BA ) /* IPR186 */
#define ICU_IPRBB_ADDR			( ( volatile uint8_t  * )0x000873BB ) /* IPR187 */
#define ICU_IPRBC_ADDR			( ( volatile uint8_t  * )0x000873BC ) /* IPR188 */
#define ICU_IPRBD_ADDR			( ( volatile uint8_t  * )0x000873BD ) /* IPR189 */
#define ICU_IPRBE_ADDR			( ( volatile uint8_t  * )0x000873BE ) /* IPR190 */
#define ICU_IPRBF_ADDR			( ( volatile uint8_t  * )0x000873BF ) /* IPR191 */
#define ICU_IPRC0_ADDR			( ( volatile uint8_t  * )0x000873C0 ) /* IPR192 */
#define ICU_IPRC1_ADDR			( ( volatile uint8_t  * )0x000873C1 ) /* IPR193 */
#define ICU_IPRC2_ADDR			( ( volatile uint8_t  * )0x000873C2 ) /* IPR194 */
#define ICU_IPRC3_ADDR			( ( volatile uint8_t  * )0x000873C3 ) /* IPR195 */
#define ICU_IPRC4_ADDR			( ( volatile uint8_t  * )0x000873C4 ) /* IPR196 */
#define ICU_IPRC5_ADDR			( ( volatile uint8_t  * )0x000873C5 ) /* IPR197 */
#define ICU_IPRC6_ADDR			( ( volatile uint8_t  * )0x000873C6 ) /* IPR198 */
#define ICU_IPRC7_ADDR			( ( volatile uint8_t  * )0x000873C7 ) /* IPR199 */
#define ICU_IPRC8_ADDR			( ( volatile uint8_t  * )0x000873C8 ) /* IPR200 */
#define ICU_IPRC9_ADDR			( ( volatile uint8_t  * )0x000873C9 ) /* IPR201 */
#define ICU_IPRCA_ADDR			( ( volatile uint8_t  * )0x000873CA ) /* IPR202 */
#define ICU_IPRCB_ADDR			( ( volatile uint8_t  * )0x000873CB ) /* IPR203 */
#define ICU_IPRCE_ADDR			( ( volatile uint8_t  * )0x000873CE ) /* IPR206 */
#define ICU_IPRCF_ADDR			( ( volatile uint8_t  * )0x000873CF ) /* IPR207 */
#define ICU_IPRD0_ADDR			( ( volatile uint8_t  * )0x000873D0 ) /* IPR208 */
#define ICU_IPRD1_ADDR			( ( volatile uint8_t  * )0x000873D1 ) /* IPR209 */
#define ICU_IPRD2_ADDR			( ( volatile uint8_t  * )0x000873D2 ) /* IPR210 */
#define ICU_IPRD6_ADDR			( ( volatile uint8_t  * )0x000873D6 ) /* IPR214 */
#define ICU_IPRD9_ADDR			( ( volatile uint8_t  * )0x000873D9 ) /* IPR217 */
#define ICU_IPRDC_ADDR			( ( volatile uint8_t  * )0x000873DC ) /* IPR220 */
#define ICU_IPRDF_ADDR			( ( volatile uint8_t  * )0x000873DF ) /* IPR223 */
#define ICU_IPRE2_ADDR			( ( volatile uint8_t  * )0x000873E2 ) /* IPR226 */
#define ICU_IPRE5_ADDR			( ( volatile uint8_t  * )0x000873E5 ) /* IPR229 */
#define ICU_IPRE8_ADDR			( ( volatile uint8_t  * )0x000873E8 ) /* IPR232 */
#define ICU_IPREB_ADDR			( ( volatile uint8_t  * )0x000873EB ) /* IPR235 */
#define ICU_IPREE_ADDR			( ( volatile uint8_t  * )0x000873EE ) /* IPR238 */
#define ICU_IPRF1_ADDR			( ( volatile uint8_t  * )0x000873F1 ) /* IPR241 */
#define ICU_IPRF4_ADDR			( ( volatile uint8_t  * )0x000873F4 ) /* IPR244 */
#define ICU_IPRF7_ADDR			( ( volatile uint8_t  * )0x000873F7 ) /* IPR247 */
#define ICU_IPRFA_ADDR			( ( volatile uint8_t  * )0x000873FA ) /* IPR250 */
#define ICU_IPRFD_ADDR			( ( volatile uint8_t  * )0x000873FD ) /* IPR253 */
#define ICU_IPR_BIT				( 7U << 0U )


#define SET_ICU_IPR(intno, pri_num)  ((*((volatile uint8_t *)(ICU_IPR_BASE | intno))) = pri_num)

/*
 * DTCER Register
 */
#define ICU_DTCER_BASE 0x00087100
#define EN_ICU_DTCER_BIT 0x1
#define DIS_ICU_DTCER_BIT 0x0

#ifndef TOPPERS_MACRO_ONLY
#define ENABLE_ICU_DTCER(intno)  (*((volatile uint8_t *)(ICU_DTCER_BASE + intno)) = EN_ICU_DTCER_BIT)

#define DISABLE_ICU_DTCER(intno) (*((volatile uint8_t *)(ICU_DTCER_BASE + intno)) = DIS_ICU_DTCER_BIT)
#endif


#define ICU_IRQCR_BASE 0x00087500
#define SET_ICU_IRQCR(intno, sel_edge) (*((volatile uint8_t *)(ICU_IRQCR_BASE | intno)) = sel_edge)

/*
 * DTCa address define
 */

#define DTCA_BASE_ADDR 0x00082400

/*
 *  �e�`�����l���̃��W�X�^�y�ѐݒ�r�b�g���
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
 *  I/O�|�[�g�̃��W�X�^�y�ѐݒ�r�b�g���
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
#define PORTH_PODR_ADDR			( ( volatile uint8_t  * )0x0008C032 )
#define PORT_PODR_B0_BIT			( 0x01U << 0U )
#define PORT_PODR_B1_BIT			( 0x01U << 1U )
#define PORT_PODR_B2_BIT			( 0x01U << 2U )
#define PORT_PODR_B3_BIT			( 0x01U << 3U )
#define PORT_PODR_B4_BIT			( 0x01U << 4U )
#define PORT_PODR_B5_BIT			( 0x01U << 5U )
#define PORT_PODR_B6_BIT			( 0x01U << 6U )
#define PORT_PODR_B7_BIT			( 0x01U << 7U )
#define PORT0_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C040 )
#define PORT1_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C041 )
#define PORT2_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C042 )
#define PORT3_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C043 )
#define PORT4_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C044 )
#define PORT5_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C045 )
#define PORT6_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C046 )
#define PORT7_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C047 )
#define PORT8_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C048 )
#define PORT9_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C049 )
#define PORTA_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C04A )
#define PORTB_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C04B )
#define PORTC_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C04C )
#define PORTD_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C04D )
#define PORTE_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C04E )
#define PORTF_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C04F )
#define PORTG_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C050 )
#define PORTH_PIDR_ADDR			( ( volatile uint8_t  * )0x0008C052 )
#define PORT_PIDR_B0_BIT			( 0x01U << 0U )
#define PORT_PIDR_B1_BIT			( 0x01U << 1U )
#define PORT_PIDR_B2_BIT			( 0x01U << 2U )
#define PORT_PIDR_B3_BIT			( 0x01U << 3U )
#define PORT_PIDR_B4_BIT			( 0x01U << 4U )
#define PORT_PIDR_B5_BIT			( 0x01U << 5U )
#define PORT_PIDR_B6_BIT			( 0x01U << 6U )
#define PORT_PIDR_B7_BIT			( 0x01U << 7U )
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
 *  UART�֘A�̒�`
 *
 *  pdic��rx600/rx610_uart.c�Ŏg�p����D
 */
/*
 *  �V���A��I/O�̌�
 */

#define TNUM_SIOP			( 7 )

#endif	/* TOPPERS_RX63N_H */

