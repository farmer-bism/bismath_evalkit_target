;
;  RX610アーキテクチャ依存出力ファイル
;
;  割込みベクタ及び割込みハンドラ定義
;


	.text
	.extern	_kernel_interrupt
	.extern	__kernel_default_int_handler
	.extern	__kernel_default_exc_handler


	.extern	_target_timer_handler
	.global	__kernel_target_timer_handler_28_entry
__kernel_target_timer_handler_28_entry:
	pushm	r1-r5						; スクラッチレジスタをタスクスタックへ退避 
	mov.l	#28, r1	; 割込みハンドラ番号をr1へ 
	mov.l	#_target_timer_handler, r2	; ハンドラのアドレスをr2へ 
	bra.a	_kernel_interrupt			; 共通ルーチンへ 


	.extern	__kernel_inthdr_217
	.global	__kernel__kernel_inthdr_217_217_entry
__kernel__kernel_inthdr_217_217_entry:
	pushm	r1-r5						; スクラッチレジスタをタスクスタックへ退避 
	mov.l	#217, r1	; 割込みハンドラ番号をr1へ 
	mov.l	#__kernel_inthdr_217, r2	; ハンドラのアドレスをr2へ 
	bra.a	_kernel_interrupt			; 共通ルーチンへ 


	.extern	__kernel_inthdr_219
	.global	__kernel__kernel_inthdr_219_219_entry
__kernel__kernel_inthdr_219_219_entry:
	pushm	r1-r5						; スクラッチレジスタをタスクスタックへ退避 
	mov.l	#219, r1	; 割込みハンドラ番号をr1へ 
	mov.l	#__kernel_inthdr_219, r2	; ハンドラのアドレスをr2へ 
	bra.a	_kernel_interrupt			; 共通ルーチンへ 


	.extern	__kernel_default_int_handler_entry
__kernel_default_int_handler_entry:
	pushm	r1-r5								; スクラッチレジスタをタスクスタックへ退避 
	mov.l	#0FFFFFFFFH, r1						; 割込みハンドラ番号をr1へ 
	mov.l	#__kernel_default_int_handler, r2	; ハンドラのアドレスをr2へ 
	bra.a	_kernel_interrupt					; 共通ルーチンへ 


	.extern	_kernel_exception

	.extern	__kernel_default_exc_handler_entry
__kernel_default_exc_handler_entry:
	pushm	r1-r5								; スクラッチレジスタをタスクスタックへ退避 
	mov.l	#0FFFFFFFFH, r1						; CPU例外ハンドラ番号をr1へ 
	mov.l	#__kernel_default_exc_handler, r2	; ハンドラのアドレスをr2へ 
	bra.a	_kernel_exception					; 共通ルーチンへ 


;
;  可変ベクタテーブル
;

	.extern 	 _start


	.section C$VECT

	.glb __vvector_table

