/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2016- by Hisashi Hata, JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
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
 *  Rx64mに依存する定義
 */
#ifndef TOPPERS_RX64M_H
#define TOPPERS_RX64M_H

#include <sil.h>


/*
 *  CPU例外ハンドラ番号の定義(固定ベクタテーブル)
 *
 *  番号の範囲は0 - 31
 */
#define INT_PRIVILEGED_INSTRUNCTION		20		/* 特権命令例外 */
#define INT_ACCESS                      21      /* Access expression */
#define INT_UNDEF_INSTRUNCTION			23		/* 未定義命令例外 */
#define INT_FLOATINGPOINT_INSTRUCTION	25		/* 浮動小数点例外 */
#define INT_NMI							30		/* ノンマスカブル割り込み */
#define INT_RESET						31		/* リセット */

/*
 *  割込み番号の定義(可変ベクタテーブル)
 */
#define INT_BUSERR 16
#define INT_RAMERR 18
#define INT_FCU_FCUERR 21
#define INT_FUC_FRDYI 23
#define INT_ICU_SWINT2 26
#define INT_ICU_SWINT 27
#define INT_CMT0_CMI0 28
#define INT_CMT1_CMI1 29
#define INT_CMTW0_CMWI0 30
#define INT_CMTW1_CMWI1 31
#define INT_USBA_D0FIFO2 32
#define INT_USBA_D1FIFO2 33
#define INT_UBS0_D0FIFO0 34
#define INT_USB0_D1FIFO0 35
#define INT_RSPI0_SPRI0 38
#define INT_RSPI0_SPTI0 39
#define INT_QSPI_SPRI 42
#define INT_QSPI_SPTI 43
#define INT_SDHI_SBFAI 44
#define INT_MMCIF_MBFAI 45
#define INT_SSI0_SSITXI0 46
#define INT_SSI0_SSIRXI0 47
#define INT_SSI1_SSIRTI1 48
#define INT_SRC_IDEI 50
#define INT_SRC_ODFI 51
#define INT_RIIC0_RXI0 52
#define INT_RIIC0_TXI0 53
#define INT_RIIC2_RXI2 54
#define INT_RIIC2_TXI2 55
#define INT_SCI0_RXI0 58
#define INT_SCI0_TXI0 59
#define INT_SCI1_RXI1 60
#define INT_SCI1_TXI1 61
#define INT_SCI2_RXI2 62
#define INT_SCI2_TXI2 63
#define INT_IRQ0 64
#define INT_IRQ1 65
#define INT_IRQ2 66
#define INT_IRQ3 67
#define INT_IRQ4 68
#define INT_IRQ5 69
#define INT_IRQ6 70
#define INT_IRQ7 71
#define INT_IRQ8 72
#define INT_IRQ9 73
#define INT_IRQ10 74
#define INT_IRQ11 75
#define INT_IRQ12 76
#define INT_IRQ13 77
#define INT_IRQ14 78
#define INT_IRQ15 79
#define INT_SCI3_RXI3 80
#define INT_SCI3_TXI3 81
#define INT_SCI4_RXI4 82
#define INT_SCI4_TXI4 83
#define INT_SCI5_RXI5 84
#define INT_SCI5_TXI5 85
#define INT_SCI6_RXI6 86
#define INT_SCI6_TXI6 87
#define INT_LVD1_LVD1 88
#define INT_LVD2_LVD2 89
#define INT_USB0_USBR0 90
#define INT_RTC_ALM 92
#define INT_RTC_PRD 93
#define INT_USBA_UBSR 94
#define INT_IWDT_IWUNI 95
#define INT_WDT_WUNI 96
#define INT_PDC_PCDFI 97
#define INT_SCI7_RXI7 98
#define INT_SCI7_TXI7 99
#define INT_SCIFA8_RXIF8 100
#define INT_SCIFA8_TXIF8 101
#define INT_SCIFA9_RXIF9 102
#define INT_SCIFA9_TXIF9 103
#define INT_SCIFA10_RXIF10 104
#define INT_SCIFA10_TXIF10 105
#define INT_ICU_GROUPBE0 106
#define INT_ICU_GROUPBL0 110
#define INT_ICU_GROUPBL1 111
#define INT_ICU_GROUPAL0 112
#define INT_ICU_GROUPAL1 113
#define INT_SCIFA11_RXIF11 114
#define INT_SCIFA11_TXIF11 115
#define INT_SCI12_RXI12 116
#define INT_SCI12_TXI12 117
#define INT_DMAC_DMAC0I 120
#define INT_DMAC_DMAC1I 121
#define INT_DMAC_DMAC2I 122
#define INT_DMAC_DMAC3I 123
#define INT_DMAC_DMAC74I 124
#define INT_OST_OSTDI 125
#define INT_EXDMAC_EXDMAC0I 126
#define INT_EXDMAC_EXDMAC1I 127
#define INT_PERIB_INTB128 128
#define INT_PERIB_INTB129 129
#define INT_PERIB_INTB130 130
#define INT_PERIB_INTB131 131
#define INT_PERIB_INTB132 132
#define INT_PERIB_INTB133 133
#define INT_PERIB_INTB134 134
#define INT_PERIB_INTB135 135
#define INT_PERIB_INTB136 136
#define INT_PERIB_INTB137 137
#define INT_PERIB_INTB138 138
#define INT_PERIB_INTB139 139
#define INT_PERIB_INTB140 140
#define INT_PERIB_INTB141 141
#define INT_PERIB_INTB142 142
#define INT_PERIB_INTB143 143
#define INT_PERIB_INTB144 144
#define INT_PERIB_INTB145 145
#define INT_PERIB_INTB146 146
#define INT_PERIB_INTB147 147
#define INT_PERIB_INTB148 148
#define INT_PERIB_INTB149 149
#define INT_PERIB_INTB150 150
#define INT_PERIB_INTB151 151
#define INT_PERIB_INTB152 152
#define INT_PERIB_INTB153 153
#define INT_PERIB_INTB154 154
#define INT_PERIB_INTB155 155
#define INT_PERIB_INTB156 156
#define INT_PERIB_INTB157 157
#define INT_PERIB_INTB158 158
#define INT_PERIB_INTB159 159
#define INT_PERIB_INTB160 160
#define INT_PERIB_INTB161 161
#define INT_PERIB_INTB162 162
#define INT_PERIB_INTB163 163
#define INT_PERIB_INTB164 164
#define INT_PERIB_INTB165 165
#define INT_PERIB_INTB166 166
#define INT_PERIB_INTB167 167
#define INT_PERIB_INTB168 168
#define INT_PERIB_INTB169 169
#define INT_PERIB_INTB170 170
#define INT_PERIB_INTB171 171
#define INT_PERIB_INTB172 172
#define INT_PERIB_INTB173 173
#define INT_PERIB_INTB174 174
#define INT_PERIB_INTB175 175
#define INT_PERIB_INTB176 176
#define INT_PERIB_INTB177 177
#define INT_PERIB_INTB178 178
#define INT_PERIB_INTB179 179
#define INT_PERIB_INTB180 180
#define INT_PERIB_INTB181 181
#define INT_PERIB_INTB182 182
#define INT_PERIB_INTB183 183
#define INT_PERIB_INTB184 184
#define INT_PERIB_INTB185 185
#define INT_PERIB_INTB186 186
#define INT_PERIB_INTB187 187
#define INT_PERIB_INTB188 188
#define INT_PERIB_INTB189 189
#define INT_PERIB_INTB190 190
#define INT_PERIB_INTB191 191
#define INT_PERIB_INTB192 192
#define INT_PERIB_INTB193 193
#define INT_PERIB_INTB194 194
#define INT_PERIB_INTB195 195
#define INT_PERIB_INTB196 196
#define INT_PERIB_INTB197 197
#define INT_PERIB_INTB198 198
#define INT_PERIB_INTB199 199
#define INT_PERIB_INTB200 200
#define INT_PERIB_INTB201 201
#define INT_PERIB_INTB202 202
#define INT_PERIB_INTB203 203
#define INT_PERIB_INTB204 204
#define INT_PERIB_INTB205 205
#define INT_PERIB_INTB206 206
#define INT_PERIB_INTB207 207
#define INT_PERIA_INTA208 208
#define INT_PERIA_INTA209 209
#define INT_PERIA_INTA210 210
#define INT_PERIA_INTA211 211
#define INT_PERIA_INTA212 212
#define INT_PERIA_INTA213 213
#define INT_PERIA_INTA214 214
#define INT_PERIA_INTA215 215
#define INT_PERIA_INTA216 216
#define INT_PERIA_INTA217 217
#define INT_PERIA_INTA218 218
#define INT_PERIA_INTA219 219
#define INT_PERIA_INTA220 220
#define INT_PERIA_INTA221 221
#define INT_PERIA_INTA222 222
#define INT_PERIA_INTA223 223
#define INT_PERIA_INTA224 224
#define INT_PERIA_INTA225 225
#define INT_PERIA_INTA226 226
#define INT_PERIA_INTA227 227
#define INT_PERIA_INTA228 228
#define INT_PERIA_INTA229 229
#define INT_PERIA_INTA230 230
#define INT_PERIA_INTA231 231
#define INT_PERIA_INTA232 232
#define INT_PERIA_INTA233 233
#define INT_PERIA_INTA234 234
#define INT_PERIA_INTA235 235
#define INT_PERIA_INTA236 236
#define INT_PERIA_INTA237 237
#define INT_PERIA_INTA238 238
#define INT_PERIA_INTA239 239
#define INT_PERIA_INTA240 240
#define INT_PERIA_INTA241 241
#define INT_PERIA_INTA242 242
#define INT_PERIA_INTA243 243
#define INT_PERIA_INTA244 244
#define INT_PERIA_INTA245 245
#define INT_PERIA_INTA246 246
#define INT_PERIA_INTA247 247
#define INT_PERIA_INTA248 248
#define INT_PERIA_INTA249 249
#define INT_PERIA_INTA250 250
#define INT_PERIA_INTA251 251
#define INT_PERIA_INTA252 252
#define INT_PERIA_INTA253 253
#define INT_PERIA_INTA254 254
#define INT_PERIA_INTA255 255

