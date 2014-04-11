

/*
 *  Global Switches
 */

#define SAC_DO_RTSPEC          0
#define SAC_DO_CHECK           0
#define SAC_DO_CHECK_TYPE      0
#define SAC_DO_CHECK_BOUNDARY  0
#define SAC_DO_CHECK_MALLOC    0
#define SAC_DO_CHECK_ERRNO     0
#define SAC_DO_CHECK_HEAP      0

#define SAC_DO_PHM             1
#define SAC_DO_APS             1
#define SAC_DO_DAO             1
#define SAC_DO_MSCA            1

#define SAC_DO_PROFILE         0
#define SAC_DO_PROFILE_WITH    0
#define SAC_DO_PROFILE_FUN     0
#define SAC_DO_PROFILE_INL     0
#define SAC_DO_PROFILE_LIB     0

#define SAC_DO_TRACE           0
#define SAC_DO_TRACE_REF       0
#define SAC_DO_TRACE_MEM       0
#define SAC_DO_TRACE_PRF       0
#define SAC_DO_TRACE_FUN       0
#define SAC_DO_TRACE_WL        0
#define SAC_DO_TRACE_AA        0
#define SAC_DO_TRACE_MT        0

#define SAC_DO_CACHESIM        0
#define SAC_DO_CACHESIM_ADV    0
#define SAC_DO_CACHESIM_GLOBAL 1
#define SAC_DO_CACHESIM_FILE   0
#define SAC_DO_CACHESIM_PIPE   0
#define SAC_DO_CACHESIM_IMDT   1

#define SAC_DO_MULTITHREAD     1
#define SAC_DO_MT_PTHREAD  1
#define SAC_DO_MT_OMP  0
#define SAC_DO_THREADS_STATIC  0
#define SAC_DO_FP  0
#define SAC_DEBUG_RC 0


/*
 *  Global Settings
 */

#define SAC_RC_METHOD SAC_RCM_local
#define SAC_FORCE_DESC_SIZE -1


/*
 *  MUTC Backend Specific Switches
 */

#define SAC_MUTC_FUNAP_AS_CREATE  0
#define SAC_MUTC_THREAD_MALLOC 0
#define SAC_MUTC_DISABLE_THREAD_MEM 0
#define SAC_MUTC_BENCH 0
#define SAC_MUTC_MACROS  0
#define SAC_MUTC_RC_PLACES  1
#define SAC_MUTC_RC_INDIRECT  0
#define SAC_MUTC_SEQ_DATA_PARALLEL  0
#define SAC_MUTC_FORCE_SPAWN_FLAGS

#define SAC_CUDA_MACROS  0
#define SAC_OMP_MACROS  0

#define SAC_BACKEND C99

#define SAC_DO_COMPILE_MODULE  0
#define SAC_C_EXTERN           extern



/*
 *  Global Settings
 */

#ifndef NULL
#define NULL                      (void*) 0
#endif

#define SAC_SET_TMPDIR              "/tmp"
#define SAC_SET_INITIAL_MASTER_HEAPSIZE      1048576
#define SAC_SET_INITIAL_WORKER_HEAPSIZE      65536
#define SAC_SET_INITIAL_UNIFIED_HEAPSIZE     0

#ifndef SAC_SET_MTMODE
#define SAC_SET_MTMODE               2
#endif

#ifndef SAC_SET_THREADS_MAX
#define SAC_SET_THREADS_MAX          32
#endif

#ifndef SAC_SET_THREADS
#define SAC_SET_THREADS              0
#endif

#ifndef SAC_OMP_ACTIVE_LEVEL
#define SAC_OMP_ACTIVE_LEVEL          1
#endif

#ifndef SAC_SET_MASTERCLASS
#define SAC_SET_MASTERCLASS          0
#endif

#define SAC_SET_NUM_SCHEDULERS       1

#define SAC_SET_CACHE_1_SIZE         -1
#define SAC_SET_CACHE_1_LINE         4
#define SAC_SET_CACHE_1_ASSOC        1
#define SAC_SET_CACHE_1_WRITEPOL     SAC_CS_default
#define SAC_SET_CACHE_1_MSCA_FACTOR  0.00

#define SAC_SET_CACHE_2_SIZE         -1
#define SAC_SET_CACHE_2_LINE         4
#define SAC_SET_CACHE_2_ASSOC        1
#define SAC_SET_CACHE_2_WRITEPOL     SAC_CS_default
#define SAC_SET_CACHE_2_MSCA_FACTOR  0.00

#define SAC_SET_CACHE_3_SIZE         -1
#define SAC_SET_CACHE_3_LINE         4
#define SAC_SET_CACHE_3_ASSOC        1
#define SAC_SET_CACHE_3_WRITEPOL     SAC_CS_default
#define SAC_SET_CACHE_3_MSCA_FACTOR  0.00

#define SAC_SET_CACHESIM_HOST        ""
#define SAC_SET_CACHESIM_FILE        "ab-totient-sac.cs"
#define SAC_SET_CACHESIM_DIR         "/tmp"
#define SAC_SET_MAXFUN               0
#define SAC_SET_MAXFUNAP             1
#define SBLOCKSZ               16
#define LBLOCKSZ               256



/*
 *  Includes
 */


#include "sac.h"


#if SAC_OMP_MACROS

#include "omp.h"

#endif

#if SAC_CUDA_MACROS

#include <stdio.h>


#include <cutil.h>


#include <cutil_inline_runtime.h>

#endif

/*
 *  SAC-Program ab-totient-sac.sac :
 */


/*
 *  type definitions
 */

