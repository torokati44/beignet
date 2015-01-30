DECL_LLVM_GEN_FUNCTION(GET_GROUP_ID0, __gen_ocl_get_group_id0)
DECL_LLVM_GEN_FUNCTION(GET_GROUP_ID1, __gen_ocl_get_group_id1)
DECL_LLVM_GEN_FUNCTION(GET_GROUP_ID2, __gen_ocl_get_group_id2)
DECL_LLVM_GEN_FUNCTION(GET_LOCAL_ID0, __gen_ocl_get_local_id0)
DECL_LLVM_GEN_FUNCTION(GET_LOCAL_ID1, __gen_ocl_get_local_id1)
DECL_LLVM_GEN_FUNCTION(GET_LOCAL_ID2, __gen_ocl_get_local_id2)
DECL_LLVM_GEN_FUNCTION(GET_NUM_GROUPS0, __gen_ocl_get_num_groups0)
DECL_LLVM_GEN_FUNCTION(GET_NUM_GROUPS1, __gen_ocl_get_num_groups1)
DECL_LLVM_GEN_FUNCTION(GET_NUM_GROUPS2, __gen_ocl_get_num_groups2)
DECL_LLVM_GEN_FUNCTION(GET_LOCAL_SIZE0, __gen_ocl_get_local_size0)
DECL_LLVM_GEN_FUNCTION(GET_LOCAL_SIZE1, __gen_ocl_get_local_size1)
DECL_LLVM_GEN_FUNCTION(GET_LOCAL_SIZE2, __gen_ocl_get_local_size2)
DECL_LLVM_GEN_FUNCTION(GET_GLOBAL_SIZE0, __gen_ocl_get_global_size0)
DECL_LLVM_GEN_FUNCTION(GET_GLOBAL_SIZE1, __gen_ocl_get_global_size1)
DECL_LLVM_GEN_FUNCTION(GET_GLOBAL_SIZE2, __gen_ocl_get_global_size2)
DECL_LLVM_GEN_FUNCTION(GET_GLOBAL_OFFSET0, __gen_ocl_get_global_offset0)
DECL_LLVM_GEN_FUNCTION(GET_GLOBAL_OFFSET1, __gen_ocl_get_global_offset1)
DECL_LLVM_GEN_FUNCTION(GET_GLOBAL_OFFSET2, __gen_ocl_get_global_offset2)
DECL_LLVM_GEN_FUNCTION(GET_WORK_DIM, __gen_ocl_get_work_dim)

// Math function
DECL_LLVM_GEN_FUNCTION(FABS, __gen_ocl_fabs)
DECL_LLVM_GEN_FUNCTION(SQR, __gen_ocl_sqrt)
DECL_LLVM_GEN_FUNCTION(RSQ, __gen_ocl_rsqrt)
DECL_LLVM_GEN_FUNCTION(LOG, __gen_ocl_log)
DECL_LLVM_GEN_FUNCTION(EXP, __gen_ocl_exp)
DECL_LLVM_GEN_FUNCTION(POW, __gen_ocl_pow)
DECL_LLVM_GEN_FUNCTION(RCP, __gen_ocl_rcp)
DECL_LLVM_GEN_FUNCTION(RNDZ, __gen_ocl_rndz)
DECL_LLVM_GEN_FUNCTION(RNDE, __gen_ocl_rnde)
DECL_LLVM_GEN_FUNCTION(RNDU, __gen_ocl_rndu)
DECL_LLVM_GEN_FUNCTION(RNDD, __gen_ocl_rndd)
DECL_LLVM_GEN_FUNCTION(MAD, __gen_ocl_mad)
DECL_LLVM_GEN_FUNCTION(FMAX, __gen_ocl_fmax)
DECL_LLVM_GEN_FUNCTION(FMIN, __gen_ocl_fmin)

// Barrier function
DECL_LLVM_GEN_FUNCTION(LBARRIER, __gen_ocl_barrier_local)
DECL_LLVM_GEN_FUNCTION(GBARRIER, __gen_ocl_barrier_global)
DECL_LLVM_GEN_FUNCTION(LGBARRIER, __gen_ocl_barrier_local_and_global)

// To force SIMD8/16 compilation
DECL_LLVM_GEN_FUNCTION(FORCE_SIMD8,  __gen_ocl_force_simd8)
DECL_LLVM_GEN_FUNCTION(FORCE_SIMD16, __gen_ocl_force_simd16)

// To read_image functions.
DECL_LLVM_GEN_FUNCTION(READ_IMAGE_I, __gen_ocl_read_imagei)
DECL_LLVM_GEN_FUNCTION(READ_IMAGE_UI, __gen_ocl_read_imageui)
DECL_LLVM_GEN_FUNCTION(READ_IMAGE_F, __gen_ocl_read_imagef)

