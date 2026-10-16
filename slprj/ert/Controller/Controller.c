/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller.c
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

#include "Controller.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rt_powd_snf.h"
#include <string.h>

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti)       ((rtm)->timingBridge->taskCounter[(rtm)->Timing.mdlref_GlobalTID[sti]] == 0)
#endif

#ifndef rtmIsSpecialSampleHit
#define rtmIsSpecialSampleHit(rtm, sti, prom_sti) ( *(((rtm)->timingBridge->rateTransition)[(unsigned int)(rtm)->Timing.mdlref_GlobalTID[sti] + (rtm)->timingBridge->nTasks*( (unsigned int)(rtm)->Timing.mdlref_GlobalTID[prom_sti])]) )
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetClockTick0
#define rtmGetClockTick0(rtm)          ( *(((rtm)->timingBridge->clockTick[(rtm)->Timing.mdlref_GlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
#define rtmGetClockTick1(rtm)          ( *(((rtm)->timingBridge->clockTick[(rtm)->Timing.mdlref_GlobalTID[1]])) )
#endif

#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0(rtm)         ( *((rtm)->timingBridge->clockTickH[(rtm)->Timing.mdlref_GlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1(rtm)         ( *((rtm)->timingBridge->clockTickH[(rtm)->Timing.mdlref_GlobalTID[1]]) )
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (*((rtm)->timingBridge->taskTime[0]))
#endif

extern const real_T rtCP_pooled_ulChJzkimpDQ[26];
extern const real_T rtCP_pooled_Ih1E7yzQQetR[26];
extern const real_T rtCP_pooled_hbXQYPhRYc53[370];
extern const real_T rtCP_pooled_nmr7KSk6yGOS[370];

#define rtCP_Constant_Value            rtCP_pooled_ulChJzkimpDQ  /* Expression: M_b
                                                                  * Referenced by: '<S2>/Constant'
                                                                  */
#define rtCP_Constant1_Value           rtCP_pooled_Ih1E7yzQQetR  /* Expression: C_b
                                                                  * Referenced by: '<S2>/Constant1'
                                                                  */
#define rtCP_Constant2_Value           rtCP_pooled_hbXQYPhRYc53  /* Expression: M_off
                                                                  * Referenced by: '<S2>/Constant2'
                                                                  */
#define rtCP_Constant7_Value           rtCP_pooled_nmr7KSk6yGOS  /* Expression: Cdr_off
                                                                  * Referenced by: '<S2>/Constant7'
                                                                  */

/* Forward declaration for local functions */
static real_T Controller_interp1_hUoSFMV1(const real_T varargin_1[26], const
  real_T varargin_2[26], real_T varargin_3, Controller_DW_f *localDW);
static real_T Controller_interp1_0JsoyEmA(const real_T varargin_1[370], const
  real_T varargin_2[370], real_T varargin_3, Controller_DW_f *localDW);
static void Controller_RK2(real_T h, real_T v, real_T pitch, real_T u_val, const
  real_T M_b[26], const real_T C_b[26], const real_T M_off[370], const real_T
  Cdr_off[370], real_T *h_final, real_T *bf, real_T *f, Controller_DW_f *localDW);

