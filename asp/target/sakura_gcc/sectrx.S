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

	.section	SI,"aw",@nobits
	.balign 4
	.glb _DEFAULT_ISTACK
_DEFAULT_ISTACK:
	.blkb		0x0500
	.glb DEFAULT_ISTACK_TOP
DEFAULT_ISTACK_TOP:





