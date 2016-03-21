/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2009 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2014 Cores Co., Ltd. Japan
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

#include "ether_phy.h"
#include <kernel.h>
#include <tinet_config.h>
#include <sil.h>

#define PHY_CONTROL_REGISTER	0x00

#define PHY_CONTROL_RESET			0x8000
#define PHY_CONTROL_LOOPBACK		0x4000
#define PHY_CONTROL_SPEED_SELECT	0x2000
#define PHY_CONTROL_A_N_ENABLE		0x1000
#define PHY_CONTROL_POWER_DOWN		0x0800
#define PHY_CONTROL_ISOLATE			0x0400
#define PHY_CONTROL_RESTART_A_N		0x0200
#define PHY_CONTROL_DUPLEX_MODE		0x0100
#define PHY_CONTROL_COLLISION_TEST	0x0080

#define PHY_STATUS_REGISTER		0x01

#define PHY_STATUS_100BASE_T4				0x8000
#define PHY_STATUS_100BASE_TX_FULL_DUPLEX	0x4000
#define PHY_STATUS_100BASE_TX_HALF_DUPLEX	0x2000
#define PHY_STATUS_10BASE_T_FULL_DUPLEX		0x1000
#define PHY_STATUS_10BASE_T_HALF_DUPLEX		0x0800
#define PHY_STATUS_A_N_COMPLETE				0x0020
#define PHY_STATUS_REMOTE_FAULT				0x0010
#define PHY_STATUS_A_N_ABILITY				0x0008
#define PHY_STATUS_LINK_STATUS				0x0004
#define PHY_STATUS_JABBER_DETECT			0x0002
#define PHY_STATUS_EXTENDED_CAPABILITY		0x0001

#define PHY_AN_ADVERTISEMENT_REGISTER	0x04

#define PHY_AN_AD_100BASE_T4				0x0200
#define PHY_AN_AD_100BASE_TX_FULL_DUPLEX	0x0100
#define PHY_AN_AD_100BASE_TX_HALF_DUPLEX	0x0080
#define PHY_AN_AD_10BASE_T_FULL_DUPLEX		0x0040
#define PHY_AN_AD_10BASE_T_HALF_DUPLEX		0x0020
#define PHY_AN_AD_SELECTOR_FIELD			0x0001

#define PHY_AN_STATUS_REGISTER	0x05

#define PHY_AN_STATUS_100BASE_T4				0x0200
#define PHY_AN_STATUS_100BASE_TX_FULL_DUPLEX	0x0100
#define PHY_AN_STATUS_100BASE_TX_HALF_DUPLEX	0x0080
#define PHY_AN_STATUS_10BASE_T_FULL_DUPLEX		0x0040
#define PHY_AN_STATUS_10BASE_T_HALF_DUPLEX		0x0020

static void phy_write_bit(bool_t bit);
static void phy_release_bus();
static bool_t phy_read_bit();
static void phy_single_rel_bus();

void phy_reset(uint8_t phy_addr)
{
  //#ifdef __RX
	/* PHY�̃��Z�b�g */
	phy_write_reg(phy_addr, PHY_CONTROL_REGISTER, PHY_CONTROL_RESET);

	/* 500ms�҂� */
	/* tslp_tsk(500); �s�v�H */

	/* ���Z�b�g�����̊m�F */
	while((phy_read_reg(phy_addr, PHY_CONTROL_REGISTER) & PHY_CONTROL_RESET) != 0)
		tslp_tsk(1);
    //#endif
}

enum phy_mode_t phy_initialize(uint8_t phy_addr)
{
	uint_t result = 0;
	uint16_t status;
    //#ifdef __RX
	/* �����N�����̊m�F */
	while((phy_read_reg(phy_addr, PHY_STATUS_REGISTER) & PHY_STATUS_LINK_STATUS) == 0)
		tslp_tsk(1);

