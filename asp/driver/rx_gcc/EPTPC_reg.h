/*
 * Copyright (c) 2017- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#ifndef RX_GCC_DRIVER_EPTPC_REG_H
#define RX_GCC_DRIVER_EPTPC_REG_H

#define EPTPC_BASEADDR 0x000C4000
#define EPTPC_MIESR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x0))
#define EPTPC_MIESR_CYC5 ((uint32_t)(0x1 << 21))
#define EPTPC_MIESR_CYC4 ((uint32_t)(0x1 << 20))
#define EPTPC_MIESR_CYC3 ((uint32_t)(0x1 << 19))
#define EPTPC_MIESR_CYC2 ((uint32_t)(0x1 << 18))
#define EPTPC_MIESR_CYC1 ((uint32_t)(0x1 << 17))
#define EPTPC_MIESR_CYC0 ((uint32_t)(0x1 << 16))
#define EPTPC_MIESR_PRC ((uint32_t)(0x1 << 3))
#define EPTPC_MIESR_SY1 ((uint32_t)(0x1 << 2))
#define EPTPC_MIESR_SY0 ((uint32_t)(0x1 << 1))
#define EPTPC_MIESR_ST ((uint32_t)0x1)
#define EPTPC_MIEIPR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x4))
#define EPTPC_MIEIPR_CYC5 ((uint32_t)(0x1 << 21))
#define EPTPC_MIEIPR_CYC4 ((uint32_t)(0x1 << 20))
#define EPTPC_MIEIPR_CYC3 ((uint32_t)(0x1 << 19))
#define EPTPC_MIEIPR_CYC2 ((uint32_t)(0x1 << 18))
#define EPTPC_MIEIPR_CYC1 ((uint32_t)(0x1 << 17))
#define EPTPC_MIEIPR_CYC0 ((uint32_t)(0x1 << 16))
#define EPTPC_MIEIPR_PR ((uint32_t)(0x1 << 3))
#define EPTPC_MIEIPR_SY1 ((uint32_t)(0x1 << 2))
#define EPTPC_MIEIPR_SY0 ((uint32_t)(0x1 << 1))
#define EPTPC_MIEIPR_ST ((uint32_t)0x1)
#define EPTPC_ELIPPR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x10))
#define EPTPC_ELIPPR_PLSN ((uint32_t)(0x1 << 24))
#define EPTPC_ELIPPR_PLSP ((uint32_t)(0x1 << 16))
#define EPTPC_ELIPPR_CYCN5 ((uint32_t)(0x1 << 13))
#define EPTPC_ELIPPR_CYCN4 ((uint32_t)(0x1 << 12))
#define EPTPC_ELIPPR_CYCN3 ((uint32_t)(0x1 << 11))
#define EPTPC_ELIPPR_CYCN2 ((uint32_t)(0x1 << 10))
#define EPTPC_ELIPPR_CYCN1 ((uint32_t)(0x1 << 9))
#define EPTPC_ELIPPR_CYCN0 ((uint32_t)(0x1 << 8))
#define EPTPC_ELIPPR_CYCP5 ((uint32_t)(0x1 << 5))
#define EPTPC_ELIPPR_CYCP4 ((uint32_t)(0x1 << 4))
#define EPTPC_ELIPPR_CYCP3 ((uint32_t)(0x1 << 3))
#define EPTPC_ELIPPR_CYCP2 ((uint32_t)(0x1 << 2))
#define EPTPC_ELIPPR_CYCP1 ((uint32_t)(0x1 << 1))
#define EPTPC_ELIPPR_CYCP0 ((uint32_t)0x1)
#define EPTPC_ELIPACR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x14))
#define EPTPC_ELIPACR_PLSN ((uint32_t)(0x1 << 24))
#define EPTPC_ELIPACR_PLSP ((uint32_t)(0x1 << 16))
#define EPTPC_ELIPACR_CYCN5 ((uint32_t)(0x1 << 13))
#define EPTPC_ELIPACR_CYCN4 ((uint32_t)(0x1 << 12))
#define EPTPC_ELIPACR_CYCN3 ((uint32_t)(0x1 << 11))
#define EPTPC_ELIPACR_CYCN2 ((uint32_t)(0x1 << 10))
#define EPTPC_ELIPACR_CYCN1 ((uint32_t)(0x1 << 9))
#define EPTPC_ELIPACR_CYCN0 ((uint32_t)(0x1 << 8))
#define EPTPC_ELIPACR_CYCP5 ((uint32_t)(0x1 << 5))
#define EPTPC_ELIPACR_CYCP4 ((uint32_t)(0x1 << 4))
#define EPTPC_ELIPACR_CYCP3 ((uint32_t)(0x1 << 3))
#define EPTPC_ELIPACR_CYCP2 ((uint32_t)(0x1 << 2))
#define EPTPC_ELIPACR_CYCP1 ((uint32_t)(0x1 << 1))
#define EPTPC_ELIPACR_CYCP0 ((uint32_t)0x1)
#define EPTPC_STSR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x40))
#define EPTPC_STSR_W10D ((uint32_t)(0x1 << 4))
#define EPTPC_STSR_SYNTOUT ((uint32_t)(0x1 << 3))
#define EPTPC_STSR_SYNCOUT ((uint32_t)(0x1 << 1))
#define EPTPC_STSR_SYNC ((uint32_t)0x1)
#define EPTPC_STIPR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x44))
#define EPTPC_STIPR_W10D ((uint32_t)(0x1 << 4))
#define EPTPC_STIPR_SYNTOUT ((uint32_t)(0x1 << 3))
#define EPTPC_STIPR_SYNCOUT ((uint32_t)(0x1 << 1))
#define EPTPC_STIPR_SYNC ((uint32_t)0x1)
#define EPTPC_STCFR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x50))
#define EPTPC_STCFR_STCF_20M ((uint32_t)0x0)
#define EPTPC_STCFR_STCF_25M ((uint32_t)0x1)
#define EPTPC_STCFR_STCF_50M ((uint32_t)0x2)
#define EPTPC_STCFR_STCF_100M ((uint32_t)0x3)
#define EPTPC_STMR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x54))
#define EPTPC_STMR_ALEN1 ((uint32_t)(0x1 << 29))
#define EPTPC_STMR_ALEN0 ((uint32_t)(0x1 << 28))
#define EPTPC_STMR_DVTH ((uint32_t)(0x1 << 20))
#define EPTPC_STMR_SYTH ((uint32_t)(0x1 << 16))
#define EPTPC_STMR_W10S ((uint32_t)(0x1 << 15))
#define EPTPC_STMR_CMOD ((uint32_t)(0x1 << 13))
#define EPTPC_STMR_WINT_MASK ((uint32_t)0xff)
#define EPTPC_SYNTOR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x58))
#define EPTPC_IPTSELR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x60))
#define EPTPC_IPTSELR_IPTSEL5 ((uint32_t)(0x1 << 5))
#define EPTPC_IPTSELR_IPTSEL4 ((uint32_t)(0x1 << 4))
#define EPTPC_IPTSELR_IPTSEL3 ((uint32_t)(0x1 << 3))
#define EPTPC_IPTSELR_IPTSEL2 ((uint32_t)(0x1 << 2))
#define EPTPC_IPTSELR_IPTSEL1 ((uint32_t)(0x1 << 1))
#define EPTPC_IPTSELR_IPTSEL0 ((uint32_t)0x1)
#define EPTPC_MITSELR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x64))
#define EPTPC_MITSELR_MINTEN5 ((uint32_t)(0x1 << 5))
#define EPTPC_MITSELR_MINTE4 ((uint32_t)(0x1 << 4))
#define EPTPC_MITSELR_MINTE3 ((uint32_t)(0x1 << 3))
#define EPTPC_MITSELR_MINTE2 ((uint32_t)(0x1 << 2))
#define EPTPC_MITSELR_MINTE1 ((uint32_t)(0x1 << 1))
#define EPTPC_MITSELR_MNTE0 ((uint32_t)0x1)
#define EPTPC_ELTSELR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x68))
#define EPTPC_ELTSELR_ELTDIS5 ((uint32_t)(0x1 << 5))
#define EPTPC_ELTSELR_ELTDIS4 ((uint32_t)(0x1 << 4))
#define EPTPC_ELTSELR_ELTDIS3 ((uint32_t)(0x1 << 3))
#define EPTPC_ELTSELR_ELTDIS2 ((uint32_t)(0x1 << 2))
#define EPTPC_ELTSELR_ELTDIS1 ((uint32_t)(0x1 << 1))
#define EPTPC_ELTSELR_ELTDIS0 ((uint32_t)0x1)
#define EPTPC_STCHSELR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x6c))
#define EPTPC_STCHSELR_SYSEL ((uint32_t)0x1)
#define EPTPC_SYNSTARTR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x80))
#define EPTPC_SYNSTARTR_STR ((uint32_t)0x1)
#define EPTPC_LCIVLDR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x84))
#define EPTPC_LCIVLDR_LOAD ((uint32_t)0x1)
#define EPTPC_SYNTDARU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x90))
#define EPTPC_SYNTDARL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x94))
#define EPTPC_SYNTDBRU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x98))
#define EPTPC_SYNTDBRL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x9c))
#define EPTPC_LCIVRU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0xb0))
#define EPTPC_LCIVRM_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0xb4))
#define EPTPC_LCIVRL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0xb8))
#define EPTPC_GETW10R_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x124))
#define EPTPC_GETW10R_GW10 ((uint32_t)0x1)
#define EPTPC_PLIMITRU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x128))
#define EPTPC_PLIMITRM_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x12c))
#define EPTPC_PLIMTRL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x130))
#define EPTPC_MLIMITRU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x134))
#define EPTPC_MLIMITRM_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x138))
#define EPTPC_MLIMITRL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x13c))
#define EPTPC_GETINFOR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x140))
#define EPTPC_GETINFOR_INFO ((uint32_t)0x1)
#define EPTPC_LCCVRU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x170))
#define EPTPC_LCCVRM_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x174))
#define EPTPC_LCCVRL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x178))
#define EPTPC_PW10VRU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x210))
#define EPTPC_PW10VRM_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x214))
#define EPTPC_PW10VRL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x218))
#define EPTPC_MW10RU_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x2d0))
#define EPTPC_MW10RM_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x2d4))
#define EPTPC_MW10RL_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x2d8))
#define EPTPC_TMSTTRU0_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x300))
#define EPTPC_TMSTTRL0_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x304))
#define EPTPC_TMSTTRU1_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x310))
#define EPTPC_TMSTTRL1_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x314))
#define EPTPC_TMSTTRU2_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x320))
#define EPTPC_TMSTTRL2_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x324))
#define EPTPC_TMSTTRU3_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x330))
#define EPTPC_TMSTTRL3_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x334))
#define EPTPC_TMSTTRU4_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x340))
#define EPTPC_TMSTTRL4_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x344))
#define EPTPC_TMSTTRU5_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x50))
#define EPTPC_TMSTTRL5_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x54))
#define EPTPC_TMCYCR0_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x308))
#define EPTPC_TMCYCR1_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x318))
#define EPTPC_TMCYCR2_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x328))
#define EPTPC_TMCYCR3_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x338))
#define EPTPC_TMCYCR4_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x348))
#define EPTPC_TMCYCR5_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x358))
#define EPTPC_TMPLSR0_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x30c))
#define EPTPC_TMPLSR1_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x31c))
#define EPTPC_TMPLSR2_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x32c))
#define EPTPC_TMPLSR3_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x33c))
#define EPTPC_TMPLSR4_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x34c))
#define EPTPC_TMPLSR5_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x35c))
#define EPTPC_TMSTARTR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x37c))
#define EPTPC_TMSTARTR_EN5 ((uint32_t)(0x1 << 5))
#define EPTPC_TMSTARTR_EN4 ((uint32_t)(0x1 << 4))
#define EPTPC_TMSTARTR_EN3 ((uint32_t)(0x1 << 3))
#define EPTPC_TMSTARTR_EN2 ((uint32_t)(0x1 << 2))
#define EPTPC_TMSTARTR_EN1 ((uint32_t)(0x1 << 1))
#define EPTPC_TMSTARTR_EN0 ((uint32_t)0x1)
#define EPTPC_PRSR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x400))
#define EPTPC_PRSR_URE1 ((uint32_t)(0x1 << 29))
#define EPTPC_PRSR_URE0 ((uint32_t)(0x1 << 28))
#define EPTPC_PRSR_MACE ((uint32_t)(0x1 << 8))
#define EPTPC_PRSR_OVRE3 ((uint32_t)(0x1 << 3))
#define EPTPC_PRSR_OVRE2 ((uint32_t)(0x1 << 2))
#define EPTPC_PRSR_OVRE1 ((uint32_t)(0x1 << 1))
#define EPTPC_PRSR_OVRE0 ((uint32_t)0x1)
#define EPTPC_PRIPR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x404))
#define EPTPC_PRIPR_URE1 ((uint32_t)(0x1 << 29))
#define EPTPC_PRIPR_URE0 ((uint32_t)(0x1 << 28))
#define EPTPC_PRIPR_MACE ((uint32_t)(0x1 << 8))
#define EPTPC_PRIPR_OVRE3 ((uint32_t)(0x1 << 3))
#define EPTPC_PRIPR_OVRE2 ((uint32_t)(0x1 << 2))
#define EPTPC_PRIPR_OVRE1 ((uint32_t)(0x1 << 1))
#define EPTPC_PRIPR_OVRE0 ((uint32_t)0x1)
#define EPTPC_PRMACRU0_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x410))
#define EPTPC_PRMACRL0_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x414))
#define EPTPC_PRMACRU1_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x418))
#define EPTPC_PRMACRL1_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x41c))
#define EPTPC_TRNDISR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x420))
#define EPTPC_TRNDISR_TDIS_BOTH ((uint32_t)0x1)
#define EPTPC_TRNDISR_TDIS_ETH0 ((uint32_t)0x1)
#define EPTPC_TRNDISR_TDIS_ETH1 ((uint32_t)0x2)
#define EPTPC_TRNMR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x430))
#define EPTPC_TRNMR_FWD1 ((uint32_t)(0x1 << 9))
#define EPTPC_TRNMR_FWD0 ((uint32_t)(0x1 << 8))
#define EPTPC_TRNMR_MOD ((uint32_t)0x1)
#define EPTPC_TRNCTTDR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0x434))
#define EPTPC_TRNCTTDR_THVAL_MASK ((uint32_t)0x7ff)
#define EPTPC_PTRSTR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0xc0500))
#define EPTPC_PTRSTR_RESET ((uint32_t)0x1)
#define EPTPC_STCSELR_ADDR ((volatile uint32_t*)(EPTPC_BASEADDR + 0xc0504))
#define EPTPC_STCSELR_SCLKSEL_PCLKA_DIV_1_6 ((uint32_t)(0x0 << 8))
#define EPTPC_STCSELR_SCLKSEL_REF50CK0 ((uint32_t)(0x2 << 8))
#define EPTPC_STCSELR_SCLKSEL_REF50CK1 ((uint32_t)(0x3 << 8))
#define EPTPC_STCSELR_SCLKDIV_DIV1 ((uint32_t)0x1)
#define EPTPC_STCSELR_SCLKDIV_DIV2 ((uint32_t)0x2)
#define EPTPC_STCSELR_SCLKDIV_DIV3 ((uint32_t)0x3)
#define EPTPC_STCSELR_SCLKDIV_DIV4 ((uint32_t)0x4)
#define EPTPC_STCSELR_SCLKDIV_DIV5 ((uint32_t)0x5)
#define EPTPC_STCSELR_SCLKDIV_DIV6 ((uint32_t)0x6)

#define EPTPC_PORT0_BASEADDR 0x000C4800
#define EPTPC_PORT1_BASEADDR 0x000C4C00

#define EPTPC_SYSR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x0))
#define EPTPC_SYSR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x0))
#define EPTPC_SYSR_OFFSET (0x0)
#define EPTPC_SYSR_GENDN ((uint32_t)(0x1 << 17))
#define EPTPC_SYSR_RESDN ((uint32_t)(0x1 << 16))
#define EPTPC_SYSR_INFABT ((uint32_t)(0x1 << 14))
#define EPTPC_SYSR_RECLP ((uint32_t)(0x1 << 12))
#define EPTPC_SYSR_DRQOVR ((uint32_t)(0x1 << 6))
#define EPTPC_SYSR_INTDEEV ((uint32_t)(0x1 << 5))
#define EPTPC_SYSR_DRPTO ((uint32_t)(0x1 << 4))
#define EPTPC_SYSR_MPDUD ((uint32_t)(0x1 << 2))
#define EPTPC_SYSR_INTCHG ((uint32_t)(0x1 << 1))
#define EPTPC_SYSR_OFMUD ((uint32_t)0x1)
#define EPTPC_SYIPR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x4))
#define EPTPC_SYIPR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x4))
#define EPTPC_SYIPR_OFFSET (0x4)
#define EPTPC_SYIPR_GENDN ((uint32_t)(0x1 << 17))
#define EPTPC_SYIPR_RESDN ((uint32_t)(0x1 << 16))
#define EPTPC_SYIPR_INFABT ((uint32_t)(0x1 << 14))
#define EPTPC_SYIPR_RECLP ((uint32_t)(0x1 << 12))
#define EPTPC_SYIPR_DRQOVR ((uint32_t)(0x1 << 6))
#define EPTPC_SYIPR_INTDEEV ((uint32_t)(0x1 << 5))
#define EPTPC_SYIPR_DRPTO ((uint32_t)(0x1 << 4))
#define EPTPC_SYIPR_MPDUD ((uint32_t)(0x1 << 2))
#define EPTPC_SYIPR_INTCHG ((uint32_t)(0x1 << 1))
#define EPTPC_SYIPR_OFMUD ((uint32_t)0x1)
#define EPTPC_SYMACRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x10))
#define EPTPC_SYMACRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x10))
#define EPTPC_SYMACRU_OFFSET (0x10)
#define EPTPC_SYMACRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x14))
#define EPTPC_SYMACRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x14))
#define EPTPC_SYMACRL_OFFSET (0x14)
#define EPTPC_SYIPR_ADDR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1c))
#define EPTPC_SYIPR_ADDR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1c))
#define EPTPC_SYIPR_ADDR_OFFSET (0x1c)
#define EPTPC_SYSPVRR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x40))
#define EPTPC_SYSPVRR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x40))
#define EPTPC_SYSPVRR_OFFSET (0x40)
#define EPTPC_SYSPVRR_TRSP ((uint32_t)(0x0 << 4))
#define EPTPC_SYSPVRR_VER ((uint32_t)0x2)
#define EPTPC_SYDOMR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x44))
#define EPTPC_SYDOMR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x44))
#define EPTPC_SYDOMR_OFFSET (0x44)
#define EPTPC_SYDOMR_DNUM_MASK ((uint32_t)(0x1 << 255))
#define EPTPC_ANFR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x50))
#define EPTPC_ANFR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x50))
#define EPTPC_ANFR_OFFSET (0x50)
#define EPTPC_ANFR_FLAG14 ((uint32_t)(0x1 << 14))
#define EPTPC_ANFR_FLAG13 ((uint32_t)(0x1 << 13))
#define EPTPC_ANFR_FLAG10 ((uint32_t)(0x1 << 10))
#define EPTPC_ANFR_FLAG8 ((uint32_t)(0x1 << 8))
#define EPTPC_ANFR_FLAG5 ((uint32_t)(0x1 << 5))
#define EPTPC_ANFR_FLAG4 ((uint32_t)(0x1 << 4))
#define EPTPC_ANFR_FLAG3 ((uint32_t)(0x1 << 3))
#define EPTPC_ANFR_FLAG2 ((uint32_t)(0x1 << 2))
#define EPTPC_ANFR_FLAG1 ((uint32_t)(0x1 << 1))
#define EPTPC_ANFR_FLAG0 ((uint32_t)0x1)
#define EPTPC_SYNFR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x54))
#define EPTPC_SYNFR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x54))
#define EPTPC_SYNFR_OFFSET (0x54)
#define EPTPC_SYNFR_FLAG14 ((uint32_t)(0x1 << 14))
#define EPTPC_SYNFR_FLAG13 ((uint32_t)(0x1 << 13))
#define EPTPC_SYNFR_FLAG10 ((uint32_t)(0x1 << 10))
#define EPTPC_SYNFR_FLAG9 ((uint32_t)(0x1 << 9))
#define EPTPC_SYNFR_FLAG8 ((uint32_t)(0x1 << 8))
#define EPTPC_DYRQFR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x58))
#define EPTPC_DYRQFR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x58))
#define EPTPC_DYRQFR_OFFSET (0x58)
#define EPTPC_DYRQFR_FLAG14 ((uint32_t)(0x1 << 14))
#define EPTPC_DYRQFR_FLAG13 ((uint32_t)(0x1 << 13))
#define EPTPC_DYRQFR_FLAG10 ((uint32_t)(0x1 << 10))
#define EPTPC_DYRPFR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x5c))
#define EPTPC_DYRPFR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x5c))
#define EPTPC_DYRPFR_OFFSET (0x5c)
#define EPTPC_DYRPFR_FLAG14 ((uint32_t)(0x1 << 14))
#define EPTPC_DYRPFR_FLAG13 ((uint32_t)(0x1 << 13))
#define EPTPC_DYRPFR_FLAG10 ((uint32_t)(0x1 << 10))
#define EPTPC_DYRPFR_FLAG9 ((uint32_t)(0x1 << 9))
#define EPTPC_DYRPFR_FLAG8 ((uint32_t)(0x1 << 8))
#define EPTPC_SYCIDRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x60))
#define EPTPC_SYCIDRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x60))
#define EPTPC_SYCIDRU_OFFSET (0x60)
#define EPTPC_SYCIDRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x64))
#define EPTPC_SYCIDRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x64))
#define EPTPC_SYCIDRL_OFFSET (0x64)
#define EPTPC_SYPNUMR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x68))
#define EPTPC_SYPNUMR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x68))
#define EPTPC_SYPNUMR_OFFSET (0x68)
#define EPTPC_SYRVLDR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x80))
#define EPTPC_SYRVLDR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x80))
#define EPTPC_SYRVLDR_OFFSET (0x80)
#define EPTPC_SYRVLDR_ANUP ((uint32_t)(0x1 << 2))
#define EPTPC_SYRVLDR_STUP ((uint32_t)(0x1 << 1))
#define EPTPC_SYRVLDR_BMUP ((uint32_t)0x1)
#define EPTPC_SYRFL1R0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x90))
#define EPTPC_SYRFL1R1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x90))
#define EPTPC_SYRFL1R_OFFSET (0x90)
#define EPTPC_SYRFL1R_PDFUP_SYNFP ((uint32_t)(0x1 << 30))
#define EPTPC_SYRFL1R_PDFUP_PRC_TC ((uint32_t)(0x1 << 29))
#define EPTPC_SYRFL1R_PDFUP_PTPEDMAC ((uint32_t)(0x1 << 28))
#define EPTPC_SYRFL1R_PDRP_SYNFP ((uint32_t)(0x1 << 26))
#define EPTPC_SYRFL1R_PDRP_PRC_TC ((uint32_t)(0x1 << 25))
#define EPTPC_SYRFL1R_PDRP_PTPEDMAC ((uint32_t)(0x1 << 24))
#define EPTPC_SYRFL1R_PDRQ_SYNFP ((uint32_t)(0x1 << 22))
#define EPTPC_SYRFL1R_PDRQ_PRC_TC ((uint32_t)(0x1 << 21))
#define EPTPC_SYRFL1R_PDRQ_PTPEDMAC ((uint32_t)(0x1 << 20))
#define EPTPC_SYRFL1R_DRP_SYNFP ((uint32_t)(0x1 << 18))
#define EPTPC_SYRFL1R_DRP_PRC_TC ((uint32_t)(0x1 << 17))
#define EPTPC_SYRFL1R_DRP_PTPEDMAC ((uint32_t)(0x1 << 16))
#define EPTPC_SYRFL1R_DRQ_SYNFP ((uint32_t)(0x1 << 14))
#define EPTPC_SYRFL1R_DRQ_PRC_TC ((uint32_t)(0x1 << 13))
#define EPTPC_SYRFL1R_DRQ_PTPEDMAC ((uint32_t)(0x1 << 12))
#define EPTPC_SYRFL1R_FUP_SYNFP ((uint32_t)(0x1 << 10))
#define EPTPC_SYRFL1R_FUP_PRC_TC ((uint32_t)(0x1 << 9))
#define EPTPC_SYRFL1R_FUP_PTPEDMAC ((uint32_t)(0x1 << 8))
#define EPTPC_SYRFL1R_SYNC_SYNFP ((uint32_t)(0x1 << 6))
#define EPTPC_SYRFL1R_SYNC_PRC_TC ((uint32_t)(0x1 << 5))
#define EPTPC_SYRFL1R_SYNC_PTPEDMAC ((uint32_t)(0x1 << 4))
#define EPTPC_SYRFL1R_ANCE_PRC_TC ((uint32_t)(0x1 << 1))
#define EPTPC_SYRFL1R_ANCE_PTPEDMAC ((uint32_t)0x1)
#define EPTPC_SYRFL2R0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x94))
#define EPTPC_SYRFL2R1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x94))
#define EPTPC_SYRFL2R_OFFSET (0x94)
#define EPTPC_SYRFL2R_ILL_PRC_TC ((uint32_t)(0x1 << 29))
#define EPTPC_SYRFL2R_ILL_PTPEDMAC ((uint32_t)(0x1 << 28))
#define EPTPC_SYRFL2R_SIG_PRC_TC ((uint32_t)(0x1 << 5))
#define EPTPC_SYRFL2R_SIG_PTPEDMAC ((uint32_t)(0x1 << 4))
#define EPTPC_SYRFL2R_MAN_PRC_TC ((uint32_t)(0x1 << 1))
#define EPTPC_SYRFL2R_MAN_PTPEDMAC ((uint32_t)0x1)
#define EPTPC_SYTRENR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x98))
#define EPTPC_SYTRENR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x98))
#define EPTPC_SYTRENR_OFFSET (0x98)
#define EPTPC_SYTRENR_PDRQ ((uint32_t)(0x1 << 12))
#define EPTPC_SYTRENR_DRQ ((uint32_t)(0x1 << 8))
#define EPTPC_SYTRENR_SYNC ((uint32_t)(0x1 << 4))
#define EPTPC_SYTRENR_ANCE ((uint32_t)0x1)
#define EPTPC_MTCIDU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xa0))
#define EPTPC_MTCIDU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xa0))
#define EPTPC_MTCIDU_OFFSET (0xa0)
#define EPTPC_MTCIDL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xa4))
#define EPTPC_MTCIDL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xa4))
#define EPTPC_MTCIDL_OFFSET (0xa4)
#define EPTPC_MTPID0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xa8))
#define EPTPC_MTPID1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xa8))
#define EPTPC_MTPID_OFFSET (0xa8)
#define EPTPC_MTPID_PNUM_MASK ((uint32_t)0xffff)
#define EPTPC_SYTLIR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xc0))
#define EPTPC_SYTLIR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xc0))
#define EPTPC_SYTLIR_OFFSET (0xc0)
#define EPTPC_SYRLIR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xc4))
#define EPTPC_SYRLIR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xc4))
#define EPTPC_SYRLIR_OFFSET (0xc4)
#define EPTPC_OFMRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xc8))
#define EPTPC_OFMRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xc8))
#define EPTPC_OFMRU_OFFSET (0xc8)
#define EPTPC_OFMRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xcc))
#define EPTPC_OFMRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xcc))
#define EPTPC_OFMRL_OFFSET (0xcc)
#define EPTPC_MPDRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xd0))
#define EPTPC_MPDRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xd0))
#define EPTPC_MPDRU_OFFSET (0xd0)
#define EPTPC_MPDRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xd4))
#define EPTPC_MPDRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xd4))
#define EPTPC_MPDRL_OFFSET (0xd4)
#define EPTPC_GMPR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xe0))
#define EPTPC_GMPR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xe0))
#define EPTPC_GMPR_OFFSET (0xe0)
#define EPTPC_GMCQR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xe4))
#define EPTPC_GMCQR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xe4))
#define EPTPC_GMCQR_OFFSET (0xe4)
#define EPTPC_GMIDRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xe8))
#define EPTPC_GMIDRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xe8))
#define EPTPC_GMIDRU_OFFSET (0xe8)
#define EPTPC_GMIDRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xec))
#define EPTPC_GMIDRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xec))
#define EPTPC_GMIDRL_OFFSET (0xec)
#define EPTPC_CUOTSR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xf0))
#define EPTPC_CUOTSR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xf0))
#define EPTPC_CUOTSR_OFFSET (0xf0)
#define EPTPC_SRR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0xf4))
#define EPTPC_SRR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0xf4))
#define EPTPC_SRR_OFFSET (0xf4)
#define EPTPC_PPMACRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x100))
#define EPTPC_PPMACRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x100))
#define EPTPC_PPMACRU_OFFSET (0x100)
#define EPTPC_PPMACRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x104))
#define EPTPC_PPMACRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x104))
#define EPTPC_PPMACRL_OFFSET (0x104)
#define EPTPC_PDMACRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x108))
#define EPTPC_PDMACRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x108))
#define EPTPC_PDMACRU_OFFSET (0x108)
#define EPTPC_PDMACRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x10c))
#define EPTPC_PDMACRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x10c))
#define EPTPC_PDMACRL_OFFSET (0x10c)
#define EPTPC_PETYPER0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x110))
#define EPTPC_PETYPER1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x110))
#define EPTPC_PETYPER_OFFSET (0x110)
#define EPTPC_PPIPR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x120))
#define EPTPC_PPIPR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x120))
#define EPTPC_PPIPR_OFFSET (0x120)
#define EPTPC_PDIPR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x124))
#define EPTPC_PDIPR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x124))
#define EPTPC_PDIPR_OFFSET (0x124)
#define EPTPC_PETOSR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x128))
#define EPTPC_PETOSR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x128))
#define EPTPC_PETOSR_OFFSET (0x128)
#define EPTPC_PGTOSR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x12c))
#define EPTPC_PGTOSR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x12c))
#define EPTPC_PGTOSR_OFFSET (0x12c)
#define EPTPC_PPTTLR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x130))
#define EPTPC_PPTTLR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x130))
#define EPTPC_PPTTLR_OFFSET (0x130)
#define EPTPC_PDTTLR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x134))
#define EPTPC_PDTTLR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x134))
#define EPTPC_PDTTLR_OFFSET (0x134)
#define EPTPC_PEUDPR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x138))
#define EPTPC_PEUDPR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x138))
#define EPTPC_PEUDPR_OFFSET (0x138)
#define EPTPC_PGUDPR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x13c))
#define EPTPC_PGUDPR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x13c))
#define EPTPC_PGUDPR_OFFSET (0x13c)
#define EPTPC_FFLTR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x140))
#define EPTPC_FFLTR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x140))
#define EPTPC_FFLTR_OFFSET (0x140)
#define EPTPC_FFLTR_EXTPRM_NORMAL ((uint32_t)(0x0 << 16))
#define EPTPC_FFLTR_EXTPRM_EXPCAST ((uint32_t)(0x1 << 16))
#define EPTPC_FFLTR_ENB ((uint32_t)(0x1 << 2))
#define EPTPC_FFLTR_PRT ((uint32_t)(0x1 << 1))
#define EPTPC_FFLTR_SEL ((uint32_t)0x1)
#define EPTPC_FMAC0RU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x160))
#define EPTPC_FMAC0RU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x160))
#define EPTPC_FMAC0RU_OFFSET (0x160)
#define EPTPC_FMAC0RL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x164))
#define EPTPC_FMAC0RL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x164))
#define EPTPC_FMAC0RL_OFFSET (0x164)
#define EPTPC_FMAC1RU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x168))
#define EPTPC_FMAC1RU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x168))
#define EPTPC_FMAC1RU_OFFSET (0x168)
#define EPTPC_FMAC1RL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x16c))
#define EPTPC_FMAC1RL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x16c))
#define EPTPC_FMAC1RL_OFFSET (0x16c)
#define EPTPC_DASYMRU0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1c0))
#define EPTPC_DASYMRU1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1c0))
#define EPTPC_DASYMRU_OFFSET (0x1c0)
#define EPTPC_DASYMRL0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1c4))
#define EPTPC_DASYMRL1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1c4))
#define EPTPC_DASYMRL_OFFSET (0x1c4)
#define EPTPC_TSLATR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1c8))
#define EPTPC_TSLATR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1c8))
#define EPTPC_TSLATR_OFFSET (0x1c8)
#define EPTPC_SYCONFR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1cc))
#define EPTPC_SYCONFR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1cc))
#define EPTPC_SYCONFR_OFFSET (0x1cc)
#define EPTPC_SYCONFR_TCMOD_E2E ((uint32_t)(0x0 << 20))
#define EPTPC_SYCONFR_TCMOD_P2P ((uint32_t)(0x1 << 20))
#define EPTPC_SYCONFR_FILDIS ((uint32_t)(0x1 << 16))
#define EPTPC_SYCONFR_SBDIS ((uint32_t)(0x1 << 12))
#define EPTPC_SYCONFR_TCYC_MASK ((uint32_t)0xff)
#define EPTPC_SYFORMR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1d0))
#define EPTPC_SYFORMR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1d0))
#define EPTPC_SYFORMR_OFFSET (0x1d0)
#define EPTPC_SYFORMR_FROM1_PTP_ETHER ((uint32_t)(0x0 << 1))
#define EPTPC_SYFORMR_FROM1_PTP_UDP_IPV4 ((uint32_t)(0x1 << 1))
#define EPTPC_SYFORMR_FORM0 ((uint32_t)0x0)
#define EPTPC_RSTOUTR0_ADDR ((volatile uint32_t*)(EPTPC_PORT0_BASEADDR + 0x1d4))
#define EPTPC_RSTOUTR1_ADDR ((volatile uint32_t*)(EPTPC_PORT1_BASEADDR + 0x1d4))
#define EPTPC_RSTOUTR_OFFSET (0x1d4)

#endif