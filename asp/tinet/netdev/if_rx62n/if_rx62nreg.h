/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2009 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2014-2015 Cores Co., Ltd. Japan
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

#ifndef RX62NRegH
#define RX62NRegH

#include "t_stddef.h"

#define EDMAC_EDMR			((uint32_t *)0x000C0000)	/* EDMAC���[�h���W�X�^ */
#define EDMAC_EDMR_SWR_BIT	0x00000001
#define EDMAC_EDMR_DE_BIT	0x00000040

#define EDMAC_EDTRR			((uint32_t *)0x000C0008)	/* EDMAC���M�v�����W�X�^ */
#define EDMAC_EDTRR_TR		0x00000001

#define EDMAC_EDRRR			((uint32_t *)0x000C0010)	/* EDMAC��M�v�����W�X�^ */
#define EDMAC_EDRRR_RR		0x00000001

#define EDMAC_TDLAR			((uint32_t *)0x000C0018)	/* ���M�f�B�X�N���v�^���X�g�擪�A�h���X���W�X�^ */
#define EDMAC_RDLAR			((uint32_t *)0x000C0020)	/* ��M�f�B�X�N���v�^���X�g�擪�A�h���X���W�X�^ */

#define EDMAC_EESR			((uint32_t *)0x000C0028)	/* ETHERC/EDMAC�X�e�[�^�X���W�X�^ */
#define EDMAC_EESR_FROF		0x00010000
#define EDMAC_EESR_RDE		0x00020000
#define EDMAC_EESR_FR		0x00040000
#define EDMAC_EESR_TC		0x00200000
#define EDMAC_EESR_TWB		0x40000000

#define EDMAC_EESIPR		((uint32_t *)0x000C0030)	/* ETHERC/EDMAC�X�e�[�^�X���荞�݋����W�X�^ */
#define EDMAC_EESIPR_RMAFIP	0x00000080
#define EDMAC_EESIPR_FROFIP	0x00010000
#define EDMAC_EESIPR_RDEIP	0x00020000
#define EDMAC_EESIPR_FRIP	0x00040000
#define EDMAC_EESIPR_TCIP	0x00200000
#define EDMAC_EESIPR_TWBIP	0x40000000

#define EDMAC_TRSCER		((uint32_t *)0x000C0038)	/* ����M�X�e�[�^�X�R�s�[�w�����W�X�^ */
#define EDMAC_RMFCR			((uint32_t *)0x000C0040)	/* �~�X�h�t���[���J�E���^���W�X�^ */
#define EDMAC_TFTR			((uint32_t *)0x000C0048)	/* ���MFIFO�������l�w�背�W�X�^ */
#define EDMAC_FDR			((uint32_t *)0x000C0050)	/* FIFO�e�ʎw�背�W�X�^ */
#define EDMAC_RMCR			((uint32_t *)0x000C0058)	/* ��M�������䃌�W�X�^ */
#define EDMAC_TFUCR			((uint32_t *)0x000C0064)	/* ���MFIFO�A���_�����J�E���g */
#define EDMAC_RFOCR			((uint32_t *)0x000C0068)	/* ��MFIFO�I�[�o�t���[�J�E���g */
#define EDMAC_IOSR			((uint32_t *)0x000C006C)	/* �ʏo�͐M���ݒ背�W�X�^ */
#define EDMAC_FCFTR			((uint32_t *)0x000C0070)	/* �t���[����J�nFIFO�������l�ݒ背�W�X�^ */
#define EDMAC_RPADIR		((uint32_t *)0x000C0078)	/* ��M�f�[�^�p�f�B���O�}���ݒ背�W�X�^ */
#define EDMAC_TRIMD			((uint32_t *)0x000C007C)	/* ���M���荞�ݐݒ背�W�X�^ */
#define EDMAC_RBWAR			((uint32_t *)0x000C00C8)	/* ��M�o�b�t�@���C�g�A�h���X���W�X�^ */
#define EDMAC_RDFAR			((uint32_t *)0x000C00CC)	/* ��M�f�B�X�N���v�^�t�F�b�`�A�h���X���W�X�^ */
#define EDMAC_TBRAR			((uint32_t *)0x000C00D4)	/* ���M�o�b�t�@���[�h�A�h���X���W�X�^ */
#define EDMAC_TDFAR			((uint32_t *)0x000C00D8)	/* ���M�f�B�X�N���v�^�t�F�b�`�A�h���X���W�X�^ */

#define ETHERC_ECMR			((uint32_t *)0x000C0100)	/* ETHERC���[�h���W�X�^ */
#define ETHERC_ECMR_PRM		0x00000001
#define ETHERC_ECMR_DM		0x00000002
#define ETHERC_ECMR_RTM		0x00000004
#define ETHERC_ECMR_TE		0x00000020
#define ETHERC_ECMR_RE		0x00000040