/*
 * number of the selectable interrupt B
 */
#define ISELB_CMT2_CMI2 1
#define ISELB_CMT3_CMI3 2
#define ISELB_TMR0_CMIA0 3
#define ISELB_TMR0_CMIB0 4
#define ISELB_TMR0_OVI0 5
#define ISELB_TMR1_CMIA1 6
#define ISELB_TMR1_CMIB1 7
#define ISELB_TMR1_OVI1 8
#define ISELB_TMR2_CMIA2 9
#define ISELB_TMR2_CMIB2 10
#define ISELB_TMR2_OVI2 11
#define ISELB_TMR3_CMIA3 12
#define ISELB_TMR3_CMIB3 13
#define ISELB_TMR3_OVI3 14
#define ISELB_TPU0_TGI0A 15
#define ISELB_TPU0_TGI0B 16
#define ISELB_TPU0_TGI0C 17
#define ISELB_TPU0_TGI0D 18
#define ISELB_TPU0_TCI0V 19
#define ISELB_TPU1_TGI1A 20
#define ISELB_TPU1_TGI1B 21
#define ISELB_TPU1_TCI1V 22
#define ISELB_TPU1_TCI1U 23
#define ISELB_TPU2_TGI2A 24
#define ISELB_TPU2_TGI2B 25
#define ISELB_TPU2_TCI2V 26
#define ISELB_TPU2_TCI2U 27
#define ISELB_TPU3_TGI3A 28
#define ISELB_TPU3_TGI3B 29
#define ISELB_TPU3_TGI3C 30
#define ISELB_TPU3_TGI3D 31
#define ISELB_TPU3_TCI3V 32
#define ISELB_TPU4_TGI4A 33
#define ISELB_TPU4_TGI4B 34
#define ISELB_TPU4_TCI4V 35
#define ISELB_TPU4_TCI4U 36
#define ISELB_TPU5_TGI5A 37
#define ISELB_TPU5_TGI5B 38
#define ISELB_TPU5_TCI5V 39
#define ISELB_TPU5_TCI5U 40
#define ISELB_CMTW0_IC0I0 41
#define ISELB_CMTW0_IC1I0 42
#define ISELB_CMTW0_OC0I0 43
#define ISELB_CMTW0_OC1I0 44
#define ISELB_CMTW0_CMTW1 45
#define ISELB_CMTW0_IC1I1 46
#define ISELB_CMTW0_OC0I1 47
#define ISELB_CMTW0_OC1I1 48
#define ISELB_RTC_CUP 49
#define ISELB_CAN0_RXF0 50
#define ISELB_CAN0_TXF0 51
#define ISELB_CAN0_RXM0 52
#define ISELB_CAN0_TXM0 53
#define ISELB_CAN1_RXF1 54
#define ISELB_CAN1_TXF1 55
#define ISELB_CAN1_RXM1 56
#define ISELB_CAN1_TXM1 57
#define ISELB_CAN2_RXF2 58
#define ISELB_CAN2_TXF2 59
#define ISELB_CAN2_RXM2 60
#define ISELB_CAN2_TXM2 61
#define ISELB_USB0_USBI0 62
#define ISELB_S12AD_S12ADI 64
#define ISELB_S12AD_S12GBADI 65
#define ISELB_S12AD1_S12ADI1 68
#define ISELB_S12AD1_S12GBADI1 69
#define ISELB_DES_DESEND 73
#define ISELB_SHA_SHADEND 74
#define ISELB_SHA_SHAEND 75
#define ISELB_RNG_RNGEND 76
#define ISELB_ELC_ELSR18I 79
#define ISELB_ELC_ELSR19I 80
/*
 * number of the selectable interrupt A
 */
