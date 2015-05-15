/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iGR-SAKURA�p�j
 */

#include "kernel_impl.h"
#include <sil.h>
#include "target_board.h"
#include "renesas/scic_uart.h"
#include "dev_led.h"

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */
void
sakura_clock_waitcount_config(void){
  //unlock lopwermode register access
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY | SYSTEM_PRC1);

  //clock wait count set
  sil_wrb_mem((void *)(SYSTEM_MOSCWTR_ADDR),SYSTEM_CLKWAIT_HE );
  sil_wrb_mem((void *)(SYSTEM_PLLWTCR_ADDR), SYSTEM_CLKWAIT_HA);
  
  //lock lopwermode register access
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY );
}


void 
sakura_clock_config( void ){
  const uint16_t wait_count = 1250; //pll lock wait count
  uint16_t i;
  sakura_clock_waitcount_config();

  //unlock access of clock setting register
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY | SYSTEM_PRC0);
  //GR-SAKURA Bord OSC is 12MHz
  //set clock freq(PLL 196MHz, PCKB 48MHz PCKA 98MHz ICK 98MHz)
  //pll set div 1, mul 16
  sil_wrh_mem((void *)(CKG_PLLCR_ADDR), CKG_PLLCR_PLIDIV1 | CKG_PLLCR_STC16);
  //set bus clock rate
  sil_wrw_mem((void *)(CKG_SCKCR_ADDR),   CKG_SCKCR_PB_DIV04 
                                        | CKG_SCKCR_PA_DIV02   
                                        | CKG_SCKCR_BCK_DIV04
                                        | CKG_SCKCR_PSTOP0
                                        | CKG_SCKCR_PSTOP1
                                        | CKG_SCKCR_FCK_DIV04
                                        | CKG_SCKCR_ICK_DIV02
                                        | CKG_SCKCR_RESERVE);

  sil_wrh_mem((void *)(CKG_SCKCR2_ADDR), CKG_SCKCR2_IEBCK_DIV4 | CKG_SCKCR2_UCK_NOT_USE);

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
   sil_wrh_mem((void *)(CKG_SCKCR3_ADDR),   CKG_SCKCR3_PLL);                        
  //lock access of clock setting register
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY );


}
void
sakura_port_config( void )
{
	/*
	 *  �|�[�g�̐ݒ�
	 */
	scic_uart_init( TARGET_PUTC_PORTID, UART_BAUDRATE, UART_CLKSRC );

	/* �|�[�gP50��TxD2, �|�[�gP52��RxD2�� */
	/* MPC setting */
	/* unlock PFS write protection */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSWE_BIT);
	/* p50 is set as TxD2 mode */
	sil_wrb_mem((void *)(MPC_P50PFS_ADDR), MPC_PFS_PSELA);
	/* p52 is set as RxD2 mode*/
	sil_wrb_mem((void *)(MPC_P52PFS_ADDR), MPC_PFS_PSELA);
	/* lock PFS write */
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_PFSW_CLEAR);
	sil_wrb_mem((void *)(MPC_PWPR_ADDR), MPC_PWPR_B0WI_BIT);

	/* port mode setting */
	/* Port Mode Register(PMR) config. P50 and P52(RxD2) are setted to IP use */
	sil_wrb_mem((void *)(PORT5_PMR_ADDR) , 
					sil_reb_mem((void *)(PORT2_PMR_ADDR)) | PORT_PMR_B0_BIT | PORT_PMR_B2_BIT);
}

void
sakura_ip_wakeup( void )
{
  //unlock register access 
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY | SYSTEM_PRC1);
  /*
   * ���W���[���X�g�b�v�@�\�̐ݒ�(SCI2)
   */
  *SYSTEM_MSTPCRB_ADDR &= ~(SYSTEM_MSTPCRB_MSTPB29_BIT); /* CMT0 */
  //lock register access
  sil_wrh_mem((void *)(SYSTEM_PRCR_ADDR), SYSTEM_PRKEY );
}
void
target_initialize( void )
{
	/*
	 *  �v���Z�b�T�ˑ��̏�����
	 */

  prc_initialize();
  sakura_clock_config();
  //set port direction
  sakura_port_config();
  sakura_ip_wakeup();

}


/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */
void
target_exit( void )
{
	/*
	 *	�v���Z�b�T�ˑ��̏I������
	 */
	prc_terminate();

	while ( 1 );
}


/*
 *  �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 */
void
target_fput_log( char c )
{
	if( c == '\n' ){
	   scic_uart_pol_putc( '\r' , TARGET_PUTC_PORTID );
	}

    scic_uart_pol_putc( c , TARGET_PUTC_PORTID );
}