	/* �I�[�g�l�S�V�G�[�V�����̂��m�点��L���ɐݒ� */
	phy_write_reg(phy_addr, PHY_AN_ADVERTISEMENT_REGISTER, 
		PHY_AN_AD_100BASE_T4 | PHY_AN_AD_100BASE_TX_FULL_DUPLEX | PHY_AN_AD_100BASE_TX_HALF_DUPLEX
		| PHY_AN_AD_10BASE_T_FULL_DUPLEX | PHY_AN_AD_10BASE_T_HALF_DUPLEX | PHY_AN_AD_SELECTOR_FIELD);

	/* �I�[�g�l�S�V�G�[�V������L���ɐݒ� */
	phy_write_reg(phy_addr, PHY_CONTROL_REGISTER, PHY_CONTROL_SPEED_SELECT | PHY_CONTROL_A_N_ENABLE);

	/* �I�[�g�l�S�V�G�[�V���������̊m�F */
	while((phy_read_reg(phy_addr, PHY_STATUS_REGISTER) & PHY_STATUS_A_N_COMPLETE) == 0)
		tslp_tsk(1);

	status = phy_read_reg(phy_addr, PHY_AN_STATUS_REGISTER);

	if ((status & (PHY_AN_STATUS_10BASE_T_FULL_DUPLEX | PHY_AN_STATUS_100BASE_TX_FULL_DUPLEX)) != 0)
		result |= 0x01;

	if ((status & (PHY_AN_STATUS_100BASE_TX_FULL_DUPLEX | PHY_AN_STATUS_100BASE_TX_HALF_DUPLEX)) != 0)
		result |= 0x02;
    //#endif
	return (enum phy_mode_t)result;
}

bool_t phy_is_link(uint8_t phy_addr)
{
  //#ifdef __RX
	/* �����N�̊m�F */
	return (phy_read_reg(phy_addr, PHY_STATUS_REGISTER) & PHY_STATUS_LINK_STATUS) == 0;
    //#else
    //	return true;
    //#endif
}

uint16_t phy_read_reg(uint8_t phy_addr, uint8_t reg_addr)
{
	uint16_t result = 0, bit;
	int i;

	/* PRE �F32�̘A������1b */
	for (i = 0; i < 32; i++)
		phy_write_bit(true);

	/* ST �F�t���[���̐擪������01b�̃��C�g */
	phy_write_bit(false);
	phy_write_bit(true);

	/* OP �F�A�N�Z�X��ʂ������R�[�h�̃��C�g */
	phy_write_bit(true);
	phy_write_bit(false);

	/* PHYAD �FPHY-LSI�̃A�h���X��1�Ԃ̏ꍇ�A00001b�����C�g�iMSB ���珇�����C�g�j�B */
	phy_write_bit((phy_addr & 0x10) != 0);
	phy_write_bit((phy_addr & 0x08) != 0);
	phy_write_bit((phy_addr & 0x04) != 0);
	phy_write_bit((phy_addr & 0x02) != 0);
	phy_write_bit((phy_addr & 0x01) != 0);

	/* REGAD �F���W�X�^�A�h���X��1�Ԃ̏ꍇ�A00001b�����C�g�iMSB���珇�����C�g�j�B */
	phy_write_bit((reg_addr & 0x10) != 0);
	phy_write_bit((reg_addr & 0x08) != 0);
	phy_write_bit((reg_addr & 0x04) != 0);
	phy_write_bit((reg_addr & 0x02) != 0);
	phy_write_bit((reg_addr & 0x01) != 0);

	/* TA �FMII/RMII�C���^�t�F�[�X��Ńf�[�^�̑��M����؂�ւ��鎞�� */
	/* �u�o�X����v�iZ0�ƕ\�L�j���s�� */
	phy_release_bus();

	/* DATA �F16�r�b�g�̃f�[�^�BMSB���珇�����[�h */
	for (bit = 0x8000; bit != 0; bit >>= 1) {
		if(phy_read_bit())
			result |= bit;
	}

	/* IDLE �F����MII�Ǘ��t�H�[�}�b�g���͂܂ł̑ҋ@���� */
	/* ���ł�TA���Ƀo�X����ς݂ł��萧��s�v */
	phy_release_bus();

	return result;
}

