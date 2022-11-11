//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: controller_ros_ue_data.cpp
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

// Block parameters (default storage)
P_controller_ros_ue_T controller_ros_ue_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S98>/Out1'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S20>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S99>/Out1'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S21>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S1>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S2>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S3>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S94>/Out1'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S16>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S95>/Out1'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S17>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S96>/Out1'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S18>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S97>/Out1'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_cf
  //  Referenced by: '<S19>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_cn
  //  Referenced by: '<S4>/Constant'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S5>/Constant'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S6>/Constant'

  {
    0.0F                               // Data
  },

  // Expression: 0.6737
  //  Referenced by: '<S22>/drone1_x'

  0.6737,

  // Expression: 0
  //  Referenced by: '<S22>/drone1_y'

  0.0,

  // Expression: -0.12468
  //  Referenced by: '<S22>/drone1_z'

  -0.12468,

  // Expression: -0.3368
  //  Referenced by: '<S22>/drone2_x'

  -0.3368,

  // Expression: 0.5834
  //  Referenced by: '<S22>/drone2_y'

  0.5834,

  // Expression: -0.12468
  //  Referenced by: '<S22>/drone2_z'

  -0.12468,

  // Expression: -0.3368
  //  Referenced by: '<S22>/drone3_x'

  -0.3368,

  // Expression: -0.5834
  //  Referenced by: '<S22>/drone3_y'

  -0.5834,

  // Expression: -0.12468
  //  Referenced by: '<S22>/drone3_z'

  -0.12468,

  // Expression: 0
  //  Referenced by: '<S43>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S44>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S45>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S22>/tool_x'

  0.0,

  // Expression: 0
  //  Referenced by: '<S22>/tool_y'

  0.0,

  // Expression: 0
  //  Referenced by: '<S22>/tool_z'

  0.0,

  // Expression: 0
  //  Referenced by: '<S47>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S49>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S48>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S60>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S61>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S62>/Integrator'

  0.0,

  // Expression: 5
  //  Referenced by: '<S31>/kp_x'

  5.0,

  // Expression: 5
  //  Referenced by: '<S31>/kp_y'

  5.0,

  // Expression: 5
  //  Referenced by: '<S31>/kp_z'

  5.0,

  // Expression: 2.0
  //  Referenced by: '<S23>/center_mass'

  2.0,

  // Expression: 1.5
  //  Referenced by: '<S23>/drone1_mass'

  1.5,

  // Expression: 1.5
  //  Referenced by: '<S23>/drone2_mass'

  1.5,

  // Expression: 1.5
  //  Referenced by: '<S23>/drone3_mass'

  1.5,

  // Expression: 15
  //  Referenced by: '<S28>/kd_x'

  15.0,

  // Expression: 15
  //  Referenced by: '<S28>/kd_y'

  15.0,

  // Expression: 15
  //  Referenced by: '<S28>/kd_z'

  15.0,

  // Expression: 0
  //  Referenced by: '<S33>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Integrator1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Integrator2'

  0.0,

  // Expression: 2
  //  Referenced by: '<S28>/ki_x'

  2.0,

  // Expression: 2
  //  Referenced by: '<S28>/ki_y'

  2.0,

  // Expression: 2
  //  Referenced by: '<S28>/ki_z'

  2.0,

  // Expression: 0
  //  Referenced by: '<S40>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S41>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S42>/Integrator'

  0.0,

  // Expression: 3
  //  Referenced by: '<S31>/kp_phi'

  3.0,

  // Expression: 3
  //  Referenced by: '<S31>/kp_theta'

  3.0,

  // Expression: 5
  //  Referenced by: '<S31>/kp_psi'

  5.0,

  // Expression: 0.06250784647
  //  Referenced by: '<S92>/Ixx'

  0.06250784647,

  // Expression: 0.06280979995
  //  Referenced by: '<S92>/Iyy'

  0.06280979995,

  // Expression: 0.11503523247
  //  Referenced by: '<S92>/Izz'

  0.11503523247,

  // Expression: 9
  //  Referenced by: '<S29>/kd_phi'

  9.0,

  // Expression: 9
  //  Referenced by: '<S29>/kd_theta'

  9.0,

  // Expression: 15
  //  Referenced by: '<S29>/kd_psi'

  15.0,

  // Expression: 0
  //  Referenced by: '<S35>/Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S35>/Integrator1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S35>/Integrator2'

  0.0,

  // Expression: 1.4
  //  Referenced by: '<S29>/ki_phi'

  1.4,

  // Expression: 1.4
  //  Referenced by: '<S29>/ki_theta'

  1.4,

  // Expression: 2
  //  Referenced by: '<S29>/ki_psi'

  2.0,

  // Expression: 0
  //  Referenced by: '<S7>/Constant'

  0.0,

  // Expression: pi*2/3
  //  Referenced by: '<S7>/Constant1'

  2.0943951023931953,

  // Expression: -pi*2/3
  //  Referenced by: '<S7>/Constant2'

  -2.0943951023931953,

  // Expression: 0
  //  Referenced by: '<S47>/Integrator1'

  0.0,

  // Expression: 8
  //  Referenced by: '<S47>/omega_phi'

  8.0,

  // Expression: 1.414
  //  Referenced by: '<S47>/epsilon_phi'

  1.414,

  // Expression: 0
  //  Referenced by: '<S48>/Integrator1'

  0.0,

  // Expression: 10
  //  Referenced by: '<S48>/omega_psi'

  10.0,

  // Expression: 1.414
  //  Referenced by: '<S48>/epsilon_psi'

  1.414,

  // Expression: 0
  //  Referenced by: '<S49>/Integrator1'

  0.0,

  // Expression: 6.9
  //  Referenced by: '<S49>/omega_theta'

  6.9,

  // Expression: 1.414
  //  Referenced by: '<S49>/epsilon_theta'

  1.414,

  // Expression: 0
  //  Referenced by: '<S60>/Integrator1'

  0.0,

  // Expression: 5
  //  Referenced by: '<S60>/omega_x'

  5.0,

  // Expression: 1.414
  //  Referenced by: '<S60>/epsilon_x'

  1.414,

  // Expression: 0
  //  Referenced by: '<S61>/Integrator1'

  0.0,

  // Expression: 8
  //  Referenced by: '<S61>/omega_y'

  8.0,

  // Expression: 1.414
  //  Referenced by: '<S61>/epsilon_y'

  1.414,

  // Expression: 0
  //  Referenced by: '<S62>/Integrator1'

  0.0,

  // Expression: 5
  //  Referenced by: '<S62>/omega_z'

  5.0,

  // Expression: 1.414
  //  Referenced by: '<S62>/epsilon_z'

  1.414,

  // Expression: 0
  //  Referenced by: '<S40>/Integrator1'

  0.0,

  // Expression: 24
  //  Referenced by: '<S40>/omega_p'

  24.0,

  // Expression: 1.414
  //  Referenced by: '<S40>/epsilon_p'

  1.414,

  // Expression: 0
  //  Referenced by: '<S41>/Integrator1'

  0.0,

  // Expression: 20
  //  Referenced by: '<S41>/omega_q'

  20.0,

  // Expression: 1.414
  //  Referenced by: '<S41>/epsilon_q'

  1.414,

  // Expression: 0
  //  Referenced by: '<S42>/Integrator1'

  0.0,

  // Expression: 20
  //  Referenced by: '<S42>/omega_r'

  20.0,

  // Expression: 1.414
  //  Referenced by: '<S42>/epsilon_r'

  1.414,

  // Expression: 0
  //  Referenced by: '<S43>/Integrator1'

  0.0,

  // Expression: 15
  //  Referenced by: '<S43>/omega_u'

  15.0,

  // Expression: 1.414
  //  Referenced by: '<S43>/epsilon_u'

  1.414,

  // Expression: 0
  //  Referenced by: '<S44>/Integrator1'

  0.0,

  // Expression: 24
  //  Referenced by: '<S44>/omega_v'

  24.0,

  // Expression: 1.414
  //  Referenced by: '<S44>/epsilon_v'

  1.414,

  // Expression: 0
  //  Referenced by: '<S45>/Integrator1'

  0.0,

  // Expression: 10
  //  Referenced by: '<S45>/omega_w'

  10.0,

  // Expression: 1.414
  //  Referenced by: '<S45>/epsilon_w'

  1.414
};

//
// File trailer for generated code.
//
// [EOF]
//
