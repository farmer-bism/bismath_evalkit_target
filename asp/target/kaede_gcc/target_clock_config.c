/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2016- by Hisashi Hata, JAPAN
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
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
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 */


/*
 *	Clock initialize
 */


#include "kernel_impl.h"
#include <sil.h>
#include "target_board.h"


void
clock_waitcount_config(void){
  //unlock lopwermode register access
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY | SYSTEM_PRC1);

  //clock wait count set
  sil_wrb_mem((void *)(SYSTEM_MOSCWTCR_ADDR),SYSTEM_CLKWAIT_HE );
  
  //lock lopwermode register access
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY );
}


void 
target_clock_config( void ){
  
  clock_waitcount_config();

  //unlock access of clock setting register
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY | SYSTEM_PRC0);
  //GR-KAEDE Bord OSC is 12MHz
  //set clock freq(PLL 240MHz, PCKB 60MHz PCKA 120MHz ICK 120MHz)
  //pll set div 2, mul 20
  sil_wrh_mem((void *)(CKG_PLLCR_ADDR), CKG_PLLCR_PLIDIV2 | CKG_PLLCR_STC20_0);
  //set bus clock rate
  sil_wrw_mem((void *)(CKG_SCKCR_ADDR),   CKG_SCKCR_PD_DIV02
                                        | CKG_SCKCR_PC_DIV02
                                        | CKG_SCKCR_PB_DIV02
                                        | CKG_SCKCR_PA_DIV01
                                        | CKG_SCKCR_BCK_DIV02
                                        | CKG_SCKCR_PSTOP0
                                        | CKG_SCKCR_PSTOP1
                                        | CKG_SCKCR_FCK_DIV02
                                        | CKG_SCKCR_ICK_DIV01);

  sil_wrh_mem((void *)(CKG_SCKCR2_ADDR), CKG_SCKCR2_UCK_NOT_USE);

  /*
   * Main clock setting
   */
  
  //Main clock disable
   sil_wrb_mem((void *)(CKG_MOSCCR_ADDR), CKG_CLOCK_DISABLE);
   //Set drivabilty of Main clock
   //    clock source is OSC, frequency is 12MHz
   sil_wrb_mem((void *)(CKG_MOFCR_ADDR), CKG_MOFCR_MODRV2_U16);
  //Main clock enable
   sil_wrb_mem((void *)(CKG_MOSCCR_ADDR), CKG_CLOCK_ENABLE);
   //Wait Main clock lock
   while(sil_reb_mem((void *)(CKG_MOSCCR_ADDR)) != CKG_CLOCK_ENABLE);
   
  //pll enable
   sil_wrb_mem((void *)(CKG_PLLCR2_ADDR), CKG_CLOCK_ENABLE);
   while(sil_reb_mem((void *)(CKG_PLLCR2_ADDR)) != CKG_CLOCK_ENABLE);
   //PLL lock wait
   //wait over 10ms, LOCO freq 125Khz, wait count is 125*10 = 1250;                               
   //switch clock(PLL select)
   sil_wrh_mem((void *)(CKG_SCKCR3_ADDR),   CKG_SCKCR3_CKSEL_PLL);                        
  //lock access of clock setting register
   sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY );
}