#define ISELA_MTU0_TGIA0 1
#define ISELA_MTU0_TGIB0 2
#define ISELA_MTU0_TGIC0 3
#define ISELA_MTU0_TGID0 4
#define ISELA_MTU0_TCIV0 5
#define ISELA_MTU0_TGIE0 6
#define ISELA_MTU0_TGIF0 7
#define ISELA_MTU1_TGIA1 8
#define ISELA_MTU1_TGIB1 9
#define ISELA_MTU1_TCIV1 10
#define ISELA_MTU1_TCIU1 11
#define ISELA_MTU2_TGIA2 12
#define ISELA_MTU2_TGIB2 13
#define ISELA_MTU2_TCIV2 14
#define ISELA_MTU2_TCIU2 15
#define ISELA_MTU3_TGIA3 16
#define ISELA_MTU3_TGIB3 17
#define ISELA_MTU3_TGIC3 18
#define ISELA_MTU3_TGID3 19
#define ISELA_MTU3_TCIV3 20
#define ISELA_MTU4_TGIA4 21
#define ISELA_MTU4_TGIB4 22
#define ISELA_MTU4_TGIC4 23
#define ISELA_MTU4_TGID4 24
#define ISELA_MTU4_TCIV4 25
#define ISELA_MTU5_TGIU5 27
#define ISELA_MTU5_TGIV5 28
#define ISELA_MTU5_TGIW5 29
#define ISELA_MTU6_TGIA6 30
#define ISELA_MTU6_TGIB6 31
#define ISELA_MTU6_TGIC6 32
#define ISELA_MTU6_TGID6 33
#define ISELA_MTU6_TCIV6 34
#define ISELA_MTU7_TGIA7 35
#define ISELA_MTU7_TGIB7 36
#define ISELA_MTU7_TGIC7 37
#define ISELA_MTU7_TGID7 38
#define ISELA_MTU7_TCIV7 39
#define ISELA_MTU8_TGIA8 41
#define ISELA_MTU8_TGIB8 42
#define ISELA_MTU8_TGIC8 43
#define ISELA_MTU8_TGID8 44
#define ISELA_MTU8_TCIV8 45
#define ISELA_GPT0_GTCIA0 47
#define ISELA_GPT0_GTCIB0 48
#define ISELA_GPT0_GTCIC0 49
#define ISELA_GPT0_GTCID0 50
#define ISELA_GPT0_GDTE0 51
#define ISELA_GPT0_GTCIE0 52
#define ISELA_GPT0_GTCIF0 53
#define ISELA_GPT0_GTCIV0 54
#define ISELA_GPT0_GTCIU0 55
#define ISELA_GPT_COMMON_ETGIN 56
#define ISELA_GPT_COMMON_ETGIP 57
#define ISELA_GPT1_GTCIA1 58
#define ISELA_GPT1_GTCIB1 59
#define ISELA_GPT1_GTCIC1 60
#define ISELA_GPT1_GTCID1 61
#define ISELA_GPT1_GDTE1 62
#define ISELA_GPT1_GTCIE1 63
#define ISELA_GPT1_GTCIF1 64
#define ISELA_GPT1_GTCIV1 65
#define ISELA_GPT1_GTCIU1 66
#define ISELA_GPT2_GTCIA2 67
#define ISELA_GPT2_GTCIB2 68
#define ISELA_GPT2_GTCIC2 69
#define ISELA_GPT2_GTCID2 70
#define ISELA_GPT2_GDTE2 71
#define ISELA_GPT2_GTCIE2 72
#define ISELA_GPT2_GTCIF2 73
#define ISELA_GPT2_GTCIV2 74
#define ISELA_GPT2_GTCIU2 75
#define ISELA_GPT3_GTCIA3 76
#define ISELA_GPT3_GTCIB3 77
#define ISELA_GPT3_GTCIC3 78
#define ISELA_GPT3_GTCID3 79
#define ISELA_GPT3_GDTE3 80
#define ISELA_GPT3_GTCIE3 81
#define ISELA_GPT3_GTCIF3 82
#define ISELA_GPT3_GTCIV3 83
#define ISELA_GPT3_GTCIU3 84
#define ISELA_EPTPC_IPLS 86
#define ISELA_AES_AESRDY 88
#define ISELA_AES_AESEND 89

