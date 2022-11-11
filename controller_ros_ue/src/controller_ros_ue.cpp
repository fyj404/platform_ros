//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: controller_ros_ue.cpp
//
// Code generated for Simulink model 'controller_ros_ue'.
//
// Model version                  : 12.4
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Aug 23 08:05:26 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_ros_ue.h"
#include "rtwtypes.h"
#include "controller_ros_ue_private.h"
#include <math.h>
#include <string.h>

extern "C" {

#include "rt_nonfinite.h"

}
// Block signals (default storage)
  B_controller_ros_ue_T controller_ros_ue_B;

// Continuous states
X_controller_ros_ue_T controller_ros_ue_X;

// Block states (default storage)
DW_controller_ros_ue_T controller_ros_ue_DW;

// Real-time model
RT_MODEL_controller_ros_ue_T controller_ros_ue_M_ = RT_MODEL_controller_ros_ue_T
  ();
RT_MODEL_controller_ros_ue_T *const controller_ros_ue_M = &controller_ros_ue_M_;

// Forward declaration for local functions
static void controller_ros_ue_mldivide_l(const real_T A[36], real_T B[6]);

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 30;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  controller_ros_ue_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  controller_ros_ue_step();
  controller_ros_ue_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  controller_ros_ue_step();
  controller_ros_ue_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// Output and update for atomic system:
//    '<S7>/MATLAB Function1'
//    '<S7>/MATLAB Function2'
//    '<S7>/MATLAB Function3'
//
void controller_ros__MATLABFunction1(real_T rtu_phi, real_T rtu_theta, real_T
  rtu_psi, real_T rtu_fx, real_T rtu_fy, real_T rtu_fz, real_T rtu_psi_cmd,
  real_T *rty_thrust, real_T *rty_phi_i, real_T *rty_theta_i,
  B_MATLABFunction1_controller__T *localB)
{
  real_T fw_tmp;
  real_T fw_tmp_0;
  real_T fw_tmp_1;
  real_T fw_tmp_2;
  real_T fw_tmp_3;
  real_T fw_tmp_4;

  // MATLAB Function 'Control Allocarion/MATLAB Function1': '<S25>:1'
  // '<S25>:1:3'
  // '<S25>:1:7'
  // '<S25>:1:9'
  fw_tmp = cos(rtu_psi);
  fw_tmp_0 = cos(rtu_phi);
  fw_tmp_1 = sin(rtu_theta);
  fw_tmp_2 = sin(rtu_phi);
  fw_tmp_3 = sin(rtu_psi);
  fw_tmp_4 = cos(rtu_theta);
  localB->fw_tmp[0] = fw_tmp_4 * fw_tmp;
  localB->fw_tmp[3] = fw_tmp_2 * fw_tmp_1 * fw_tmp - fw_tmp_0 * fw_tmp_3;
  localB->fw_tmp[6] = fw_tmp_0 * fw_tmp_1 * fw_tmp + fw_tmp_2 * fw_tmp_3;
  localB->fw_tmp[1] = fw_tmp_4 * fw_tmp_3;
  localB->fw_tmp[4] = sin(rtu_phi) * sin(rtu_theta) * fw_tmp_3 + fw_tmp_0 *
    fw_tmp;
  localB->fw_tmp[7] = cos(rtu_phi) * sin(rtu_theta) * fw_tmp_3 - fw_tmp_2 *
    fw_tmp;
  localB->fw_tmp[2] = -fw_tmp_1;
  localB->fw_tmp[5] = fw_tmp_2 * fw_tmp_4;
  localB->fw_tmp[8] = fw_tmp_0 * fw_tmp_4;
  for (int32_T i = 0; i < 3; i++) {
    localB->fw[i] = (localB->fw_tmp[i + 3] * rtu_fy + localB->fw_tmp[i] * rtu_fx)
      + localB->fw_tmp[i + 6] * rtu_fz;
  }

  // '<S25>:1:11'
  // '<S25>:1:12'
  // '<S25>:1:13'
  // '<S25>:1:14'
  fw_tmp = localB->fw[2] * localB->fw[2];
  fw_tmp_0 = sqrt((localB->fw[0] * localB->fw[0] + localB->fw[1] * localB->fw[1])
                  + fw_tmp);

  // '<S25>:1:16'
  fw_tmp_1 = cos(rtu_psi_cmd);
  fw_tmp_2 = sin(rtu_psi_cmd);
  *rty_phi_i = (localB->fw[1] * fw_tmp_1 - localB->fw[0] * fw_tmp_2) / fw_tmp_0;
  *rty_phi_i = asin(*rty_phi_i);

  // '<S25>:1:17'
  fw_tmp_1 = localB->fw[0] * fw_tmp_1 + localB->fw[1] * fw_tmp_2;
  *rty_theta_i = -(localB->fw[0] * cos(rtu_psi_cmd) + localB->fw[1] * sin
                   (rtu_psi_cmd)) / sqrt(fw_tmp_1 * fw_tmp_1 + fw_tmp);
  *rty_theta_i = asin(*rty_theta_i);
  *rty_thrust = fw_tmp_0;
}

//
// Output and update for atomic system:
//    '<S47>/MATLAB Function1'
//    '<S47>/MATLAB Function3'
//    '<S48>/MATLAB Function1'
//    '<S48>/MATLAB Function3'
//    '<S49>/MATLAB Function1'
//    '<S49>/MATLAB Function3'
//    '<S60>/MATLAB Function1'
//    '<S60>/MATLAB Function3'
//    '<S61>/MATLAB Function1'
//    '<S61>/MATLAB Function3'
//    ...
//
void controller_ro_MATLABFunction1_a(real_T rtu_u, real_T rtu_omega, real_T
  *rty_y)
{
  // MATLAB Function 'Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator phi/MATLAB Function1': '<S50>:1' 
  // '<S50>:1:3'
  *rty_y = rtu_omega * rtu_omega * rtu_u;
}

//
// Output and update for atomic system:
//    '<S47>/MATLAB Function2'
//    '<S48>/MATLAB Function2'
//    '<S49>/MATLAB Function2'
//    '<S60>/MATLAB Function2'
//    '<S61>/MATLAB Function2'
//    '<S62>/MATLAB Function2'
//    '<S40>/MATLAB Function2'
//    '<S41>/MATLAB Function2'
//    '<S42>/MATLAB Function2'
//    '<S43>/MATLAB Function2'
//    ...
//
void controller_ros__MATLABFunction2(real_T rtu_u, real_T rtu_omega, real_T
  rtu_epsilon, real_T *rty_y)
{
  // MATLAB Function 'Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator phi/MATLAB Function2': '<S51>:1' 
  // '<S51>:1:3'
  *rty_y = 2.0 * rtu_omega * rtu_epsilon * rtu_u;
}

// Function for MATLAB Function: '<S7>/MATLAB Function'
static void controller_ros_ue_mldivide_l(const real_T A[36], real_T B[6])
{
  memcpy(&controller_ros_ue_B.b_A[0], &A[0], 36U * sizeof(real_T));
  for (controller_ros_ue_B.jj = 0; controller_ros_ue_B.jj < 6;
       controller_ros_ue_B.jj++) {
    controller_ros_ue_B.ipiv[controller_ros_ue_B.jj] = static_cast<int8_T>
      (controller_ros_ue_B.jj + 1);
  }

  for (controller_ros_ue_B.j = 0; controller_ros_ue_B.j < 5;
       controller_ros_ue_B.j++) {
    controller_ros_ue_B.jj = controller_ros_ue_B.j * 7;
    controller_ros_ue_B.jA = 0;
    controller_ros_ue_B.ix = controller_ros_ue_B.jj;
    controller_ros_ue_B.smax = fabs
      (controller_ros_ue_B.b_A[controller_ros_ue_B.jj]);
    controller_ros_ue_B.c_k = 2;
    while (controller_ros_ue_B.c_k <= 6 - controller_ros_ue_B.j) {
      controller_ros_ue_B.ix++;
      controller_ros_ue_B.s = fabs
        (controller_ros_ue_B.b_A[controller_ros_ue_B.ix]);
      if (controller_ros_ue_B.s > controller_ros_ue_B.smax) {
        controller_ros_ue_B.jA = controller_ros_ue_B.c_k - 1;
        controller_ros_ue_B.smax = controller_ros_ue_B.s;
      }

      controller_ros_ue_B.c_k++;
    }

    if (controller_ros_ue_B.b_A[controller_ros_ue_B.jj + controller_ros_ue_B.jA]
        != 0.0) {
      if (controller_ros_ue_B.jA != 0) {
        controller_ros_ue_B.ix = controller_ros_ue_B.j + controller_ros_ue_B.jA;
        controller_ros_ue_B.ipiv[controller_ros_ue_B.j] = static_cast<int8_T>
          (controller_ros_ue_B.ix + 1);
        for (controller_ros_ue_B.jA = 0; controller_ros_ue_B.jA < 6;
             controller_ros_ue_B.jA++) {
          controller_ros_ue_B.c_k = controller_ros_ue_B.jA * 6 +
            controller_ros_ue_B.j;
          controller_ros_ue_B.smax =
            controller_ros_ue_B.b_A[controller_ros_ue_B.c_k];
          controller_ros_ue_B.c_ix = controller_ros_ue_B.jA * 6 +
            controller_ros_ue_B.ix;
          controller_ros_ue_B.b_A[controller_ros_ue_B.c_k] =
            controller_ros_ue_B.b_A[controller_ros_ue_B.c_ix];
          controller_ros_ue_B.b_A[controller_ros_ue_B.c_ix] =
            controller_ros_ue_B.smax;
        }
      }

      controller_ros_ue_B.jA = (controller_ros_ue_B.jj - controller_ros_ue_B.j)
        + 6;
      controller_ros_ue_B.ix = controller_ros_ue_B.jj + 1;
      while (controller_ros_ue_B.ix + 1 <= controller_ros_ue_B.jA) {
        controller_ros_ue_B.b_A[controller_ros_ue_B.ix] /=
          controller_ros_ue_B.b_A[controller_ros_ue_B.jj];
        controller_ros_ue_B.ix++;
      }
    }

    controller_ros_ue_B.jA = controller_ros_ue_B.jj;
    controller_ros_ue_B.ix = controller_ros_ue_B.jj + 6;
    controller_ros_ue_B.c_k = 0;
    while (controller_ros_ue_B.c_k <= 4 - controller_ros_ue_B.j) {
      if (controller_ros_ue_B.b_A[controller_ros_ue_B.ix] != 0.0) {
        controller_ros_ue_B.smax =
          -controller_ros_ue_B.b_A[controller_ros_ue_B.ix];
        controller_ros_ue_B.c_ix = controller_ros_ue_B.jj + 1;
        controller_ros_ue_B.ijA = controller_ros_ue_B.jA + 7;
        controller_ros_ue_B.c = (controller_ros_ue_B.jA - controller_ros_ue_B.j)
          + 12;
        while (controller_ros_ue_B.ijA + 1 <= controller_ros_ue_B.c) {
          controller_ros_ue_B.b_A[controller_ros_ue_B.ijA] +=
            controller_ros_ue_B.b_A[controller_ros_ue_B.c_ix] *
            controller_ros_ue_B.smax;
          controller_ros_ue_B.c_ix++;
          controller_ros_ue_B.ijA++;
        }
      }

      controller_ros_ue_B.ix += 6;
      controller_ros_ue_B.jA += 6;
      controller_ros_ue_B.c_k++;
    }

    if (controller_ros_ue_B.j + 1 !=
        controller_ros_ue_B.ipiv[controller_ros_ue_B.j]) {
      controller_ros_ue_B.smax = B[controller_ros_ue_B.j];
      controller_ros_ue_B.jj = controller_ros_ue_B.ipiv[controller_ros_ue_B.j] -
        1;
      B[controller_ros_ue_B.j] = B[controller_ros_ue_B.jj];
      B[controller_ros_ue_B.jj] = controller_ros_ue_B.smax;
    }
  }

  for (controller_ros_ue_B.j = 0; controller_ros_ue_B.j < 6;
       controller_ros_ue_B.j++) {
    controller_ros_ue_B.jj = 6 * controller_ros_ue_B.j;
    if (B[controller_ros_ue_B.j] != 0.0) {
      controller_ros_ue_B.jA = controller_ros_ue_B.j + 1;
      while (controller_ros_ue_B.jA + 1 < 7) {
        B[controller_ros_ue_B.jA] -=
          controller_ros_ue_B.b_A[controller_ros_ue_B.jA +
          controller_ros_ue_B.jj] * B[controller_ros_ue_B.j];
        controller_ros_ue_B.jA++;
      }
    }
  }

  for (controller_ros_ue_B.j = 5; controller_ros_ue_B.j >= 0;
       controller_ros_ue_B.j--) {
    controller_ros_ue_B.jj = 6 * controller_ros_ue_B.j;
    if (B[controller_ros_ue_B.j] != 0.0) {
      B[controller_ros_ue_B.j] /= controller_ros_ue_B.b_A[controller_ros_ue_B.j
        + controller_ros_ue_B.jj];
      controller_ros_ue_B.jA = 0;
      while (controller_ros_ue_B.jA <= controller_ros_ue_B.j - 1) {
        B[controller_ros_ue_B.jA] -=
          controller_ros_ue_B.b_A[controller_ros_ue_B.jA +
          controller_ros_ue_B.jj] * B[controller_ros_ue_B.j];
        controller_ros_ue_B.jA++;
      }
    }
  }
}

