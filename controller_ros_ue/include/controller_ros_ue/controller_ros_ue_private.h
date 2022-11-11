//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: controller_ros_ue_private.h
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
#ifndef RTW_HEADER_controller_ros_ue_private_h_
#define RTW_HEADER_controller_ros_ue_private_h_
#include "rtwtypes.h"
#include "controller_ros_ue.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void controller_ros__MATLABFunction1(real_T rtu_phi, real_T rtu_theta,
  real_T rtu_psi, real_T rtu_fx, real_T rtu_fy, real_T rtu_fz, real_T
  rtu_psi_cmd, real_T *rty_thrust, real_T *rty_phi_i, real_T *rty_theta_i,
  B_MATLABFunction1_controller__T *localB);
extern void controller_ro_MATLABFunction1_a(real_T rtu_u, real_T rtu_omega,
  real_T *rty_y);
extern void controller_ros__MATLABFunction2(real_T rtu_u, real_T rtu_omega,
  real_T rtu_epsilon, real_T *rty_y);

// private model entry point functions
extern void controller_ros_ue_derivatives(void);

#endif                               // RTW_HEADER_controller_ros_ue_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