/*
 *  各モジュールのレジスタ及び設定ビット情報
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
#define CKG_SCKCR_PD_DIV01 ( 0UL )
#define CKG_SCKCR_PD_DIV02 ( 1UL )
#define CKG_SCKCR_PD_DIV04 ( 2UL )
#define CKG_SCKCR_PD_DIV08 ( 3UL )
#define CKG_SCKCR_PD_DIV16 ( 4UL )
#define CKG_SCKCR_PD_DIV32 ( 5UL )
#define CKG_SCKCR_PD_DIV64 ( 6UL )
#define CKG_SCKCR_PC_DIV01 ( 0UL << 4 )
#define CKG_SCKCR_PC_DIV02 ( 1UL << 4 )
#define CKG_SCKCR_PC_DIV04 ( 2UL << 4 )
#define CKG_SCKCR_PC_DIV08 ( 3UL << 4 )
#define CKG_SCKCR_PC_DIV16 ( 4UL << 4 )
#define CKG_SCKCR_PC_DIV32 ( 5UL << 4 )
#define CKG_SCKCR_PC_DIV64 ( 6UL << 4 )
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
#define CKG_SCKCR2_UCK_NOT_USE (1UL << 4)
#define CKG_SCKCR2_UCK_DIV2 (1UL << 4)
#define CKG_SCKCR2_UCK_DIV3 (2UL << 4)
#define CKG_SCKCR2_UCK_DIV4 (3UL << 4)
#define CKG_SCKCR2_UCK_DIV5 (4UL << 4)


//CLock Select register
#define CKG_SCKCR3_ADDR ( ( volatile uint16_t *)0x00080026 )
#define CKG_SCKCR3_CKSEL_LOCO ( 0UL << 8 )
#define CKG_SCKCR3_CKSEL_HOCO ( 1UL << 8 )
#define CKG_SCKCR3_CKSEL_MAIN ( 2UL << 8 )
#define CKG_SCKCR3_CKSEL_SUB ( 3UL << 8 )
#define CKG_SCKCR3_CKSEL_PLL ( 4UL << 8 )
//PLL freq setting
#define CKG_PLLCR_ADDR ( ( volatile uint16_t *)0x00080028 )
#define CKG_PLLCR_PLIDIV1 ( 0UL << 0U )
#define CKG_PLLCR_PLIDIV2 ( 1UL << 0U )
#define CKG_PLLCR_PLIDIV3 ( 2UL << 0U )
#define CKG_PLLCR_PLLSRCSEL_MAIN (0U << 4)
#define CKG_PLLCR_PLLSRCSEL_HOCO (1U << 4)
#define CKG_PLLCR_STC10_0 ( 0x13UL << 8U )
#define CKG_PLLCR_STC10_5 ( 0x14UL << 8U )
#define CKG_PLLCR_STC11_0 ( 0x15UL << 8U )
#define CKG_PLLCR_STC11_5 ( 0x16UL << 8U )
#define CKG_PLLCR_STC12_0 ( 0x17UL << 8U )
#define CKG_PLLCR_STC12_5 ( 0x18UL << 8U )
#define CKG_PLLCR_STC13_0 ( 0x19UL << 8U )
#define CKG_PLLCR_STC13_5 ( 0x1AUL << 8U )
#define CKG_PLLCR_STC14_0 ( 0x1BUL << 8U )
#define CKG_PLLCR_STC14_5 ( 0x1CUL << 8U )
#define CKG_PLLCR_STC15_0 ( 0x1DUL << 8U )
#define CKG_PLLCR_STC15_5 ( 0x1EUL << 8U )
#define CKG_PLLCR_STC16_0 ( 0x1FUL << 8U )
#define CKG_PLLCR_STC16_5 ( 0x20UL << 8U )
#define CKG_PLLCR_STC17_0 ( 0x21UL << 8U )
#define CKG_PLLCR_STC17_5 ( 0x22UL << 8U )
#define CKG_PLLCR_STC18_0 ( 0x23UL << 8U )
#define CKG_PLLCR_STC18_5 ( 0x24UL << 8U )
#define CKG_PLLCR_STC19_0 ( 0x25UL << 8U )
#define CKG_PLLCR_STC19_5 ( 0x26UL << 8U )
#define CKG_PLLCR_STC20_0 ( 0x27UL << 8U )
#define CKG_PLLCR_STC20_5 ( 0x28UL << 8U )
#define CKG_PLLCR_STC21_0 ( 0x29UL << 8U )
#define CKG_PLLCR_STC21_5 ( 0x2AUL << 8U )
#define CKG_PLLCR_STC22_0 ( 0x2BUL << 8U )
#define CKG_PLLCR_STC22_5 ( 0x2CUL << 8U )
#define CKG_PLLCR_STC23_0 ( 0x2DUL << 8U )
#define CKG_PLLCR_STC23_5 ( 0x2EUL << 8U )
#define CKG_PLLCR_STC24_0 ( 0x2FUL << 8U )
#define CKG_PLLCR_STC24_5 ( 0x30UL << 8U )
#define CKG_PLLCR_STC25_0 ( 0x31UL << 8U )
#define CKG_PLLCR_STC25_5 ( 0x32UL << 8U )
#define CKG_PLLCR_STC26_0 ( 0x33UL << 8U )
#define CKG_PLLCR_STC26_5 ( 0x34UL << 8U )
#define CKG_PLLCR_STC27_0 ( 0x35UL << 8U )
#define CKG_PLLCR_STC27_5 ( 0x36UL << 8U )
#define CKG_PLLCR_STC28_0 ( 0x37UL << 8U )
#define CKG_PLLCR_STC28_5 ( 0x38UL << 8U )
#define CKG_PLLCR_STC29_0 ( 0x39UL << 8U )
#define CKG_PLLCR_STC29_5 ( 0x3AUL << 8U )
#define CKG_PLLCR_STC30_0 ( 0x3BUL << 8U )
//Clock enable setting
#define CKG_PLLCR2_ADDR ( ( volatile uint16_t *)0x0008002A )
#define CKG_MOSCCR_ADDR ( ( volatile uint8_t *)0x00080032 )
#define CKG_SOSCCR_ADDR ( ( volatile uint8_t *)0x00080033 )
#define CKG_LOSCCR_ADDR ( ( volatile uint8_t *)0x00080034 )
#define CKG_ILOCOCR_ADDR ( ( volatile uint8_t *)0x00080035 )
#define CKG_HOCOCR_ADDR ( ( volatile uint8_t *)0x00080036 )

#define CKG_CLOCK_ENABLE  0UL
#define CKG_CLOCK_DISABLE 1UL

//HOCOCR control
#define CKG_HOCOCR2_ADDR ( ( volatile uint8_t *)0x00080037 )
#define CKG_HOCOCR2_HCFRQ16 (0x0U)
#define CKG_HOCOCR2_HCFRQ18 (0x1U)
#define CKG_HOCOCR2_HCFRQ20 (0x2U)

//OCOVFSR register
#define CKG_OSCOVFSR_ADDR ( ( volatile uint8_t *)0x0008003C )
#define CKG_OSCOVFSR_MOOVF_STOP (0x0U)
#define CKG_OSCOVFSR_MOOVF_RUN (0x1U )
#define CKG_OSCOVFSR_MOOVF_MASK (0x1U )
#define CKG_OSCOVFSR_SOOVF_STOP (0x0U)
#define CKG_OSCOVFSR_SOOVF_RUN (0x2U)
#define CKG_OSCOVFSR_SOOVF_MASK (0x2U)
#define CKG_OSCOVFSR_PLOVF_STOP (0x0U)
#define CKG_OSCOVFSR_PLOVF_RUN (0x4U)
#define CKG_OSCOVFSR_PLOVF_MASK (0x4U)
#define CKG_OSCOVFSR_HCOVF_STOP (0x0U)
#define CKG_OSCOVFSR_HCOVF_RUN (0x8U)
#define CKG_OSCOVFSR_HCOVF_MASK (0x8U)
#define CKG_OSCOVFSR_ILCOVF_STOP (0x0U)
#define CKG_OSCOVFSR_ILCOVF_RUN (0x10U)
#define CKG_OSCOVFSR_ILCOVF_MASK (0x10U)

//OSTDCR register
#define CKG_OSTDCR_ADDR ( ( volatile uint8_t *)0x00080040 )
#define CKG_OSTDCR_OSTDIE_DIS (0x0U)
#define CKG_OSTDCR_OSTDIE_EN (0x1U)
#define CKG_OSTDCR_OSTDE_DIS (0x0U)
#define CKG_OSTDCR_OSTDE_EN (0x80U)

//OSTDSR Register
#define CKG_OSTDSR_ADDR ( ( volatile uint8_t *)0x00080041 )
#define CKG_OSTDSR_OSTDF_RUN (0x0U)
#define CKG_OSTDCR_OSTDF_STOP (0x1U)
#define CKG_OSTDCR_OSTDF_MASK (0x1U)

//MOFCR Register
#define CKG_MOFCR_ADDR ( ( volatile uint8_t *)0x0008C293 )
#define CKG_MOFCR_MOFXIN_FORCE_EN (0x1)
#define CKG_MOFCR_MOFXIN_FREE (0x0)
#define CKG_MOFCR_MODRV2_U24 (0x0)
#define CKG_MOFCR_MODRV2_U20 (0x10)
#define CKG_MOFCR_MODRV2_U16 (0x20)
#define CKG_MOFCR_MODRV2_U8 (0x30)
#define CKG_MOFCR_MOSEL_OSC (0x0)
#define CKG_MOFCR_MOSEL_EXCLK (0x40)

/*
 * モジュールストップコントロールレジスタA（MSTPCRA）
 */