// Model step function
void controller_ros_ue_step(void)
{
  if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&controller_ros_ue_M->solverInfo,
                          ((controller_ros_ue_M->Timing.clockTick0+1)*
      controller_ros_ue_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(controller_ros_ue_M)) {
    controller_ros_ue_M->Timing.t[0] = rtsiGetT(&controller_ros_ue_M->solverInfo);
  }

  {
    real_T *lastU;
    boolean_T b_varargout_1;
    static const int8_T c[27] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0,
      0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T d[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // Outputs for Atomic SubSystem: '<Root>/Subscribe'
      // MATLABSystem: '<S16>/SourceBlock'
      b_varargout_1 = Sub_controller_ros_ue_222.getLatestMessage
        (&controller_ros_ue_B.b_varargout_2);

      // Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S94>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S94>/In1'
        controller_ros_ue_B.In1_l = controller_ros_ue_B.b_varargout_2;
      }

      // End of MATLABSystem: '<S16>/SourceBlock'
      // End of Outputs for SubSystem: '<S16>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<Root>/Subscribe'

      // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
      // MATLABSystem: '<S17>/SourceBlock'
      b_varargout_1 = Sub_controller_ros_ue_225.getLatestMessage
        (&controller_ros_ue_B.b_varargout_2);

      // Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S95>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S95>/In1'
        controller_ros_ue_B.In1_f = controller_ros_ue_B.b_varargout_2;
      }

      // End of MATLABSystem: '<S17>/SourceBlock'
      // End of Outputs for SubSystem: '<S17>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<Root>/Subscribe1'
    }

    // Integrator: '<S43>/Integrator'
    controller_ros_ue_B.Integrator = controller_ros_ue_X.Integrator_CSTATE;

    // Derivative: '<S43>/Derivative' incorporates:
    //   Derivative: '<S40>/Derivative'
    //   Derivative: '<S41>/Derivative'
    //   Derivative: '<S42>/Derivative'
    //   Derivative: '<S44>/Derivative'
    //   Derivative: '<S45>/Derivative'
    //   Derivative: '<S47>/Derivative'
    //   Derivative: '<S48>/Derivative'
    //   Derivative: '<S49>/Derivative'
    //   Derivative: '<S60>/Derivative'
    //   Derivative: '<S61>/Derivative'
    //   Derivative: '<S62>/Derivative'

    controller_ros_ue_B.rtb_y_h_g = controller_ros_ue_M->Timing.t[0];
    if ((controller_ros_ue_DW.TimeStampA >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA;
      lastU = &controller_ros_ue_DW.LastUAtTimeA;
      if (controller_ros_ue_DW.TimeStampA < controller_ros_ue_DW.TimeStampB) {
        if (controller_ros_ue_DW.TimeStampB < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB;
          lastU = &controller_ros_ue_DW.LastUAtTimeB;
        }
      } else if (controller_ros_ue_DW.TimeStampA >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB;
        lastU = &controller_ros_ue_DW.LastUAtTimeB;
      }

      controller_ros_ue_B.Derivative = (controller_ros_ue_B.Integrator - *lastU)
        / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // End of Derivative: '<S43>/Derivative'

    // Integrator: '<S44>/Integrator'
    controller_ros_ue_B.Integrator_a = controller_ros_ue_X.Integrator_CSTATE_p;

    // Derivative: '<S44>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_h >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_h >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_i = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_h;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_o;
      if (controller_ros_ue_DW.TimeStampA_h < controller_ros_ue_DW.TimeStampB_h)
      {
        if (controller_ros_ue_DW.TimeStampB_h < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_h;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_g;
        }
      } else if (controller_ros_ue_DW.TimeStampA_h >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_h;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_g;
      }

      controller_ros_ue_B.Derivative_i = (controller_ros_ue_B.Integrator_a -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S45>/Integrator'
    controller_ros_ue_B.Integrator_j = controller_ros_ue_X.Integrator_CSTATE_m;

    // Derivative: '<S45>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_p >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_g >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_g = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_p;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_m;
      if (controller_ros_ue_DW.TimeStampA_p < controller_ros_ue_DW.TimeStampB_g)
      {
        if (controller_ros_ue_DW.TimeStampB_g < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_g;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_f;
        }
      } else if (controller_ros_ue_DW.TimeStampA_p >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_g;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_f;
      }

      controller_ros_ue_B.Derivative_g = (controller_ros_ue_B.Integrator_j -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // Outputs for Atomic SubSystem: '<Root>/Subscribe5'
      // MATLABSystem: '<S21>/SourceBlock'
      b_varargout_1 = Sub_controller_ros_ue_238.getLatestMessage
        (&controller_ros_ue_B.b_varargout_2_c);

      // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S99>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S99>/In1'
        controller_ros_ue_B.In1_n = controller_ros_ue_B.b_varargout_2_c;
      }

      // End of MATLABSystem: '<S21>/SourceBlock'
      // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<Root>/Subscribe5'
    }

    // Integrator: '<S47>/Integrator'
    controller_ros_ue_B.Integrator_b = controller_ros_ue_X.Integrator_CSTATE_e;

    // Derivative: '<S47>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_e >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_j >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_gu = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_e;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_mt;
      if (controller_ros_ue_DW.TimeStampA_e < controller_ros_ue_DW.TimeStampB_j)
      {
        if (controller_ros_ue_DW.TimeStampB_j < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_j;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_fx;
        }
      } else if (controller_ros_ue_DW.TimeStampA_e >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_j;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_fx;
      }

      controller_ros_ue_B.Derivative_gu = (controller_ros_ue_B.Integrator_b -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S49>/Integrator'
    controller_ros_ue_B.Integrator_e = controller_ros_ue_X.Integrator_CSTATE_k;

    // Derivative: '<S49>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_n >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_gr >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_iw = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_n;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_l;
      if (controller_ros_ue_DW.TimeStampA_n < controller_ros_ue_DW.TimeStampB_gr)
      {
        if (controller_ros_ue_DW.TimeStampB_gr < controller_ros_ue_B.rtb_y_h_g)
        {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_gr;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_h;
        }
      } else if (controller_ros_ue_DW.TimeStampA_n >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_gr;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_h;
      }

      controller_ros_ue_B.Derivative_iw = (controller_ros_ue_B.Integrator_e -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S48>/Integrator'
    controller_ros_ue_B.Integrator_i = controller_ros_ue_X.Integrator_CSTATE_j;

    // Derivative: '<S48>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_nq >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_e >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_d = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_nq;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_e;
      if (controller_ros_ue_DW.TimeStampA_nq < controller_ros_ue_DW.TimeStampB_e)
      {
        if (controller_ros_ue_DW.TimeStampB_e < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_e;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_n;
        }
      } else if (controller_ros_ue_DW.TimeStampA_nq >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_e;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_n;
      }

      controller_ros_ue_B.Derivative_d = (controller_ros_ue_B.Integrator_i -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // MATLAB Function: '<S38>/MATLAB Function' incorporates:
    //   MATLAB Function: '<S39>/MATLAB Function'

    // MATLAB Function 'Controller/calc_epsilon_d/Rotational kinematic inverse/MATLAB Function': '<S46>:1' 
    // '<S46>:1:2'
    controller_ros_ue_B.rtb_p_bar_tmp = sin(controller_ros_ue_B.In1_n.Y);
    controller_ros_ue_B.Derivative_gu -= controller_ros_ue_B.Derivative_d *
      controller_ros_ue_B.rtb_p_bar_tmp;

    // '<S46>:1:3'
    controller_ros_ue_B.rtb_q_bar_tmp = sin(controller_ros_ue_B.In1_n.X);
    controller_ros_ue_B.rtb_q_bar_tmp_g = cos(controller_ros_ue_B.In1_n.X);
    controller_ros_ue_B.rtb_q_bar_tmp_m = cos(controller_ros_ue_B.In1_n.Y);
    controller_ros_ue_B.q_bar = controller_ros_ue_B.Derivative_d *
      controller_ros_ue_B.rtb_q_bar_tmp * controller_ros_ue_B.rtb_q_bar_tmp_m +
      controller_ros_ue_B.Derivative_iw * controller_ros_ue_B.rtb_q_bar_tmp_g;

    // '<S46>:1:4'
    controller_ros_ue_B.Derivative_iw = controller_ros_ue_B.Derivative_d *
      controller_ros_ue_B.rtb_q_bar_tmp_g * controller_ros_ue_B.rtb_q_bar_tmp_m
      + -controller_ros_ue_B.Derivative_iw * controller_ros_ue_B.rtb_q_bar_tmp;

    // Integrator: '<S60>/Integrator'
    controller_ros_ue_B.Integrator_k = controller_ros_ue_X.Integrator_CSTATE_k3;

    // Derivative: '<S60>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_f >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_f >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_d = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_f;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_d;
      if (controller_ros_ue_DW.TimeStampA_f < controller_ros_ue_DW.TimeStampB_f)
      {
        if (controller_ros_ue_DW.TimeStampB_f < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_f;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_fd;
        }
      } else if (controller_ros_ue_DW.TimeStampA_f >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_f;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_fd;
      }

      controller_ros_ue_B.Derivative_d = (controller_ros_ue_B.Integrator_k -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S61>/Integrator'
    controller_ros_ue_B.Integrator_n = controller_ros_ue_X.Integrator_CSTATE_c;

    // Derivative: '<S61>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_j >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_f4 >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_j = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_j;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_n;
      if (controller_ros_ue_DW.TimeStampA_j < controller_ros_ue_DW.TimeStampB_f4)
      {
        if (controller_ros_ue_DW.TimeStampB_f4 < controller_ros_ue_B.rtb_y_h_g)
        {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_f4;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_l;
        }
      } else if (controller_ros_ue_DW.TimeStampA_j >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_f4;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_l;
      }

      controller_ros_ue_B.Derivative_j = (controller_ros_ue_B.Integrator_n -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S62>/Integrator'
    controller_ros_ue_B.Integrator_ad = controller_ros_ue_X.Integrator_CSTATE_i;

    // Derivative: '<S62>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_m >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_l >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_n = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_m;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_j;
      if (controller_ros_ue_DW.TimeStampA_m < controller_ros_ue_DW.TimeStampB_l)
      {
        if (controller_ros_ue_DW.TimeStampB_l < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_l;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_b;
        }
      } else if (controller_ros_ue_DW.TimeStampA_m >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_l;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_b;
      }

      controller_ros_ue_B.Derivative_n = (controller_ros_ue_B.Integrator_ad -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // MATLAB Function: '<S39>/MATLAB Function'
    // MATLAB Function 'Controller/calc_epsilon_d/Translational kinematic inverse/MATLAB Function': '<S59>:1' 
    // '<S59>:1:3'
    // '<S59>:1:9'
    // '<S59>:1:11'
    controller_ros_ue_B.vd_tmp = cos(controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.lastTime = sin(controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[0] = controller_ros_ue_B.rtb_q_bar_tmp_m *
      controller_ros_ue_B.vd_tmp;
    controller_ros_ue_B.Rd[1] = controller_ros_ue_B.rtb_q_bar_tmp *
      controller_ros_ue_B.rtb_p_bar_tmp * controller_ros_ue_B.vd_tmp -
      controller_ros_ue_B.rtb_q_bar_tmp_g * controller_ros_ue_B.lastTime;
    controller_ros_ue_B.Rd[2] = controller_ros_ue_B.rtb_q_bar_tmp_g *
      controller_ros_ue_B.rtb_p_bar_tmp * controller_ros_ue_B.vd_tmp +
      controller_ros_ue_B.rtb_q_bar_tmp * controller_ros_ue_B.lastTime;
    controller_ros_ue_B.Rd[3] = controller_ros_ue_B.rtb_q_bar_tmp_m *
      controller_ros_ue_B.lastTime;
    controller_ros_ue_B.Rd[4] = sin(controller_ros_ue_B.In1_n.X) * sin
      (controller_ros_ue_B.In1_n.Y) * controller_ros_ue_B.lastTime +
      controller_ros_ue_B.rtb_q_bar_tmp_g * controller_ros_ue_B.vd_tmp;
    controller_ros_ue_B.Rd[5] = cos(controller_ros_ue_B.In1_n.X) * sin
      (controller_ros_ue_B.In1_n.Y) * controller_ros_ue_B.lastTime -
      controller_ros_ue_B.rtb_q_bar_tmp * controller_ros_ue_B.vd_tmp;
    controller_ros_ue_B.Rd[6] = -controller_ros_ue_B.rtb_p_bar_tmp;
    controller_ros_ue_B.Rd[7] = controller_ros_ue_B.rtb_q_bar_tmp *
      controller_ros_ue_B.rtb_q_bar_tmp_m;
    controller_ros_ue_B.Rd[8] = controller_ros_ue_B.rtb_q_bar_tmp_g *
      controller_ros_ue_B.rtb_q_bar_tmp_m;
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.vd[controller_ros_ue_B.i] =
        (controller_ros_ue_B.Rd[controller_ros_ue_B.i + 3] *
         controller_ros_ue_B.Derivative_j +
         controller_ros_ue_B.Rd[controller_ros_ue_B.i] *
         controller_ros_ue_B.Derivative_d) +
        controller_ros_ue_B.Rd[controller_ros_ue_B.i + 6] *
        controller_ros_ue_B.Derivative_n;
    }

    // MATLAB Function: '<S30>/MATLAB Function' incorporates:
    //   Constant: '<S22>/tool_x'
    //   Constant: '<S22>/tool_y'
    //   Constant: '<S22>/tool_z'
    //   MATLAB Function: '<S28>/MATLAB Function'
    //   MATLAB Function: '<S30>/MATLAB Function1'
    //   MATLAB Function: '<S31>/MATLAB Function1'
    //   MATLAB Function: '<S39>/MATLAB Function'

    // '<S59>:1:13'
    // '<S59>:1:14'
    // '<S59>:1:15'
    // MATLAB Function 'Controller/calc_epsilon_d/MATLAB Function': '<S36>:1'
    // '<S36>:1:3'
    // '<S36>:1:6'
    controller_ros_ue_B.rtb_p_bar_tmp = cos(controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.rtb_q_bar_tmp = cos(controller_ros_ue_B.In1_l.X);
    controller_ros_ue_B.rtb_q_bar_tmp_g = sin(controller_ros_ue_B.In1_l.Y);
    controller_ros_ue_B.rtb_q_bar_tmp_m = sin(controller_ros_ue_B.In1_l.X);
    controller_ros_ue_B.Derivative_d = sin(controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Derivative_j = cos(controller_ros_ue_B.In1_l.Y);
    controller_ros_ue_B.R[0] = controller_ros_ue_B.Derivative_j *
      controller_ros_ue_B.rtb_p_bar_tmp;
    controller_ros_ue_B.R[1] = controller_ros_ue_B.rtb_q_bar_tmp_m *
      controller_ros_ue_B.rtb_q_bar_tmp_g * controller_ros_ue_B.rtb_p_bar_tmp -
      controller_ros_ue_B.rtb_q_bar_tmp * controller_ros_ue_B.Derivative_d;
    controller_ros_ue_B.R[2] = controller_ros_ue_B.rtb_q_bar_tmp *
      controller_ros_ue_B.rtb_q_bar_tmp_g * controller_ros_ue_B.rtb_p_bar_tmp +
      controller_ros_ue_B.rtb_q_bar_tmp_m * controller_ros_ue_B.Derivative_d;
    controller_ros_ue_B.R[3] = controller_ros_ue_B.Derivative_j *
      controller_ros_ue_B.Derivative_d;
    controller_ros_ue_B.R[4] = sin(controller_ros_ue_B.In1_l.X) * sin
      (controller_ros_ue_B.In1_l.Y) * controller_ros_ue_B.Derivative_d +
      controller_ros_ue_B.rtb_q_bar_tmp * controller_ros_ue_B.rtb_p_bar_tmp;
    controller_ros_ue_B.R[5] = cos(controller_ros_ue_B.In1_l.X) * sin
      (controller_ros_ue_B.In1_l.Y) * controller_ros_ue_B.Derivative_d -
      controller_ros_ue_B.rtb_q_bar_tmp_m * controller_ros_ue_B.rtb_p_bar_tmp;
    controller_ros_ue_B.R[6] = -controller_ros_ue_B.rtb_q_bar_tmp_g;
    controller_ros_ue_B.R[7] = controller_ros_ue_B.rtb_q_bar_tmp_m *
      controller_ros_ue_B.Derivative_j;
    controller_ros_ue_B.R[8] = controller_ros_ue_B.rtb_q_bar_tmp *
      controller_ros_ue_B.Derivative_j;

    // '<S36>:1:8'
    controller_ros_ue_B.rtb_p_bar_tmp = cos(controller_ros_ue_B.In1_n.Y) * cos
      (controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[0] = controller_ros_ue_B.rtb_p_bar_tmp;
    controller_ros_ue_B.rtb_q_bar_tmp = sin(controller_ros_ue_B.In1_n.X) * sin
      (controller_ros_ue_B.In1_n.Y) * cos(controller_ros_ue_B.In1_n.Z) - cos
      (controller_ros_ue_B.In1_n.X) * sin(controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[3] = controller_ros_ue_B.rtb_q_bar_tmp;
    controller_ros_ue_B.rtb_q_bar_tmp_g = cos(controller_ros_ue_B.In1_n.X) * sin
      (controller_ros_ue_B.In1_n.Y) * cos(controller_ros_ue_B.In1_n.Z) + sin
      (controller_ros_ue_B.In1_n.X) * sin(controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[6] = controller_ros_ue_B.rtb_q_bar_tmp_g;
    controller_ros_ue_B.rtb_q_bar_tmp_m = cos(controller_ros_ue_B.In1_n.Y) * sin
      (controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[1] = controller_ros_ue_B.rtb_q_bar_tmp_m;
    controller_ros_ue_B.Derivative_d = sin(controller_ros_ue_B.In1_n.X) * sin
      (controller_ros_ue_B.In1_n.Y) * sin(controller_ros_ue_B.In1_n.Z) + cos
      (controller_ros_ue_B.In1_n.X) * cos(controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[4] = controller_ros_ue_B.Derivative_d;
    controller_ros_ue_B.Derivative_j = cos(controller_ros_ue_B.In1_n.X) * sin
      (controller_ros_ue_B.In1_n.Y) * sin(controller_ros_ue_B.In1_n.Z) - sin
      (controller_ros_ue_B.In1_n.X) * cos(controller_ros_ue_B.In1_n.Z);
    controller_ros_ue_B.Rd[7] = controller_ros_ue_B.Derivative_j;
    controller_ros_ue_B.Rd[2] = -sin(controller_ros_ue_B.In1_n.Y);
    controller_ros_ue_B.Derivative_n = sin(controller_ros_ue_B.In1_n.X) * cos
      (controller_ros_ue_B.In1_n.Y);
    controller_ros_ue_B.Rd[5] = controller_ros_ue_B.Derivative_n;
    controller_ros_ue_B.vd_tmp = cos(controller_ros_ue_B.In1_n.X) * cos
      (controller_ros_ue_B.In1_n.Y);
    controller_ros_ue_B.Rd[8] = controller_ros_ue_B.vd_tmp;

    // '<S36>:1:12'
    // '<S36>:1:13'
    // '<S36>:1:14'
    // '<S36>:1:16'
    controller_ros_ue_B.Rd_k[0] = 0.0;
    controller_ros_ue_B.Rd_k[3] = -controller_ros_ue_P.tool_z_Value;
    controller_ros_ue_B.Rd_k[6] = controller_ros_ue_P.tool_y_Value;
    controller_ros_ue_B.Rd_k[1] = controller_ros_ue_P.tool_z_Value;
    controller_ros_ue_B.Rd_k[4] = 0.0;
    controller_ros_ue_B.Rd_k[7] = -controller_ros_ue_P.tool_x_Value;
    controller_ros_ue_B.Rd_k[2] = -controller_ros_ue_P.tool_y_Value;
    controller_ros_ue_B.Rd_k[5] = controller_ros_ue_P.tool_x_Value;
    controller_ros_ue_B.Rd_k[8] = 0.0;
    controller_ros_ue_B.rtb_p_bar_b[0] = controller_ros_ue_B.Derivative_gu;
    controller_ros_ue_B.rtb_p_bar_b[1] = controller_ros_ue_B.q_bar;
    controller_ros_ue_B.rtb_p_bar_b[2] = controller_ros_ue_B.Derivative_iw;
    controller_ros_ue_B.grad[0] = controller_ros_ue_B.vd[0];
    controller_ros_ue_B.grad[1] = controller_ros_ue_B.vd[1];
    controller_ros_ue_B.grad[2] = controller_ros_ue_B.vd[2];
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i;
        controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] = 0.0;
        controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp] *
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i];
        controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp + 1] *
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3];
        controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp + 2] *
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6];
      }

      controller_ros_ue_B.position_error[controller_ros_ue_B.i] = 0.0;
      controller_ros_ue_B.vd[controller_ros_ue_B.i] = 0.0;
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i;
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] = 0.0;
        controller_ros_ue_B.lastTime = controller_ros_ue_B.Rd[3 *
          controller_ros_ue_B.B_tmp];
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.lastTime *
          controller_ros_ue_B.dv[controller_ros_ue_B.i];
        controller_ros_ue_B.rtb_ex_idx_1 = controller_ros_ue_B.Rd[3 *
          controller_ros_ue_B.B_tmp + 1];
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.dv[controller_ros_ue_B.i + 3] *
          controller_ros_ue_B.rtb_ex_idx_1;
        controller_ros_ue_B.rtb_ex_idx_2 = controller_ros_ue_B.Rd[3 *
          controller_ros_ue_B.B_tmp + 2];
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.dv[controller_ros_ue_B.i + 6] *
          controller_ros_ue_B.rtb_ex_idx_2;
        controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp] = 0.0;
        controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.lastTime *
          controller_ros_ue_B.R[controller_ros_ue_B.i];
        controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.R[controller_ros_ue_B.i + 3] *
          controller_ros_ue_B.rtb_ex_idx_1;
        controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.R[controller_ros_ue_B.i + 6] *
          controller_ros_ue_B.rtb_ex_idx_2;
        controller_ros_ue_B.position_error[controller_ros_ue_B.i] +=
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] *
          controller_ros_ue_B.rtb_p_bar_b[controller_ros_ue_B.B_tmp];
        controller_ros_ue_B.vd[controller_ros_ue_B.i] +=
          controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp] *
          controller_ros_ue_B.grad[controller_ros_ue_B.B_tmp];
      }

      controller_ros_ue_B.epsilon_d_v[controller_ros_ue_B.i] =
        controller_ros_ue_B.position_error[controller_ros_ue_B.i] +
        controller_ros_ue_B.vd[controller_ros_ue_B.i];
    }

    // '<S36>:1:18'
    // '<S36>:1:19'
    // '<S36>:1:20'
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
      // MATLABSystem: '<S18>/SourceBlock'
      b_varargout_1 = Sub_controller_ros_ue_229.getLatestMessage
        (&controller_ros_ue_B.b_varargout_2);

      // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S96>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S96>/In1'
        controller_ros_ue_B.In1_h = controller_ros_ue_B.b_varargout_2;
      }

      // End of MATLABSystem: '<S18>/SourceBlock'
      // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<Root>/Subscribe2'

      // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
      // MATLABSystem: '<S19>/SourceBlock'
      b_varargout_1 = Sub_controller_ros_ue_232.getLatestMessage
        (&controller_ros_ue_B.b_varargout_2);

      // Outputs for Enabled SubSystem: '<S19>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S97>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S97>/In1'
        controller_ros_ue_B.In1 = controller_ros_ue_B.b_varargout_2;
      }

      // End of MATLABSystem: '<S19>/SourceBlock'
      // End of Outputs for SubSystem: '<S19>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<Root>/Subscribe3'

      // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
      // MATLABSystem: '<S20>/SourceBlock'
      b_varargout_1 = Sub_controller_ros_ue_235.getLatestMessage
        (&controller_ros_ue_B.b_varargout_2_c);

      // Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S98>/Enable'

      if (b_varargout_1) {
        // SignalConversion generated from: '<S98>/In1'
        controller_ros_ue_B.In1_k = controller_ros_ue_B.b_varargout_2_c;
      }

      // End of MATLABSystem: '<S20>/SourceBlock'
      // End of Outputs for SubSystem: '<S20>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<Root>/Subscribe4'

      // Sum: '<S8>/Sum'
      controller_ros_ue_B.ex[0] = controller_ros_ue_B.In1.X -
        controller_ros_ue_B.In1_k.X;
      controller_ros_ue_B.ex[1] = controller_ros_ue_B.In1.Y -
        controller_ros_ue_B.In1_k.Y;
      controller_ros_ue_B.ex[2] = controller_ros_ue_B.In1.Z -
        controller_ros_ue_B.In1_k.Z;

      // MATLAB Function: '<S31>/MATLAB Function1' incorporates:
      //   Constant: '<S31>/kp_x'
      //   Constant: '<S31>/kp_y'
      //   Constant: '<S31>/kp_z'

      // MATLAB Function 'Controller/calc_grad/MATLAB Function1': '<S90>:1'
      // '<S90>:1:3'
      // '<S90>:1:8'
      // '<S90>:1:10'
      // '<S90>:1:12'
      controller_ros_ue_B.lastTime = controller_ros_ue_B.ex[0];
      controller_ros_ue_B.rtb_ex_idx_1 = controller_ros_ue_B.ex[1];
      controller_ros_ue_B.rtb_ex_idx_2 = controller_ros_ue_B.ex[2];
      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        controller_ros_ue_B.position_error[controller_ros_ue_B.i] =
          (controller_ros_ue_B.R[controller_ros_ue_B.i + 3] *
           controller_ros_ue_B.rtb_ex_idx_1 +
           controller_ros_ue_B.R[controller_ros_ue_B.i] *
           controller_ros_ue_B.lastTime) +
          controller_ros_ue_B.R[controller_ros_ue_B.i + 6] *
          controller_ros_ue_B.rtb_ex_idx_2;
      }

      // '<S90>:1:14'
      controller_ros_ue_B.Rd_k[0] = controller_ros_ue_P.kp_x_Value;
      controller_ros_ue_B.Rd_k[3] = 0.0;
      controller_ros_ue_B.Rd_k[6] = 0.0;
      controller_ros_ue_B.Rd_k[1] = 0.0;
      controller_ros_ue_B.Rd_k[4] = controller_ros_ue_P.kp_y_Value;
      controller_ros_ue_B.Rd_k[7] = 0.0;
      controller_ros_ue_B.Rd_k[2] = 0.0;
      controller_ros_ue_B.Rd_k[5] = 0.0;
      controller_ros_ue_B.Rd_k[8] = controller_ros_ue_P.kp_z_Value;
      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        controller_ros_ue_B.grad[controller_ros_ue_B.i] =
          (controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3] *
           controller_ros_ue_B.position_error[1] +
           controller_ros_ue_B.Rd_k[controller_ros_ue_B.i] *
           controller_ros_ue_B.position_error[0]) +
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6] *
          controller_ros_ue_B.position_error[2];
      }

      // '<S90>:1:16'
      controller_ros_ue_B.grad1_n = controller_ros_ue_B.grad[0];

      // '<S90>:1:17'
      controller_ros_ue_B.grad2_e = controller_ros_ue_B.grad[1];

      // '<S90>:1:18'
      controller_ros_ue_B.grad3_l = controller_ros_ue_B.grad[2];

      // '<S90>:1:20'
      controller_ros_ue_B.x_error = controller_ros_ue_B.position_error[0];

      // '<S90>:1:21'
      controller_ros_ue_B.y_error = controller_ros_ue_B.position_error[1];

      // '<S90>:1:22'
      controller_ros_ue_B.z_error = controller_ros_ue_B.position_error[2];

      // Sum: '<S23>/Add' incorporates:
      //   Constant: '<S23>/center_mass'
      //   Constant: '<S23>/drone1_mass'
      //   Constant: '<S23>/drone2_mass'
      //   Constant: '<S23>/drone3_mass'

      controller_ros_ue_B.Add = ((controller_ros_ue_P.center_mass_Value +
        controller_ros_ue_P.drone1_mass_Value) +
        controller_ros_ue_P.drone2_mass_Value) +
        controller_ros_ue_P.drone3_mass_Value;
    }

    // MATLAB Function: '<S28>/MATLAB Function' incorporates:
    //   Constant: '<S28>/kd_x'
    //   Constant: '<S28>/kd_y'
    //   Constant: '<S28>/kd_z'
    //   Constant: '<S28>/ki_x'
    //   Constant: '<S28>/ki_y'
    //   Constant: '<S28>/ki_z'
    //   Integrator: '<S33>/Integrator'
    //   Integrator: '<S33>/Integrator1'
    //   Integrator: '<S33>/Integrator2'
    //   MATLAB Function: '<S30>/MATLAB Function'
    //   Sum: '<S8>/Sum1'

    // MATLAB Function 'Controller/calc_Thrusts/MATLAB Function': '<S32>:1'
    // '<S32>:1:20'
    // '<S32>:1:3'
    // '<S32>:1:5'
    // '<S32>:1:10'
    // '<S32>:1:11'
    // '<S32>:1:12'
    // '<S32>:1:13'
    // '<S32>:1:14'
    // '<S32>:1:15'
    // '<S32>:1:17'
    // '<S32>:1:18'
    // '<S32>:1:20'
    controller_ros_ue_B.lastTime = -controller_ros_ue_B.Add * 9.8;

    // '<S32>:1:22'
    controller_ros_ue_B.a[0] = controller_ros_ue_B.Add *
      controller_ros_ue_B.In1_f.X;
    controller_ros_ue_B.a[1] = controller_ros_ue_B.Add *
      controller_ros_ue_B.In1_f.Y;
    controller_ros_ue_B.a[2] = controller_ros_ue_B.Add *
      controller_ros_ue_B.In1_f.Z;
    controller_ros_ue_B.position_error[0] = controller_ros_ue_B.Add *
      controller_ros_ue_B.Derivative;
    controller_ros_ue_B.position_error[1] = controller_ros_ue_B.Add *
      controller_ros_ue_B.Derivative_i;
    controller_ros_ue_B.position_error[2] = controller_ros_ue_B.Add *
      controller_ros_ue_B.Derivative_g;
    controller_ros_ue_B.rtb_p_bar_b[0] = controller_ros_ue_B.a[1] *
      controller_ros_ue_B.epsilon_d_v[2] - controller_ros_ue_B.epsilon_d_v[1] *
      controller_ros_ue_B.a[2];
    controller_ros_ue_B.rtb_p_bar_b[1] = controller_ros_ue_B.epsilon_d_v[0] *
      controller_ros_ue_B.a[2] - controller_ros_ue_B.a[0] *
      controller_ros_ue_B.epsilon_d_v[2];
    controller_ros_ue_B.rtb_p_bar_b[2] = controller_ros_ue_B.a[0] *
      controller_ros_ue_B.epsilon_d_v[1] - controller_ros_ue_B.epsilon_d_v[0] *
      controller_ros_ue_B.a[1];
    controller_ros_ue_B.Rd_k[0] = controller_ros_ue_P.kd_x_Value;
    controller_ros_ue_B.Rd_k[3] = 0.0;
    controller_ros_ue_B.Rd_k[6] = 0.0;
    controller_ros_ue_B.Rd_k[1] = 0.0;
    controller_ros_ue_B.Rd_k[4] = controller_ros_ue_P.kd_y_Value;
    controller_ros_ue_B.Rd_k[7] = 0.0;
    controller_ros_ue_B.Rd_k[2] = 0.0;
    controller_ros_ue_B.Rd_k[5] = 0.0;
    controller_ros_ue_B.Rd_k[8] = controller_ros_ue_P.kd_z_Value;
    controller_ros_ue_B.Derivative = controller_ros_ue_B.In1_h.X -
      controller_ros_ue_B.epsilon_d_v[0];
    controller_ros_ue_B.Derivative_i = controller_ros_ue_B.In1_h.Y -
      controller_ros_ue_B.epsilon_d_v[1];
    controller_ros_ue_B.Derivative_g = controller_ros_ue_B.In1_h.Z -
      controller_ros_ue_B.epsilon_d_v[2];
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.vd[controller_ros_ue_B.i] =
        (controller_ros_ue_B.position_error[controller_ros_ue_B.i] +
         controller_ros_ue_B.rtb_p_bar_b[controller_ros_ue_B.i]) -
        ((controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3] *
          controller_ros_ue_B.Derivative_i +
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i] *
          controller_ros_ue_B.Derivative) +
         controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6] *
         controller_ros_ue_B.Derivative_g);
    }

    controller_ros_ue_B.position_error[0] = controller_ros_ue_B.grad1_n;
    controller_ros_ue_B.position_error[1] = controller_ros_ue_B.grad2_e;
    controller_ros_ue_B.position_error[2] = controller_ros_ue_B.grad3_l;
    controller_ros_ue_B.Rd_k[0] = controller_ros_ue_P.ki_x_Value;
    controller_ros_ue_B.Rd_k[3] = 0.0;
    controller_ros_ue_B.Rd_k[6] = 0.0;
    controller_ros_ue_B.Rd_k[1] = 0.0;
    controller_ros_ue_B.Rd_k[4] = controller_ros_ue_P.ki_y_Value;
    controller_ros_ue_B.Rd_k[7] = 0.0;
    controller_ros_ue_B.Rd_k[2] = 0.0;
    controller_ros_ue_B.Rd_k[5] = 0.0;
    controller_ros_ue_B.Rd_k[8] = controller_ros_ue_P.ki_z_Value;
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.grad[controller_ros_ue_B.i] =
        ((controller_ros_ue_B.vd[controller_ros_ue_B.i] -
          controller_ros_ue_B.position_error[controller_ros_ue_B.i]) -
         ((controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3] *
           controller_ros_ue_X.Integrator1_CSTATE +
           controller_ros_ue_B.Rd_k[controller_ros_ue_B.i] *
           controller_ros_ue_X.Integrator_CSTATE_eh) +
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6] *
          controller_ros_ue_X.Integrator2_CSTATE)) +
        ((controller_ros_ue_B.R[controller_ros_ue_B.i + 3] *
          controller_ros_ue_B.lastTime * 0.0 + controller_ros_ue_B.lastTime *
          controller_ros_ue_B.R[controller_ros_ue_B.i] * 0.0) +
         controller_ros_ue_B.R[controller_ros_ue_B.i + 6] *
         controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S40>/Integrator'
    // '<S32>:1:24'
    // '<S32>:1:25'
    // '<S32>:1:26'
    controller_ros_ue_B.Integrator_aj = controller_ros_ue_X.Integrator_CSTATE_cv;

    // Derivative: '<S40>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_fq >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_m >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_fq;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_et;
      if (controller_ros_ue_DW.TimeStampA_fq < controller_ros_ue_DW.TimeStampB_m)
      {
        if (controller_ros_ue_DW.TimeStampB_m < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_m;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_ba;
        }
      } else if (controller_ros_ue_DW.TimeStampA_fq >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_m;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_ba;
      }

      controller_ros_ue_B.Derivative = (controller_ros_ue_B.Integrator_aj -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S41>/Integrator'
    controller_ros_ue_B.Integrator_jm = controller_ros_ue_X.Integrator_CSTATE_b;

    // Derivative: '<S41>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_a >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_gd >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_i = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_a;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_p;
      if (controller_ros_ue_DW.TimeStampA_a < controller_ros_ue_DW.TimeStampB_gd)
      {
        if (controller_ros_ue_DW.TimeStampB_gd < controller_ros_ue_B.rtb_y_h_g)
        {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_gd;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_d;
        }
      } else if (controller_ros_ue_DW.TimeStampA_a >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_gd;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_d;
      }

      controller_ros_ue_B.Derivative_i = (controller_ros_ue_B.Integrator_jm -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // Integrator: '<S42>/Integrator'
    controller_ros_ue_B.Integrator_h = controller_ros_ue_X.Integrator_CSTATE_o;

    // Derivative: '<S42>/Derivative'
    if ((controller_ros_ue_DW.TimeStampA_l >= controller_ros_ue_B.rtb_y_h_g) &&
        (controller_ros_ue_DW.TimeStampB_p >= controller_ros_ue_B.rtb_y_h_g)) {
      controller_ros_ue_B.Derivative_g = 0.0;
    } else {
      controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampA_l;
      lastU = &controller_ros_ue_DW.LastUAtTimeA_g;
      if (controller_ros_ue_DW.TimeStampA_l < controller_ros_ue_DW.TimeStampB_p)
      {
        if (controller_ros_ue_DW.TimeStampB_p < controller_ros_ue_B.rtb_y_h_g) {
          controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_p;
          lastU = &controller_ros_ue_DW.LastUAtTimeB_lt;
        }
      } else if (controller_ros_ue_DW.TimeStampA_l >=
                 controller_ros_ue_B.rtb_y_h_g) {
        controller_ros_ue_B.lastTime = controller_ros_ue_DW.TimeStampB_p;
        lastU = &controller_ros_ue_DW.LastUAtTimeB_lt;
      }

      controller_ros_ue_B.Derivative_g = (controller_ros_ue_B.Integrator_h -
        *lastU) / (controller_ros_ue_B.rtb_y_h_g - controller_ros_ue_B.lastTime);
    }

    // MATLAB Function: '<S30>/MATLAB Function1' incorporates:
    //   MATLAB Function: '<S31>/MATLAB Function2'

    // MATLAB Function 'Controller/calc_epsilon_d/MATLAB Function1': '<S37>:1'
    // '<S37>:1:3'
    // '<S37>:1:8'
    // '<S37>:1:12'
    // '<S37>:1:14'
    controller_ros_ue_B.rtb_y_h_g = cos(controller_ros_ue_B.In1_l.Y) * cos
      (controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Rd_k[0] = controller_ros_ue_B.rtb_y_h_g;
    controller_ros_ue_B.lastTime = sin(controller_ros_ue_B.In1_l.X) * sin
      (controller_ros_ue_B.In1_l.Y) * cos(controller_ros_ue_B.In1_l.Z) - cos
      (controller_ros_ue_B.In1_l.X) * sin(controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Rd_k[1] = controller_ros_ue_B.lastTime;
    controller_ros_ue_B.rtb_ex_idx_1 = cos(controller_ros_ue_B.In1_l.X) * sin
      (controller_ros_ue_B.In1_l.Y) * cos(controller_ros_ue_B.In1_l.Z) + sin
      (controller_ros_ue_B.In1_l.X) * sin(controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Rd_k[2] = controller_ros_ue_B.rtb_ex_idx_1;
    controller_ros_ue_B.rtb_ex_idx_2 = cos(controller_ros_ue_B.In1_l.Y) * sin
      (controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Rd_k[3] = controller_ros_ue_B.rtb_ex_idx_2;
    controller_ros_ue_B.d = sin(controller_ros_ue_B.In1_l.X) * sin
      (controller_ros_ue_B.In1_l.Y) * sin(controller_ros_ue_B.In1_l.Z) + cos
      (controller_ros_ue_B.In1_l.X) * cos(controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Rd_k[4] = controller_ros_ue_B.d;
    controller_ros_ue_B.d1 = cos(controller_ros_ue_B.In1_l.X) * sin
      (controller_ros_ue_B.In1_l.Y) * sin(controller_ros_ue_B.In1_l.Z) - sin
      (controller_ros_ue_B.In1_l.X) * cos(controller_ros_ue_B.In1_l.Z);
    controller_ros_ue_B.Rd_k[5] = controller_ros_ue_B.d1;
    controller_ros_ue_B.Rd_k[6] = -sin(controller_ros_ue_B.In1_l.Y);
    controller_ros_ue_B.d2 = sin(controller_ros_ue_B.In1_l.X) * cos
      (controller_ros_ue_B.In1_l.Y);
    controller_ros_ue_B.Rd_k[7] = controller_ros_ue_B.d2;
    controller_ros_ue_B.d3 = cos(controller_ros_ue_B.In1_l.X) * cos
      (controller_ros_ue_B.In1_l.Y);
    controller_ros_ue_B.Rd_k[8] = controller_ros_ue_B.d3;
    controller_ros_ue_B.dv[0] = controller_ros_ue_B.rtb_p_bar_tmp;
    controller_ros_ue_B.dv[3] = controller_ros_ue_B.rtb_q_bar_tmp;
    controller_ros_ue_B.dv[6] = controller_ros_ue_B.rtb_q_bar_tmp_g;
    controller_ros_ue_B.dv[1] = controller_ros_ue_B.rtb_q_bar_tmp_m;
    controller_ros_ue_B.dv[4] = controller_ros_ue_B.Derivative_d;
    controller_ros_ue_B.dv[7] = controller_ros_ue_B.Derivative_j;
    controller_ros_ue_B.dv[2] = -sin(controller_ros_ue_B.In1_n.Y);
    controller_ros_ue_B.dv[5] = controller_ros_ue_B.Derivative_n;
    controller_ros_ue_B.dv[8] = controller_ros_ue_B.vd_tmp;
    controller_ros_ue_B.rtb_p_bar_b[0] = controller_ros_ue_B.Derivative_gu;
    controller_ros_ue_B.rtb_p_bar_b[1] = controller_ros_ue_B.q_bar;
    controller_ros_ue_B.rtb_p_bar_b[2] = controller_ros_ue_B.Derivative_iw;
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.vd[controller_ros_ue_B.i] = 0.0;
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i;
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] = 0.0;
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.dv[3 * controller_ros_ue_B.B_tmp] *
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i];
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.dv[3 * controller_ros_ue_B.B_tmp + 1] *
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3];
        controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
          controller_ros_ue_B.dv[3 * controller_ros_ue_B.B_tmp + 2] *
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6];
        controller_ros_ue_B.vd[controller_ros_ue_B.i] +=
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] *
          controller_ros_ue_B.rtb_p_bar_b[controller_ros_ue_B.B_tmp];
      }
    }

    // Sum: '<S8>/Sum2' incorporates:
    //   MATLAB Function: '<S30>/MATLAB Function1'

    // '<S37>:1:16'
    // '<S37>:1:17'
    // '<S37>:1:18'
    controller_ros_ue_B.Derivative_gu = controller_ros_ue_B.In1_f.X -
      controller_ros_ue_B.vd[0];
    controller_ros_ue_B.q_bar = controller_ros_ue_B.In1_f.Y -
      controller_ros_ue_B.vd[1];
    controller_ros_ue_B.Derivative_iw = controller_ros_ue_B.In1_f.Z -
      controller_ros_ue_B.vd[2];
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S31>/MATLAB Function2' incorporates:
      //   Constant: '<S22>/tool_x'
      //   Constant: '<S22>/tool_y'
      //   Constant: '<S22>/tool_z'
      //   Constant: '<S31>/kp_phi'
      //   Constant: '<S31>/kp_psi'
      //   Constant: '<S31>/kp_theta'
      //   Constant: '<S31>/kp_x'
      //   Constant: '<S31>/kp_y'
      //   Constant: '<S31>/kp_z'

      // MATLAB Function 'Controller/calc_grad/MATLAB Function2': '<S91>:1'
      // '<S91>:1:3'
      controller_ros_ue_B.R[0] = controller_ros_ue_B.rtb_y_h_g;
      controller_ros_ue_B.R[3] = controller_ros_ue_B.lastTime;
      controller_ros_ue_B.R[6] = controller_ros_ue_B.rtb_ex_idx_1;
      controller_ros_ue_B.R[1] = controller_ros_ue_B.rtb_ex_idx_2;
      controller_ros_ue_B.R[4] = controller_ros_ue_B.d;
      controller_ros_ue_B.R[7] = controller_ros_ue_B.d1;
      controller_ros_ue_B.R[2] = -sin(controller_ros_ue_B.In1_l.Y);
      controller_ros_ue_B.R[5] = controller_ros_ue_B.d2;
      controller_ros_ue_B.R[8] = controller_ros_ue_B.d3;

      // '<S91>:1:6'
      // '<S91>:1:8'
      // '<S91>:1:13'
      // '<S91>:1:14'
      // '<S91>:1:15'
      // '<S91>:1:16'
      // '<S91>:1:18'
      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
             controller_ros_ue_B.B_tmp++) {
          controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
            controller_ros_ue_B.i;
          controller_ros_ue_B.Rt[controller_ros_ue_B.B_tmp + 3 *
            controller_ros_ue_B.i] =
            controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp];
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] = 0.0;
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i] *
            controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp];
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i + 1] *
            controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp + 1];
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i + 2] *
            controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp + 2];
        }
      }

      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
             controller_ros_ue_B.B_tmp++) {
          controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i +
            controller_ros_ue_B.B_tmp;
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] = 0.0;
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i] *
            controller_ros_ue_B.Rt[controller_ros_ue_B.B_tmp];
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i + 1] *
            controller_ros_ue_B.Rt[controller_ros_ue_B.B_tmp + 3];
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i + 2] *
            controller_ros_ue_B.Rt[controller_ros_ue_B.B_tmp + 6];
        }
      }

      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 9;
           controller_ros_ue_B.i++) {
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.i] =
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i] -
          controller_ros_ue_B.R[controller_ros_ue_B.i];
      }

      // '<S91>:1:19'
      // '<S91>:1:21'
      controller_ros_ue_B.Rd_k[0] = controller_ros_ue_P.kp_phi_Value;
      controller_ros_ue_B.Rd_k[3] = 0.0;
      controller_ros_ue_B.Rd_k[6] = 0.0;
      controller_ros_ue_B.Rd_k[1] = 0.0;
      controller_ros_ue_B.Rd_k[4] = controller_ros_ue_P.kp_theta_Value;
      controller_ros_ue_B.Rd_k[7] = 0.0;
      controller_ros_ue_B.Rd_k[2] = 0.0;
      controller_ros_ue_B.Rd_k[5] = 0.0;
      controller_ros_ue_B.Rd_k[8] = controller_ros_ue_P.kp_psi_Value;

      // '<S91>:1:22'
      // '<S91>:1:24'
      controller_ros_ue_B.dv[0] = controller_ros_ue_P.kp_x_Value;
      controller_ros_ue_B.dv[3] = 0.0;
      controller_ros_ue_B.dv[6] = 0.0;
      controller_ros_ue_B.dv[1] = 0.0;
      controller_ros_ue_B.dv[4] = controller_ros_ue_P.kp_y_Value;
      controller_ros_ue_B.dv[7] = 0.0;
      controller_ros_ue_B.dv[2] = 0.0;
      controller_ros_ue_B.dv[5] = 0.0;
      controller_ros_ue_B.dv[8] = controller_ros_ue_P.kp_z_Value;
      controller_ros_ue_B.a[0] = controller_ros_ue_B.ex[0];
      controller_ros_ue_B.a[1] = controller_ros_ue_B.ex[1];
      controller_ros_ue_B.a[2] = controller_ros_ue_B.ex[2];
      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        controller_ros_ue_B.position_error[controller_ros_ue_B.i] = 0.0;
        for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
             controller_ros_ue_B.B_tmp++) {
          controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
            controller_ros_ue_B.i;
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] = 0.0;
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] = 0.0;
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.rotation_error_c[3 * controller_ros_ue_B.B_tmp] *
            controller_ros_ue_B.Rd_k[controller_ros_ue_B.i];
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rt[3 * controller_ros_ue_B.B_tmp] *
            controller_ros_ue_B.dv[controller_ros_ue_B.i];
          controller_ros_ue_B.R_tmp = 3 * controller_ros_ue_B.B_tmp + 1;
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3] *
            controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.R_tmp];
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.dv[controller_ros_ue_B.i + 3] *
            controller_ros_ue_B.Rt[controller_ros_ue_B.R_tmp];
          controller_ros_ue_B.R_tmp = 3 * controller_ros_ue_B.B_tmp + 2;
          controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6] *
            controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.R_tmp];
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.dv[controller_ros_ue_B.i + 6] *
            controller_ros_ue_B.Rt[controller_ros_ue_B.R_tmp];
          controller_ros_ue_B.position_error[controller_ros_ue_B.i] +=
            controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] *
            controller_ros_ue_B.a[controller_ros_ue_B.B_tmp];
        }
      }

      // '<S91>:1:26'
      controller_ros_ue_B.grad1 = -(controller_ros_ue_P.tool_y_Value *
        controller_ros_ue_B.position_error[2] -
        controller_ros_ue_B.position_error[1] * controller_ros_ue_P.tool_z_Value)
        + controller_ros_ue_B.R[5];

      // '<S91>:1:27'
      controller_ros_ue_B.grad2 = -(controller_ros_ue_B.position_error[0] *
        controller_ros_ue_P.tool_z_Value - controller_ros_ue_P.tool_x_Value *
        controller_ros_ue_B.position_error[2]) + controller_ros_ue_B.R[6];

      // '<S91>:1:28'
      controller_ros_ue_B.grad3 = -(controller_ros_ue_P.tool_x_Value *
        controller_ros_ue_B.position_error[1] -
        controller_ros_ue_B.position_error[0] * controller_ros_ue_P.tool_y_Value)
        + controller_ros_ue_B.R[1];

      // '<S91>:1:30'
      controller_ros_ue_B.phi_error = controller_ros_ue_B.rotation_error_c[5];

      // '<S91>:1:31'
      controller_ros_ue_B.theta_error = controller_ros_ue_B.rotation_error_c[6];

      // '<S91>:1:32'
      controller_ros_ue_B.psi_error = controller_ros_ue_B.rotation_error_c[1];

      // MATLAB Function: '<S9>/calc_J_sys' incorporates:
      //   Constant: '<S22>/drone1_x'
      //   Constant: '<S22>/drone1_y'
      //   Constant: '<S22>/drone1_z'
      //   Constant: '<S22>/drone2_x'
      //   Constant: '<S22>/drone2_y'
      //   Constant: '<S22>/drone2_z'
      //   Constant: '<S22>/drone3_x'
      //   Constant: '<S22>/drone3_y'
      //   Constant: '<S22>/drone3_z'
      //   Constant: '<S23>/drone1_mass'
      //   Constant: '<S23>/drone2_mass'
      //   Constant: '<S23>/drone3_mass'
      //   Constant: '<S92>/Ixx'
      //   Constant: '<S92>/Iyy'
      //   Constant: '<S92>/Izz'

      // MATLAB Function 'J/calc_J_sys': '<S93>:1'
      // '<S93>:1:3'
      // '<S93>:1:5'
      controller_ros_ue_B.Rd[0] = 0.0;
      controller_ros_ue_B.Rd[3] = -controller_ros_ue_P.drone1_z_Value;
      controller_ros_ue_B.Rd[6] = controller_ros_ue_P.drone1_y_Value;
      controller_ros_ue_B.Rd[1] = controller_ros_ue_P.drone1_z_Value;
      controller_ros_ue_B.Rd[4] = 0.0;
      controller_ros_ue_B.Rd[7] = -controller_ros_ue_P.drone1_x_Value;
      controller_ros_ue_B.Rd[2] = -controller_ros_ue_P.drone1_y_Value;
      controller_ros_ue_B.Rd[5] = controller_ros_ue_P.drone1_x_Value;
      controller_ros_ue_B.Rd[8] = 0.0;

      // '<S93>:1:6'
      controller_ros_ue_B.R[0] = 0.0;
      controller_ros_ue_B.R[3] = -controller_ros_ue_P.drone2_z_Value;
      controller_ros_ue_B.R[6] = controller_ros_ue_P.drone2_y_Value;
      controller_ros_ue_B.R[1] = controller_ros_ue_P.drone2_z_Value;
      controller_ros_ue_B.R[4] = 0.0;
      controller_ros_ue_B.R[7] = -controller_ros_ue_P.drone2_x_Value;
      controller_ros_ue_B.R[2] = -controller_ros_ue_P.drone2_y_Value;
      controller_ros_ue_B.R[5] = controller_ros_ue_P.drone2_x_Value;
      controller_ros_ue_B.R[8] = 0.0;

      // '<S93>:1:7'
      controller_ros_ue_B.Rt[0] = 0.0;
      controller_ros_ue_B.Rt[3] = -controller_ros_ue_P.drone3_z_Value;
      controller_ros_ue_B.Rt[6] = controller_ros_ue_P.drone3_y_Value;
      controller_ros_ue_B.Rt[1] = controller_ros_ue_P.drone3_z_Value;
      controller_ros_ue_B.Rt[4] = 0.0;
      controller_ros_ue_B.Rt[7] = -controller_ros_ue_P.drone3_x_Value;
      controller_ros_ue_B.Rt[2] = -controller_ros_ue_P.drone3_y_Value;
      controller_ros_ue_B.Rt[5] = controller_ros_ue_P.drone3_x_Value;
      controller_ros_ue_B.Rt[8] = 0.0;

      // '<S93>:1:9'
      controller_ros_ue_B.Rd_k[0] = controller_ros_ue_P.Ixx_Value;
      controller_ros_ue_B.Rd_k[3] = 0.0;
      controller_ros_ue_B.Rd_k[6] = 0.0;
      controller_ros_ue_B.Rd_k[1] = 0.0;
      controller_ros_ue_B.Rd_k[4] = controller_ros_ue_P.Iyy_Value;
      controller_ros_ue_B.Rd_k[7] = 0.0;
      controller_ros_ue_B.Rd_k[2] = 0.0;
      controller_ros_ue_B.Rd_k[5] = 0.0;
      controller_ros_ue_B.Rd_k[8] = controller_ros_ue_P.Izz_Value;
      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
             controller_ros_ue_B.B_tmp++) {
          controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
            controller_ros_ue_B.i;
          controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] = 0.0;
          controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_P.drone1_mass_Value *
            controller_ros_ue_B.Rd[controller_ros_ue_B.i] *
            controller_ros_ue_B.Rd[3 * controller_ros_ue_B.B_tmp];
          controller_ros_ue_B.R_tmp = 3 * controller_ros_ue_B.B_tmp + 1;
          controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[controller_ros_ue_B.i + 3] *
            controller_ros_ue_P.drone1_mass_Value *
            controller_ros_ue_B.Rd[controller_ros_ue_B.R_tmp];
          controller_ros_ue_B.i1 = 3 * controller_ros_ue_B.B_tmp + 2;
          controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rd[controller_ros_ue_B.i + 6] *
            controller_ros_ue_P.drone1_mass_Value *
            controller_ros_ue_B.Rd[controller_ros_ue_B.i1];
          controller_ros_ue_B.dv1[controller_ros_ue_B.Rt_tmp] =
            (controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] -
             controller_ros_ue_B.dv[controller_ros_ue_B.Rt_tmp]) -
            ((controller_ros_ue_B.R[controller_ros_ue_B.i + 3] *
              controller_ros_ue_P.drone2_mass_Value *
              controller_ros_ue_B.R[controller_ros_ue_B.R_tmp] +
              controller_ros_ue_P.drone2_mass_Value *
              controller_ros_ue_B.R[controller_ros_ue_B.i] *
              controller_ros_ue_B.R[3 * controller_ros_ue_B.B_tmp]) +
             controller_ros_ue_B.R[controller_ros_ue_B.i + 6] *
             controller_ros_ue_P.drone2_mass_Value *
             controller_ros_ue_B.R[controller_ros_ue_B.i1]);
        }
      }

      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
           controller_ros_ue_B.i++) {
        for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 3;
             controller_ros_ue_B.B_tmp++) {
          controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.B_tmp +
            controller_ros_ue_B.i;
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] = 0.0;
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_P.drone3_mass_Value *
            controller_ros_ue_B.Rt[controller_ros_ue_B.i] *
            controller_ros_ue_B.Rt[3 * controller_ros_ue_B.B_tmp];
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rt[controller_ros_ue_B.i + 3] *
            controller_ros_ue_P.drone3_mass_Value * controller_ros_ue_B.Rt[3 *
            controller_ros_ue_B.B_tmp + 1];
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.Rt_tmp] +=
            controller_ros_ue_B.Rt[controller_ros_ue_B.i + 6] *
            controller_ros_ue_P.drone3_mass_Value * controller_ros_ue_B.Rt[3 *
            controller_ros_ue_B.B_tmp + 2];
        }
      }

      for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 9;
           controller_ros_ue_B.i++) {
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.i] =
          controller_ros_ue_B.dv1[controller_ros_ue_B.i] -
          controller_ros_ue_B.Rd_k[controller_ros_ue_B.i];
      }

      // '<S93>:1:11'
      controller_ros_ue_B.Ix_sys = controller_ros_ue_B.rotation_error_c[0];

      // '<S93>:1:12'
      controller_ros_ue_B.Iy_sys = controller_ros_ue_B.rotation_error_c[4];

      // '<S93>:1:13'
      controller_ros_ue_B.Iz_sys = controller_ros_ue_B.rotation_error_c[8];

      // End of MATLAB Function: '<S9>/calc_J_sys'
    }

    // MATLAB Function: '<S29>/MATLAB Function' incorporates:
    //   Constant: '<S29>/kd_phi'
    //   Constant: '<S29>/kd_psi'
    //   Constant: '<S29>/kd_theta'
    //   Constant: '<S29>/ki_phi'
    //   Constant: '<S29>/ki_psi'
    //   Constant: '<S29>/ki_theta'
    //   Integrator: '<S35>/Integrator'
    //   Integrator: '<S35>/Integrator1'
    //   Integrator: '<S35>/Integrator2'
    //   MATLAB Function: '<S30>/MATLAB Function1'

    // MATLAB Function 'Controller/calc_Torques/MATLAB Function': '<S34>:1'
    // '<S34>:1:3'
    controller_ros_ue_B.Rd[0] = controller_ros_ue_B.Ix_sys;
    controller_ros_ue_B.Rd[3] = 0.0;
    controller_ros_ue_B.Rd[6] = 0.0;
    controller_ros_ue_B.Rd[1] = 0.0;
    controller_ros_ue_B.Rd[4] = controller_ros_ue_B.Iy_sys;
    controller_ros_ue_B.Rd[7] = 0.0;
    controller_ros_ue_B.Rd[2] = 0.0;
    controller_ros_ue_B.Rd[5] = 0.0;
    controller_ros_ue_B.Rd[8] = controller_ros_ue_B.Iz_sys;

    // '<S34>:1:5'
    // '<S34>:1:6'
    // '<S34>:1:7'
    // '<S34>:1:8'
    // '<S34>:1:9'
    // '<S34>:1:10'
    // '<S34>:1:12'
    // '<S34>:1:13'
    // '<S34>:1:15'
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.rtb_y_h_g =
        controller_ros_ue_B.Rd[controller_ros_ue_B.i];
      controller_ros_ue_B.rtb_p_bar_tmp = controller_ros_ue_B.rtb_y_h_g *
        controller_ros_ue_B.In1_f.X;
      controller_ros_ue_B.rtb_q_bar_tmp = controller_ros_ue_B.rtb_y_h_g *
        controller_ros_ue_B.Derivative;
      controller_ros_ue_B.rtb_y_h_g =
        controller_ros_ue_B.Rd[controller_ros_ue_B.i + 3];
      controller_ros_ue_B.rtb_p_bar_tmp += controller_ros_ue_B.rtb_y_h_g *
        controller_ros_ue_B.In1_f.Y;
      controller_ros_ue_B.rtb_q_bar_tmp += controller_ros_ue_B.rtb_y_h_g *
        controller_ros_ue_B.Derivative_i;
      controller_ros_ue_B.rtb_y_h_g =
        controller_ros_ue_B.Rd[controller_ros_ue_B.i + 6];
      controller_ros_ue_B.a[controller_ros_ue_B.i] =
        controller_ros_ue_B.rtb_y_h_g * controller_ros_ue_B.In1_f.Z +
        controller_ros_ue_B.rtb_p_bar_tmp;
      controller_ros_ue_B.Rd_p[controller_ros_ue_B.i] =
        controller_ros_ue_B.rtb_y_h_g * controller_ros_ue_B.Derivative_g +
        controller_ros_ue_B.rtb_q_bar_tmp;
    }

    controller_ros_ue_B.rtb_p_bar_b[0] = controller_ros_ue_B.a[1] *
      controller_ros_ue_B.vd[2] - controller_ros_ue_B.vd[1] *
      controller_ros_ue_B.a[2];
    controller_ros_ue_B.rtb_p_bar_b[1] = controller_ros_ue_B.vd[0] *
      controller_ros_ue_B.a[2] - controller_ros_ue_B.a[0] *
      controller_ros_ue_B.vd[2];
    controller_ros_ue_B.rtb_p_bar_b[2] = controller_ros_ue_B.a[0] *
      controller_ros_ue_B.vd[1] - controller_ros_ue_B.vd[0] *
      controller_ros_ue_B.a[1];
    controller_ros_ue_B.Rd_k[0] = controller_ros_ue_P.kd_phi_Value;
    controller_ros_ue_B.Rd_k[3] = 0.0;
    controller_ros_ue_B.Rd_k[6] = 0.0;
    controller_ros_ue_B.Rd_k[1] = 0.0;
    controller_ros_ue_B.Rd_k[4] = controller_ros_ue_P.kd_theta_Value;
    controller_ros_ue_B.Rd_k[7] = 0.0;
    controller_ros_ue_B.Rd_k[2] = 0.0;
    controller_ros_ue_B.Rd_k[5] = 0.0;
    controller_ros_ue_B.Rd_k[8] = controller_ros_ue_P.kd_psi_Value;
    controller_ros_ue_B.dv[0] = controller_ros_ue_P.ki_phi_Value;
    controller_ros_ue_B.dv[3] = 0.0;
    controller_ros_ue_B.dv[6] = 0.0;
    controller_ros_ue_B.dv[1] = 0.0;
    controller_ros_ue_B.dv[4] = controller_ros_ue_P.ki_theta_Value;
    controller_ros_ue_B.dv[7] = 0.0;
    controller_ros_ue_B.dv[2] = 0.0;
    controller_ros_ue_B.dv[5] = 0.0;
    controller_ros_ue_B.dv[8] = controller_ros_ue_P.ki_psi_Value;
    controller_ros_ue_B.position_error[0] = controller_ros_ue_B.grad1;
    controller_ros_ue_B.position_error[1] = controller_ros_ue_B.grad2;
    controller_ros_ue_B.position_error[2] = controller_ros_ue_B.grad3;
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.ex[controller_ros_ue_B.i] =
        (((controller_ros_ue_B.Rd_p[controller_ros_ue_B.i] -
           controller_ros_ue_B.rtb_p_bar_b[controller_ros_ue_B.i]) -
          ((controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 3] *
            controller_ros_ue_B.q_bar +
            controller_ros_ue_B.Rd_k[controller_ros_ue_B.i] *
            controller_ros_ue_B.Derivative_gu) +
           controller_ros_ue_B.Rd_k[controller_ros_ue_B.i + 6] *
           controller_ros_ue_B.Derivative_iw)) -
         ((controller_ros_ue_B.dv[controller_ros_ue_B.i + 3] *
           controller_ros_ue_X.Integrator1_CSTATE_g +
           controller_ros_ue_B.dv[controller_ros_ue_B.i] *
           controller_ros_ue_X.Integrator_CSTATE_a) +
          controller_ros_ue_B.dv[controller_ros_ue_B.i + 6] *
          controller_ros_ue_X.Integrator2_CSTATE_a)) -
        controller_ros_ue_B.position_error[controller_ros_ue_B.i];
    }

    // MATLAB Function: '<S7>/MATLAB Function' incorporates:
    //   Constant: '<S22>/drone1_x'
    //   Constant: '<S22>/drone1_y'
    //   Constant: '<S22>/drone1_z'
    //   Constant: '<S22>/drone2_x'
    //   Constant: '<S22>/drone2_y'
    //   Constant: '<S22>/drone2_z'
    //   Constant: '<S22>/drone3_x'
    //   Constant: '<S22>/drone3_y'
    //   Constant: '<S22>/drone3_z'
    //   MATLAB Function: '<S28>/MATLAB Function'
    //   MATLAB Function: '<S29>/MATLAB Function'

    // '<S34>:1:17'
    // '<S34>:1:18'
    // '<S34>:1:19'
    // MATLAB Function 'Control Allocarion/MATLAB Function': '<S24>:1'
    // '<S24>:1:13'
    // '<S24>:1:23'
    // '<S24>:1:9'
    controller_ros_ue_B.Rd[0] = 0.0;
    controller_ros_ue_B.Rd[3] = -controller_ros_ue_P.drone1_z_Value;
    controller_ros_ue_B.Rd[6] = controller_ros_ue_P.drone1_y_Value;
    controller_ros_ue_B.Rd[1] = controller_ros_ue_P.drone1_z_Value;
    controller_ros_ue_B.Rd[4] = 0.0;
    controller_ros_ue_B.Rd[7] = -controller_ros_ue_P.drone1_x_Value;
    controller_ros_ue_B.Rd[2] = -controller_ros_ue_P.drone1_y_Value;
    controller_ros_ue_B.Rd[5] = controller_ros_ue_P.drone1_x_Value;
    controller_ros_ue_B.Rd[8] = 0.0;

    // '<S24>:1:10'
    controller_ros_ue_B.R[0] = 0.0;
    controller_ros_ue_B.R[3] = -controller_ros_ue_P.drone2_z_Value;
    controller_ros_ue_B.R[6] = controller_ros_ue_P.drone2_y_Value;
    controller_ros_ue_B.R[1] = controller_ros_ue_P.drone2_z_Value;
    controller_ros_ue_B.R[4] = 0.0;
    controller_ros_ue_B.R[7] = -controller_ros_ue_P.drone2_x_Value;
    controller_ros_ue_B.R[2] = -controller_ros_ue_P.drone2_y_Value;
    controller_ros_ue_B.R[5] = controller_ros_ue_P.drone2_x_Value;
    controller_ros_ue_B.R[8] = 0.0;

    // '<S24>:1:11'
    controller_ros_ue_B.Rt[0] = 0.0;
    controller_ros_ue_B.Rt[3] = -controller_ros_ue_P.drone3_z_Value;
    controller_ros_ue_B.Rt[6] = controller_ros_ue_P.drone3_y_Value;
    controller_ros_ue_B.Rt[1] = controller_ros_ue_P.drone3_z_Value;
    controller_ros_ue_B.Rt[4] = 0.0;
    controller_ros_ue_B.Rt[7] = -controller_ros_ue_P.drone3_x_Value;
    controller_ros_ue_B.Rt[2] = -controller_ros_ue_P.drone3_y_Value;
    controller_ros_ue_B.Rt[5] = controller_ros_ue_P.drone3_x_Value;
    controller_ros_ue_B.Rt[8] = 0.0;

    // '<S24>:1:13'
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 9;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.B[6 * controller_ros_ue_B.i] = c[3 *
        controller_ros_ue_B.i];
      controller_ros_ue_B.B[6 * controller_ros_ue_B.i + 1] = c[3 *
        controller_ros_ue_B.i + 1];
      controller_ros_ue_B.B[6 * controller_ros_ue_B.i + 2] = c[3 *
        controller_ros_ue_B.i + 2];
    }

    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.B[6 * controller_ros_ue_B.i + 3] =
        controller_ros_ue_B.Rd[3 * controller_ros_ue_B.i];
      controller_ros_ue_B.R_tmp = (controller_ros_ue_B.i + 3) * 6;
      controller_ros_ue_B.B[controller_ros_ue_B.R_tmp + 3] =
        controller_ros_ue_B.R[3 * controller_ros_ue_B.i];
      controller_ros_ue_B.B_tmp = (controller_ros_ue_B.i + 6) * 6;
      controller_ros_ue_B.B[controller_ros_ue_B.B_tmp + 3] =
        controller_ros_ue_B.Rt[3 * controller_ros_ue_B.i];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 1;
      controller_ros_ue_B.B[6 * controller_ros_ue_B.i + 4] =
        controller_ros_ue_B.Rd[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.B[controller_ros_ue_B.R_tmp + 4] =
        controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.B[controller_ros_ue_B.B_tmp + 4] =
        controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 2;
      controller_ros_ue_B.B[6 * controller_ros_ue_B.i + 5] =
        controller_ros_ue_B.Rd[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.B[controller_ros_ue_B.R_tmp + 5] =
        controller_ros_ue_B.R[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.B[controller_ros_ue_B.B_tmp + 5] =
        controller_ros_ue_B.Rt[controller_ros_ue_B.Rt_tmp];
    }

    // '<S24>:1:14'
    // '<S24>:1:21'
    // '<S24>:1:23'
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 9;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.i] =
        d[controller_ros_ue_B.i];
    }

    controller_ros_ue_B.LAMDA1_tmp[0] = controller_ros_ue_B.grad[0];
    controller_ros_ue_B.LAMDA1_tmp[1] = controller_ros_ue_B.grad[1];
    controller_ros_ue_B.LAMDA1_tmp[2] = controller_ros_ue_B.grad[2];
    controller_ros_ue_B.LAMDA1_tmp[3] = controller_ros_ue_B.ex[0];
    controller_ros_ue_B.LAMDA1_tmp[4] = controller_ros_ue_B.ex[1];
    controller_ros_ue_B.LAMDA1_tmp[5] = controller_ros_ue_B.ex[2];
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 6;
         controller_ros_ue_B.i++) {
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 6;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.R_tmp = 6 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i;
        controller_ros_ue_B.B_m[controller_ros_ue_B.R_tmp] = 0.0;
        for (controller_ros_ue_B.Rt_tmp = 0; controller_ros_ue_B.Rt_tmp < 9;
             controller_ros_ue_B.Rt_tmp++) {
          controller_ros_ue_B.B_m[controller_ros_ue_B.R_tmp] +=
            controller_ros_ue_B.B[6 * controller_ros_ue_B.Rt_tmp +
            controller_ros_ue_B.i] * controller_ros_ue_B.B[6 *
            controller_ros_ue_B.Rt_tmp + controller_ros_ue_B.B_tmp];
        }
      }
    }

    controller_ros_ue_mldivide_l(controller_ros_ue_B.B_m,
      controller_ros_ue_B.LAMDA1_tmp);
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.rotation_error[3 * controller_ros_ue_B.i] =
        controller_ros_ue_B.rotation_error_c[3 * controller_ros_ue_B.i];
      controller_ros_ue_B.B_tmp = (controller_ros_ue_B.i + 3) * 3;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp] =
        controller_ros_ue_B.Rd[controller_ros_ue_B.i];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 1;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.Rt_tmp] =
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp + 1] =
        controller_ros_ue_B.Rd[controller_ros_ue_B.i + 3];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 2;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.Rt_tmp] =
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp + 2] =
        controller_ros_ue_B.Rd[controller_ros_ue_B.i + 6];
    }

    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.ex[controller_ros_ue_B.i] = 0.0;
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 6;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.ex[controller_ros_ue_B.i] +=
          controller_ros_ue_B.rotation_error[3 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i] *
          controller_ros_ue_B.LAMDA1_tmp[controller_ros_ue_B.B_tmp];
      }
    }

    // '<S24>:1:24'
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.rotation_error[3 * controller_ros_ue_B.i] =
        controller_ros_ue_B.rotation_error_c[3 * controller_ros_ue_B.i];
      controller_ros_ue_B.B_tmp = (controller_ros_ue_B.i + 3) * 3;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp] =
        controller_ros_ue_B.R[controller_ros_ue_B.i];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 1;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.Rt_tmp] =
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp + 1] =
        controller_ros_ue_B.R[controller_ros_ue_B.i + 3];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 2;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.Rt_tmp] =
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp + 2] =
        controller_ros_ue_B.R[controller_ros_ue_B.i + 6];
    }

    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.grad[controller_ros_ue_B.i] = 0.0;
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 6;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.grad[controller_ros_ue_B.i] +=
          controller_ros_ue_B.rotation_error[3 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i] *
          controller_ros_ue_B.LAMDA1_tmp[controller_ros_ue_B.B_tmp];
      }
    }

    // '<S24>:1:25'
    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.rotation_error[3 * controller_ros_ue_B.i] =
        controller_ros_ue_B.rotation_error_c[3 * controller_ros_ue_B.i];
      controller_ros_ue_B.B_tmp = (controller_ros_ue_B.i + 3) * 3;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp] =
        controller_ros_ue_B.Rt[controller_ros_ue_B.i];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 1;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.Rt_tmp] =
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp + 1] =
        controller_ros_ue_B.Rt[controller_ros_ue_B.i + 3];
      controller_ros_ue_B.Rt_tmp = 3 * controller_ros_ue_B.i + 2;
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.Rt_tmp] =
        controller_ros_ue_B.rotation_error_c[controller_ros_ue_B.Rt_tmp];
      controller_ros_ue_B.rotation_error[controller_ros_ue_B.B_tmp + 2] =
        controller_ros_ue_B.Rt[controller_ros_ue_B.i + 6];
    }

    for (controller_ros_ue_B.i = 0; controller_ros_ue_B.i < 3;
         controller_ros_ue_B.i++) {
      controller_ros_ue_B.position_error[controller_ros_ue_B.i] = 0.0;
      for (controller_ros_ue_B.B_tmp = 0; controller_ros_ue_B.B_tmp < 6;
           controller_ros_ue_B.B_tmp++) {
        controller_ros_ue_B.position_error[controller_ros_ue_B.i] +=
          controller_ros_ue_B.rotation_error[3 * controller_ros_ue_B.B_tmp +
          controller_ros_ue_B.i] *
          controller_ros_ue_B.LAMDA1_tmp[controller_ros_ue_B.B_tmp];
      }
    }

    // '<S24>:1:27'
    // '<S24>:1:28'
    // '<S24>:1:29'
    // '<S24>:1:30'
    // '<S24>:1:31'
    // '<S24>:1:32'
    // '<S24>:1:33'
    // '<S24>:1:34'
    // '<S24>:1:35'
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // Sum: '<S7>/Sum3' incorporates:
      //   Constant: '<S7>/Constant'

      controller_ros_ue_B.Sum3 = controller_ros_ue_B.In1_n.Z +
        controller_ros_ue_P.Constant_Value_l;
    }

    // MATLAB Function: '<S7>/MATLAB Function1' incorporates:
    //   MATLAB Function: '<S7>/MATLAB Function'

    controller_ros__MATLABFunction1(controller_ros_ue_B.In1_l.X,
      controller_ros_ue_B.In1_l.Y, controller_ros_ue_B.In1_l.Z,
      controller_ros_ue_B.ex[0], controller_ros_ue_B.ex[1],
      controller_ros_ue_B.ex[2], controller_ros_ue_B.Sum3,
      &controller_ros_ue_B.Derivative_gu, &controller_ros_ue_B.q_bar,
      &controller_ros_ue_B.rtb_y_h_g, &controller_ros_ue_B.sf_MATLABFunction1);

    // BusAssignment: '<Root>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion'

    controller_ros_ue_B.BusAssignment.Data = static_cast<real32_T>
      (controller_ros_ue_B.Derivative_gu);

    // Outputs for Atomic SubSystem: '<Root>/Publish'
    // MATLABSystem: '<S10>/SinkBlock'
    Pub_controller_ros_ue_265.publish(&controller_ros_ue_B.BusAssignment);

    // End of Outputs for SubSystem: '<Root>/Publish'

    // BusAssignment: '<Root>/Bus Assignment3'
    controller_ros_ue_B.BusAssignment3.X = controller_ros_ue_B.q_bar;
    controller_ros_ue_B.BusAssignment3.Y = controller_ros_ue_B.rtb_y_h_g;
    controller_ros_ue_B.BusAssignment3.Z = controller_ros_ue_B.Sum3;

    // Outputs for Atomic SubSystem: '<Root>/Publish1'
    // MATLABSystem: '<S11>/SinkBlock'
    Pub_controller_ros_ue_266.publish(&controller_ros_ue_B.BusAssignment3);

    // End of Outputs for SubSystem: '<Root>/Publish1'
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // Sum: '<S7>/Sum4' incorporates:
      //   Constant: '<S7>/Constant1'

      controller_ros_ue_B.Sum4 = controller_ros_ue_B.In1_n.Z +
        controller_ros_ue_P.Constant1_Value;
    }

    // MATLAB Function: '<S7>/MATLAB Function2' incorporates:
    //   MATLAB Function: '<S7>/MATLAB Function'

    controller_ros__MATLABFunction1(controller_ros_ue_B.In1_l.X,
      controller_ros_ue_B.In1_l.Y, controller_ros_ue_B.In1_l.Z,
      controller_ros_ue_B.grad[0], controller_ros_ue_B.grad[1],
      controller_ros_ue_B.grad[2], controller_ros_ue_B.Sum4,
      &controller_ros_ue_B.Derivative_gu, &controller_ros_ue_B.q_bar,
      &controller_ros_ue_B.rtb_y_h_g, &controller_ros_ue_B.sf_MATLABFunction2);

    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion1'

    controller_ros_ue_B.BusAssignment1.Data = static_cast<real32_T>
      (controller_ros_ue_B.Derivative_gu);

    // Outputs for Atomic SubSystem: '<Root>/Publish2'
    // MATLABSystem: '<S12>/SinkBlock'
    Pub_controller_ros_ue_267.publish(&controller_ros_ue_B.BusAssignment1);

    // End of Outputs for SubSystem: '<Root>/Publish2'

    // BusAssignment: '<Root>/Bus Assignment4'
    controller_ros_ue_B.BusAssignment4.X = controller_ros_ue_B.q_bar;
    controller_ros_ue_B.BusAssignment4.Y = controller_ros_ue_B.rtb_y_h_g;
    controller_ros_ue_B.BusAssignment4.Z = controller_ros_ue_B.Sum4;

    // Outputs for Atomic SubSystem: '<Root>/Publish3'
    // MATLABSystem: '<S13>/SinkBlock'
    Pub_controller_ros_ue_268.publish(&controller_ros_ue_B.BusAssignment4);

    // End of Outputs for SubSystem: '<Root>/Publish3'
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // Sum: '<S7>/Sum1' incorporates:
      //   Constant: '<S7>/Constant2'

      controller_ros_ue_B.Sum1 = controller_ros_ue_B.In1_n.Z +
        controller_ros_ue_P.Constant2_Value;
    }

    // MATLAB Function: '<S7>/MATLAB Function3' incorporates:
    //   MATLAB Function: '<S7>/MATLAB Function'

    controller_ros__MATLABFunction1(controller_ros_ue_B.In1_l.X,
      controller_ros_ue_B.In1_l.Y, controller_ros_ue_B.In1_l.Z,
      controller_ros_ue_B.position_error[0], controller_ros_ue_B.position_error
      [1], controller_ros_ue_B.position_error[2], controller_ros_ue_B.Sum1,
      &controller_ros_ue_B.rtb_y_h_g, &controller_ros_ue_B.q_bar,
      &controller_ros_ue_B.Derivative_gu,
      &controller_ros_ue_B.sf_MATLABFunction3);

    // BusAssignment: '<Root>/Bus Assignment2' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion2'

    controller_ros_ue_B.BusAssignment2.Data = static_cast<real32_T>
      (controller_ros_ue_B.rtb_y_h_g);

    // Outputs for Atomic SubSystem: '<Root>/Publish4'
    // MATLABSystem: '<S14>/SinkBlock'
    Pub_controller_ros_ue_269.publish(&controller_ros_ue_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish4'

    // BusAssignment: '<Root>/Bus Assignment5'
    controller_ros_ue_B.BusAssignment5.X = controller_ros_ue_B.q_bar;
    controller_ros_ue_B.BusAssignment5.Y = controller_ros_ue_B.Derivative_gu;
    controller_ros_ue_B.BusAssignment5.Z = controller_ros_ue_B.Sum1;

    // Outputs for Atomic SubSystem: '<Root>/Publish5'
    // MATLABSystem: '<S15>/SinkBlock'
    Pub_controller_ros_ue_270.publish(&controller_ros_ue_B.BusAssignment5);

    // End of Outputs for SubSystem: '<Root>/Publish5'

    // Integrator: '<S47>/Integrator1'
    controller_ros_ue_B.Integrator1 = controller_ros_ue_X.Integrator1_CSTATE_i;
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S47>/MATLAB Function1' incorporates:
      //   Constant: '<S47>/omega_phi'

      controller_ro_MATLABFunction1_a(controller_ros_ue_B.In1_n.X,
        controller_ros_ue_P.omega_phi_Value, &controller_ros_ue_B.y_m);
    }

    // MATLAB Function: '<S47>/MATLAB Function2' incorporates:
    //   Constant: '<S47>/epsilon_phi'
    //   Constant: '<S47>/omega_phi'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1,
      controller_ros_ue_P.omega_phi_Value, controller_ros_ue_P.epsilon_phi_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S47>/MATLAB Function3' incorporates:
    //   Constant: '<S47>/omega_phi'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_b,
      controller_ros_ue_P.omega_phi_Value, &controller_ros_ue_B.Derivative_gu);

    // Sum: '<S47>/Sum'
    controller_ros_ue_B.Sum = (controller_ros_ue_B.y_m -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.Derivative_gu;

    // Integrator: '<S48>/Integrator1'
    controller_ros_ue_B.Integrator1_g = controller_ros_ue_X.Integrator1_CSTATE_j;
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S48>/MATLAB Function1' incorporates:
      //   Constant: '<S48>/omega_psi'

      controller_ro_MATLABFunction1_a(controller_ros_ue_B.In1_n.Z,
        controller_ros_ue_P.omega_psi_Value, &controller_ros_ue_B.y_k);
    }

    // MATLAB Function: '<S48>/MATLAB Function2' incorporates:
    //   Constant: '<S48>/epsilon_psi'
    //   Constant: '<S48>/omega_psi'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_g,
      controller_ros_ue_P.omega_psi_Value, controller_ros_ue_P.epsilon_psi_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S48>/MATLAB Function3' incorporates:
    //   Constant: '<S48>/omega_psi'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_i,
      controller_ros_ue_P.omega_psi_Value, &controller_ros_ue_B.Derivative_gu);

    // Sum: '<S48>/Sum'
    controller_ros_ue_B.Sum_p = (controller_ros_ue_B.y_k -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.Derivative_gu;

    // Integrator: '<S49>/Integrator1'
    controller_ros_ue_B.Integrator1_a = controller_ros_ue_X.Integrator1_CSTATE_n;
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S49>/MATLAB Function1' incorporates:
      //   Constant: '<S49>/omega_theta'

      controller_ro_MATLABFunction1_a(controller_ros_ue_B.In1_n.Y,
        controller_ros_ue_P.omega_theta_Value, &controller_ros_ue_B.y_c);
    }

    // MATLAB Function: '<S49>/MATLAB Function2' incorporates:
    //   Constant: '<S49>/epsilon_theta'
    //   Constant: '<S49>/omega_theta'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_a,
      controller_ros_ue_P.omega_theta_Value,
      controller_ros_ue_P.epsilon_theta_Value, &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S49>/MATLAB Function3' incorporates:
    //   Constant: '<S49>/omega_theta'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_e,
      controller_ros_ue_P.omega_theta_Value, &controller_ros_ue_B.Derivative_gu);

    // Sum: '<S49>/Sum'
    controller_ros_ue_B.Sum_c = (controller_ros_ue_B.y_c -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.Derivative_gu;

    // Integrator: '<S60>/Integrator1'
    controller_ros_ue_B.Integrator1_i = controller_ros_ue_X.Integrator1_CSTATE_b;
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S60>/MATLAB Function1' incorporates:
      //   Constant: '<S60>/omega_x'

      controller_ro_MATLABFunction1_a(controller_ros_ue_B.In1_k.X,
        controller_ros_ue_P.omega_x_Value, &controller_ros_ue_B.y_i);
    }

    // MATLAB Function: '<S60>/MATLAB Function2' incorporates:
    //   Constant: '<S60>/epsilon_x'
    //   Constant: '<S60>/omega_x'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_i,
      controller_ros_ue_P.omega_x_Value, controller_ros_ue_P.epsilon_x_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S60>/MATLAB Function3' incorporates:
    //   Constant: '<S60>/omega_x'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_k,
      controller_ros_ue_P.omega_x_Value, &controller_ros_ue_B.Derivative_gu);

    // Sum: '<S60>/Sum'
    controller_ros_ue_B.Sum_e = (controller_ros_ue_B.y_i -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.Derivative_gu;

    // Integrator: '<S61>/Integrator1'
    controller_ros_ue_B.Integrator1_d = controller_ros_ue_X.Integrator1_CSTATE_p;
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S61>/MATLAB Function1' incorporates:
      //   Constant: '<S61>/omega_y'

      controller_ro_MATLABFunction1_a(controller_ros_ue_B.In1_k.Y,
        controller_ros_ue_P.omega_y_Value, &controller_ros_ue_B.y_g);
    }

    // MATLAB Function: '<S61>/MATLAB Function2' incorporates:
    //   Constant: '<S61>/epsilon_y'
    //   Constant: '<S61>/omega_y'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_d,
      controller_ros_ue_P.omega_y_Value, controller_ros_ue_P.epsilon_y_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S61>/MATLAB Function3' incorporates:
    //   Constant: '<S61>/omega_y'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_n,
      controller_ros_ue_P.omega_y_Value, &controller_ros_ue_B.Derivative_gu);

    // Sum: '<S61>/Sum'
    controller_ros_ue_B.Sum_n = (controller_ros_ue_B.y_g -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.Derivative_gu;

    // Integrator: '<S62>/Integrator1'
    controller_ros_ue_B.Integrator1_k =
      controller_ros_ue_X.Integrator1_CSTATE_pj;
    if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
      // MATLAB Function: '<S62>/MATLAB Function1' incorporates:
      //   Constant: '<S62>/omega_z'

      controller_ro_MATLABFunction1_a(controller_ros_ue_B.In1_k.Z,
        controller_ros_ue_P.omega_z_Value, &controller_ros_ue_B.y);
    }

    // MATLAB Function: '<S62>/MATLAB Function2' incorporates:
    //   Constant: '<S62>/epsilon_z'
    //   Constant: '<S62>/omega_z'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_k,
      controller_ros_ue_P.omega_z_Value, controller_ros_ue_P.epsilon_z_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S62>/MATLAB Function3' incorporates:
    //   Constant: '<S62>/omega_z'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_ad,
      controller_ros_ue_P.omega_z_Value, &controller_ros_ue_B.Derivative_gu);

    // Sum: '<S62>/Sum'
    controller_ros_ue_B.Sum_o = (controller_ros_ue_B.y -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.Derivative_gu;

    // Integrator: '<S40>/Integrator1'
    controller_ros_ue_B.Integrator1_n =
      controller_ros_ue_X.Integrator1_CSTATE_n4;

    // MATLAB Function: '<S40>/MATLAB Function1' incorporates:
    //   Constant: '<S40>/omega_p'
    //   MATLAB Function: '<S30>/MATLAB Function1'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.vd[0],
      controller_ros_ue_P.omega_p_Value, &controller_ros_ue_B.Derivative_gu);

    // MATLAB Function: '<S40>/MATLAB Function2' incorporates:
    //   Constant: '<S40>/epsilon_p'
    //   Constant: '<S40>/omega_p'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_n,
      controller_ros_ue_P.omega_p_Value, controller_ros_ue_P.epsilon_p_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S40>/MATLAB Function3' incorporates:
    //   Constant: '<S40>/omega_p'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_aj,
      controller_ros_ue_P.omega_p_Value, &controller_ros_ue_B.q_bar);

    // Sum: '<S40>/Sum'
    controller_ros_ue_B.Sum_ng = (controller_ros_ue_B.Derivative_gu -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.q_bar;

    // Integrator: '<S41>/Integrator1'
    controller_ros_ue_B.Integrator1_l = controller_ros_ue_X.Integrator1_CSTATE_d;

    // MATLAB Function: '<S41>/MATLAB Function1' incorporates:
    //   Constant: '<S41>/omega_q'
    //   MATLAB Function: '<S30>/MATLAB Function1'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.vd[1],
      controller_ros_ue_P.omega_q_Value, &controller_ros_ue_B.Derivative_gu);

    // MATLAB Function: '<S41>/MATLAB Function2' incorporates:
    //   Constant: '<S41>/epsilon_q'
    //   Constant: '<S41>/omega_q'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_l,
      controller_ros_ue_P.omega_q_Value, controller_ros_ue_P.epsilon_q_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S41>/MATLAB Function3' incorporates:
    //   Constant: '<S41>/omega_q'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_jm,
      controller_ros_ue_P.omega_q_Value, &controller_ros_ue_B.q_bar);

    // Sum: '<S41>/Sum'
    controller_ros_ue_B.Sum_k = (controller_ros_ue_B.Derivative_gu -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.q_bar;

    // Integrator: '<S42>/Integrator1'
    controller_ros_ue_B.Integrator1_ly =
      controller_ros_ue_X.Integrator1_CSTATE_bd;

    // MATLAB Function: '<S42>/MATLAB Function1' incorporates:
    //   Constant: '<S42>/omega_r'
    //   MATLAB Function: '<S30>/MATLAB Function1'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.vd[2],
      controller_ros_ue_P.omega_r_Value, &controller_ros_ue_B.Derivative_gu);

    // MATLAB Function: '<S42>/MATLAB Function2' incorporates:
    //   Constant: '<S42>/epsilon_r'
    //   Constant: '<S42>/omega_r'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_ly,
      controller_ros_ue_P.omega_r_Value, controller_ros_ue_P.epsilon_r_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S42>/MATLAB Function3' incorporates:
    //   Constant: '<S42>/omega_r'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_h,
      controller_ros_ue_P.omega_r_Value, &controller_ros_ue_B.q_bar);

    // Sum: '<S42>/Sum'
    controller_ros_ue_B.Sum_j = (controller_ros_ue_B.Derivative_gu -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.q_bar;

    // Integrator: '<S43>/Integrator1'
    controller_ros_ue_B.Integrator1_h =
      controller_ros_ue_X.Integrator1_CSTATE_gk;

    // MATLAB Function: '<S43>/MATLAB Function1' incorporates:
    //   Constant: '<S43>/omega_u'
    //   MATLAB Function: '<S30>/MATLAB Function'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.epsilon_d_v[0],
      controller_ros_ue_P.omega_u_Value, &controller_ros_ue_B.Derivative_gu);

    // MATLAB Function: '<S43>/MATLAB Function2' incorporates:
    //   Constant: '<S43>/epsilon_u'
    //   Constant: '<S43>/omega_u'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_h,
      controller_ros_ue_P.omega_u_Value, controller_ros_ue_P.epsilon_u_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S43>/MATLAB Function3' incorporates:
    //   Constant: '<S43>/omega_u'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator,
      controller_ros_ue_P.omega_u_Value, &controller_ros_ue_B.q_bar);

    // Sum: '<S43>/Sum'
    controller_ros_ue_B.Sum_l = (controller_ros_ue_B.Derivative_gu -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.q_bar;

    // Integrator: '<S44>/Integrator1'
    controller_ros_ue_B.Integrator1_e = controller_ros_ue_X.Integrator1_CSTATE_h;

    // MATLAB Function: '<S44>/MATLAB Function1' incorporates:
    //   Constant: '<S44>/omega_v'
    //   MATLAB Function: '<S30>/MATLAB Function'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.epsilon_d_v[1],
      controller_ros_ue_P.omega_v_Value, &controller_ros_ue_B.Derivative_gu);

    // MATLAB Function: '<S44>/MATLAB Function2' incorporates:
    //   Constant: '<S44>/epsilon_v'
    //   Constant: '<S44>/omega_v'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_e,
      controller_ros_ue_P.omega_v_Value, controller_ros_ue_P.epsilon_v_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S44>/MATLAB Function3' incorporates:
    //   Constant: '<S44>/omega_v'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_a,
      controller_ros_ue_P.omega_v_Value, &controller_ros_ue_B.q_bar);

    // Sum: '<S44>/Sum'
    controller_ros_ue_B.Sum_nj = (controller_ros_ue_B.Derivative_gu -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.q_bar;

    // Integrator: '<S45>/Integrator1'
    controller_ros_ue_B.Integrator1_j = controller_ros_ue_X.Integrator1_CSTATE_k;

    // MATLAB Function: '<S45>/MATLAB Function1' incorporates:
    //   Constant: '<S45>/omega_w'
    //   MATLAB Function: '<S30>/MATLAB Function'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.epsilon_d_v[2],
      controller_ros_ue_P.omega_w_Value, &controller_ros_ue_B.Derivative_gu);

    // MATLAB Function: '<S45>/MATLAB Function2' incorporates:
    //   Constant: '<S45>/epsilon_w'
    //   Constant: '<S45>/omega_w'

    controller_ros__MATLABFunction2(controller_ros_ue_B.Integrator1_j,
      controller_ros_ue_P.omega_w_Value, controller_ros_ue_P.epsilon_w_Value,
      &controller_ros_ue_B.rtb_y_h_g);

    // MATLAB Function: '<S45>/MATLAB Function3' incorporates:
    //   Constant: '<S45>/omega_w'

    controller_ro_MATLABFunction1_a(controller_ros_ue_B.Integrator_j,
      controller_ros_ue_P.omega_w_Value, &controller_ros_ue_B.q_bar);

    // Sum: '<S45>/Sum'
    controller_ros_ue_B.Sum_a = (controller_ros_ue_B.Derivative_gu -
      controller_ros_ue_B.rtb_y_h_g) - controller_ros_ue_B.q_bar;
  }

  if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
    real_T *lastU;

    // Update for Derivative: '<S43>/Derivative'
    if (controller_ros_ue_DW.TimeStampA == (rtInf)) {
      controller_ros_ue_DW.TimeStampA = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA;
    } else if (controller_ros_ue_DW.TimeStampB == (rtInf)) {
      controller_ros_ue_DW.TimeStampB = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB;
    } else if (controller_ros_ue_DW.TimeStampA < controller_ros_ue_DW.TimeStampB)
    {
      controller_ros_ue_DW.TimeStampA = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA;
    } else {
      controller_ros_ue_DW.TimeStampB = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB;
    }

    *lastU = controller_ros_ue_B.Integrator;

    // End of Update for Derivative: '<S43>/Derivative'

    // Update for Derivative: '<S44>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_h == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_h = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_o;
    } else if (controller_ros_ue_DW.TimeStampB_h == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_h = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_g;
    } else if (controller_ros_ue_DW.TimeStampA_h <
               controller_ros_ue_DW.TimeStampB_h) {
      controller_ros_ue_DW.TimeStampA_h = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_o;
    } else {
      controller_ros_ue_DW.TimeStampB_h = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_g;
    }

    *lastU = controller_ros_ue_B.Integrator_a;

    // End of Update for Derivative: '<S44>/Derivative'

    // Update for Derivative: '<S45>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_p == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_p = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_m;
    } else if (controller_ros_ue_DW.TimeStampB_g == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_g = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_f;
    } else if (controller_ros_ue_DW.TimeStampA_p <
               controller_ros_ue_DW.TimeStampB_g) {
      controller_ros_ue_DW.TimeStampA_p = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_m;
    } else {
      controller_ros_ue_DW.TimeStampB_g = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_f;
    }

    *lastU = controller_ros_ue_B.Integrator_j;

    // End of Update for Derivative: '<S45>/Derivative'

    // Update for Derivative: '<S47>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_e == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_e = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_mt;
    } else if (controller_ros_ue_DW.TimeStampB_j == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_j = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_fx;
    } else if (controller_ros_ue_DW.TimeStampA_e <
               controller_ros_ue_DW.TimeStampB_j) {
      controller_ros_ue_DW.TimeStampA_e = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_mt;
    } else {
      controller_ros_ue_DW.TimeStampB_j = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_fx;
    }

    *lastU = controller_ros_ue_B.Integrator_b;

    // End of Update for Derivative: '<S47>/Derivative'

    // Update for Derivative: '<S49>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_n == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_n = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_l;
    } else if (controller_ros_ue_DW.TimeStampB_gr == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_gr = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_h;
    } else if (controller_ros_ue_DW.TimeStampA_n <
               controller_ros_ue_DW.TimeStampB_gr) {
      controller_ros_ue_DW.TimeStampA_n = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_l;
    } else {
      controller_ros_ue_DW.TimeStampB_gr = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_h;
    }

    *lastU = controller_ros_ue_B.Integrator_e;

    // End of Update for Derivative: '<S49>/Derivative'

    // Update for Derivative: '<S48>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_nq == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_nq = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_e;
    } else if (controller_ros_ue_DW.TimeStampB_e == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_e = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_n;
    } else if (controller_ros_ue_DW.TimeStampA_nq <
               controller_ros_ue_DW.TimeStampB_e) {
      controller_ros_ue_DW.TimeStampA_nq = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_e;
    } else {
      controller_ros_ue_DW.TimeStampB_e = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_n;
    }

    *lastU = controller_ros_ue_B.Integrator_i;

    // End of Update for Derivative: '<S48>/Derivative'

    // Update for Derivative: '<S60>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_f == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_f = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_d;
    } else if (controller_ros_ue_DW.TimeStampB_f == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_f = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_fd;
    } else if (controller_ros_ue_DW.TimeStampA_f <
               controller_ros_ue_DW.TimeStampB_f) {
      controller_ros_ue_DW.TimeStampA_f = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_d;
    } else {
      controller_ros_ue_DW.TimeStampB_f = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_fd;
    }

    *lastU = controller_ros_ue_B.Integrator_k;

    // End of Update for Derivative: '<S60>/Derivative'

    // Update for Derivative: '<S61>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_j == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_j = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_n;
    } else if (controller_ros_ue_DW.TimeStampB_f4 == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_f4 = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_l;
    } else if (controller_ros_ue_DW.TimeStampA_j <
               controller_ros_ue_DW.TimeStampB_f4) {
      controller_ros_ue_DW.TimeStampA_j = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_n;
    } else {
      controller_ros_ue_DW.TimeStampB_f4 = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_l;
    }

    *lastU = controller_ros_ue_B.Integrator_n;

    // End of Update for Derivative: '<S61>/Derivative'

    // Update for Derivative: '<S62>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_m == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_m = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_j;
    } else if (controller_ros_ue_DW.TimeStampB_l == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_l = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_b;
    } else if (controller_ros_ue_DW.TimeStampA_m <
               controller_ros_ue_DW.TimeStampB_l) {
      controller_ros_ue_DW.TimeStampA_m = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_j;
    } else {
      controller_ros_ue_DW.TimeStampB_l = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_b;
    }

    *lastU = controller_ros_ue_B.Integrator_ad;

    // End of Update for Derivative: '<S62>/Derivative'

    // Update for Derivative: '<S40>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_fq == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_fq = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_et;
    } else if (controller_ros_ue_DW.TimeStampB_m == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_m = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_ba;
    } else if (controller_ros_ue_DW.TimeStampA_fq <
               controller_ros_ue_DW.TimeStampB_m) {
      controller_ros_ue_DW.TimeStampA_fq = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_et;
    } else {
      controller_ros_ue_DW.TimeStampB_m = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_ba;
    }

    *lastU = controller_ros_ue_B.Integrator_aj;

    // End of Update for Derivative: '<S40>/Derivative'

    // Update for Derivative: '<S41>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_a == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_a = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_p;
    } else if (controller_ros_ue_DW.TimeStampB_gd == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_gd = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_d;
    } else if (controller_ros_ue_DW.TimeStampA_a <
               controller_ros_ue_DW.TimeStampB_gd) {
      controller_ros_ue_DW.TimeStampA_a = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_p;
    } else {
      controller_ros_ue_DW.TimeStampB_gd = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_d;
    }

    *lastU = controller_ros_ue_B.Integrator_jm;

    // End of Update for Derivative: '<S41>/Derivative'

    // Update for Derivative: '<S42>/Derivative'
    if (controller_ros_ue_DW.TimeStampA_l == (rtInf)) {
      controller_ros_ue_DW.TimeStampA_l = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_g;
    } else if (controller_ros_ue_DW.TimeStampB_p == (rtInf)) {
      controller_ros_ue_DW.TimeStampB_p = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_lt;
    } else if (controller_ros_ue_DW.TimeStampA_l <
               controller_ros_ue_DW.TimeStampB_p) {
      controller_ros_ue_DW.TimeStampA_l = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeA_g;
    } else {
      controller_ros_ue_DW.TimeStampB_p = controller_ros_ue_M->Timing.t[0];
      lastU = &controller_ros_ue_DW.LastUAtTimeB_lt;
    }

    *lastU = controller_ros_ue_B.Integrator_h;

    // End of Update for Derivative: '<S42>/Derivative'
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(controller_ros_ue_M)) {
    rt_ertODEUpdateContinuousStates(&controller_ros_ue_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++controller_ros_ue_M->Timing.clockTick0;
    controller_ros_ue_M->Timing.t[0] = rtsiGetSolverStopTime
      (&controller_ros_ue_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      controller_ros_ue_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void controller_ros_ue_derivatives(void)
{
  XDot_controller_ros_ue_T *_rtXdot;
  _rtXdot = ((XDot_controller_ros_ue_T *) controller_ros_ue_M->derivs);

  // Derivatives for Integrator: '<S43>/Integrator'
  _rtXdot->Integrator_CSTATE = controller_ros_ue_B.Integrator1_h;

  // Derivatives for Integrator: '<S44>/Integrator'
  _rtXdot->Integrator_CSTATE_p = controller_ros_ue_B.Integrator1_e;

  // Derivatives for Integrator: '<S45>/Integrator'
  _rtXdot->Integrator_CSTATE_m = controller_ros_ue_B.Integrator1_j;

  // Derivatives for Integrator: '<S47>/Integrator'
  _rtXdot->Integrator_CSTATE_e = controller_ros_ue_B.Integrator1;

  // Derivatives for Integrator: '<S49>/Integrator'
  _rtXdot->Integrator_CSTATE_k = controller_ros_ue_B.Integrator1_a;

  // Derivatives for Integrator: '<S48>/Integrator'
  _rtXdot->Integrator_CSTATE_j = controller_ros_ue_B.Integrator1_g;

  // Derivatives for Integrator: '<S60>/Integrator'
  _rtXdot->Integrator_CSTATE_k3 = controller_ros_ue_B.Integrator1_i;

  // Derivatives for Integrator: '<S61>/Integrator'
  _rtXdot->Integrator_CSTATE_c = controller_ros_ue_B.Integrator1_d;

  // Derivatives for Integrator: '<S62>/Integrator'
  _rtXdot->Integrator_CSTATE_i = controller_ros_ue_B.Integrator1_k;

  // Derivatives for Integrator: '<S33>/Integrator'
  _rtXdot->Integrator_CSTATE_eh = controller_ros_ue_B.x_error;

  // Derivatives for Integrator: '<S33>/Integrator1'
  _rtXdot->Integrator1_CSTATE = controller_ros_ue_B.y_error;

  // Derivatives for Integrator: '<S33>/Integrator2'
  _rtXdot->Integrator2_CSTATE = controller_ros_ue_B.z_error;

  // Derivatives for Integrator: '<S40>/Integrator'
  _rtXdot->Integrator_CSTATE_cv = controller_ros_ue_B.Integrator1_n;

  // Derivatives for Integrator: '<S41>/Integrator'
  _rtXdot->Integrator_CSTATE_b = controller_ros_ue_B.Integrator1_l;

  // Derivatives for Integrator: '<S42>/Integrator'
  _rtXdot->Integrator_CSTATE_o = controller_ros_ue_B.Integrator1_ly;

  // Derivatives for Integrator: '<S35>/Integrator'
  _rtXdot->Integrator_CSTATE_a = controller_ros_ue_B.phi_error;

  // Derivatives for Integrator: '<S35>/Integrator1'
  _rtXdot->Integrator1_CSTATE_g = controller_ros_ue_B.theta_error;

  // Derivatives for Integrator: '<S35>/Integrator2'
  _rtXdot->Integrator2_CSTATE_a = controller_ros_ue_B.psi_error;

  // Derivatives for Integrator: '<S47>/Integrator1'
  _rtXdot->Integrator1_CSTATE_i = controller_ros_ue_B.Sum;

  // Derivatives for Integrator: '<S48>/Integrator1'
  _rtXdot->Integrator1_CSTATE_j = controller_ros_ue_B.Sum_p;

  // Derivatives for Integrator: '<S49>/Integrator1'
  _rtXdot->Integrator1_CSTATE_n = controller_ros_ue_B.Sum_c;

  // Derivatives for Integrator: '<S60>/Integrator1'
  _rtXdot->Integrator1_CSTATE_b = controller_ros_ue_B.Sum_e;

  // Derivatives for Integrator: '<S61>/Integrator1'
  _rtXdot->Integrator1_CSTATE_p = controller_ros_ue_B.Sum_n;

  // Derivatives for Integrator: '<S62>/Integrator1'
  _rtXdot->Integrator1_CSTATE_pj = controller_ros_ue_B.Sum_o;

  // Derivatives for Integrator: '<S40>/Integrator1'
  _rtXdot->Integrator1_CSTATE_n4 = controller_ros_ue_B.Sum_ng;

  // Derivatives for Integrator: '<S41>/Integrator1'
  _rtXdot->Integrator1_CSTATE_d = controller_ros_ue_B.Sum_k;

  // Derivatives for Integrator: '<S42>/Integrator1'
  _rtXdot->Integrator1_CSTATE_bd = controller_ros_ue_B.Sum_j;

  // Derivatives for Integrator: '<S43>/Integrator1'
  _rtXdot->Integrator1_CSTATE_gk = controller_ros_ue_B.Sum_l;

  // Derivatives for Integrator: '<S44>/Integrator1'
  _rtXdot->Integrator1_CSTATE_h = controller_ros_ue_B.Sum_nj;

  // Derivatives for Integrator: '<S45>/Integrator1'
  _rtXdot->Integrator1_CSTATE_k = controller_ros_ue_B.Sum_a;
}

// Model initialize function
void controller_ros_ue_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&controller_ros_ue_M->solverInfo,
                          &controller_ros_ue_M->Timing.simTimeStep);
    rtsiSetTPtr(&controller_ros_ue_M->solverInfo, &rtmGetTPtr
                (controller_ros_ue_M));
    rtsiSetStepSizePtr(&controller_ros_ue_M->solverInfo,
                       &controller_ros_ue_M->Timing.stepSize0);
    rtsiSetdXPtr(&controller_ros_ue_M->solverInfo, &controller_ros_ue_M->derivs);
    rtsiSetContStatesPtr(&controller_ros_ue_M->solverInfo, (real_T **)
                         &controller_ros_ue_M->contStates);
    rtsiSetNumContStatesPtr(&controller_ros_ue_M->solverInfo,
      &controller_ros_ue_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&controller_ros_ue_M->solverInfo,
      &controller_ros_ue_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&controller_ros_ue_M->solverInfo,
      &controller_ros_ue_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&controller_ros_ue_M->solverInfo,
      &controller_ros_ue_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&controller_ros_ue_M->solverInfo, (&rtmGetErrorStatus
      (controller_ros_ue_M)));
    rtsiSetRTModelPtr(&controller_ros_ue_M->solverInfo, controller_ros_ue_M);
  }

  rtsiSetSimTimeStep(&controller_ros_ue_M->solverInfo, MAJOR_TIME_STEP);
  controller_ros_ue_M->intgData.y = controller_ros_ue_M->odeY;
  controller_ros_ue_M->intgData.f[0] = controller_ros_ue_M->odeF[0];
  controller_ros_ue_M->intgData.f[1] = controller_ros_ue_M->odeF[1];
  controller_ros_ue_M->intgData.f[2] = controller_ros_ue_M->odeF[2];
  controller_ros_ue_M->contStates = ((X_controller_ros_ue_T *)
    &controller_ros_ue_X);
  rtsiSetSolverData(&controller_ros_ue_M->solverInfo, static_cast<void *>
                    (&controller_ros_ue_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&controller_ros_ue_M->solverInfo, false);
  rtsiSetSolverName(&controller_ros_ue_M->solverInfo,"ode3");
  rtmSetTPtr(controller_ros_ue_M, &controller_ros_ue_M->Timing.tArray[0]);
  controller_ros_ue_M->Timing.stepSize0 = 0.01;

  {
    char_T b_zeroDelimTopic_3[14];
    char_T b_zeroDelimTopic_1[12];
    char_T b_zeroDelimTopic[11];
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic_2[9];
    static const char_T tmp[14] = { '/', 'e', 'u', 'l', 'e', 'r', '_', 'a', 'n',
      'g', 'l', 'e', '_', '0' };

    static const char_T tmp_0[10] = { '/', 'b', 'o', 'd', 'y', '_', 'r', 'a',
      't', 'e' };

    static const char_T tmp_1[21] = { '/', 'n', 'o', 'm', 'i', 'n', 'a', 'l',
      '_', 'e', 'u', 'l', 'e', 'r', '_', 'a', 'n', 'g', 'l', 'e', 's' };

    static const char_T tmp_2[9] = { '/', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'
    };

    static const char_T tmp_3[11] = { '/', 'p', 'o', 's', 'i', 't', 'i', 'o',
      'n', '_', '0' };

    static const char_T tmp_4[17] = { '/', 'n', 'o', 'm', 'i', 'n', 'a', 'l',
      '_', 'p', 'o', 's', 'i', 't', 'i', 'o', 'n' };

    static const char_T tmp_5[8] = { '/', 't', 'h', 'r', 'u', 's', 't', '1' };

    static const char_T tmp_6[13] = { '/', 'e', 'u', 'l', 'e', 'r', '_', 'a',
      'n', 'g', 'l', 'e', '1' };

    static const char_T tmp_7[8] = { '/', 't', 'h', 'r', 'u', 's', 't', '2' };

    static const char_T tmp_8[13] = { '/', 'e', 'u', 'l', 'e', 'r', '_', 'a',
      'n', 'g', 'l', 'e', '2' };

    static const char_T tmp_9[8] = { '/', 't', 'h', 'r', 'u', 's', 't', '3' };

    static const char_T tmp_a[13] = { '/', 'e', 'u', 'l', 'e', 'r', '_', 'a',
      'n', 'g', 'l', 'e', '3' };

    // InitializeConditions for Integrator: '<S43>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE = controller_ros_ue_P.Integrator_IC;

    // InitializeConditions for Derivative: '<S43>/Derivative'
    controller_ros_ue_DW.TimeStampA = (rtInf);
    controller_ros_ue_DW.TimeStampB = (rtInf);

    // InitializeConditions for Integrator: '<S44>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_p =
      controller_ros_ue_P.Integrator_IC_b;

    // InitializeConditions for Derivative: '<S44>/Derivative'
    controller_ros_ue_DW.TimeStampA_h = (rtInf);
    controller_ros_ue_DW.TimeStampB_h = (rtInf);

    // InitializeConditions for Integrator: '<S45>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_m =
      controller_ros_ue_P.Integrator_IC_a;

    // InitializeConditions for Derivative: '<S45>/Derivative'
    controller_ros_ue_DW.TimeStampA_p = (rtInf);
    controller_ros_ue_DW.TimeStampB_g = (rtInf);

    // InitializeConditions for Integrator: '<S47>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_e =
      controller_ros_ue_P.Integrator_IC_c;

    // InitializeConditions for Derivative: '<S47>/Derivative'
    controller_ros_ue_DW.TimeStampA_e = (rtInf);
    controller_ros_ue_DW.TimeStampB_j = (rtInf);

    // InitializeConditions for Integrator: '<S49>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_k =
      controller_ros_ue_P.Integrator_IC_g;

    // InitializeConditions for Derivative: '<S49>/Derivative'
    controller_ros_ue_DW.TimeStampA_n = (rtInf);
    controller_ros_ue_DW.TimeStampB_gr = (rtInf);

    // InitializeConditions for Integrator: '<S48>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_j =
      controller_ros_ue_P.Integrator_IC_j;

    // InitializeConditions for Derivative: '<S48>/Derivative'
    controller_ros_ue_DW.TimeStampA_nq = (rtInf);
    controller_ros_ue_DW.TimeStampB_e = (rtInf);

    // InitializeConditions for Integrator: '<S60>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_k3 =
      controller_ros_ue_P.Integrator_IC_k;

    // InitializeConditions for Derivative: '<S60>/Derivative'
    controller_ros_ue_DW.TimeStampA_f = (rtInf);
    controller_ros_ue_DW.TimeStampB_f = (rtInf);

    // InitializeConditions for Integrator: '<S61>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_c =
      controller_ros_ue_P.Integrator_IC_m;

    // InitializeConditions for Derivative: '<S61>/Derivative'
    controller_ros_ue_DW.TimeStampA_j = (rtInf);
    controller_ros_ue_DW.TimeStampB_f4 = (rtInf);

    // InitializeConditions for Integrator: '<S62>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_i =
      controller_ros_ue_P.Integrator_IC_gr;

    // InitializeConditions for Derivative: '<S62>/Derivative'
    controller_ros_ue_DW.TimeStampA_m = (rtInf);
    controller_ros_ue_DW.TimeStampB_l = (rtInf);

    // InitializeConditions for Integrator: '<S33>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_eh =
      controller_ros_ue_P.Integrator_IC_n;

    // InitializeConditions for Integrator: '<S33>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE = controller_ros_ue_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S33>/Integrator2'
    controller_ros_ue_X.Integrator2_CSTATE = controller_ros_ue_P.Integrator2_IC;

    // InitializeConditions for Integrator: '<S40>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_cv =
      controller_ros_ue_P.Integrator_IC_aa;

    // InitializeConditions for Derivative: '<S40>/Derivative'
    controller_ros_ue_DW.TimeStampA_fq = (rtInf);
    controller_ros_ue_DW.TimeStampB_m = (rtInf);

    // InitializeConditions for Integrator: '<S41>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_b =
      controller_ros_ue_P.Integrator_IC_d;

    // InitializeConditions for Derivative: '<S41>/Derivative'
    controller_ros_ue_DW.TimeStampA_a = (rtInf);
    controller_ros_ue_DW.TimeStampB_gd = (rtInf);

    // InitializeConditions for Integrator: '<S42>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_o =
      controller_ros_ue_P.Integrator_IC_at;

    // InitializeConditions for Derivative: '<S42>/Derivative'
    controller_ros_ue_DW.TimeStampA_l = (rtInf);
    controller_ros_ue_DW.TimeStampB_p = (rtInf);

    // InitializeConditions for Integrator: '<S35>/Integrator'
    controller_ros_ue_X.Integrator_CSTATE_a =
      controller_ros_ue_P.Integrator_IC_o;

    // InitializeConditions for Integrator: '<S35>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_g =
      controller_ros_ue_P.Integrator1_IC_c;

    // InitializeConditions for Integrator: '<S35>/Integrator2'
    controller_ros_ue_X.Integrator2_CSTATE_a =
      controller_ros_ue_P.Integrator2_IC_e;

    // InitializeConditions for Integrator: '<S47>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_i =
      controller_ros_ue_P.Integrator1_IC_m;

    // InitializeConditions for Integrator: '<S48>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_j =
      controller_ros_ue_P.Integrator1_IC_b;

    // InitializeConditions for Integrator: '<S49>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_n =
      controller_ros_ue_P.Integrator1_IC_e;

    // InitializeConditions for Integrator: '<S60>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_b =
      controller_ros_ue_P.Integrator1_IC_a;

    // InitializeConditions for Integrator: '<S61>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_p =
      controller_ros_ue_P.Integrator1_IC_p;

    // InitializeConditions for Integrator: '<S62>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_pj =
      controller_ros_ue_P.Integrator1_IC_h;

    // InitializeConditions for Integrator: '<S40>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_n4 =
      controller_ros_ue_P.Integrator1_IC_g;

    // InitializeConditions for Integrator: '<S41>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_d =
      controller_ros_ue_P.Integrator1_IC_ck;

    // InitializeConditions for Integrator: '<S42>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_bd =
      controller_ros_ue_P.Integrator1_IC_bq;

    // InitializeConditions for Integrator: '<S43>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_gk =
      controller_ros_ue_P.Integrator1_IC_ph;

    // InitializeConditions for Integrator: '<S44>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_h =
      controller_ros_ue_P.Integrator1_IC_j;

    // InitializeConditions for Integrator: '<S45>/Integrator1'
    controller_ros_ue_X.Integrator1_CSTATE_k =
      controller_ros_ue_P.Integrator1_IC_o;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S94>/In1' incorporates:
    //   Outport: '<S94>/Out1'

    controller_ros_ue_B.In1_l = controller_ros_ue_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem'

    // Start for MATLABSystem: '<S16>/SourceBlock'
    controller_ros_ue_DW.obj_mx.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_mx.isInitialized = 1;
    for (int32_T i = 0; i < 14; i++) {
      controller_ros_ue_B.b_zeroDelimTopic_f[i] = tmp[i];
    }

    controller_ros_ue_B.b_zeroDelimTopic_f[14] = '\x00';
    Sub_controller_ros_ue_222.createSubscriber
      (&controller_ros_ue_B.b_zeroDelimTopic_f[0], 1);
    controller_ros_ue_DW.obj_mx.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S17>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S95>/In1' incorporates:
    //   Outport: '<S95>/Out1'

    controller_ros_ue_B.In1_f = controller_ros_ue_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S17>/Enabled Subsystem'

    // Start for MATLABSystem: '<S17>/SourceBlock'
    controller_ros_ue_DW.obj_l.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp_0[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Sub_controller_ros_ue_225.createSubscriber(&b_zeroDelimTopic[0], 1);
    controller_ros_ue_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S17>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe5'
    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S99>/In1' incorporates:
    //   Outport: '<S99>/Out1'

    controller_ros_ue_B.In1_n = controller_ros_ue_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // Start for MATLABSystem: '<S21>/SourceBlock'
    controller_ros_ue_DW.obj_m.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_m.isInitialized = 1;
    for (int32_T i = 0; i < 21; i++) {
      controller_ros_ue_B.b_zeroDelimTopic[i] = tmp_1[i];
    }

    controller_ros_ue_B.b_zeroDelimTopic[21] = '\x00';
    Sub_controller_ros_ue_238.createSubscriber
      (&controller_ros_ue_B.b_zeroDelimTopic[0], 1);
    controller_ros_ue_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S21>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe5'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S96>/In1' incorporates:
    //   Outport: '<S96>/Out1'

    controller_ros_ue_B.In1_h = controller_ros_ue_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // Start for MATLABSystem: '<S18>/SourceBlock'
    controller_ros_ue_DW.obj_ou.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_ou.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_2[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Sub_controller_ros_ue_229.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    controller_ros_ue_DW.obj_ou.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S18>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S19>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S97>/In1' incorporates:
    //   Outport: '<S97>/Out1'

    controller_ros_ue_B.In1 = controller_ros_ue_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S19>/Enabled Subsystem'

    // Start for MATLABSystem: '<S19>/SourceBlock'
    controller_ros_ue_DW.obj_on.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_on.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = tmp_3[i];
    }

    b_zeroDelimTopic_1[11] = '\x00';
    Sub_controller_ros_ue_232.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    controller_ros_ue_DW.obj_on.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S19>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S98>/In1' incorporates:
    //   Outport: '<S98>/Out1'

    controller_ros_ue_B.In1_k = controller_ros_ue_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem'

    // Start for MATLABSystem: '<S20>/SourceBlock'
    controller_ros_ue_DW.obj_a.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_a.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      controller_ros_ue_B.b_zeroDelimTopic_c[i] = tmp_4[i];
    }

    controller_ros_ue_B.b_zeroDelimTopic_c[17] = '\x00';
    Sub_controller_ros_ue_235.createSubscriber
      (&controller_ros_ue_B.b_zeroDelimTopic_c[0], 1);
    controller_ros_ue_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S20>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S10>/SinkBlock'
    controller_ros_ue_DW.obj_g.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 8; i++) {
      b_zeroDelimTopic_2[i] = tmp_5[i];
    }

    b_zeroDelimTopic_2[8] = '\x00';
    Pub_controller_ros_ue_265.createPublisher(&b_zeroDelimTopic_2[0], 1);
    controller_ros_ue_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S11>/SinkBlock'
    controller_ros_ue_DW.obj_e.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_e.isInitialized = 1;
    for (int32_T i = 0; i < 13; i++) {
      b_zeroDelimTopic_3[i] = tmp_6[i];
    }

    b_zeroDelimTopic_3[13] = '\x00';
    Pub_controller_ros_ue_266.createPublisher(&b_zeroDelimTopic_3[0], 1);
    controller_ros_ue_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S12>/SinkBlock'
    controller_ros_ue_DW.obj_k.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_k.isInitialized = 1;
    for (int32_T i = 0; i < 8; i++) {
      b_zeroDelimTopic_2[i] = tmp_7[i];
    }

    b_zeroDelimTopic_2[8] = '\x00';
    Pub_controller_ros_ue_267.createPublisher(&b_zeroDelimTopic_2[0], 1);
    controller_ros_ue_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S13>/SinkBlock'
    controller_ros_ue_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_b.isInitialized = 1;
    for (int32_T i = 0; i < 13; i++) {
      b_zeroDelimTopic_3[i] = tmp_8[i];
    }

    b_zeroDelimTopic_3[13] = '\x00';
    Pub_controller_ros_ue_268.createPublisher(&b_zeroDelimTopic_3[0], 1);
    controller_ros_ue_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S13>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish4'
    // Start for MATLABSystem: '<S14>/SinkBlock'
    controller_ros_ue_DW.obj_o.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj_o.isInitialized = 1;
    for (int32_T i = 0; i < 8; i++) {
      b_zeroDelimTopic_2[i] = tmp_9[i];
    }

    b_zeroDelimTopic_2[8] = '\x00';
    Pub_controller_ros_ue_269.createPublisher(&b_zeroDelimTopic_2[0], 1);
    controller_ros_ue_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S14>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish5'
    // Start for MATLABSystem: '<S15>/SinkBlock'
    controller_ros_ue_DW.obj.matlabCodegenIsDeleted = false;
    controller_ros_ue_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 13; i++) {
      b_zeroDelimTopic_3[i] = tmp_a[i];
    }

    b_zeroDelimTopic_3[13] = '\x00';
    Pub_controller_ros_ue_270.createPublisher(&b_zeroDelimTopic_3[0], 1);
    controller_ros_ue_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S15>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish5'
  }
}