/* Function for MATLAB Function: '<S2>/NAP' */
static real_T Controller_interp1_hUoSFMV1(const real_T varargin_1[26], const
  real_T varargin_2[26], real_T varargin_3, Controller_DW_f *localDW)
{
  real_T Vq;
  int32_T i;
  memcpy(&localDW->y_m[0], &varargin_2[0], 26U * sizeof(real_T));
  memcpy(&localDW->x_c[0], &varargin_1[0], 26U * sizeof(real_T));
  Vq = 0.0;
  i = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (i < 26) {
      if (rtIsNaN(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      real_T xtmp;
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 13; i++) {
          xtmp = localDW->x_c[i];
          localDW->x_c[i] = localDW->x_c[25 - i];
          localDW->x_c[25 - i] = xtmp;
          xtmp = localDW->y_m[i];
          localDW->y_m[i] = localDW->y_m[25 - i];
          localDW->y_m[25 - i] = xtmp;
        }
      }

      if (rtIsNaN(varargin_3)) {
        Vq = (rtNaN);
      } else if (varargin_3 > localDW->x_c[25]) {
        Vq = (varargin_3 - localDW->x_c[25]) / (localDW->x_c[25] - localDW->x_c
          [24]) * (localDW->y_m[25] - localDW->y_m[24]) + localDW->y_m[25];
      } else if (varargin_3 < localDW->x_c[0]) {
        Vq = (varargin_3 - localDW->x_c[0]) / (localDW->x_c[1] - localDW->x_c[0])
          * (localDW->y_m[1] - localDW->y_m[0]) + localDW->y_m[0];
      } else {
        int32_T low_i;
        int32_T low_ip1;
        i = 26;
        low_i = 1;
        low_ip1 = 2;
        while (i > low_ip1) {
          int32_T mid_i;
          mid_i = (low_i + i) >> 1;
          if (varargin_3 >= localDW->x_c[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            i = mid_i;
          }
        }

        xtmp = localDW->x_c[low_i - 1];
        xtmp = (varargin_3 - xtmp) / (localDW->x_c[low_i] - xtmp);
        if (xtmp == 0.0) {
          Vq = localDW->y_m[low_i - 1];
        } else if (xtmp == 1.0) {
          Vq = localDW->y_m[low_i];
        } else {
          Vq = localDW->y_m[low_i - 1];
          if (!(Vq == localDW->y_m[low_i])) {
            Vq = (1.0 - xtmp) * Vq + xtmp * localDW->y_m[low_i];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Vq;
}

/* Function for MATLAB Function: '<S2>/NAP' */
static real_T Controller_interp1_0JsoyEmA(const real_T varargin_1[370], const
  real_T varargin_2[370], real_T varargin_3, Controller_DW_f *localDW)
{
  real_T Vq;
  int32_T i;
  memcpy(&localDW->y[0], &varargin_2[0], 370U * sizeof(real_T));
  memcpy(&localDW->x[0], &varargin_1[0], 370U * sizeof(real_T));
  Vq = 0.0;
  i = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (i < 370) {
      if (rtIsNaN(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      real_T xtmp;
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 185; i++) {
          xtmp = localDW->x[i];
          localDW->x[i] = localDW->x[369 - i];
          localDW->x[369 - i] = xtmp;
          xtmp = localDW->y[i];
          localDW->y[i] = localDW->y[369 - i];
          localDW->y[369 - i] = xtmp;
        }
      }

      if (rtIsNaN(varargin_3)) {
        Vq = (rtNaN);
      } else if (varargin_3 > localDW->x[369]) {
        Vq = (varargin_3 - localDW->x[369]) / (localDW->x[369] - localDW->x[368])
          * (localDW->y[369] - localDW->y[368]) + localDW->y[369];
      } else if (varargin_3 < localDW->x[0]) {
        Vq = (varargin_3 - localDW->x[0]) / (localDW->x[1] - localDW->x[0]) *
          (localDW->y[1] - localDW->y[0]) + localDW->y[0];
      } else {
        int32_T low_i;
        int32_T low_ip1;
        i = 370;
        low_i = 1;
        low_ip1 = 2;
        while (i > low_ip1) {
          int32_T mid_i;
          mid_i = (low_i + i) >> 1;
          if (varargin_3 >= localDW->x[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            i = mid_i;
          }
        }

        xtmp = localDW->x[low_i - 1];
        xtmp = (varargin_3 - xtmp) / (localDW->x[low_i] - xtmp);
        if (xtmp == 0.0) {
          Vq = localDW->y[low_i - 1];
        } else if (xtmp == 1.0) {
          Vq = localDW->y[low_i];
        } else {
          Vq = localDW->y[low_i - 1];
          if (!(Vq == localDW->y[low_i])) {
            Vq = (1.0 - xtmp) * Vq + xtmp * localDW->y[low_i];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Vq;
}

/* Function for MATLAB Function: '<S2>/NAP' */
static void Controller_RK2(real_T h, real_T v, real_T pitch, real_T u_val, const
  real_T M_b[26], const real_T C_b[26], const real_T M_off[370], const real_T
  Cdr_off[370], real_T *h_final, real_T *bf, real_T *f, Controller_DW_f *localDW)
{
  real_T T0;
  real_T T2;
  real_T mach0;
  real_T stream0_tmp;
  int32_T iter;
  boolean_T exitg1;
  *h_final = h;
  localDW->v1 = v;
  stream0_tmp = cos(pitch);
  localDW->stream0 = v / stream0_tmp;
  T0 = 288.15 - 0.0065 * h;
  mach0 = localDW->stream0 / sqrt(401.87391999999994 * T0);
  localDW->stream0 = rt_powd_snf(T0 / 288.15, 5.2558) * 101325.0 / (287.0528 *
    T0) * -0.5 * (localDW->stream0 * localDW->stream0);
  *bf = localDW->stream0 * Controller_interp1_hUoSFMV1(M_b, C_b, mach0, localDW)
    * 0.002222324 / 25.142 * stream0_tmp;
  *f = localDW->stream0 * Controller_interp1_0JsoyEmA(M_off, Cdr_off, mach0,
    localDW) * 0.013478217882063612 / 25.142 * stream0_tmp - 9.81;
  iter = 0;
  exitg1 = false;
  while ((!exitg1) && ((iter < 500) && (!(localDW->v1 < 0.0)))) {
    localDW->stream0 = localDW->v1 / stream0_tmp;
    T0 = 288.15 - 0.0065 * *h_final;
    mach0 = localDW->stream0 / sqrt(401.87391999999994 * T0);
    localDW->stream0 = rt_powd_snf(T0 / 288.15, 5.2558) * 101325.0 / (287.0528 *
      T0) * -0.5 * (localDW->stream0 * localDW->stream0);
    mach0 = ((localDW->stream0 * Controller_interp1_0JsoyEmA(M_off, Cdr_off,
               mach0, localDW) * 0.013478217882063612 / 25.142 * stream0_tmp -
              9.81) + localDW->stream0 * Controller_interp1_hUoSFMV1(M_b, C_b,
              mach0, localDW) * 0.002222324 / 25.142 * stream0_tmp * u_val) *
      0.05 + localDW->v1;
    T0 = mach0 / stream0_tmp;
    T2 = 288.15 - (localDW->v1 * 0.05 + *h_final) * 0.0065;
    localDW->stream0 = T0 / sqrt(401.87391999999994 * T2);
    T0 = rt_powd_snf(T2 / 288.15, 5.2558) * 101325.0 / (287.0528 * T2) * -0.5 *
      (T0 * T0);
    localDW->v1 += ((T0 * Controller_interp1_0JsoyEmA(M_off, Cdr_off,
      localDW->stream0, localDW) * 0.013478217882063612 / 25.142 * stream0_tmp -
                     9.81) + T0 * Controller_interp1_hUoSFMV1(M_b, C_b,
      localDW->stream0, localDW) * 0.002222324 / 25.142 * stream0_tmp * u_val) *
      0.1;
    *h_final += mach0 * 0.1;
    if (*h_final > 12000.0) {
      exitg1 = true;
    } else {
      iter++;
    }
  }
}

/* System initialize for referenced model: 'Controller' */
void Controller_Init(Controller_DW_f *localDW)
{
  /* SystemInitialize for Enabled SubSystem: '<Root>/NAP Subsystem' */
  /* SystemInitialize for MATLAB Function: '<S2>/NAP' */
  localDW->bf_store = -4.5;
  localDW->f_store = -9.81;

  /* End of SystemInitialize for SubSystem: '<Root>/NAP Subsystem' */
}

/* Disable for referenced model: 'Controller' */
void Controller_Disable(Controller_DW_f *localDW)
{
  /* Disable for Enabled SubSystem: '<Root>/NAP Subsystem' */
  if (localDW->NAPSubsystem_MODE) {
    localDW->NAPSubsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<Root>/NAP Subsystem' */
}

/* Output and update for referenced model: 'Controller' */
void ControllerTID0(Controller_RT_MODEL * const ControllerrtM, const real_T
                    *rtu_vz, const real_T *rtu_h_baro, const boolean_T
                    *rtu_logic, const real_T *rtu_pitch, real_T *rty_Out1,
                    Controller_DW_f *localDW)
{
  int_T tid = 0;
  real_T b0;
  real_T e;
  real_T f;
  real_T rtb_pitchpass;
  real_T u_nmpc;

  /* RateTransition generated from: '<Root>/NAP Subsystem' incorporates:
   *  Delay: '<Root>/Delay2'
   *  RateTransition generated from: '<Root>/ESO Function'
   */
  if (rtmIsSpecialSampleHit(ControllerrtM, 1, 0)) {
    localDW->TmpRTBAtNAPSubsystemInport1_Buf = localDW->Delay2_DSTATE[0];

    /* RateTransition generated from: '<Root>/NAP Subsystem' incorporates:
     *  Delay: '<Root>/Delay2'
     */
    localDW->TmpRTBAtNAPSubsystemInport2_Buf = localDW->Delay2_DSTATE[1];

    /* RateTransition generated from: '<Root>/ESO Function' */
    localDW->TmpRTBAtESOFunctionInport3 =
      localDW->TmpRTBAtESOFunctionInport3_Buff;

    /* RateTransition generated from: '<Root>/ESO Function' */
    localDW->TmpRTBAtESOFunctionInport4 =
      localDW->TmpRTBAtESOFunctionInport4_Buff;

    /* RateTransition generated from: '<Root>/ESO Function' */
    localDW->TmpRTBAtESOFunctionInport5 =
      localDW->TmpRTBAtESOFunctionInport5_Buff;
  }

  /* End of RateTransition generated from: '<Root>/NAP Subsystem' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Delay: '<Root>/Delay3'
   */
  if (*rtu_logic) {
    *rty_Out1 = localDW->Delay3_DSTATE[0];
  } else {
    *rty_Out1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<Root>/ESO Function' */
  u_nmpc = localDW->TmpRTBAtESOFunctionInport3;
  b0 = localDW->TmpRTBAtESOFunctionInport4;
  f = localDW->TmpRTBAtESOFunctionInport5;
  rtb_pitchpass = *rtu_pitch;
  if (rtIsNaN(localDW->TmpRTBAtESOFunctionInport3)) {
    u_nmpc = 0.0;
  }

  if (rtIsNaN(localDW->TmpRTBAtESOFunctionInport4)) {
    b0 = -5.0;
  } else if (localDW->TmpRTBAtESOFunctionInport4 == 0.0) {
    b0 = -5.0;
  }

  if (rtIsNaN(localDW->TmpRTBAtESOFunctionInport5)) {
    f = -9.81;
  }

  if (!localDW->bitsForTID0.z1_not_empty) {
    localDW->z1 = 892.0;
    localDW->bitsForTID0.z1_not_empty = true;
    localDW->z2 = 0.0;
    localDW->z3 = -9.81;
    localDW->u_prev = 0.0;
    if (!rtIsNaN(*rtu_h_baro)) {
      localDW->z1 = *rtu_h_baro;
    }

    if (!rtIsNaN(*rtu_vz)) {
      localDW->z2 = *rtu_vz;
    }

    if (!rtIsNaN(f)) {
      localDW->z3 = f;
    }
  }

  if (rtIsNaN(*rtu_h_baro) || rtIsNaN(*rtu_vz)) {
  } else {
    e = localDW->z1 - *rtu_h_baro;
    localDW->u_prev = fmax(0.0, fmin(1.0, fmax(fmin((fmax(-0.5, fmin(0.5,
      -localDW->z3 / b0)) + u_nmpc) - localDW->u_prev, 0.3), -0.3) +
      localDW->u_prev));
    localDW->z1 += (localDW->z2 - 18.0 * e) * 0.001;
    localDW->z2 += (((localDW->z3 + f) - 108.0 * e) + b0 * localDW->u_prev) *
      0.001;
    localDW->z3 += -216.0 * e * 0.001;
  }

  /* RateTransition generated from: '<Root>/ESO Function' */
  if (rtmIsSpecialSampleHit(ControllerrtM, 1, 0)) {
    localDW->TmpRTBAtESOFunctionOutport4_Buf = rtb_pitchpass;
  }

  /* End of RateTransition generated from: '<Root>/ESO Function' */

  /* Outputs for Enabled SubSystem: '<Root>/NAP Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (*rtu_logic) {
    if (!localDW->NAPSubsystem_MODE) {
      localDW->NAPSubsystem_MODE = true;
    }
  } else if (localDW->NAPSubsystem_MODE) {
    localDW->NAPSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/NAP Subsystem' */

  /* Update for Delay: '<Root>/Delay2' */
  localDW->Delay2_DSTATE[0] = localDW->Delay2_DSTATE[2];
  localDW->Delay2_DSTATE[1] = localDW->Delay2_DSTATE[3];
  localDW->Delay2_DSTATE[2] = localDW->z1;
  localDW->Delay2_DSTATE[3] = localDW->z2;

  /* Update for Delay: '<Root>/Delay3' incorporates:
   *  MATLAB Function: '<Root>/ESO Function'
   */
  localDW->Delay3_DSTATE[0] = localDW->Delay3_DSTATE[1];
  localDW->Delay3_DSTATE[1] = localDW->u_prev;

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as a local variable.
   * As result, some Output functions may have unused tid.
   */
  (void) (tid);
}

/* Output and update for referenced model: 'Controller' */
void ControllerTID1(Controller_DW_f *localDW)
{
  int_T tid = 1;
  int32_T iter;
  boolean_T guard1;

  /* Delay: '<Root>/Delay' */
  localDW->Delay = localDW->Delay_DSTATE[0];

  /* RateTransition generated from: '<Root>/ESO Function' */
  localDW->TmpRTBAtESOFunctionInport3_Buff = localDW->Delay;

  /* Delay: '<Root>/Delay1' */
  localDW->Delay = localDW->Delay1_DSTATE[0];

  /* RateTransition generated from: '<Root>/ESO Function' */
  localDW->TmpRTBAtESOFunctionInport4_Buff = localDW->Delay;

  /* Delay: '<Root>/Delay4' */
  localDW->Delay = localDW->Delay4_DSTATE[0];

  /* RateTransition generated from: '<Root>/ESO Function' */
  localDW->TmpRTBAtESOFunctionInport5_Buff = localDW->Delay;

  /* Outputs for Enabled SubSystem: '<Root>/NAP Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (localDW->NAPSubsystem_MODE) {
    /* MATLAB Function: '<S2>/NAP' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant7'
     *  RateTransition generated from: '<Root>/ESO Function'
     *  RateTransition generated from: '<Root>/NAP Subsystem'
     * */
    localDW->u_out = 0.0;
    localDW->bf = -4.5;
    localDW->f_nominal = -9.81;
    if ((!rtIsNaN(localDW->TmpRTBAtNAPSubsystemInport1_Buf)) && (!rtIsNaN
         (localDW->TmpRTBAtNAPSubsystemInport2_Buf))) {
      guard1 = false;
      if (localDW->tick <= 0.0) {
        Controller_RK2(localDW->TmpRTBAtNAPSubsystemInport1_Buf,
                       localDW->TmpRTBAtNAPSubsystemInport2_Buf,
                       localDW->TmpRTBAtESOFunctionOutport4_Buf, 0.0,
                       rtCP_Constant_Value, rtCP_Constant1_Value,
                       rtCP_Constant2_Value, rtCP_Constant7_Value,
                       &localDW->Delay, &localDW->bf, &localDW->f_nominal,
                       localDW);
        if (localDW->Delay < 11072.32) {
        } else {
          Controller_RK2(localDW->TmpRTBAtNAPSubsystemInport1_Buf,
                         localDW->TmpRTBAtNAPSubsystemInport2_Buf,
                         localDW->TmpRTBAtESOFunctionOutport4_Buf, 1.0,
                         rtCP_Constant_Value, rtCP_Constant1_Value,
                         rtCP_Constant2_Value, rtCP_Constant7_Value,
                         &localDW->Delay, &localDW->bf, &localDW->f_nominal,
                         localDW);
          if (localDW->Delay > 11072.32) {
            localDW->u_out = 1.0;
          } else {
            localDW->Delay = 0.0;
            localDW->u_high = 1.0;
            localDW->u_store = 0.5;
            for (iter = 0; iter < 5; iter++) {
              Controller_RK2(localDW->TmpRTBAtNAPSubsystemInport1_Buf,
                             localDW->TmpRTBAtNAPSubsystemInport2_Buf,
                             localDW->TmpRTBAtESOFunctionOutport4_Buf,
                             localDW->u_store, rtCP_Constant_Value,
                             rtCP_Constant1_Value, rtCP_Constant2_Value,
                             rtCP_Constant7_Value, &localDW->h_sim,
                             &localDW->bf_store, &localDW->f_store, localDW);
              if (localDW->h_sim > 11072.32) {
                localDW->Delay = localDW->u_store;
              } else {
                localDW->u_high = localDW->u_store;
              }

              localDW->u_store = (localDW->Delay + localDW->u_high) / 2.0;
            }

            localDW->tick = 10.0;
            guard1 = true;
          }
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        localDW->tick--;
        localDW->u_out = localDW->u_store;
        localDW->bf = localDW->bf_store;
        localDW->f_nominal = localDW->f_store;
      }
    }

    /* End of MATLAB Function: '<S2>/NAP' */
  }

  /* End of Outputs for SubSystem: '<Root>/NAP Subsystem' */

  /* Update for Delay: '<Root>/Delay' */
  localDW->Delay_DSTATE[0] = localDW->Delay_DSTATE[1];
  localDW->Delay_DSTATE[1] = localDW->u_out;

  /* Update for Delay: '<Root>/Delay1' */
  localDW->Delay1_DSTATE[0] = localDW->Delay1_DSTATE[1];
  localDW->Delay1_DSTATE[1] = localDW->bf;

  /* Update for Delay: '<Root>/Delay4' */
  localDW->Delay4_DSTATE[0] = localDW->Delay4_DSTATE[1];
  localDW->Delay4_DSTATE[1] = localDW->f_nominal;

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as a local variable.
   * As result, some Output functions may have unused tid.
   */
  (void) (tid);
}

/* Model initialize function */
void Controller_initialize(const char_T **rt_errorStatus, const rtTimingBridge
  *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1, Controller_RT_MODEL *
  const ControllerrtM)
{
  /* Registration code */

  /* setup the global timing engine */
  ControllerrtM->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
  ControllerrtM->Timing.mdlref_GlobalTID[1] = mdlref_TID1;
  ControllerrtM->timingBridge = (timingBridge);

  /* initialize error status */
  rtmSetErrorStatusPointer(ControllerrtM, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