#define SYSTEM_MSTPCRA_ADDR			( ( volatile uint32_t  * )0x00080010 )

#define SYSTEM_MSTPCRA_MSTPA0_CMTW1 ( 1UL << 0U )
#define SYSTEM_MSTPCRA_MSTPA1_CMTW0 ( 1UL << 1U )
#define SYSTEM_MSTPCRA_MSTPA4_TMR3_2 ( 1UL << 4U )
#define SYSTEM_MSTPCRA_MSTPA5_TMR1_0 ( 1UL << 5U )
#define SYSTEM_MSTPCRA_MSTPA7_GPTA   ( 1UL << 7U )
#define SYSTEM_MSTPCRA_MSTPA9_MTU3  ( 1UL << 9U )
#define SYSTEM_MSTPCRA_MSTPA10_PPG1  ( 1UL << 10U )
#define SYSTEM_MSTPCRA_MSTPA11_PPG0  ( 1UL << 11U )
#define SYSTEM_MSTPCRA_MSTPA13_TPU_U0  ( 1UL << 13U )  // TPU0 to TPU5
#define SYSTEM_MSTPCRA_MSTPA14_CMT_U1  ( 1UL << 14U ) //CMT2, CMT3
#define SYSTEM_MSTPCRA_MSTPA15_CMT_U0  ( 1UL << 15U )  //CMT0, CMT1
#define SYSTEM_MSTPCRA_MSTPA16_S12AD_U1  ( 1UL << 16U )
#define SYSTEM_MSTPCRA_MSTPA17_S12AD_U0  ( 1UL << 17U )
#define SYSTEM_MSTPCRA_MSTPA19_12BITDA  ( 1UL << 19U )
#define SYSTEM_MSTPCRA_MSTPA24_MSTOP_A23  ( 1UL << 24U )
#define SYSTEM_MSTPCRA_MSTPA27_MSTOP_A27  ( 1UL << 27U )
#define SYSTEM_MSTPCRA_MSTPA28_DMAC_DTC  ( 1UL << 28U )
#define SYSTEM_MSTPCRA_MSTPA29_EXDMAC  ( 1UL << 29U )
#define SYSTEM_MSTPCRA_ACSE    ( 1UL << 31U)
#define SYSTEM_MSTPCRA_RESERVE    (0x46F4214C)