// To write_image functions.
DECL_LLVM_GEN_FUNCTION(WRITE_IMAGE_I, __gen_ocl_write_imagei)
DECL_LLVM_GEN_FUNCTION(WRITE_IMAGE_UI, __gen_ocl_write_imageui)
DECL_LLVM_GEN_FUNCTION(WRITE_IMAGE_F, __gen_ocl_write_imagef)

// To get image info function
DECL_LLVM_GEN_FUNCTION(GET_IMAGE_WIDTH, __gen_ocl_get_image_width)
DECL_LLVM_GEN_FUNCTION(GET_IMAGE_HEIGHT, __gen_ocl_get_image_height)
DECL_LLVM_GEN_FUNCTION(GET_IMAGE_DEPTH,  __gen_ocl_get_image_depth)
DECL_LLVM_GEN_FUNCTION(GET_IMAGE_CHANNEL_DATA_TYPE,  __gen_ocl_get_image_channel_data_type)
DECL_LLVM_GEN_FUNCTION(GET_IMAGE_CHANNEL_ORDER,  __gen_ocl_get_image_channel_order)

// atomic related functions.
DECL_LLVM_GEN_FUNCTION(ATOMIC_ADD0, _Z20__gen_ocl_atomic_addPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_ADD1, _Z20__gen_ocl_atomic_addPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_SUB0, _Z20__gen_ocl_atomic_subPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_SUB1, _Z20__gen_ocl_atomic_subPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_AND0, _Z20__gen_ocl_atomic_andPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_AND1, _Z20__gen_ocl_atomic_andPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_OR0,  _Z19__gen_ocl_atomic_orPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_OR1,  _Z19__gen_ocl_atomic_orPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_XOR0, _Z20__gen_ocl_atomic_xorPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_XOR1, _Z20__gen_ocl_atomic_xorPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_UMIN0, _Z21__gen_ocl_atomic_uminPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_UMIN1, _Z21__gen_ocl_atomic_uminPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_UMAX0, _Z21__gen_ocl_atomic_umaxPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_UMAX1, _Z21__gen_ocl_atomic_umaxPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_IMIN0, _Z21__gen_ocl_atomic_iminPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_IMIN1, _Z21__gen_ocl_atomic_iminPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_IMAX0, _Z21__gen_ocl_atomic_imaxPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_IMAX1, _Z21__gen_ocl_atomic_imaxPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_XCHG0, _Z21__gen_ocl_atomic_xchgPU3AS1jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_XCHG1, _Z21__gen_ocl_atomic_xchgPU3AS3jj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_INC0, _Z20__gen_ocl_atomic_incPU3AS1j)
DECL_LLVM_GEN_FUNCTION(ATOMIC_INC1, _Z20__gen_ocl_atomic_incPU3AS3j)
DECL_LLVM_GEN_FUNCTION(ATOMIC_DEC0, _Z20__gen_ocl_atomic_decPU3AS1j)
DECL_LLVM_GEN_FUNCTION(ATOMIC_DEC1, _Z20__gen_ocl_atomic_decPU3AS3j)
DECL_LLVM_GEN_FUNCTION(ATOMIC_CMPXCHG0, _Z24__gen_ocl_atomic_cmpxchgPU3AS1jjj)
DECL_LLVM_GEN_FUNCTION(ATOMIC_CMPXCHG1, _Z24__gen_ocl_atomic_cmpxchgPU3AS3jjj)

// saturation related functions.
DECL_LLVM_GEN_FUNCTION(SADD_SAT_CHAR, _Z12ocl_sadd_satcc)
DECL_LLVM_GEN_FUNCTION(SADD_SAT_SHORT, _Z12ocl_sadd_satss)
DECL_LLVM_GEN_FUNCTION(SADD_SAT_INT, _Z12ocl_sadd_satii)
DECL_LLVM_GEN_FUNCTION(SADD_SAT_LONG, _Z12ocl_sadd_satll)
DECL_LLVM_GEN_FUNCTION(UADD_SAT_CHAR, _Z12ocl_uadd_sathh)
DECL_LLVM_GEN_FUNCTION(UADD_SAT_SHORT, _Z12ocl_uadd_sattt)
DECL_LLVM_GEN_FUNCTION(UADD_SAT_INT, _Z12ocl_uadd_satjj)
DECL_LLVM_GEN_FUNCTION(UADD_SAT_LONG, _Z12ocl_uadd_satmm)

DECL_LLVM_GEN_FUNCTION(SSUB_SAT_CHAR, _Z12ocl_ssub_satcc)
DECL_LLVM_GEN_FUNCTION(SSUB_SAT_SHORT, _Z12ocl_ssub_satss)
DECL_LLVM_GEN_FUNCTION(SSUB_SAT_INT, _Z12ocl_ssub_satii)
DECL_LLVM_GEN_FUNCTION(SSUB_SAT_LONG, _Z12ocl_ssub_satll)
DECL_LLVM_GEN_FUNCTION(USUB_SAT_CHAR, _Z12ocl_usub_sathh)
DECL_LLVM_GEN_FUNCTION(USUB_SAT_SHORT, _Z12ocl_usub_sattt)
DECL_LLVM_GEN_FUNCTION(USUB_SAT_INT, _Z12ocl_usub_satjj)
DECL_LLVM_GEN_FUNCTION(USUB_SAT_LONG, _Z12ocl_usub_satmm)