SAC_ND_TYPEDEF((SACt_String__string, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_hidden)

SAC_C_EXTERN SACt_String__string copy_string( SACt_String__string);
SAC_C_EXTERN void free( SACt_String__string);

SAC_ND_TYPEDEF((SACt_World__World, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_hidden)
SAC_ND_TYPEDEF((SACt_CommandLine__CommandLine, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_hidden)
SAC_ND_TYPEDEF((SACt_Terminal__Terminal, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_hidden)
SAC_ND_TYPEDEF((SACt_TermFile__TermFile, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_hidden)
SAC_ND_TYPEDEF((SACt_sacprelude__SACarg, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_hidden)

SAC_C_EXTERN SACt_sacprelude__SACarg SACARGcopy( SACt_sacprelude__SACarg);
SAC_C_EXTERN void SACARGfree( SACt_sacprelude__SACarg);



/*
 *  Global Definitions
 */

SAC_MT_DEFINE()
SAC_PF_DEFINE()
SAC_HM_DEFINE()


/*
 *  prototypes for externals (FUNDECS)
 */

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACtoi, (int, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, in_nodesc, SACt_String__string, (SACl_S, (SCL, (HID, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACtoi, SAC_ND_TYPE_NT( (int, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))),  SAC_ND_PARAM_in_nodesc( (SACl_S, (SCL, (HID, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), SACt_String__string));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACargv, (SACt_String__string, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, in_nodesc, int, (SACl_N, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACargv, SAC_ND_TYPE_NT( (SACt_String__string, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))),  SAC_ND_PARAM_in_nodesc( (SACl_N, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACprintf, , 2, in_nodesc, SACt_String__string, (SACl_FORMAT, (SCL, (HID, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), , ..., )
 */
SAC_ND_DECL_FUN2(SACprintf, void,  SAC_ND_PARAM_in_nodesc( (SACl_FORMAT, (SCL, (HID, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), SACt_String__string), SAC_ND_PARAM_( , ...));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( to_string, , 3, out, SACt_String__string, (SAC_arg_1, (SCL, (HID, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in_nodesc, int, (SACl_LENGTH, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(to_string, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (HID, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), SACt_String__string), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in_nodesc( (SACl_LENGTH, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));



/*
 *  prototypes for locals (FUNDEFS)
 */

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__partitionIntersectMax__i_S__i_S, , 3, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_PWLbound1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ivmin, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__partitionIntersectMax__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_PWLbound1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ivmin, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__partitionSlicer__i_S__i_S__i_S__i_S__i_S, , 9, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_4, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_min, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_max, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_axis, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lb, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ub, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__partitionSlicer__i_S__i_S__i_S__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_4, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_min, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_max, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_axis, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_lb, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ub, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__isPartitionIntersectNull__i_S__i_S__i_S__i_S, , 5, out, bool, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idxmin, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idxmax, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_bound1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_bound2, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__isPartitionIntersectNull__i_S__i_S__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_idxmin, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_idxmax, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_bound1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_bound2, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__partitionIntersectMin__i_S__i_S, , 3, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_PWLbound2, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ivmax, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__partitionIntersectMin__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_PWLbound2, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ivmax, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__adjustLacFunParams__bl_S__i_S__i_S, , 4, out, int, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_iv, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__adjustLacFunParams__bl_S__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_iv, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf__MAIN_CL_ST__main, , 1, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf__MAIN_CL_ST__main, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__prod__i_S, , 2, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_v, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__prod__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_v, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__adjustLacFunParamsReshape__bl_S__i_S__i_S__i_S, , 5, out, int, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_iv, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_shp, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__adjustLacFunParamsReshape__bl_S__i_S__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_iv, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_shp, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__eq__c_S__c_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__eq__c_S__c_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__eq__bl_S__bl_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__eq__bl_S__bl_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__eq__d_S__d_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__eq__d_S__d_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__eq__f_S__f_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__eq__f_S__f_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__eq__i_S__i_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__eq__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__gridFiller__i_S__i_S__i_S__i_S__i_S, , 8, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lb, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ub, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_wdth, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_dim, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_maxwidth, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__gridFiller__i_S__i_S__i_S__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_lb, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ub, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_wdth, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_dim, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_maxwidth, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__zero__bl_S, , 2, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__zero__bl_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__zero__c_S, , 2, out, unsigned char, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__zero__c_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__zero__f_S, , 2, out, float, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__zero__f_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__zero__d_S, , 2, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__zero__d_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__zero__i_S, , 2, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__zero__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__partitionMax__i_S__i_S, , 3, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_x, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_y, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__partitionMax__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_x, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_y, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__partitionMin__i_S__i_S, , 3, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_x, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_y, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__partitionMin__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_x, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_y, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__sel__i_S__c_S, , 3, out, unsigned char, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__sel__i_S__c_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in( (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__sel__i_S__bl_S, , 3, out, bool, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__sel__i_S__bl_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__sel__i_S__d_S, , 3, out, double, (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__sel__i_S__d_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__sel__i_S__f_S, , 3, out, float, (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__sel__i_S__f_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float), SAC_ND_PARAM_in( (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACwf_sacprelude__sel__i_S__i_S, , 3, out, int, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACwf_sacprelude__sel__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_idx, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf__MAIN_CL_ST__main, , 1, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf__MAIN_CL_ST__main, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * MT_SPMDFUN_DECL( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 8, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_MT_SPMDFUN_REAL_RETTYPE() SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i( SAC_MT_SPMDFUN_REAL_PARAM_LIST())
;

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf__MAIN_CL_ST_CL_INIT__init, , 0)
 */
SAC_ND_DECL_FUN2(SACf__MAIN_CL_ST_CL_INIT__init, void, );

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_World_CL_ST_CL_INIT__init_TheWorld__SACt_World__World, , 1, inout, SACt_World__World, (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_World_CL_ST_CL_INIT__init_TheWorld__SACt_World__World, void,  SAC_ND_PARAM_inout( (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))), SACt_World__World));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_CommandLine_CL_ST_CL_INIT__init_TheCommandLine__SACt_CommandLine__CommandLine, , 1, inout, SACt_CommandLine__CommandLine, (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_CommandLine_CL_ST_CL_INIT__init_TheCommandLine__SACt_CommandLine__CommandLine, void,  SAC_ND_PARAM_inout( (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))), SACt_CommandLine__CommandLine));

SAC_C_EXTERN 
/*
 * MT_MTFUN_DECL( SACf_ScalarArith_CL_MT___PL__d__d, , 3, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_A, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_B, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
void SACf_ScalarArith_CL_MT___PL__d__d( SAC_MT_MYTHREAD_PARAM(),  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_A, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_B, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_Terminal_CL_ST_CL_INIT__init_TheTerminal__SACt_Terminal__Terminal, , 1, inout, SACt_Terminal__Terminal, (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_Terminal_CL_ST_CL_INIT__init_TheTerminal__SACt_Terminal__Terminal, void,  SAC_ND_PARAM_inout( (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))), SACt_Terminal__Terminal));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_TermFile_CL_ST_CL_INIT__init_stdout__SACt_TermFile__TermFile, , 1, inout, SACt_TermFile__TermFile, (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_TermFile_CL_ST_CL_INIT__init_stdout__SACt_TermFile__TermFile, void,  SAC_ND_PARAM_inout( (SACp_OI_object, (SCL, (HID, (NUQ, (INT, (GLO, (FPO, (NOT, )))))))), SACt_TermFile__TermFile));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__sel__i_X__i_S, , 3, out, int, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__sel__i_X__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__sel__i_X__f_S, , 3, out, float, (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__sel__i_X__f_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float), SAC_ND_PARAM_in( (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__sel__i_X__d_S, , 3, out, double, (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__sel__i_X__d_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__sel__i_X__bl_S, , 3, out, bool, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__sel__i_X__bl_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__sel__i_X__c_S, , 3, out, unsigned char, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__sel__i_X__c_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in( (SACl_idx, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_array, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__zero__i_S, , 2, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__zero__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__zero__d_S, , 2, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__zero__d_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__zero__f_S, , 2, out, float, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__zero__f_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__zero__c_S, , 2, out, unsigned char, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__zero__c_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__zero__bl_S, , 2, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__zero__bl_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__eq__i_S__i_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__eq__i_S__i_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__eq__f_S__f_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, float, (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__eq__f_S__f_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), float));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__eq__d_S__d_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, double, (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__eq__d_S__d_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), double));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__eq__bl_S__bl_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__eq__bl_S__bl_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__eq__c_S__c_S, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, unsigned char, (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__eq__c_S__c_S, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_A, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char), SAC_ND_PARAM_in( (SACl_B, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), unsigned char));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__adjustLacFunParams__bl_S__i_S__i_X, , 4, out, int, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_iv, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__adjustLacFunParams__bl_S__i_S__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_iv, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__prod__i_X, , 2, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_v, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__prod__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_v, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__adjustLacFunParamsReshape__bl_S__i_S__i_X__i_X, , 5, out, int, (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_iv, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_shp, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__adjustLacFunParamsReshape__bl_S__i_S__i_X__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_p, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_i, (AUD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_iv, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_shp, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionSlicer__i_X__i_X__i__i_X__i_X, , 9, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_4, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_min, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_max, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_axis, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lb, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ub, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionSlicer__i_X__i_X__i__i_X__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_4, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_min, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_max, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_axis, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_lb, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ub, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__gridFiller__i_X__i_X__i_X__i__i_X, , 8, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), out, int, (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lb, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ub, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_wdth, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_dim, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_maxwidth, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__gridFiller__i_X__i_X__i_X__i__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_out( (SAC_arg_3, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_lb, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ub, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_wdth, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_dim, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_maxwidth, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionIntersectMax__i_X__i_X, , 3, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_PWLbound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ivmin, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionIntersectMax__i_X__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_PWLbound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ivmin, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionIntersectMax__i_X__i, , 3, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_PWLbound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ivmin, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionIntersectMax__i_X__i, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_PWLbound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ivmin, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionIntersectMin__i_X__i_X, , 3, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_PWLbound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ivmax, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionIntersectMin__i_X__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_PWLbound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ivmax, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionIntersectMin__i_X__i, , 3, out, int, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_PWLbound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_ivmax, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionIntersectMin__i_X__i, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_PWLbound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_ivmax, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__isPartitionIntersectNull__i_X__i_X__i_X__i_X, , 5, out, bool, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idxmin, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idxmax, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_bound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_bound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__isPartitionIntersectNull__i_X__i_X__i_X__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_idxmin, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_idxmax, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_bound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_bound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__isPartitionIntersectNull__i__i__i_X__i_X, , 5, out, bool, (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idxmin, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_idxmax, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_bound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_bound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__isPartitionIntersectNull__i__i__i_X__i_X, void,  SAC_ND_PARAM_out( (SAC_arg_1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_idxmin, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_idxmax, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_bound1, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_bound2, (AKD, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionMin__i__i, , 3, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_x, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_y, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionMin__i__i, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_x, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_y, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__partitionMax__i__i, , 3, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_x, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_y, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__partitionMax__i__i, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_x, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_y, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude___ST__i__i, , 3, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_a, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_b, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude___ST__i__i, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_a, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int), SAC_ND_PARAM_in( (SACl_b, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int));

SAC_C_EXTERN 
/*
 * ND_FUN_DECL( SACf_sacprelude__and__bl__bl, , 3, out, bool, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_a, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACl_b, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DECL_FUN2(SACf_sacprelude__and__bl__bl, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_a, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool), SAC_ND_PARAM_in( (SACl_b, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), bool));



/*
 *  global objects
 */

/*
 * ND_OBJDEF_EXTERN( (SACo_World__TheWorld, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_World__World, 0)
 */
SAC_ND_DECL__DATA( (SACo_World__TheWorld, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_World__World, extern)
SAC_ND_DECL__DESC( (SACo_World__TheWorld, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), extern)
SAC_NOTHING()

/*
 * ND_OBJDEF_EXTERN( (SACo_CommandLine__TheCommandLine, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_CommandLine__CommandLine, 0)
 */
SAC_ND_DECL__DATA( (SACo_CommandLine__TheCommandLine, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_CommandLine__CommandLine, extern)
SAC_ND_DECL__DESC( (SACo_CommandLine__TheCommandLine, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), extern)
SAC_NOTHING()

/*
 * ND_OBJDEF_EXTERN( (SACo_Terminal__TheTerminal, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_Terminal__Terminal, 0)
 */
SAC_ND_DECL__DATA( (SACo_Terminal__TheTerminal, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_Terminal__Terminal, extern)
SAC_ND_DECL__DESC( (SACo_Terminal__TheTerminal, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), extern)
SAC_NOTHING()

/*
 * ND_OBJDEF_EXTERN( (SACo_TermFile__stdout, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_TermFile__TermFile, 0)
 */
SAC_ND_DECL__DATA( (SACo_TermFile__stdout, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_TermFile__TermFile, extern)
SAC_ND_DECL__DESC( (SACo_TermFile__stdout, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), extern)
SAC_NOTHING()



/*
 *  SPMD infrastructure
 */

SAC_MT_SPMD_FRAME_BEGIN()
/*
 * MT_SPMD_FRAME_ELEMENT( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 8, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_MT_SPMD_FRAME_ELEMENT_BEGIN( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i)
SAC_MT_FRAME_ELEMENT_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 1, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 2, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 3, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 4, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 5, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 6, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
SAC_MT_FRAME_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 7, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_SPMD_FRAME_ELEMENT_END( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i)

SAC_MT_SPMD_FRAME_END()
SAC_MT_SPMD_BARRIER_BEGIN()
/*
 * MT_SPMD_BARRIER_ELEMENT( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 8, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_MT_SPMD_BARRIER_ELEMENT_BEGIN( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i)
SAC_MT_BARRIER_ELEMENT_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 1, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 2, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 3, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 4, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 5, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 6, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
SAC_MT_BARRIER_ELEMENT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 7, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
SAC_MT_SPMD_BARRIER_ELEMENT_END( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i)

SAC_MT_SPMD_BARRIER_END()


/*
 *  function definitions (FUNDEFS)
 */



/****************************************************************************
 * Wrapper function:
 * ST function:
 * SACwf__MAIN_CL_ST__main(...) [ wrapper ]
 ****************************************************************************/
/*
 * ND_FUN_DEF_BEGIN( SACwf__MAIN_CL_ST__main, , 1, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DEF_FUN_BEGIN2(SACwf__MAIN_CL_ST__main, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int))
{
  SAC_HM_DEFINE_THREAD_STATUS( SAC_HM_single_threaded)

  { 
    SAC_ND_DECL_CONST__DATA((SACp_emal_3925__cwc_123, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
    /*
     * ND_DECL( (SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()


    SAC_INIT_LOCAL_MEM()
    /*
     * ND_FUN_AP( SACf__MAIN_CL_ST__main, , 1, out, int, SAC_SET_NT_USG( FAG, (SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(SACf__MAIN_CL_ST__main,  SAC_ND_ARG_out( SAC_SET_NT_USG( FAG, (SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), int))

    /*
     * ND_REFRESH__MIRROR( (SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_FREE((SACp_cwc_124, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    /*
     * ND_FUN_RET( , 1, out, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), (SACp_emal_3925__cwc_123, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))))
     */
    SAC_ND_RET_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), (SACp_emal_3925__cwc_123, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))))
    return;
    SAC_CLEANUP_LOCAL_MEM()
  }
/*
   * ND_FUN_DEF_END( SACwf__MAIN_CL_ST__main, , 1, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
   */
}
SAC_ND_FUN_DEF_END2()



/****************************************************************************
 * ST function:
 * SACf__MAIN_CL_ST__main(...) [ body ]
 ****************************************************************************/
/*
 * ND_FUN_DEF_BEGIN( SACf__MAIN_CL_ST__main, , 1, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_ND_DEF_FUN_BEGIN2(SACf__MAIN_CL_ST__main, void,  SAC_ND_PARAM_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), int))
{
  SAC_HM_DEFINE_THREAD_STATUS( SAC_HM_single_threaded)

  { 
    /*
     * ND_DECL( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), unsigned char, -1)
     */
    SAC_ND_DECL__DATA( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), unsigned char, )
    SAC_ND_DECL__DESC( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    int SAC_ND_A_MIRROR_SIZE( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = 0;
    int SAC_ND_A_MIRROR_DIM( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = 0;

    /*
     * ND_DECL( (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    SAC_ND_DECL_CONST__DATA((SACp_emal_3947__isaa_2200__rso_95_TheWorld, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
    SAC_ND_DECL_CONST__DATA((SACp_emal_3946__flat_1, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 1)
    SAC_ND_DECL_CONST__DATA((SACp_emal_3945__flat_3, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 2)
    /*
     * ND_DECL( (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    SAC_ND_DECL_CONST__DATA((SACp_emal_3942__flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0.0)
    SAC_ND_DECL_CONST__DATA((SACp_emal_3941__pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 3.0)
    SAC_ND_DECL_CONST__DATA((SACp_emal_3927__flat_60, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 41)
    /*
     * ND_DECL( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), unsigned char, 1, 42)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), unsigned char, )
    SAC_ND_DECL__DESC( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    const int SAC_ND_A_MIRROR_SHAPE( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0) = 42;
    const int SAC_ND_A_MIRROR_SIZE( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = 42;
    const int SAC_ND_A_MIRROR_DIM( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = 1;

    /*
     * ND_DECL( (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_String__string, 0)
     */
    SAC_ND_DECL__DATA( (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_String__string, )
    SAC_ND_DECL__DESC( (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_String__string, 0)
     */
    SAC_ND_DECL__DATA( (SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_String__string, )
    SAC_ND_DECL__DESC( (SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_String__string, 0)
     */
    SAC_ND_DECL__DATA( (SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACt_String__string, )
    SAC_ND_DECL__DESC( (SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()


    SAC_INIT_LOCAL_MEM()
    /*
     * ND_FUN_AP( SACf__MAIN_CL_ST_CL_INIT__init, , 0)
     */
    SAC_ND_FUNAP2(SACf__MAIN_CL_ST_CL_INIT__init, )

    /*
     * ND_FUN_AP( SACargv, SACp_flat_0, 1, in_nodesc, int, SAC_SET_NT_USG( FAG, (SACp_emal_3946__flat_1, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SACp_flat_0 = SACargv( SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_emal_3946__flat_1, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), int));

    SAC_ND_ALLOC__DESC((SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
    /*
     * ND_REFRESH__MIRROR( (SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_SET__RC((SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1)
    SAC_ND_DEC_RC_FREE((SACp_emal_3946__flat_1, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, )
    /*
     * ND_FUN_AP( SACtoi, SACl_lower, 1, in_nodesc, SACt_String__string, SAC_SET_NT_USG( FAG, (SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SACl_lower = SACtoi( SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_String__string));

    SAC_ND_ALLOC__DESC((SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
    /*
     * ND_REFRESH__MIRROR( (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_SET__RC((SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1)
    SAC_ND_DEC_RC_FREE((SACp_flat_0, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, free)
    /*
     * ND_FUN_AP( SACargv, SACp_flat_2, 1, in_nodesc, int, SAC_SET_NT_USG( FAG, (SACp_emal_3945__flat_3, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SACp_flat_2 = SACargv( SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_emal_3945__flat_3, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), int));

    SAC_ND_ALLOC__DESC((SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
    /*
     * ND_REFRESH__MIRROR( (SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_SET__RC((SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1)
    SAC_ND_DEC_RC_FREE((SACp_emal_3945__flat_3, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, )
    /*
     * ND_FUN_AP( SACtoi, SACl_upper, 1, in_nodesc, SACt_String__string, SAC_SET_NT_USG( FAG, (SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SACl_upper = SACtoi( SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_String__string));

    SAC_ND_ALLOC__DESC((SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
    /*
     * ND_REFRESH__MIRROR( (SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_SET__RC((SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1)
    SAC_ND_DEC_RC_FREE((SACp_flat_2, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, free)
    SAC_ND_ALLOC_BEGIN((SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
    /*
     * ND_SET__SHAPE_arr( (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
    SAC_NOOP()

    SAC_ND_ALLOC_END((SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
    SAC_ND_PRF_SxS__DATA((SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0))
    SAC_ND_PRF_SxS__DATA((SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_ADD, SAC_ND_READ((SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0), 1)
    /*
     * MT_SPMDFUN_AP( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 8, out, double, SAC_SET_NT_USG( FAG, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))), in, bool, SAC_SET_NT_USG( FAG, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in, bool, SAC_SET_NT_USG( FAG, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in, double, SAC_SET_NT_USG( FAG, (SACp_emal_3941__pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))), in, bool, SAC_SET_NT_USG( FAG, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in, int, SAC_SET_NT_USG( FAG, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in, double, SAC_SET_NT_USG( FAG, (SACp_emal_3942__flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))), in, int, SAC_SET_NT_USG( FAG, (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_MT_SEND_PARAM_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, SAC_SET_NT_USG( FAG, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 1, SAC_SET_NT_USG( FAG, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 2, SAC_SET_NT_USG( FAG, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 3, SAC_SET_NT_USG( FAG, (SACp_emal_3941__pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 4, SAC_SET_NT_USG( FAG, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 5, SAC_SET_NT_USG( FAG, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 6, SAC_SET_NT_USG( FAG, (SACp_emal_3942__flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_SEND_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 7, SAC_SET_NT_USG( FAG, (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    
SAC_MT_SPMD_EXECUTE( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i);
    SAC_MT_RECEIVE_RESULT_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 0, SAC_SET_NT_USG( FAG, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 1, SAC_SET_NT_USG( FAG, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 2, SAC_SET_NT_USG( FAG, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 3, SAC_SET_NT_USG( FAG, (SACp_emal_3941__pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 4, SAC_SET_NT_USG( FAG, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 5, SAC_SET_NT_USG( FAG, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 6, SAC_SET_NT_USG( FAG, (SACp_emal_3942__flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
    SAC_MT_RECEIVE_RESULT_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, 7, SAC_SET_NT_USG( FAG, (SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))

    /*
     * ND_REFRESH__MIRROR( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_FREE((SACp_emal_3944__pinl_1641__flat_212, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_ND_FREE((SACp_emal_3941__pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_ND_ALLOC_BEGIN((SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 1, unsigned char)
    /*
     * ND_SET__SHAPE_arr( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 42)
     */
    SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 1), 60, "Assignment with incompatible types found!");
    SAC_ASSURE_TYPE_LINE( (SAC_ND_A_SHAPE( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0) == 42), 60, "Assignment with incompatible types found!");
    SAC_NOOP()

    SAC_ND_ALLOC_END((SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 1, unsigned char)
    SAC_ND_CREATE__STRING__DATA((SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), "Sum of Totients between [%d..%d] is %.f \n")
    /*
     * ND_ASSIGN( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), -1, (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, )
     */
    SAC_ND_A_DESC( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = SAC_ND_A_DESC( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))));
    SAC_ND_A_MIRROR_SIZE( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = SAC_ND_A_SIZE( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))));
    SAC_ND_A_MIRROR_DIM( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = SAC_ND_A_DIM( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))));
    SAC_ND_A_DESC_SHAPE( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0) = SAC_ND_A_SHAPE( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0);
    SAC_ND_A_DESC_SIZE( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = SAC_ND_A_SIZE( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))));
    SAC_ND_A_DESC_DIM( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = SAC_ND_A_DIM( (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))));
    SAC_ND_ASSIGN__DATA( (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), (SACp_emal_3926__flat_17, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )

    /*
     * ND_FUN_AP( to_string, , 3, out, SACt_String__string, SAC_SET_NT_USG( FAG, (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in, unsigned char, SAC_SET_NT_USG( FAG, (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in_nodesc, int, SAC_SET_NT_USG( FAG, (SACp_emal_3927__flat_60, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(to_string,  SAC_ND_ARG_out( SAC_SET_NT_USG( FAG, (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_String__string), SAC_ND_ARG_in( SAC_SET_NT_USG( FAG, (SACp_tcp_4306__emal_3926__flat_17, (AUD, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), unsigned char), SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_emal_3927__flat_60, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), int))

    /*
     * ND_REFRESH__MIRROR( (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_NOOP()

    SAC_ND_DEC_RC_FREE((SACp_emal_3927__flat_60, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, )
    /*
     * ND_FUN_AP( SACprintf, , 4, in_nodesc, SACt_String__string, SAC_SET_NT_USG( FAG, (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in_nodesc, int, SAC_SET_NT_USG( FAG, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in_nodesc, int, SAC_SET_NT_USG( FAG, (SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), in_nodesc, double, SAC_SET_NT_USG( FAG, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(SACprintf,  SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_flat_16, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_String__string), SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), int), SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), int), SAC_ND_ARG_in_nodesc( SAC_SET_NT_USG( FAG, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))), double))

    SAC_ND_DEC_RC_FREE((SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
    SAC_ND_DEC_RC_FREE((SACl_upper, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, )
    SAC_ND_DEC_RC_FREE((SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, )
    /*
     * ND_FUN_RET( , 1, out, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), (SACp_emal_3947__isaa_2200__rso_95_TheWorld, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))))
     */
    SAC_ND_RET_out( (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), (SACp_emal_3947__isaa_2200__rso_95_TheWorld, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))))
    return;
    SAC_CLEANUP_LOCAL_MEM()
  }
/*
   * ND_FUN_DEF_END( SACf__MAIN_CL_ST__main, , 1, out, int, (SAC_arg_1, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
   */
}
SAC_ND_FUN_DEF_END2()



/****************************************************************************
 * SPMD function:
 * SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i(...) [ body ]
 ****************************************************************************/
/*
 * MT_SPMDFUN_DEF_BEGIN( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 8, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
 */
SAC_MT_SPMDFUN_REAL_RETTYPE() SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i( SAC_MT_SPMDFUN_REAL_PARAM_LIST())
{
  SAC_HM_DEFINE_THREAD_STATUS( SAC_HM_multi_threaded)
  SAC_MT_RECEIVE_PARAM_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 1, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 2, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 3, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 4, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 5, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 6, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))))
  SAC_MT_RECEIVE_PARAM_in( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 7, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))

  { 
    /* MT parallel branch */
    /*
     * ND_DECL( (SACp_mtspmdfanon_4301__icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_mtspmdfanon_4301__icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_mtspmdfanon_4301__icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), bool, )
    SAC_ND_DECL__DESC( (SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, )
    SAC_ND_DECL__DESC( (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 0)
     */
    SAC_ND_DECL__DATA( (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    SAC_NOTHING()

    /*
     * ND_DECL( (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, 1, 1)
     */
    SAC_ND_DECL__DATA( (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
    SAC_ND_DECL__DESC( (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    const int SAC_ND_A_MIRROR_SHAPE( (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0) = 1;
    const int SAC_ND_A_MIRROR_SIZE( (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = 1;
    const int SAC_ND_A_MIRROR_DIM( (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) = 1;


    /*
     * ND_DECL__MIRROR_PARAM( (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    /*
     * ND_DECL__MIRROR_PARAM( (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    /*
     * ND_DECL__MIRROR_PARAM( (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    /*
     * ND_DECL__MIRROR_PARAM( (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    /*
     * ND_DECL__MIRROR_PARAM( (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    /*
     * ND_DECL__MIRROR_PARAM( (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    /*
     * ND_DECL__MIRROR_PARAM( (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0)
     */
    SAC_NOTHING()

    SAC_INIT_LOCAL_MEM()
    SAC_ND_ALLOC_BEGIN((SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
    /*
     * ND_SET__SHAPE_arr( (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
     */
    SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 56, "Assignment with incompatible types found!");
    SAC_NOOP()

    SAC_ND_ALLOC_END((SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
    /*
     * ND_ASSIGN( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), 0, )
     */
    SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 57, "Assignment with incompatible types found!");
    SAC_NOOP()
    SAC_NOOP()
    SAC_NOOP()
    SAC_ND_ASSIGN__DATA( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), )

    SAC_PF_BEGIN_WITH(fold)
    /*
     * WL_SCHEDULE__BEGIN( 1)
     */
    {
      int SAC_WL_MT_SCHEDULE_START( 0);
      int SAC_WL_MT_SCHEDULE_STOP( 0);

      /*
       * MT_SCHEDULER_BlockVar_BEGIN( 1, 1, 0, SAC_ND_READ( (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1)
       */
      SAC_MT_SCHEDULER_BlockVar_DIM0( 0, SAC_ND_READ( (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1);

      SAC_MT_ADJUST_SCHEDULER__BEGIN((SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, 0, SAC_ND_READ((SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1)
      SAC_MT_ADJUST_SCHEDULER__END((SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, 0, SAC_ND_READ((SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1)
      SAC_WL_MT_STRIDE_LOOP0_BEGIN(0, (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0, SAC_ND_READ((SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1)
      SAC_WL_MT_GRID_UNROLL_BEGIN(0, (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0, 1)
      SAC_NOOP()
      SAC_ND_ALLOC_BEGIN((SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_ADD, SAC_ND_READ((SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0))
      SAC_ND_ALLOC_BEGIN((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 2, 0, double)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 308, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 2, 0, double)
      SAC_ND_PRF_S__DATA((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOD, SAC_ND_READ((SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0))
      SAC_ND_FREE((SACp_emal_3940__dup_2291__pinl_1741__flat_213, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
      SAC_ND_ALLOC_BEGIN((SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
      SAC_ND_ALLOC_BEGIN((SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 190, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
      SAC_ND_PRF_S__DATA((SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOI, SAC_ND_READ((SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
      SAC_ND_FREE((SACp_emal_3938__dup_2293__pinl_1834__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
      SAC_ND_ALLOC_BEGIN((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 308, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      SAC_ND_PRF_S__DATA((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOD, SAC_ND_READ((SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0))
      SAC_ND_FREE((SACp_emal_3937__dup_2294__pinl_1833__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
      SAC_ND_PRF_SxS__DATA((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_MUL, SAC_ND_READ((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
      SAC_ND_ALLOC_BEGIN((SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_EQ, SAC_ND_READ((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
      SAC_ND_FREE((SACp_emal_3936__dup_2295__pinl_1832__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
      if (SAC_ND_GETVAR((SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_emal_3933__dup_2298__pinl_1824__flat_176)) 
      { 
        SAC_ND_FREE((SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        SAC_ND_ALLOC_BEGIN((SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        /*
         * ND_SET__SHAPE_arr( (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
        SAC_NOOP()

        SAC_ND_ALLOC_END((SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        SAC_ND_PRF_SxS__DATA((SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
        SAC_ND_PRF_SxS__DATA((SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
        SAC_ND_DEC_RC_FREE((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
        SAC_ND_ALLOC_BEGIN((SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        /*
         * ND_COPY__SHAPE( (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 25, "Assignment with incompatible types found!");
        SAC_NOOP()

        SAC_ND_ALLOC_END((SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        SAC_ND_COPY__DATA((SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
        SAC_ND_DEC_RC_FREE((SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
        /*
         * ND_ASSIGN( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 25, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4213__emlr_4170_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        SAC_ND_GOTO(_dup_4302__f2l_4207_label)
        do 
        { 
          SAC_ND_FREE((SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
          /*
           * ND_ASSIGN( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 25, "Assignment with incompatible types found!");
          SAC_NOOP()
          SAC_NOOP()
          SAC_NOOP()
          SAC_ND_ASSIGN__DATA( (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          SAC_ND_LABEL(_dup_4302__f2l_4207_label)
          /*
           * ND_ASSIGN( (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
          SAC_NOOP()
          SAC_NOOP()
          SAC_NOOP()
          SAC_ND_ASSIGN__DATA( (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          SAC_ND_PRF_SxS__DATA((SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_pinl_4228__f2l_4206_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 190, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
          SAC_ND_PRF_S__DATA((SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOI, SAC_ND_READ((SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_FREE((SACp_pinl_4226__emal_3976__pinl_1771__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 308, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          SAC_ND_PRF_S__DATA((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOD, SAC_ND_READ((SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_FREE((SACp_pinl_4225__emal_3975__pinl_1770__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_MUL, SAC_ND_READ((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_EQ, SAC_ND_READ((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
          SAC_ND_FREE((SACp_pinl_4224__emal_3974__pinl_1769__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
        }
        while (SAC_ND_GETVAR((SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_pinl_4223__emal_3971__pinl_1772__flat_176));
        SAC_ND_FREE((SACp_pinl_4223__emal_3971__pinl_1772__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        /*
         * ND_ASSIGN( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 23, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4227__emal_3977__pinl_1761__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 23, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4212__emal_3970__pinl_1759__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      }
      else
      { 
        SAC_ND_FREE((SACp_emal_3933__dup_2298__pinl_1824__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        /*
         * ND_ASSIGN( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 23, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 23, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_emal_3939__dup_2292__pinl_1742__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      }
      SAC_ND_ALLOC_BEGIN((SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, 9.0, SAC_ND_READ((SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
      SAC_ND_ALLOC_BEGIN((SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_LE, SAC_ND_READ((SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
      SAC_ND_FREE((SACp_emal_3932__dup_2309__ctz_1882, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
      if (SAC_ND_GETVAR((SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_emal_3931__dup_2310__pinl_1822__flat_173)) 
      { 
        SAC_ND_FREE((SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        SAC_ND_ALLOC_BEGIN((SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        /*
         * ND_COPY__SHAPE( (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), 0)
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()

        SAC_ND_ALLOC_END((SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        SAC_ND_COPY__DATA((SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), )
        /*
         * ND_ASSIGN( (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4232__emlr_4168_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4260_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        SAC_ND_GOTO(_dup_4304__f2l_4203_label)
        do 
        { 
          SAC_ND_FREE((SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
          /*
           * ND_ASSIGN( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
          SAC_NOOP()
          SAC_NOOP()
          SAC_NOOP()
          SAC_ND_ASSIGN__DATA( (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          /*
           * ND_ASSIGN( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
          SAC_NOOP()
          SAC_NOOP()
          SAC_NOOP()
          SAC_ND_ASSIGN__DATA( (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          /*
           * ND_ASSIGN( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
          SAC_NOOP()
          SAC_NOOP()
          SAC_NOOP()
          SAC_ND_ASSIGN__DATA( (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          SAC_ND_LABEL(_dup_4304__f2l_4203_label)
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 190, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
          SAC_ND_PRF_S__DATA((SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOI, SAC_ND_READ((SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_FREE((SACp_pinl_4256__emal_3959__pinl_1784__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 308, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          SAC_ND_PRF_S__DATA((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOD, SAC_ND_READ((SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_FREE((SACp_pinl_4255__emal_3958__pinl_1783__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_MUL, SAC_ND_READ((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_EQ, SAC_ND_READ((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
          SAC_ND_FREE((SACp_pinl_4254__emal_3957__pinl_1782__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
          if (SAC_ND_GETVAR((SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_pinl_4253__emal_3954__pinl_1785__flat_176)) 
          { 
            SAC_ND_INC_RC((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1)
            SAC_ND_FREE((SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
            SAC_ND_ALLOC_BEGIN((SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
            /*
             * ND_SET__SHAPE_arr( (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
            SAC_NOOP()

            SAC_ND_ALLOC_END((SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
            SAC_ND_PRF_SxS__DATA((SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
            SAC_ND_PRF_SxS__DATA((SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
            SAC_ND_DEC_RC_FREE((SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
            SAC_ND_ALLOC_BEGIN((SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
            /*
             * ND_COPY__SHAPE( (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 34, "Assignment with incompatible types found!");
            SAC_NOOP()

            SAC_ND_ALLOC_END((SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
            SAC_ND_COPY__DATA((SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
            SAC_ND_DEC_RC_FREE((SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
            /*
             * ND_ASSIGN( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 34, "Assignment with incompatible types found!");
            SAC_NOOP()
            SAC_NOOP()
            SAC_NOOP()
            SAC_ND_ASSIGN__DATA( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4270__emlr_4166_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

            SAC_ND_GOTO(_dup_4303__f2l_4205_label)
            do 
            { 
              SAC_ND_FREE((SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
              /*
               * ND_ASSIGN( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
               */
              SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 34, "Assignment with incompatible types found!");
              SAC_NOOP()
              SAC_NOOP()
              SAC_NOOP()
              SAC_ND_ASSIGN__DATA( (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

              SAC_ND_LABEL(_dup_4303__f2l_4205_label)
              /*
               * ND_ASSIGN( (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
               */
              SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
              SAC_NOOP()
              SAC_NOOP()
              SAC_NOOP()
              SAC_ND_ASSIGN__DATA( (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

              SAC_ND_PRF_SxS__DATA((SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_pinl_4285__f2l_4204_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
              SAC_ND_ALLOC_BEGIN((SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
              /*
               * ND_SET__SHAPE_arr( (SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
               */
              SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
              SAC_NOOP()

              SAC_ND_ALLOC_END((SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
              SAC_ND_PRF_SxS__DATA((SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
              SAC_ND_ALLOC_BEGIN((SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
              /*
               * ND_SET__SHAPE_arr( (SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
               */
              SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 190, "Assignment with incompatible types found!");
              SAC_NOOP()

              SAC_ND_ALLOC_END((SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, int)
              SAC_ND_PRF_S__DATA((SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOI, SAC_ND_READ((SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
              SAC_ND_FREE((SACp_pinl_4283__emal_3967__pinl_1798__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
              SAC_ND_ALLOC_BEGIN((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
              /*
               * ND_SET__SHAPE_arr( (SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
               */
              SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 308, "Assignment with incompatible types found!");
              SAC_NOOP()

              SAC_ND_ALLOC_END((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
              SAC_ND_PRF_S__DATA((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_TOD, SAC_ND_READ((SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0))
              SAC_ND_FREE((SACp_pinl_4282__emal_3966__pinl_1797__flat_118, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
              SAC_ND_PRF_SxS__DATA((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_MUL, SAC_ND_READ((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
              SAC_ND_PRF_SxS__DATA((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
              SAC_ND_ALLOC_BEGIN((SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
              /*
               * ND_SET__SHAPE_arr( (SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
               */
              SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
              SAC_NOOP()

              SAC_ND_ALLOC_END((SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
              SAC_ND_PRF_SxS__DATA((SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_EQ, SAC_ND_READ((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
              SAC_ND_FREE((SACp_pinl_4281__emal_3965__pinl_1796__flat_9, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
            }
            while (SAC_ND_GETVAR((SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_pinl_4280__emal_3962__pinl_1799__flat_176));
            SAC_ND_DEC_RC_FREE((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
            SAC_ND_FREE((SACp_pinl_4280__emal_3962__pinl_1799__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
            /*
             * ND_ASSIGN( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 32, "Assignment with incompatible types found!");
            SAC_NOOP()
            SAC_NOOP()
            SAC_NOOP()
            SAC_ND_ASSIGN__DATA( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4284__emal_3968__pinl_1788__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

            /*
             * ND_ASSIGN( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 32, "Assignment with incompatible types found!");
            SAC_NOOP()
            SAC_NOOP()
            SAC_NOOP()
            SAC_ND_ASSIGN__DATA( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4269__emal_3961__pinl_1786__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          }
          else
          { 
            SAC_ND_FREE((SACp_pinl_4253__emal_3954__pinl_1785__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
            /*
             * ND_ASSIGN( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 32, "Assignment with incompatible types found!");
            SAC_NOOP()
            SAC_NOOP()
            SAC_NOOP()
            SAC_ND_ASSIGN__DATA( (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4259__f2l_4202_number, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

            /*
             * ND_ASSIGN( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
             */
            SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 32, "Assignment with incompatible types found!");
            SAC_NOOP()
            SAC_NOOP()
            SAC_NOOP()
            SAC_ND_ASSIGN__DATA( (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4257__f2l_4200_result, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          }
          /*
           * ND_ASSIGN( (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
          SAC_NOOP()
          SAC_NOOP()
          SAC_NOOP()
          SAC_ND_ASSIGN__DATA( (SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

          SAC_ND_PRF_SxS__DATA((SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_ADD, SAC_ND_READ((SACp_pinl_4258__f2l_4201_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 2.0)
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_MUL, SAC_ND_READ((SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
          SAC_ND_ALLOC_BEGIN((SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
          /*
           * ND_SET__SHAPE_arr( (SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
           */
          SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
          SAC_NOOP()

          SAC_ND_ALLOC_END((SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
          SAC_ND_PRF_SxS__DATA((SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_LE, SAC_ND_READ((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
          SAC_ND_FREE((SACp_pinl_4251__emal_3952__pinl_1801__flat_195, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
        }
        while (SAC_ND_GETVAR((SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_pinl_4250__emal_3950__pinl_1802__flat_173));
        SAC_ND_FREE((SACp_pinl_4252__emal_3953__pinl_1800__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
        SAC_ND_FREE((SACp_pinl_4250__emal_3950__pinl_1802__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        /*
         * ND_ASSIGN( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4231_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4230_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      }
      else
      { 
        SAC_ND_FREE((SACp_emal_3931__dup_2310__pinl_1822__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        /*
         * ND_ASSIGN( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_dup_2300__pinl_1817_number__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

        /*
         * ND_ASSIGN( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 31, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_dup_2299__pinl_1816_result__SSA0_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      }
      SAC_ND_ALLOC_BEGIN((SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_ADD, SAC_ND_READ((SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), -1.0)
      SAC_ND_ALLOC_BEGIN((SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))) == 0), 119, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, 0, bool)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_GT, SAC_ND_READ((SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), 0.0)
      SAC_ND_FREE((SACp_emal_3930__dup_2323__ctz_1880, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )
      if (SAC_ND_GETVAR((SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), SACp_emal_3929__dup_2324__pinl_1821__flat_172)) 
      { 
        SAC_ND_FREE((SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        SAC_ND_ALLOC_BEGIN((SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        /*
         * ND_SET__SHAPE_arr( (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
        SAC_NOOP()

        SAC_ND_ALLOC_END((SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
        SAC_ND_PRF_SxS__DATA((SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_DIV, SAC_ND_READ((SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
        SAC_ND_DEC_RC_FREE((SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
        SAC_ND_PRF_SxS__DATA((SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_SUB, SAC_ND_READ((SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
        SAC_ND_DEC_RC_FREE((SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
        /*
         * ND_ASSIGN( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 41, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_pinl_4290__emal_3949__pinl_1804__flat_194, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      }
      else
      { 
        SAC_ND_DEC_RC_FREE((SACp_dup_2312__pinl_1819_number__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
        SAC_ND_FREE((SACp_emal_3929__dup_2324__pinl_1821__flat_172, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
        /*
         * ND_ASSIGN( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
         */
        SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 41, "Assignment with incompatible types found!");
        SAC_NOOP()
        SAC_NOOP()
        SAC_NOOP()
        SAC_ND_ASSIGN__DATA( (SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_dup_2311__pinl_1818_result__SSA0_2, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      }
      SAC_ND_ALLOC_BEGIN((SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      /*
       * ND_SET__SHAPE_arr( (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0)
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
      SAC_NOOP()

      SAC_ND_ALLOC_END((SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, 0, double)
      SAC_ND_PRF_SxS__DATA((SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), SAC_ND_PRF_ADD, SAC_ND_READ((SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0), SAC_ND_READ((SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0))
      SAC_ND_DEC_RC_FREE((SACp_dup_2325__pinl_1820_result__SSA0_3, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
      SAC_ND_DEC_RC_FREE((SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 1, )
      /*
       * ND_ASSIGN( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, )
       */
      SAC_ASSURE_TYPE_LINE( (SAC_ND_A_DIM( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, ))))))))) == 0), 105, "Assignment with incompatible types found!");
      SAC_NOOP()
      SAC_NOOP()
      SAC_NOOP()
      SAC_ND_ASSIGN__DATA( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_emal_3928__dup_2330__pinl_1842__flat_197, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), )

      /*
       * WL_FOLD( (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), 0, (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 1, (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))))
       */
      SAC_TR_WL_PRINT( ("index vector [%d] -- fold", SAC_ND_READ( (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0)));
      /* fold operation */

      SAC_WL_MT_GRID_UNROLL_END(0, (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0, 1)
      SAC_WL_MT_STRIDE_LOOP_END(0, (SACl_iv, (AKS, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), (SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0, SAC_ND_READ((SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1)
      /*
       * MT_SCHEDULER_BlockVar_END( 1, 1, 0, SAC_ND_READ( (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), 0), 1)
       */


      /*
       * WL_SCHEDULE__END( 1)
       */
    }

    SAC_PF_END_WITH(fold)
    SAC_ND_LABEL(_comp_4307_SAC_label)
    SAC_ND_FREE((SACp_eat_110, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
    /*
     * MT_SPMDFUN_RET( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 1, out, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_mtspmdfanon_4301__icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, MT, SACf_ScalarArith_CL_MT___PL__d__d)
     */
    SAC_MT_SYNC_BEGIN( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i);
      SAC_MT_SYNC_FOLD_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 0, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), (SACp_mtspmdfanon_4301__icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))), double, MT, SACf_ScalarArith_CL_MT___PL__d__d);
    SAC_MT_SYNC_CONT( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i);
      SAC_MT_SEND_RESULT_out( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, SAC_MT_MYTHREAD(), 0, (SACp_icc_253, (SCL, (NHD, (NUQ, (FLO, (GLO, (NON, (NOT, )))))))));
    SAC_MT_SYNC_END( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i);
    SAC_MT_SPMDFUN_REAL_RETURN();

    SAC_CLEANUP_LOCAL_MEM()
  }
/*
   * MT_SPMDFUN_DEF_END( SACf__MAIN_CL_ST___mtspmdf_4305_main__bl__bl__d__bl__i__d__i, 8, out, double, (SAC_arg_1, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4274__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4240__flat_173, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_pinl_1811_prime, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, bool, (SACp_pinl_4217__flat_176, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, int, (SACl_lower, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))), in, double, (SACp_flat_4, (SCL, (NHD, (NUQ, (FLO, (GLO, (FPM, (NOT, )))))))), in, int, (SACp_uprf_1877, (SCL, (NHD, (NUQ, (INT, (GLO, (FPM, (NOT, )))))))))
   */
}



/****************************************************************************
 * ST function:
 * SACf__MAIN_CL_ST_CL_INIT__init(...) [ body ]
 ****************************************************************************/
/*
 * ND_FUN_DEF_BEGIN( SACf__MAIN_CL_ST_CL_INIT__init, , 0)
 */
SAC_ND_DEF_FUN_BEGIN2(SACf__MAIN_CL_ST_CL_INIT__init, void, )
{
  SAC_HM_DEFINE_THREAD_STATUS( SAC_HM_single_threaded)

  { 
    SAC_INIT_LOCAL_MEM()
    /*
     * ND_FUN_AP( SACf_World_CL_ST_CL_INIT__init_TheWorld__SACt_World__World, , 1, inout, SACt_World__World, SAC_SET_NT_USG( TFA, (SACo_World__TheWorld, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(SACf_World_CL_ST_CL_INIT__init_TheWorld__SACt_World__World,  SAC_ND_ARG_inout( SAC_SET_NT_USG( TFA, (SACo_World__TheWorld, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_World__World))

    /*
     * ND_FUN_AP( SACf_CommandLine_CL_ST_CL_INIT__init_TheCommandLine__SACt_CommandLine__CommandLine, , 1, inout, SACt_CommandLine__CommandLine, SAC_SET_NT_USG( TFA, (SACo_CommandLine__TheCommandLine, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(SACf_CommandLine_CL_ST_CL_INIT__init_TheCommandLine__SACt_CommandLine__CommandLine,  SAC_ND_ARG_inout( SAC_SET_NT_USG( TFA, (SACo_CommandLine__TheCommandLine, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_CommandLine__CommandLine))

    /*
     * ND_FUN_AP( SACf_Terminal_CL_ST_CL_INIT__init_TheTerminal__SACt_Terminal__Terminal, , 1, inout, SACt_Terminal__Terminal, SAC_SET_NT_USG( TFA, (SACo_Terminal__TheTerminal, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(SACf_Terminal_CL_ST_CL_INIT__init_TheTerminal__SACt_Terminal__Terminal,  SAC_ND_ARG_inout( SAC_SET_NT_USG( TFA, (SACo_Terminal__TheTerminal, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_Terminal__Terminal))

    /*
     * ND_FUN_AP( SACf_TermFile_CL_ST_CL_INIT__init_stdout__SACt_TermFile__TermFile, , 1, inout, SACt_TermFile__TermFile, SAC_SET_NT_USG( TFA, (SACo_TermFile__stdout, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))))
     */
    SAC_ND_FUNAP2(SACf_TermFile_CL_ST_CL_INIT__init_stdout__SACt_TermFile__TermFile,  SAC_ND_ARG_inout( SAC_SET_NT_USG( TFA, (SACo_TermFile__stdout, (SCL, (HID, (NUQ, (INT, (GLO, (NON, (NOT, ))))))))), SACt_TermFile__TermFile))

    /*
     * ND_FUN_RET( , 0)
     */
    return;
    SAC_CLEANUP_LOCAL_MEM()
  }
/*
   * ND_FUN_DEF_END( SACf__MAIN_CL_ST_CL_INIT__init, , 0)
   */
}
SAC_ND_FUN_DEF_END2()

/*
 * stubs for SACARGfreeDataUdt and SACARGcopyDataUdt
 */
extern void SACARGfreeDataUdt( int, void *);
extern void *SACARGcopyDataUdt( int, int, void *);
void SACARGfreeDataUdt( int size, void *data) {}
void *SACARGcopyDataUdt( int type, int size, void *data) { return ((void *) 0x0); } 

int main( int __argc, char *__argv[])
{
  SAC_MT_DECL_MYTHREAD()
  SAC_ND_DECL__DATA( (SAC_res, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int, )
  SAC_ND_DECL__DESC( (SAC_res, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), )
  SAC_NOTHING()
  SAC_MT_SETUP_INITIAL();
  SAC_PF_SETUP();
  SAC_HM_SETUP();
  SAC_MT_SETUP();
  SAC_CS_SETUP();
  SAC_RTSPEC_SETUP();
  SAC_COMMANDLINE_SET( __argc, __argv);

  SACf__MAIN_CL_ST__main( SAC_ND_ARG_out( (SAC_res, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), int));

  SAC_PF_PRINT();
  SAC_CS_FINALIZE();
  SAC_HM_PRINT();

  SAC_RTSPEC_FINALIZE();

  return( SAC_ND_READ( (SAC_res, (SCL, (NHD, (NUQ, (INT, (GLO, (NON, (NOT, )))))))), 0));
}