/*
 * モジュールストップコントロールレジスタB（MSTPCRB）
 */


#define SYSTEM_MSTPCRB_ADDR      ( ( volatile uint32_t  * )0x00080014 )
#define SYSTEM_MSTPCRB_MSTPB0_CAN0  ( 1UL << 0U )
#define SYSTEM_MSTPCRB_MSTPB1_CAN1  ( 1UL << 1U )
#define SYSTEM_MSTPCRB_MSTPB2_CAN2  ( 1UL << 2U )
#define SYSTEM_MSTPCRB_MSTPB4_SCIh  ( 1UL << 4U )
#define SYSTEM_MSTPCRB_MSTPB6_DOC  ( 1UL << 6U )
#define SYSTEM_MSTPCRB_MSTPB8_TEMPS  ( 1UL << 8U )
#define SYSTEM_MSTPCRB_MSTPB9_ELC  ( 1UL << 9U )
#define SYSTEM_MSTPCRB_MSTPB12_USBA  ( 1UL << 12U )
#define SYSTEM_MSTPCRB_MSTPB14_ETH1  ( 1UL << 14U )
#define SYSTEM_MSTPCRB_MSTPB15_ETH0  ( 1UL << 15U )
#define SYSTEM_MSTPCRB_MSTPB17_RSPI0  ( 1UL << 17U )
#define SYSTEM_MSTPCRB_MSTPB19_USB0  ( 1UL << 19U )
#define SYSTEM_MSTPCRB_MSTPB21_RIIC0 ( 1UL << 21U )
#define SYSTEM_MSTPCRB_MSTPB22_PDC ( 1UL << 22U )
#define SYSTEM_MSTPCRB_MSTPB23_CRC  ( 1UL << 23U )
#define SYSTEM_MSTPCRB_MSTPB24_SCI7  ( 1UL << 24U )
#define SYSTEM_MSTPCRB_MSTPB25_SCI6  ( 1UL << 25U )
#define SYSTEM_MSTPCRB_MSTPB26_SCI5  ( 1UL << 26U )
#define SYSTEM_MSTPCRB_MSTPB27_SCI4  ( 1UL << 27U )
#define SYSTEM_MSTPCRB_MSTPB28_SCI3  ( 1UL << 28U )
#define SYSTEM_MSTPCRB_MSTPB29_SCI2  ( 1UL << 29U )
#define SYSTEM_MSTPCRB_MSTPB30_SCI1  ( 1UL << 30U )
#define SYSTEM_MSTPCRB_MSTPB31_SCI0  ( 1UL << 31U )
#define SYSTEM_MSTPCRB_RESERVE    (0x00152CA8)

