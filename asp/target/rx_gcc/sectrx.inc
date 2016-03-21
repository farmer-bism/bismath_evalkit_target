;*
;*  TOPPERS/ASP Kernel
;*      Toyohashi Open Platform for Embedded Real-Time Systems/
;*      Advanced Standard Profile Kernel
;* 
;*  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
;* 
;*  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
;*  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
;*  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
;*  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
;*  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;*  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
;*      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
;*      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
;*  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
;*      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
;*      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
;*      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;*  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
;*      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
;*    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
;*        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;*    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
;*        ���ƁD
;*  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
;*      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
;* 
;*  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
;*  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
;*  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
;*  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
;*


;
;  �^�[�Q�b�g�V�X�e���ˑ��Z�N�V������`�t�@�C��(�X�^�[�^�[�L�b�g�p)
;

;
;  �Z�N�V�����̒�`
;
;  �Z�N�V�����̃A�h���X��`��HEW��̍œK�������J��
;  �I�v�V�����ɂĎ��{����.
;

	;
	;  �����l�L��f�[�^�̈�̃Z�N�V����
	;
	;  00000000h - 00020000h
	;
	.section	D, ROMDATA
	.section	D_2, ROMDATA, ALIGN = 2
	.section	D_1, ROMDATA


	;
	;  �����l�����f�[�^�̈�̃Z�N�V����
	;
	;  00000000h - 00020000h
	;
	.section	B, DATA, ALIGN = 4
	.section	B_2, DATA, ALIGN = 2
	.section	B_1, DATA

	;
	;  �J�[�l���X�^�b�N�̈�̃Z�N�V����
	;
	;  00000000h - 00020000h
	;
	;  �ȉ�.blkb���߂Ŋm�ۂ��Ă���J�[�l���X�^�b�N�̈�̃T�C�Y��
	;  �ύX����ꍇ��, target_config.h��DEFAULT_ISTKSZ�̒l��, ����
	;  �l�ɕύX���邱��.
	;
	.section	SI, DATA, ALIGN = 4
	.glb _DEFAULT_ISTACK
_DEFAULT_ISTACK:
	.blkb		0500H
	.glb DEFAULT_ISTACK_TOP
DEFAULT_ISTACK_TOP:

	;
	;  �萔�̈�̃Z�N�V����
	;
	;  00100000h - 00107FFFh
	;
	.section	C, ROMDATA, ALIGN = 4
	.section	C_2, ROMDATA, ALIGN = 2
	.section	C_1, ROMDATA

	;
	;  �����l�L��f�[�^�̈�̏����l
	;
	;  00100000h - 00107FFFh
	;
	.section	R, DATA, ALIGN = 4
	.section	R_2, DATA, ALIGN = 2
	.section	R_1, DATA

	;
	;  �σx�N�^�e�[�u���̈�̃Z�N�V����
	;
	;  00100000h - 00107FFFh
	;
	.section	C$VECT, ROMDATA, ALIGN = 4
	.glb VVECTOR_TOP
VVECTOR_TOP:

	;
	;  �v���O�����̈�̃Z�N�V����
	;
	;  FFE80000h - FFFFFF7Fh
	;
	.section	P, CODE

	;
	;  �Œ�x�N�^�e�[�u���̈�̃Z�N�V����
	;
	;  FFFFFF80h - FFFFFFFFh
	;
	.section	FVECT, ROMDATA, ALIGN = 4
