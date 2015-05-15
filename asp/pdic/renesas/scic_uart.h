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
 *  RX610 UART�p �Ȉ�SIO�h���C�o
 */

#ifndef TOPPERS_RX610_UART_H
#define TOPPERS_RX610_UART_H

/* �w��\�ȃN���b�N�\�[�X */
#define CLK_F1	UINT_C(0x00)
#define CLK_F4	UINT_C(0x01)
#define CLK_F16	UINT_C(0x02)
#define CLK_F64	UINT_C(0x03)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block	SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_RDY_SND    (1U)        /* ���M�\�R�[���o�b�N */
#define SIO_RDY_RCV    (2U)        /* ��M�ʒm�R�[���o�b�N */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void scic_uart_initialize(void);

/*
 * �J�[�l���N�����̃o�i�[�o�͗p�̏�����
 */
extern void scic_uart_init(ID siopid , uint8_t baud , uint8_t clksrc);

/*
 *  �V���A��I/O�|�[�g�ւ̃|�[�����O�ł̏o��
 */
extern void scic_uart_pol_putc(char c, ID siopid);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB *scic_uart_opn_por
	(ID siopid, intptr_t exinf , uint8_t baud , uint8_t clksrc);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void scic_uart_cls_por(SIOPCB *p_siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern bool_t scic_uart_snd_chr(SIOPCB *p_siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern int_t scic_uart_rcv_chr(SIOPCB *p_siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void  scic_uart_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void scic_uart_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void scic_uart_tx_isr(ID siopid);
extern void scic_uart_rx_isr(ID siopid);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void scic_uart_irdy_snd(intptr_t exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void scic_uart_irdy_rcv(intptr_t exinf);


#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_RX610_UART_H */