// Model terminate function
void controller_ros_ue_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S16>/SourceBlock'
  if (!controller_ros_ue_DW.obj_mx.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!controller_ros_ue_DW.obj_l.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe5'
  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!controller_ros_ue_DW.obj_m.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe5'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!controller_ros_ue_DW.obj_ou.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_ou.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S19>/SourceBlock'
  if (!controller_ros_ue_DW.obj_on.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_on.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S20>/SourceBlock'
  if (!controller_ros_ue_DW.obj_a.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S10>/SinkBlock'
  if (!controller_ros_ue_DW.obj_g.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S11>/SinkBlock'
  if (!controller_ros_ue_DW.obj_e.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!controller_ros_ue_DW.obj_k.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Terminate for MATLABSystem: '<S13>/SinkBlock'
  if (!controller_ros_ue_DW.obj_b.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish3'

  // Terminate for Atomic SubSystem: '<Root>/Publish4'
  // Terminate for MATLABSystem: '<S14>/SinkBlock'
  if (!controller_ros_ue_DW.obj_o.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish4'

  // Terminate for Atomic SubSystem: '<Root>/Publish5'
  // Terminate for MATLABSystem: '<S15>/SinkBlock'
  if (!controller_ros_ue_DW.obj.matlabCodegenIsDeleted) {
    controller_ros_ue_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish5'
}

//
// File trailer for generated code.
//
// [EOF]
//