#define ETHERC_RFLR			((uint32_t *)0x000C0108)	/* ��M�t���[����������W�X�^ */
#define ETHERC_ECSR			((uint32_t *)0x000C0110)	/* ETHERC�X�e�[�^�X���W�X�^ */
#define ETHERC_ECSR_LCHNG	0x00000004
#define ETHERC_ECSIPR		((uint32_t *)0x000C0118)	/* ETHERC���荞�݋����W�X�^ */
#define ETHERC_ECSIPR_LCHNGIP	0x00000004
#define ETHERC_PIR			((uint32_t *)0x000C0120)	/* PHY���C���^�t�F�[�X���W�X�^ */
#define ETHERC_PIR_MDC		0x00000001
#define ETHERC_PIR_MMD		0x00000002
#define ETHERC_PIR_MDO		0x00000004
#define ETHERC_PIR_MDI		0x00000008

#define ETHERC_PSR			((uint32_t *)0x000C0128)	/* PHY���X�e�[�^�X���W�X�^ */
#define ETHERC_PSR_LMON		0x00000001

#define ETHERC_RDMLR		((uint32_t *)0x000C0140)	/* ���������J�E���^����l�ݒ背�W�X�^ */
#define ETHERC_IPGR			((uint32_t *)0x000C0150)	/* IPG�ݒ背�W�X�^ */
#define ETHERC_APR			((uint32_t *)0x000C0154)	/* ����PAUSE�t���[���ݒ背�W�X�^ */
#define ETHERC_MPR			((uint32_t *)0x000C0158)	/* �蓮PAUSE�t���[���ݒ背�W�X�^ */
#define ETHERC_RFCF			((uint32_t *)0x000C0160)	/* ��MPAUSE�t���[���J�E���^ */
#define ETHERC_TPAUSER		((uint32_t *)0x000C0164)	/* ����PAUSE�t���[���đ��񐔐ݒ背�W�X�^ */
#define ETHERC_TPAUSECR		((uint32_t *)0x000C0168)	/* PAUSE�t���[���đ��񐔃J�E���^ */
#define ETHERC_BCFRR		((uint32_t *)0x000C016C)	/* Broadcast�t���[����M�񐔐ݒ背�W�X�^ */
#define ETHERC_MAHR			((uint32_t *)0x000C01C0)	/* MAC�A�h���X��ʐݒ背�W�X�^ */
#define ETHERC_MALR			((uint32_t *)0x000C01C8)	/* MAC�A�h���X���ʐݒ背�W�X�^ */
#define ETHERC_TROCR		((uint32_t *)0x000C01D0)	/* ���M���g���C�I�[�o�J�E���^���W�X�^ */
#define ETHERC_CDCR			((uint32_t *)0x000C01D4)	/* �x���Փˌ��o�J�E���^���W�X�^ */
#define ETHERC_LCCR			((uint32_t *)0x000C01D8)	/* �L�����A�����J�E���^���W�X�^ */
#define ETHERC_CNDCR		((uint32_t *)0x000C01DC)	/* �L�����A�����o�J�E���^���W�X�^ */
#define ETHERC_CEFCR		((uint32_t *)0x000C01E4)	/* CRC�G���[�t���[����M�J�E���^���W�X�^ */
#define ETHERC_FRECR		((uint32_t *)0x000C01E8)	/* �t���[����M�G���[�J�E���^���W�X�^ */
#define ETHERC_TSFRCR		((uint32_t *)0x000C01EC)	/* 64�o�C�g�����t���[����M�J�E���^���W�X�^ */
#define ETHERC_TLFRCR		((uint32_t *)0x000C01F0)	/* �w��o�C�g���t���[����M�J�E���^���W�X�^ */
#define ETHERC_RFCR			((uint32_t *)0x000C01F4)	/* �[���r�b�g�t���[����M�J�E���^���W�X�^ */
#define ETHERC_MAFCR		((uint32_t *)0x000C01F8)	/* �}���`�L���X�g�A�h���X�t���[����M�J�E���^���W�X�^ */

/* ���M�f�B�X�N���v�^ */
typedef struct t_rx62n_tx_desc {
	uint32_t	tfs : 26;
	uint32_t	twbi : 1;
	uint32_t	tfe : 1;
	uint32_t	tfp : 2;
	uint32_t	tdle : 1;
	uint32_t	tact : 1;
	uint32_t	: 16;
	uint32_t	tbl : 16;
	uint32_t	tba;
	uint32_t	binding;
} T_RX62N_TX_DESC;

/* ��M�f�B�X�N���v�^ */
typedef struct t_rx62n_rx_desc {
	uint32_t	rfs : 27;
	uint32_t	rfe : 1;
	uint32_t	rfp : 2;
	uint32_t	rdle : 1;
	uint32_t	ract : 1;
	uint32_t	rfl : 16;
	uint32_t	rbl : 16;
	uint32_t	rba;
	uint32_t	binding;
} T_RX62N_RX_DESC;

#endif /* RX62NRegH */
