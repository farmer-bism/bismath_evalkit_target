/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */


//SPCR BIT Define
#define SPCR_SPMS 0x1
#define SPCR_TXMD 0x2
#define SPCR_MODFEN 0x4
#define SPCR_MSTR 0x8
#define SPCR_SPEIE 0x10
#define SPCR_SPTIE 0x20
#define SPCR_SPE 0x40
#define SPCR_SPRIE  0x80

//SSLP BIT Define
#define SSLP_SSL0P 0x1
#define SSLP_SSL1P 0x2
#define SSLP_SSL2P 0x4
#define SSLP_SSL3P 0x8

//SPPCR BIT Define
#define SPPCR_SPLP 0x1
#define SPPCR_SPLP2_ 0x2
#define SPPCR_MOIFV 0x10
#define SPPCR_MOIFE 0x20

//SPSR BIT Define
#define SPSR_OVRF 0x1
#define SPSR_IDLNF 0x2
#define SPSR_MODF 0x4
#define SPSR_PERF 0x8

//SPSCR BIT Define
#define SPSCR_SPSLN_1 0x0
#define SPSCR_SPSLN_2 0x1
#define SPSCR_SPSLN_3 0x2
#define SPSCR_SPSLN_4 0x3
#define SPSCR_SPSLN_5 0x4
#define SPSCR_SPSLN_6 0x5
#define SPSCR_SPSLN_7 0x6
#define SPSCR_SPSLN_8 0x7

//SPDCR BIT Define
#define SPDCR_SPFC_MASK 0x3
#define SPDCR_SPFC_1 0x0
#define SPDCR_SPFC_2 0x1
#define SPDCR_SPFC_3 0x2
#define SPDCR_SPFC_4 0x3
#define SPDCR_SPRDTD 0x10
#define SPDCR_SPLW 0x20

//SPCR2 BIT Define
#define SPCR2_SPPE 0x1
#define SPCR2_SPOE 0x2
#define SPCR2_SPIIE 0x4
#define SPCR2_PTE 0x8

//SPCMD BIT Define
#define SPCMD_CPHA 0x1
#define SPCMD_CPOL 0x2
#define SPCMD_BRDV_MASK 0xC
#define SPCMD_BRDV_0 0x0
#define SPCMD_BRDV_1 0x4
#define SPCMD_BRDV_2 0x8
#define SPCMD_BRDV_3 0xC
#define SPCMD_SSLA_MASK 0x70
#define SPCMD_SSLA_SSL0 0x0
#define SPCMD_SSLA_SSL1 0x10
#define SPCMD_SSLA_SSL2 0x20
#define SPCMD_SSLA_SSL3 0x30
#define SPCMD_SSLKP 0x80
#define SPCMD_SPB_MASK 0xF00
#define SPCMD_SPB_08 0x700
#define SPCMD_SPB_09 0x800
#define SPCMD_SPB_10 0x900
#define SPCMD_SPB_11 0xA00
#define SPCMD_SPB_12 0xB00
#define SPCMD_SPB_13 0xC00
#define SPCMD_SPB_14 0xD00
#define SPCMD_SPB_15 0xE00
#define SPCMD_SPB_16 0xF00
#define SPCMD_SPB_20 0x000
#define SPCMD_SPB_24 0x100
#define SPCMD_SPB_32 0x200
#define SPCMD_LSBF 0x1000
#define SPCMD_LSBF_MSB 0x0
#define SPCMD_LSBF_LSB 0x1000

typedef struct rspi_param_type{
  uint8_t spcr;
  uint8_t sslp;
  uint8_t sppcr;
  uint8_t spscr;
  uint32_t bit_rate;
  uint8_t spdcr;
  uint16_t spcmd0;
} rspi_param_t;
  
//device node type
//rspi node's api is null

//device node status
typedef struct rspi_dev_status_type{
  uint32_t baddr; //base address
  uint8_t spri; //irq number of spri
  uint8_t spti; //irq number of spti
  uint8_t spii; //irq number of spii
} rspi_dstat;