void phy_write_reg(uint8_t phy_addr, uint8_t reg_addr, uint16_t reg_data)
{
	int i;
	uint16_t bit;

	/* PRE �F32�̘A������1b */
	for (i = 0; i < 32; i++)
		phy_write_bit(true);

	/* ST �F�t���[���̐擪������01b�̃��C�g */
	phy_write_bit(false);
	phy_write_bit(true);

	/* OP �F�A�N�Z�X��ʂ������R�[�h�̃��C�g */
	phy_write_bit(false);
	phy_write_bit(true);

	/* PHYAD �FPHY-LSI�̃A�h���X��1�Ԃ̏ꍇ�A00001b�����C�g�iMSB ���珇�����C�g�j�B */
	phy_write_bit((phy_addr & 0x10) != 0);
	phy_write_bit((phy_addr & 0x08) != 0);
	phy_write_bit((phy_addr & 0x04) != 0);
	phy_write_bit((phy_addr & 0x02) != 0);
	phy_write_bit((phy_addr & 0x01) != 0);

	/* REGAD �F���W�X�^�A�h���X��1�Ԃ̏ꍇ�A00001b�����C�g�iMSB���珇�����C�g�j�B */
	phy_write_bit((reg_addr & 0x10) != 0);
	phy_write_bit((reg_addr & 0x08) != 0);
	phy_write_bit((reg_addr & 0x04) != 0);
	phy_write_bit((reg_addr & 0x02) != 0);
	phy_write_bit((reg_addr & 0x01) != 0);

	/* TA �FMII/RMII�C���^�t�F�[�X��Ńf�[�^�̑��M����؂�ւ��鎞�� */
	/* 10b�����C�g */
	phy_write_bit(true);
	phy_write_bit(false);

	/* DATA �F16�r�b�g�̃f�[�^�BMSB���珇�����C�g */
	for (bit = 0x8000; bit != 0; bit >>= 1) {
		phy_write_bit((reg_data & bit) != 0);
	}

	/* IDLE �F����MII�Ǘ��t�H�[�}�b�g���͂܂ł̑ҋ@���� */
	/* �u�P�ƃo�X����v�iX�ƕ\�L�j���s�� */
	phy_single_rel_bus();
}

#define ETHERC_PIR_WAIT 4

/*
 * 1 �r�b�g�f�[�^�̃��C�g
 */
static void phy_write_bit(bool_t bit)
{
	int i;
	uint32_t data = bit ? ETHERC_PIR_MDO : 0;

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, data | ETHERC_PIR_MMD | 0/*ETHERC_PIR_MDC*/);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, data | ETHERC_PIR_MMD | ETHERC_PIR_MDC);

	for(i = 2 * ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, data | ETHERC_PIR_MMD | 0/*ETHERC_PIR_MDC*/);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);
}

/*
 * �o�X���
 */
static void phy_release_bus()
{
	int i;

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, 0/*ETHERC_PIR_MMD*/ | 0/*ETHERC_PIR_MDC*/);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, 0/*ETHERC_PIR_MMD*/ | ETHERC_PIR_MDC);

	for(i = 2 * ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, 0/*ETHERC_PIR_MMD*/ | 0/*ETHERC_PIR_MDC*/);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);
}

/*
 * 1 �r�b�g�f�[�^�̃��[�h
 */
static bool_t phy_read_bit()
{
	bool_t bit;
	int i;

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, 0/*ETHERC_PIR_MMD*/ | ETHERC_PIR_MDC);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	bit = (sil_rew_mem(ETHERC_PIR) & ETHERC_PIR_MDI) != 0;

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, 0/*ETHERC_PIR_MMD*/ | 0/*ETHERC_PIR_MDC*/);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	return bit;
}

/*
 * �P�ƃo�X���
 */
static void phy_single_rel_bus()
{
	int i;

	for(i = ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, ETHERC_PIR_MMD | ETHERC_PIR_MDC);

	for(i = 2 * ETHERC_PIR_WAIT; i > 0; i--);

	/* PHY���C���^�t�F�[�X���W�X�^�ւ̃��C�g */
	sil_wrw_mem(ETHERC_PIR, 0/*ETHERC_PIR_MMD*/ | 0/*ETHERC_PIR_MDC*/);

	for(i = ETHERC_PIR_WAIT; i > 0; i--);
}
