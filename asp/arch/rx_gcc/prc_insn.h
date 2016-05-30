/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *		�v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iRX�p�j
 */

#ifndef	TOPPERS_PRC_INSN_H
#define	TOPPERS_PRC_INSN_H


static uint32_t current_psw( void );
static void set_psw( uint32_t psw );
Inline uint32_t current_ipl( void );
Inline void set_ipl( uint32_t ipl );
static void disint( void );
static void enaint( void );
static uint16_t rev_endian_uint16( uint16_t data );
static uint32_t rev_endian_uint32( uint32_t data );


/*
 *  I�t���O, IPL���擾���邽�߂̃}�N����`
 */
#define PSW_I_MASK		( 0x00010000UL )
#define PSW_IPL_MASK	( 0x07000000UL )


/*
 *  �v���Z�b�T�X�e�[�^�X���W�X�^(PSW)�̌��ݒl�̓Ǐo��
 */
static uint32_t
current_psw( void )
{
  uint32_t load_psw;
  __asm__("mvfc	psw, %0" : "=r"(load_psw) :);
  return load_psw;
}


/*
 *  �v���Z�b�T�X�e�[�^�X���W�X�^(PSW)�֐ݒ�
 */
static void
set_psw( uint32_t psw )
{
  __asm__("mvtc	%0, psw"::"r"(psw));
}


/*
 *  IPL�̌��ݒl�̓Ǐo��
 */
Inline uint32_t
current_ipl( void )
{
	return ( uint32_t )( current_psw() & PSW_IPL_MASK );
}


/*
 *  IPL�֐ݒ�
 */
Inline void
set_ipl( uint32_t ipl )
{
	set_psw( ( current_psw() & ( ~PSW_IPL_MASK ) ) | ipl );
}


/*
 *  NMI���������ׂĂ̊����݂̋֎~
 */
static void
disint( void )
{
  __asm__("clrpsw	I");
}


/*
 *  NMI���������ׂĂ̊����݂̋���
 */
static void
enaint( void )
{
  __asm__("setpsw	I");
}


/*
 *  �G���f�B�A���ϊ� 16bit
 */
static inline uint16_t
rev_endian_uint16( uint16_t data )
{
  __asm__("revw	%0, %1":"=r"(data):"r"(data));
  return data;
}

/*
 *  �G���f�B�A���ϊ� 32bit
 */
static inline uint32_t
rev_endian_uint32( uint32_t data )
{
  __asm__("revl	%1, %0":"=r"(data):"r"(data));
  return data;
}


#endif /* TOPPERS_PRC_INSN_H */
