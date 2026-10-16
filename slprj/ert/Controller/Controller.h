/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.203
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 16 20:51:23 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#ifndef Controller_h_
#define Controller_h_
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "model_reference_types.h"

/* Forward declaration for rtModel */
typedef struct Controller_tag_RTM Controller_RT_MODEL;

/* Block signals and states (default storage) for model 'Controller' */
typedef struct {
  real_T Delay2_DSTATE[4];             /* '<Root>/Delay2' */
  real_T Delay3_DSTATE[2];             /* '<Root>/Delay3' */
  real_T Delay_DSTATE[2];              /* '<Root>/Delay' */
  real_T Delay1_DSTATE[2];             /* '<Root>/Delay1' */
  real_T Delay4_DSTATE[2];             /* '<Root>/Delay4' */
  real_T y[370];
  real_T x[370];
  real_T y_m[26];
  real_T x_c[26];
  real_T TmpRTBAtESOFunctionInport3;   /* '<Root>/Delay' */
  real_T TmpRTBAtESOFunctionInport4;   /* '<Root>/Delay1' */
  real_T TmpRTBAtESOFunctionInport5;   /* '<Root>/Delay4' */
  real_T u_out;                        /* '<S2>/NAP' */
  real_T bf;                           /* '<S2>/NAP' */
  real_T f_nominal;                    /* '<S2>/NAP' */
  real_T TmpRTBAtNAPSubsystemInport1_Buf;/* synthesized block */
  real_T TmpRTBAtNAPSubsystemInport2_Buf;/* synthesized block */
  real_T TmpRTBAtESOFunctionInport3_Buff;/* synthesized block */
  real_T TmpRTBAtESOFunctionInport4_Buff;/* synthesized block */
  real_T TmpRTBAtESOFunctionInport5_Buff;/* synthesized block */
  real_T TmpRTBAtESOFunctionOutport4_Buf;/* synthesized block */
  real_T tick;                         /* '<S2>/NAP' */
  real_T u_store;                      /* '<S2>/NAP' */
  real_T bf_store;                     /* '<S2>/NAP' */
  real_T f_store;                      /* '<S2>/NAP' */
  real_T z1;                           /* '<Root>/ESO Function' */
  real_T z2;                           /* '<Root>/ESO Function' */
  real_T z3;                           /* '<Root>/ESO Function' */
  real_T u_prev;                       /* '<Root>/ESO Function' */
  real_T u_high;
  real_T h_sim;
  real_T Delay;                        /* '<Root>/Delay' */
  real_T v1;
  real_T stream0;
  struct {
    uint_T z1_not_empty:1;             /* '<Root>/ESO Function' */
  } bitsForTID0;

  boolean_T NAPSubsystem_MODE;         /* '<Root>/NAP Subsystem' */
} Controller_DW_f;

/* Real-time Model Data Structure */
struct Controller_tag_RTM {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    int_T mdlref_GlobalTID[2];
    struct {
      uint32_T TID0_1;
    } RateInteraction;
  } Timing;
};

typedef struct {
  Controller_DW_f rtdw;
  Controller_RT_MODEL rtm;
} Controller_MdlrefDW;

/* Model reference registration function */
extern void Controller_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1,
  Controller_RT_MODEL *const ControllerrtM);
extern void Controller_Init(Controller_DW_f *localDW);
extern void Controller_Disable(Controller_DW_f *localDW);
extern void ControllerTID0(Controller_RT_MODEL * const ControllerrtM, const
  real_T *rtu_vz, const real_T *rtu_h_baro, const boolean_T *rtu_logic, const
  real_T *rtu_pitch, real_T *rty_Out1, Controller_DW_f *localDW);
extern void ControllerTID1(Controller_DW_f *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ADRC' : Unused code path elimination
 * Block '<Root>/NMPC' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/b0' : Unused code path elimination
 * Block '<Root>/f' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller'
 * '<S1>'   : 'Controller/ESO Function'
 * '<S2>'   : 'Controller/NAP Subsystem'
 * '<S3>'   : 'Controller/NAP Subsystem/NAP'
 */
#endif                                 /* Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