DECL_LLVM_GEN_FUNCTION(I64_MAD_SAT, _Z17__gen_ocl_mad_satlll)
DECL_LLVM_GEN_FUNCTION(I64_MAD_SATU, _Z17__gen_ocl_mad_satmmm)

// integer built-in functions
DECL_LLVM_GEN_FUNCTION(MUL_HI_INT, _Z16__gen_ocl_mul_hiii)
DECL_LLVM_GEN_FUNCTION(MUL_HI_UINT, _Z16__gen_ocl_mul_hijj)
DECL_LLVM_GEN_FUNCTION(MUL_HI_I64, _Z16__gen_ocl_mul_hill)
DECL_LLVM_GEN_FUNCTION(MUL_HI_UI64, _Z16__gen_ocl_mul_himm)
DECL_LLVM_GEN_FUNCTION(FBH, __gen_ocl_fbh)
DECL_LLVM_GEN_FUNCTION(FBL, __gen_ocl_fbl)
DECL_LLVM_GEN_FUNCTION(ABS, __gen_ocl_abs)
DECL_LLVM_GEN_FUNCTION(HADD, _Z14__gen_ocl_haddjj)
DECL_LLVM_GEN_FUNCTION(RHADD, _Z15__gen_ocl_rhaddjj)
DECL_LLVM_GEN_FUNCTION(I64HADD, _Z14__gen_ocl_haddmm)
DECL_LLVM_GEN_FUNCTION(I64RHADD, _Z15__gen_ocl_rhaddmm)
DECL_LLVM_GEN_FUNCTION(UPSAMPLE_SHORT, _Z18__gen_ocl_upsampless)
DECL_LLVM_GEN_FUNCTION(UPSAMPLE_INT, _Z18__gen_ocl_upsampleii)
DECL_LLVM_GEN_FUNCTION(UPSAMPLE_LONG, _Z18__gen_ocl_upsamplell)
DECL_LLVM_GEN_FUNCTION(CBIT, __gen_ocl_cbit)

// saturate convert
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U8_TO_I8,  _Z16convert_char_sath)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_I16_TO_I8, _Z16convert_char_sats)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U16_TO_I8, _Z16convert_char_satt)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_I32_TO_I8, _Z16convert_char_sati)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U32_TO_I8, _Z16convert_char_satj)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_F32_TO_I8, _Z16convert_char_satf)

DECL_LLVM_GEN_FUNCTION(SAT_CONV_I8_TO_U8,  _Z17convert_uchar_satc)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_I16_TO_U8, _Z17convert_uchar_sats)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U16_TO_U8, _Z17convert_uchar_satt)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_I32_TO_U8, _Z17convert_uchar_sati)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U32_TO_U8, _Z17convert_uchar_satj)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_F32_TO_U8, _Z17convert_uchar_satf)

DECL_LLVM_GEN_FUNCTION(SAT_CONV_U16_TO_I16, _Z17convert_short_satt)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_I32_TO_I16, _Z17convert_short_sati)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U32_TO_I16, _Z17convert_short_satj)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_F32_TO_I16, _Z17convert_short_satf)

DECL_LLVM_GEN_FUNCTION(SAT_CONV_I16_TO_U16, _Z18convert_ushort_sats)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_I32_TO_U16, _Z18convert_ushort_sati)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_U32_TO_U16, _Z18convert_ushort_satj)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_F32_TO_U16, _Z18convert_ushort_satf)

DECL_LLVM_GEN_FUNCTION(SAT_CONV_U32_TO_I32, _Z15convert_int_satj)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_F32_TO_I32, _Z15convert_int_satf)

DECL_LLVM_GEN_FUNCTION(SAT_CONV_I32_TO_U32, _Z16convert_uint_sati)
DECL_LLVM_GEN_FUNCTION(SAT_CONV_F32_TO_U32, _Z16convert_uint_satf)

DECL_LLVM_GEN_FUNCTION(CONV_F16_TO_F32, __gen_ocl_f16to32)
DECL_LLVM_GEN_FUNCTION(CONV_F32_TO_F16, __gen_ocl_f32to16)

// SIMD level function for internal usage
DECL_LLVM_GEN_FUNCTION(SIMD_ANY, __gen_ocl_simd_any)
DECL_LLVM_GEN_FUNCTION(SIMD_ALL, __gen_ocl_simd_all)

DECL_LLVM_GEN_FUNCTION(READ_TM, __gen_ocl_read_tm)
DECL_LLVM_GEN_FUNCTION(REGION, __gen_ocl_region)

// printf function
DECL_LLVM_GEN_FUNCTION(PRINTF, __gen_ocl_printf)
