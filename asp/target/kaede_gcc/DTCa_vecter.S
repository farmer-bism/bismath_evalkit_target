/*
 * Copyright (c) 2015- Hisashi Hata
 * Released under the toppers license
 * https://www.toppers.jp/license.html
 */

#include "target_device/use_device.h"
    
.section DTCA_VECTOR_SEC, "aw", @nobits
.glb _dtca_table
    
_dtca_table:
#ifdef USE_DTCA_0
	.space		0400H
#else
	.space		4H
#endif
	.glb _dtca_vector_end
_dtca_vector_end:
