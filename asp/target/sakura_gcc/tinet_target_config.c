/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2009 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id$
 */

/*
 *  �^�[�Q�b�g�ˑ����W���[���iRX63N�p�j
 */

#include <sil.h>

#if defined(SUPPORT_ETHER)

#include <tinet_defs.h>
#include <tinet_config.h>
#include "target_board.h"


/*
 *  rx62n_bus_init -- �^�[�Q�b�g�ˑ����̃o�X�̏�����
 */

void
rx62n_bus_init (void)
{
	/* �C�[�T�l�b�g�E�R���g���[���̓�������� */
	sil_wrh_mem((uint16_t *)SYSTEM_PRCR_ADDR, (uint16_t)0xA502);	/* �����݋��� */
	sil_wrw_mem((uint32_t *)SYSTEM_MSTPCRB_ADDR,
		sil_rew_mem((uint32_t *)SYSTEM_MSTPCRB_ADDR) & ~SYSTEM_MSTPCRB_MSTPB15_BIT);
	sil_wrh_mem((uint16_t *)SYSTEM_PRCR_ADDR, (uint16_t)0xA500);	/* �����݋֎~ */

	/* EtherNET�L�� */
	/* PA3�`5 RMII_MDIO, RMII_MDC, RMII_LINKSTA */
	sil_wrb_mem((uint8_t *)PORTA_PMR_ADDR,
		sil_reb_mem((uint8_t *)PORTA_PMR_ADDR) | (1 << 3) | (1 << 4) | (1 << 5));
	/* PB0�`7 RXD1, RXD0, REF50CK, RX-ER, TXD-EN, TXD0, TXD1, CRS */
	sil_wrb_mem((uint8_t *)PORTB_PMR_ADDR,
		sil_reb_mem((uint8_t *)PORTB_PMR_ADDR) | 0xFF);

	/* �������݃v���e�N�g���W�X�^�̐ݒ� PFSWE�r�b�g�ւ̏������݂����� */
	sil_wrb_mem((uint8_t *)(MPC_PWPR_ADDR) , 0x00);
	/* �������݃v���e�N�g���W�X�^�̐ݒ� PxxFS���W�X�^�ւ̏������݂����� */
	sil_wrb_mem((uint8_t *)(MPC_PWPR_ADDR) , 0x40);

	/* PA3��ET_MDIO�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PA3PFS_ADDR, 0x11); 
	/* PA4��ET_MDC�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PA4PFS_ADDR, 0x11); 
	/* PA5��ET_LINKSTA�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PA5PFS_ADDR, 0x11); 

	/* PB0��RXD1�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB0PFS_ADDR, 0x12);
	/* PB1��RXD0�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB1PFS_ADDR, 0x12);
	/* PB2��REF50CK�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB2PFS_ADDR, 0x12);
	/* PB3��RX-ER�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB3PFS_ADDR, 0x12);
	/* PB4��TXD-EN�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB4PFS_ADDR, 0x12);
	/* PB5��TXD0�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB5PFS_ADDR, 0x12);
	/* PB6��TXD1�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB6PFS_ADDR, 0x12);
	/* PB7��CRS�Ƃ��� */
	sil_wrb_mem((uint8_t *)MPC_PB7PFS_ADDR, 0x12);

	/* �������݃v���e�N�g���W�X�^�̐ݒ� �������݂��֎~ */
	sil_wrb_mem((uint8_t *)(MPC_PWPR_ADDR) , 0x80);
}

/*
 *  rx62n_inter_init -- �^�[�Q�b�g�ˑ����̊����݂̏�����
 */

void
rx62n_inter_init (void)
{
}

#endif	/* of #if defined(SUPPORT_ETHER) */