/*
 * モジュールストップコントロールレジスタC（MSTPCRC）
 */

#define SYSTEM_MSTPCRC_ADDR      ( ( volatile uint32_t  * )0x00080018 )
#define SYSTEM_MSTPCRC_MSTPC0_RAM0  ( 1UL << 0U )
#define SYSTEM_MSTPCRC_MSTPC6_ECCRAM  ( 1UL << 6U )
#define SYSTEM_MSTPCRC_MSTPC7_STANDBY_RAM  ( 1UL << 7U )
#define SYSTEM_MSTPCRC_MSTPC17_RIIC2  ( 1UL << 17U )
#define SYSTEM_MSTPCRC_MSTPC19_CAC  ( 1UL << 19U )
#define SYSTEM_MSTPCRC_MSTPC23_QSPI  ( 1UL << 23U )
#define SYSTEM_MSTPCRC_MSTPC24_SCIF11  ( 1UL << 24U )
#define SYSTEM_MSTPCRC_MSTPC25_SCIF10  ( 1UL << 25U )
#define SYSTEM_MSTPCRC_MSTPC26_SCIF9  ( 1UL << 26U )
#define SYSTEM_MSTPCRC_MSTPC27_SCIF8  ( 1UL << 27U )
#define SYSTEM_MSTPCRC_RESERVE    (0xF0750000)


#define SYSTEM_MSTPCRD_ADDR      ( ( volatile uint32_t  * )0x0008001C )
#define SYSTEM_MSTPCRD_MSTPD31_BIT  ( 1UL << 31U )

/*
 * clock wait control register
 */
#define SYSTEM_MOSCWTCR_ADDR         ( ( volatile uint32_t  * )0x000800A2 )
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
#define ICU_IR_BIT        ( 1U << 0U )


/*
 * 割り込み要求許可レジスタ
 */
#define ICU_IER_BASE 0x00087200


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
 *  各チャンネルのレジスタ及び設定ビット情報
 */