__vvector_table:
	.word	__kernel_default_int_handler_entry 	 	 ; 00 
	.word	__kernel_default_int_handler_entry 	 	 ; 01 
	.word	__kernel_default_int_handler_entry 	 	 ; 02 
	.word	__kernel_default_int_handler_entry 	 	 ; 03 
	.word	__kernel_default_int_handler_entry 	 	 ; 04 
	.word	__kernel_default_int_handler_entry 	 	 ; 05 
	.word	__kernel_default_int_handler_entry 	 	 ; 06 
	.word	__kernel_default_int_handler_entry 	 	 ; 07 
	.word	__kernel_default_int_handler_entry 	 	 ; 08 
	.word	__kernel_default_int_handler_entry 	 	 ; 09 
	.word	__kernel_default_int_handler_entry 	 	 ; 10 
	.word	__kernel_default_int_handler_entry 	 	 ; 11 
	.word	__kernel_default_int_handler_entry 	 	 ; 12 
	.word	__kernel_default_int_handler_entry 	 	 ; 13 
	.word	__kernel_default_int_handler_entry 	 	 ; 14 
	.word	__kernel_default_int_handler_entry 	 	 ; 15 
	.word	__kernel_default_int_handler_entry 	 	 ; 16 
	.word	__kernel_default_int_handler_entry 	 	 ; 17 
	.word	__kernel_default_int_handler_entry 	 	 ; 18 
	.word	__kernel_default_int_handler_entry 	 	 ; 19 
	.word	__kernel_default_int_handler_entry 	 	 ; 20 
	.word	__kernel_default_int_handler_entry 	 	 ; 21 
	.word	__kernel_default_int_handler_entry 	 	 ; 22 
	.word	__kernel_default_int_handler_entry 	 	 ; 23 
	.word	__kernel_default_int_handler_entry 	 	 ; 24 
	.word	__kernel_default_int_handler_entry 	 	 ; 25 
	.word	__kernel_default_int_handler_entry 	 	 ; 26 
	.word	__kernel_default_int_handler_entry 	 	 ; 27 
	.word	__kernel_target_timer_handler_28_entry 	 	 ; 28 
	.word	__kernel_default_int_handler_entry 	 	 ; 29 
	.word	__kernel_default_int_handler_entry 	 	 ; 30 
	.word	__kernel_default_int_handler_entry 	 	 ; 31 
	.word	__kernel_default_int_handler_entry 	 	 ; 32 
	.word	__kernel_default_int_handler_entry 	 	 ; 33 
	.word	__kernel_default_int_handler_entry 	 	 ; 34 
	.word	__kernel_default_int_handler_entry 	 	 ; 35 
	.word	__kernel_default_int_handler_entry 	 	 ; 36 
	.word	__kernel_default_int_handler_entry 	 	 ; 37 
	.word	__kernel_default_int_handler_entry 	 	 ; 38 
	.word	__kernel_default_int_handler_entry 	 	 ; 39 
	.word	__kernel_default_int_handler_entry 	 	 ; 40 
	.word	__kernel_default_int_handler_entry 	 	 ; 41 
	.word	__kernel_default_int_handler_entry 	 	 ; 42 
	.word	__kernel_default_int_handler_entry 	 	 ; 43 
	.word	__kernel_default_int_handler_entry 	 	 ; 44 
	.word	__kernel_default_int_handler_entry 	 	 ; 45 
	.word	__kernel_default_int_handler_entry 	 	 ; 46 
	.word	__kernel_default_int_handler_entry 	 	 ; 47 
	.word	__kernel_default_int_handler_entry 	 	 ; 48 
	.word	__kernel_default_int_handler_entry 	 	 ; 49 
	.word	__kernel_default_int_handler_entry 	 	 ; 50 
	.word	__kernel_default_int_handler_entry 	 	 ; 51 
	.word	__kernel_default_int_handler_entry 	 	 ; 52 
	.word	__kernel_default_int_handler_entry 	 	 ; 53 
	.word	__kernel_default_int_handler_entry 	 	 ; 54 
	.word	__kernel_default_int_handler_entry 	 	 ; 55 
	.word	__kernel_default_int_handler_entry 	 	 ; 56 
	.word	__kernel_default_int_handler_entry 	 	 ; 57 
	.word	__kernel_default_int_handler_entry 	 	 ; 58 
	.word	__kernel_default_int_handler_entry 	 	 ; 59 
	.word	__kernel_default_int_handler_entry 	 	 ; 60 
	.word	__kernel_default_int_handler_entry 	 	 ; 61 
	.word	__kernel_default_int_handler_entry 	 	 ; 62 
	.word	__kernel_default_int_handler_entry 	 	 ; 63 
	.word	__kernel_default_int_handler_entry 	 	 ; 64 
	.word	__kernel_default_int_handler_entry 	 	 ; 65 
	.word	__kernel_default_int_handler_entry 	 	 ; 66 
	.word	__kernel_default_int_handler_entry 	 	 ; 67 
	.word	__kernel_default_int_handler_entry 	 	 ; 68 
	.word	__kernel_default_int_handler_entry 	 	 ; 69 
	.word	__kernel_default_int_handler_entry 	 	 ; 70 
	.word	__kernel_default_int_handler_entry 	 	 ; 71 
	.word	__kernel_default_int_handler_entry 	 	 ; 72 
	.word	__kernel_default_int_handler_entry 	 	 ; 73 
	.word	__kernel_default_int_handler_entry 	 	 ; 74 
	.word	__kernel_default_int_handler_entry 	 	 ; 75 
	.word	__kernel_default_int_handler_entry 	 	 ; 76 
	.word	__kernel_default_int_handler_entry 	 	 ; 77 
	.word	__kernel_default_int_handler_entry 	 	 ; 78 
	.word	__kernel_default_int_handler_entry 	 	 ; 79 
	.word	__kernel_default_int_handler_entry 	 	 ; 80 
	.word	__kernel_default_int_handler_entry 	 	 ; 81 
	.word	__kernel_default_int_handler_entry 	 	 ; 82 
	.word	__kernel_default_int_handler_entry 	 	 ; 83 
	.word	__kernel_default_int_handler_entry 	 	 ; 84 
	.word	__kernel_default_int_handler_entry 	 	 ; 85 
	.word	__kernel_default_int_handler_entry 	 	 ; 86 
	.word	__kernel_default_int_handler_entry 	 	 ; 87 
	.word	__kernel_default_int_handler_entry 	 	 ; 88 
	.word	__kernel_default_int_handler_entry 	 	 ; 89 
	.word	__kernel_default_int_handler_entry 	 	 ; 90 
	.word	__kernel_default_int_handler_entry 	 	 ; 91 
	.word	__kernel_default_int_handler_entry 	 	 ; 92 
	.word	__kernel_default_int_handler_entry 	 	 ; 93 
	.word	__kernel_default_int_handler_entry 	 	 ; 94 
	.word	__kernel_default_int_handler_entry 	 	 ; 95 
	.word	__kernel_default_int_handler_entry 	 	 ; 96 
	.word	__kernel_default_int_handler_entry 	 	 ; 97 
	.word	__kernel_default_int_handler_entry 	 	 ; 98 
	.word	__kernel_default_int_handler_entry 	 	 ; 99 
	.word	__kernel_default_int_handler_entry 	 	 ; 100 
	.word	__kernel_default_int_handler_entry 	 	 ; 101 
	.word	__kernel_default_int_handler_entry 	 	 ; 102 
	.word	__kernel_default_int_handler_entry 	 	 ; 103 
	.word	__kernel_default_int_handler_entry 	 	 ; 104 
	.word	__kernel_default_int_handler_entry 	 	 ; 105 
	.word	__kernel_default_int_handler_entry 	 	 ; 106 
	.word	__kernel_default_int_handler_entry 	 	 ; 107 
	.word	__kernel_default_int_handler_entry 	 	 ; 108 
	.word	__kernel_default_int_handler_entry 	 	 ; 109 
	.word	__kernel_default_int_handler_entry 	 	 ; 110 
	.word	__kernel_default_int_handler_entry 	 	 ; 111 
	.word	__kernel_default_int_handler_entry 	 	 ; 112 
	.word	__kernel_default_int_handler_entry 	 	 ; 113 
	.word	__kernel_default_int_handler_entry 	 	 ; 114 
	.word	__kernel_default_int_handler_entry 	 	 ; 115 
	.word	__kernel_default_int_handler_entry 	 	 ; 116 
	.word	__kernel_default_int_handler_entry 	 	 ; 117 
	.word	__kernel_default_int_handler_entry 	 	 ; 118 
	.word	__kernel_default_int_handler_entry 	 	 ; 119 
	.word	__kernel_default_int_handler_entry 	 	 ; 120 
	.word	__kernel_default_int_handler_entry 	 	 ; 121 
	.word	__kernel_default_int_handler_entry 	 	 ; 122 
	.word	__kernel_default_int_handler_entry 	 	 ; 123 
	.word	__kernel_default_int_handler_entry 	 	 ; 124 
	.word	__kernel_default_int_handler_entry 	 	 ; 125 
	.word	__kernel_default_int_handler_entry 	 	 ; 126 
	.word	__kernel_default_int_handler_entry 	 	 ; 127 
	.word	__kernel_default_int_handler_entry 	 	 ; 128 
	.word	__kernel_default_int_handler_entry 	 	 ; 129 
	.word	__kernel_default_int_handler_entry 	 	 ; 130 
	.word	__kernel_default_int_handler_entry 	 	 ; 131 
	.word	__kernel_default_int_handler_entry 	 	 ; 132 
	.word	__kernel_default_int_handler_entry 	 	 ; 133 
	.word	__kernel_default_int_handler_entry 	 	 ; 134 
	.word	__kernel_default_int_handler_entry 	 	 ; 135 
	.word	__kernel_default_int_handler_entry 	 	 ; 136 
	.word	__kernel_default_int_handler_entry 	 	 ; 137 
	.word	__kernel_default_int_handler_entry 	 	 ; 138 
	.word	__kernel_default_int_handler_entry 	 	 ; 139 
	.word	__kernel_default_int_handler_entry 	 	 ; 140 
	.word	__kernel_default_int_handler_entry 	 	 ; 141 
	.word	__kernel_default_int_handler_entry 	 	 ; 142 
	.word	__kernel_default_int_handler_entry 	 	 ; 143 
	.word	__kernel_default_int_handler_entry 	 	 ; 144 
	.word	__kernel_default_int_handler_entry 	 	 ; 145 
	.word	__kernel_default_int_handler_entry 	 	 ; 146 
	.word	__kernel_default_int_handler_entry 	 	 ; 147 
	.word	__kernel_default_int_handler_entry 	 	 ; 148 
	.word	__kernel_default_int_handler_entry 	 	 ; 149 
	.word	__kernel_default_int_handler_entry 	 	 ; 150 
	.word	__kernel_default_int_handler_entry 	 	 ; 151 
	.word	__kernel_default_int_handler_entry 	 	 ; 152 
	.word	__kernel_default_int_handler_entry 	 	 ; 153 
	.word	__kernel_default_int_handler_entry 	 	 ; 154 
	.word	__kernel_default_int_handler_entry 	 	 ; 155 
	.word	__kernel_default_int_handler_entry 	 	 ; 156 
	.word	__kernel_default_int_handler_entry 	 	 ; 157 
	.word	__kernel_default_int_handler_entry 	 	 ; 158 
	.word	__kernel_default_int_handler_entry 	 	 ; 159 
	.word	__kernel_default_int_handler_entry 	 	 ; 160 
	.word	__kernel_default_int_handler_entry 	 	 ; 161 
	.word	__kernel_default_int_handler_entry 	 	 ; 162 
	.word	__kernel_default_int_handler_entry 	 	 ; 163 
	.word	__kernel_default_int_handler_entry 	 	 ; 164 
	.word	__kernel_default_int_handler_entry 	 	 ; 165 
	.word	__kernel_default_int_handler_entry 	 	 ; 166 
	.word	__kernel_default_int_handler_entry 	 	 ; 167 
	.word	__kernel_default_int_handler_entry 	 	 ; 168 
	.word	__kernel_default_int_handler_entry 	 	 ; 169 
	.word	__kernel_default_int_handler_entry 	 	 ; 170 
	.word	__kernel_default_int_handler_entry 	 	 ; 171 
	.word	__kernel_default_int_handler_entry 	 	 ; 172 
	.word	__kernel_default_int_handler_entry 	 	 ; 173 
	.word	__kernel_default_int_handler_entry 	 	 ; 174 
	.word	__kernel_default_int_handler_entry 	 	 ; 175 
	.word	__kernel_default_int_handler_entry 	 	 ; 176 
	.word	__kernel_default_int_handler_entry 	 	 ; 177 
	.word	__kernel_default_int_handler_entry 	 	 ; 178 
	.word	__kernel_default_int_handler_entry 	 	 ; 179 
	.word	__kernel_default_int_handler_entry 	 	 ; 180 
	.word	__kernel_default_int_handler_entry 	 	 ; 181 
	.word	__kernel_default_int_handler_entry 	 	 ; 182 
	.word	__kernel_default_int_handler_entry 	 	 ; 183 
	.word	__kernel_default_int_handler_entry 	 	 ; 184 
	.word	__kernel_default_int_handler_entry 	 	 ; 185 
	.word	__kernel_default_int_handler_entry 	 	 ; 186 
	.word	__kernel_default_int_handler_entry 	 	 ; 187 
	.word	__kernel_default_int_handler_entry 	 	 ; 188 
	.word	__kernel_default_int_handler_entry 	 	 ; 189 
	.word	__kernel_default_int_handler_entry 	 	 ; 190 
	.word	__kernel_default_int_handler_entry 	 	 ; 191 
	.word	__kernel_default_int_handler_entry 	 	 ; 192 
	.word	__kernel_default_int_handler_entry 	 	 ; 193 
	.word	__kernel_default_int_handler_entry 	 	 ; 194 
	.word	__kernel_default_int_handler_entry 	 	 ; 195 
	.word	__kernel_default_int_handler_entry 	 	 ; 196 
	.word	__kernel_default_int_handler_entry 	 	 ; 197 
	.word	__kernel_default_int_handler_entry 	 	 ; 198 
	.word	__kernel_default_int_handler_entry 	 	 ; 199 
	.word	__kernel_default_int_handler_entry 	 	 ; 200 
	.word	__kernel_default_int_handler_entry 	 	 ; 201 
	.word	__kernel_default_int_handler_entry 	 	 ; 202 
	.word	__kernel_default_int_handler_entry 	 	 ; 203 
	.word	__kernel_default_int_handler_entry 	 	 ; 204 
	.word	__kernel_default_int_handler_entry 	 	 ; 205 
	.word	__kernel_default_int_handler_entry 	 	 ; 206 
	.word	__kernel_default_int_handler_entry 	 	 ; 207 
	.word	__kernel_default_int_handler_entry 	 	 ; 208 
	.word	__kernel_default_int_handler_entry 	 	 ; 209 
	.word	__kernel_default_int_handler_entry 	 	 ; 210 
	.word	__kernel_default_int_handler_entry 	 	 ; 211 
	.word	__kernel_default_int_handler_entry 	 	 ; 212 
	.word	__kernel_default_int_handler_entry 	 	 ; 213 
	.word	__kernel_default_int_handler_entry 	 	 ; 214 
	.word	__kernel_default_int_handler_entry 	 	 ; 215 
	.word	__kernel_default_int_handler_entry 	 	 ; 216 
	.word	__kernel__kernel_inthdr_217_217_entry 	 	 ; 217 
	.word	__kernel_default_int_handler_entry 	 	 ; 218 
	.word	__kernel__kernel_inthdr_219_219_entry 	 	 ; 219 
	.word	__kernel_default_int_handler_entry 	 	 ; 220 
	.word	__kernel_default_int_handler_entry 	 	 ; 221 
	.word	__kernel_default_int_handler_entry 	 	 ; 222 
	.word	__kernel_default_int_handler_entry 	 	 ; 223 
	.word	__kernel_default_int_handler_entry 	 	 ; 224 
	.word	__kernel_default_int_handler_entry 	 	 ; 225 
	.word	__kernel_default_int_handler_entry 	 	 ; 226 
	.word	__kernel_default_int_handler_entry 	 	 ; 227 
	.word	__kernel_default_int_handler_entry 	 	 ; 228 
	.word	__kernel_default_int_handler_entry 	 	 ; 229 
	.word	__kernel_default_int_handler_entry 	 	 ; 230 
	.word	__kernel_default_int_handler_entry 	 	 ; 231 
	.word	__kernel_default_int_handler_entry 	 	 ; 232 
	.word	__kernel_default_int_handler_entry 	 	 ; 233 
	.word	__kernel_default_int_handler_entry 	 	 ; 234 
	.word	__kernel_default_int_handler_entry 	 	 ; 235 
	.word	__kernel_default_int_handler_entry 	 	 ; 236 
	.word	__kernel_default_int_handler_entry 	 	 ; 237 
	.word	__kernel_default_int_handler_entry 	 	 ; 238 
	.word	__kernel_default_int_handler_entry 	 	 ; 239 
	.word	__kernel_default_int_handler_entry 	 	 ; 240 
	.word	__kernel_default_int_handler_entry 	 	 ; 241 
	.word	__kernel_default_int_handler_entry 	 	 ; 242 
	.word	__kernel_default_int_handler_entry 	 	 ; 243 
	.word	__kernel_default_int_handler_entry 	 	 ; 244 
	.word	__kernel_default_int_handler_entry 	 	 ; 245 
	.word	__kernel_default_int_handler_entry 	 	 ; 246 
	.word	__kernel_default_int_handler_entry 	 	 ; 247 
	.word	__kernel_default_int_handler_entry 	 	 ; 248 
	.word	__kernel_default_int_handler_entry 	 	 ; 249 
	.word	__kernel_default_int_handler_entry 	 	 ; 250 
	.word	__kernel_default_int_handler_entry 	 	 ; 251 
	.word	__kernel_default_int_handler_entry 	 	 ; 252 
	.word	__kernel_default_int_handler_entry 	 	 ; 253 
	.word	__kernel_default_int_handler_entry 	 	 ; 254 
	.word	__kernel_default_int_handler_entry 	 	 ; 255 

;
;  固定ベクタテーブル
;

	 .section .fvect,ROMDATA,align=4 
	 .glb fvector_table 
fvector_table:

	 .space	 0x1c
	 .word	 0xFFFFFFFF 	 ; ROMコード(0xFFFFFF9C)
	 .word	 0xFFFFFFFF 	 ; 制御コード(0xFFFFFFA0), IDコード1 - 3
	 .word	 0xFFFFFFFF 	 ; IDコード4 - 7
	 .word	 0xFFFFFFFF 	 ; IDコード8 - 11
	 .word	 0xFFFFFFFF 	 ; IDコード12 - 15
	 .space	 0x20
	 .word	 __kernel_default_exc_handler_entry 	 	 ;  20:特権命令例外  
	 .space	 0x8
	 .word	 __kernel_default_exc_handler_entry 	 	 ;  23:未定義命令例外  
	 .space	 0x4
	 .word	 __kernel_default_exc_handler_entry 	 	 ;  25:浮動小数点例外  
	 .space	 0x10
	 .word	 __kernel_default_exc_handler_entry 	 	 ;  30:ノンマスカブル例外  
	 .word	 _start 	 	 	 	 ;  31:リセット  

 
	.end