#define CMT_CMSTR0_ADDR      ( ( volatile uint16_t  * )0x00088000 )
#define CMT_CMSTR0_STR0_BIT    ( 1U << 0U )
#define CMT_CMSTR0_STR1_BIT    ( 1U << 1U )
#define CMT_CMSTR1_ADDR      ( ( volatile uint16_t  * )0x00088010 )
#define CMT_CMSTR1_STR2_BIT    ( 1U << 0U )
#define CMT_CMSTR1_STR3_BIT    ( 1U << 1U )
#define CMT0_CMCR_ADDR      ( ( volatile uint16_t  * )0x00088002 )
#define CMT0_CMCR_CKS_BIT    ( 3U )
#define CMT0_CMCR_CMIE_BIT    ( 1U << 6U )
#define CMT1_CMCR_ADDR      ( ( volatile uint16_t  * )0x00088008 )
#define CMT1_CMCR_CKS_BIT    ( 3U )
#define CMT1_CMCR_CMIE_BIT    ( 1U << 6U )
#define CMT2_CMCR_ADDR      ( ( volatile uint16_t  * )0x00088012 )
#define CMT2_CMCR_CKS_BIT    ( 3U)
#define CMT2_CMCR_CMIE_BIT    ( 1U << 6U )
#define CMT3_CMCR_ADDR      ( ( volatile uint16_t  * )0x00088018 )
#define CMT3_CMCR_CKS_BIT    ( 3U )
#define CMT3_CMCR_CMIE_BIT    ( 1U << 6U )
#define CMT0_CMCNT_ADDR      ( ( volatile uint16_t  * )0x00088004 )
#define CMT1_CMCNT_ADDR      ( ( volatile uint16_t  * )0x0008800A )
#define CMT2_CMCNT_ADDR      ( ( volatile uint16_t  * )0x00088014 )
#define CMT3_CMCNT_ADDR      ( ( volatile uint16_t  * )0x0008801A )
#define CMT0_CMCOR_ADDR      ( ( volatile uint16_t  * )0x00088006 )
#define CMT1_CMCOR_ADDR      ( ( volatile uint16_t  * )0x0008800C )
#define CMT2_CMCOR_ADDR      ( ( volatile uint16_t  * )0x00088016 )
#define CMT3_CMCOR_ADDR      ( ( volatile uint16_t  * )0x0008801C )

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
#define PORT0_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C000 )
#define PORT1_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C001 )
#define PORT2_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C002 )
#define PORT3_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C003 )
#define PORT4_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C004 )
#define PORT5_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C005 )
#define PORT6_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C006 )
#define PORT7_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C007 )
#define PORT8_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C008 )
#define PORT9_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C009 )
#define PORTA_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C00A )
#define PORTB_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C00B )
#define PORTC_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C00C )
#define PORTD_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C00D )
#define PORTE_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C00E )
#define PORTF_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C00F )
#define PORTG_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C010 )
#define PORTJ_PDR_ADDR      ( ( volatile uint8_t  * )0x0008C012 )
#define PORT_PDR_B0_BIT      ( 0x01U << 0U )
#define PORT_PDR_B1_BIT      ( 0x01U << 1U )
#define PORT_PDR_B2_BIT      ( 0x01U << 2U )
#define PORT_PDR_B3_BIT      ( 0x01U << 3U )
#define PORT_PDR_B4_BIT      ( 0x01U << 4U )
#define PORT_PDR_B5_BIT      ( 0x01U << 5U )
#define PORT_PDR_B6_BIT      ( 0x01U << 6U )
#define PORT_PDR_B7_BIT      ( 0x01U << 7U )
#define PORT0_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C020 )
#define PORT1_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C021 )
#define PORT2_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C022 )
#define PORT3_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C023 )
#define PORT4_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C024 )
#define PORT5_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C025 )
#define PORT6_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C026 )
#define PORT7_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C027 )
#define PORT8_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C028 )
#define PORT9_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C029 )
#define PORTA_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C02A )
#define PORTB_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C02B )
#define PORTC_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C02C )
#define PORTD_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C02D )
#define PORTE_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C02E )
#define PORTF_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C02F )
#define PORTG_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C030 )
#define PORTJ_PODR_ADDR      ( ( volatile uint8_t  * )0x0008C032 )
#define PORT_PODR_B0_BIT      ( 0x01U << 0U )
#define PORT_PODR_B1_BIT      ( 0x01U << 1U )
#define PORT_PODR_B2_BIT      ( 0x01U << 2U )
#define PORT_PODR_B3_BIT      ( 0x01U << 3U )
#define PORT_PODR_B4_BIT      ( 0x01U << 4U )
#define PORT_PODR_B5_BIT      ( 0x01U << 5U )
#define PORT_PODR_B6_BIT      ( 0x01U << 6U )
#define PORT_PODR_B7_BIT      ( 0x01U << 7U )
#define PORT0_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C040 )
#define PORT1_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C041 )
#define PORT2_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C042 )
#define PORT3_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C043 )
#define PORT4_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C044 )
#define PORT5_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C045 )
#define PORT6_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C046 )
#define PORT7_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C047 )
#define PORT8_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C048 )
#define PORT9_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C049 )
#define PORTA_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C04A )
#define PORTB_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C04B )
#define PORTC_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C04C )
#define PORTD_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C04D )
#define PORTE_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C04E )
#define PORTF_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C04F )
#define PORTG_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C050 )
#define PORTJ_PIDR_ADDR      ( ( volatile uint8_t  * )0x0008C052 )
#define PORT_PIDR_B0_BIT      ( 0x01U << 0U )
#define PORT_PIDR_B1_BIT      ( 0x01U << 1U )
#define PORT_PIDR_B2_BIT      ( 0x01U << 2U )
#define PORT_PIDR_B3_BIT      ( 0x01U << 3U )
#define PORT_PIDR_B4_BIT      ( 0x01U << 4U )
#define PORT_PIDR_B5_BIT      ( 0x01U << 5U )
#define PORT_PIDR_B6_BIT      ( 0x01U << 6U )
#define PORT_PIDR_B7_BIT      ( 0x01U << 7U )
#define PORT0_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C060 )
#define PORT1_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C061 )
#define PORT2_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C062 )
#define PORT3_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C063 )
#define PORT4_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C064 )
#define PORT5_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C065 )
#define PORT6_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C066 )
#define PORT7_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C067 )
#define PORT8_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C068 )
#define PORT9_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C068 )
#define PORTA_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C06A )
#define PORTB_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C06B )
#define PORTC_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C06C )
#define PORTD_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C06D )
#define PORTE_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C06E )
#define PORTF_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C06F )
#define PORTG_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C070 )
#define PORTJ_PMR_ADDR      ( ( volatile uint8_t  * )0x0008C072 )
#define PORT_PMR_B0_BIT      ( 0x01U << 0U )
#define PORT_PMR_B1_BIT      ( 0x01U << 1U )
#define PORT_PMR_B2_BIT      ( 0x01U << 2U )
#define PORT_PMR_B3_BIT      ( 0x01U << 3U )
#define PORT_PMR_B4_BIT      ( 0x01U << 4U )
#define PORT_PMR_B5_BIT      ( 0x01U << 5U )
#define PORT_PMR_B6_BIT      ( 0x01U << 6U )
#define PORT_PMR_B7_BIT      ( 0x01U << 7U )

/*
 *  Device関連の定義
 *
 */
/*
 *  シリアルI/Oの個数
 */
//SCI base address
#define SCI0_BASE_ADDR 0x0008A000
#define SCI1_BASE_ADDR 0x0008A020
#define SCI2_BASE_ADDR 0x0008A040
#define SCI3_BASE_ADDR 0x0008A060
#define SCI4_BASE_ADDR 0x0008A080
#define SCI5_BASE_ADDR 0x0008A0A0
#define SCI6_BASE_ADDR 0x0008A0C0
#define SCI7_BASE_ADDR 0x0008A0E0
#define SCI12_BASE_ADDR 0x0008B300

#define TNUM_SIOP      ( 7 )

#endif  /* TOPPERS_RX64M_H */

