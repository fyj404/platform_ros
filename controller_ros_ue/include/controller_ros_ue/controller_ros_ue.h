//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: controller_ros_ue.h
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
#ifndef RTW_HEADER_controller_ros_ue_h_
#define RTW_HEADER_controller_ros_ue_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "controller_ros_ue_types.h"

extern "C" {

#include "rtGetInf.h"

}
  extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals for system '<S7>/MATLAB Function1'
struct B_MATLABFunction1_controller__T {
  real_T fw_tmp[9];
  real_T fw[3];
};

// Block signals (default storage)
struct B_controller_ros_ue_T {
  real_T B[54];
  real_T B_m[36];
  real_T b_A[36];
  real_T rotation_error[18];
  real_T Rd[9];
  real_T R[9];
  real_T Rt[9];
  real_T rotation_error_c[9];
  real_T dv[9];
  real_T dv1[9];
  real_T Rd_k[9];
  real_T LAMDA1_tmp[6];
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 In1;// '<S97>/In1'
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 In1_h;// '<S96>/In1'
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 In1_f;// '<S95>/In1'
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 In1_l;// '<S94>/In1'
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 b_varargout_2;
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 BusAssignment3;// '<Root>/Bus Assignment3' 
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 BusAssignment4;// '<Root>/Bus Assignment4' 
  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 BusAssignment5;// '<Root>/Bus Assignment5' 
  SL_Bus_controller_ros_ue_geometry_msgs_Point In1_n;// '<S99>/In1'
  SL_Bus_controller_ros_ue_geometry_msgs_Point In1_k;// '<S98>/In1'
  SL_Bus_controller_ros_ue_geometry_msgs_Point b_varargout_2_c;
  real_T vd[3];
  real_T epsilon_d_v[3];
  real_T position_error[3];
  real_T grad[3];
  real_T a[3];
  real_T ex[3];                        // '<S8>/Sum'
  real_T rtb_p_bar_b[3];
  real_T Rd_p[3];
  char_T b_zeroDelimTopic[22];
  char_T b_zeroDelimTopic_c[18];
  char_T b_zeroDelimTopic_f[15];
  real_T Integrator;                   // '<S43>/Integrator'
  real_T Integrator_a;                 // '<S44>/Integrator'
  real_T Integrator_j;                 // '<S45>/Integrator'
  real_T Integrator_b;                 // '<S47>/Integrator'
  real_T Integrator_e;                 // '<S49>/Integrator'
  real_T Integrator_i;                 // '<S48>/Integrator'
  real_T Integrator_k;                 // '<S60>/Integrator'
  real_T Integrator_n;                 // '<S61>/Integrator'
  real_T Integrator_ad;                // '<S62>/Integrator'
  real_T Add;                          // '<S23>/Add'
  real_T Integrator_aj;                // '<S40>/Integrator'
  real_T Integrator_jm;                // '<S41>/Integrator'
  real_T Integrator_h;                 // '<S42>/Integrator'
  real_T Sum3;                         // '<S7>/Sum3'
  real_T Sum4;                         // '<S7>/Sum4'
  real_T Sum1;                         // '<S7>/Sum1'
  real_T Integrator1;                  // '<S47>/Integrator1'
  real_T Sum;                          // '<S47>/Sum'
  real_T Integrator1_g;                // '<S48>/Integrator1'
  real_T Sum_p;                        // '<S48>/Sum'
  real_T Integrator1_a;                // '<S49>/Integrator1'
  real_T Sum_c;                        // '<S49>/Sum'
  real_T Integrator1_i;                // '<S60>/Integrator1'
  real_T Sum_e;                        // '<S60>/Sum'
  real_T Integrator1_d;                // '<S61>/Integrator1'
  real_T Sum_n;                        // '<S61>/Sum'
  real_T Integrator1_k;                // '<S62>/Integrator1'
  real_T Sum_o;                        // '<S62>/Sum'
  real_T Integrator1_n;                // '<S40>/Integrator1'
  real_T Sum_ng;                       // '<S40>/Sum'
  real_T Integrator1_l;                // '<S41>/Integrator1'
  real_T Sum_k;                        // '<S41>/Sum'
  real_T Integrator1_ly;               // '<S42>/Integrator1'
  real_T Sum_j;                        // '<S42>/Sum'
  real_T Integrator1_h;                // '<S43>/Integrator1'
  real_T Sum_l;                        // '<S43>/Sum'
  real_T Integrator1_e;                // '<S44>/Integrator1'
  real_T Sum_nj;                       // '<S44>/Sum'
  real_T Integrator1_j;                // '<S45>/Integrator1'
  real_T Sum_a;                        // '<S45>/Sum'
  real_T Ix_sys;                       // '<S9>/calc_J_sys'
  real_T Iy_sys;                       // '<S9>/calc_J_sys'
  real_T Iz_sys;                       // '<S9>/calc_J_sys'
  real_T grad1;                        // '<S31>/MATLAB Function2'
  real_T grad2;                        // '<S31>/MATLAB Function2'
  real_T grad3;                        // '<S31>/MATLAB Function2'
  real_T phi_error;                    // '<S31>/MATLAB Function2'
  real_T theta_error;                  // '<S31>/MATLAB Function2'
  real_T psi_error;                    // '<S31>/MATLAB Function2'
  real_T grad1_n;                      // '<S31>/MATLAB Function1'
  real_T grad2_e;                      // '<S31>/MATLAB Function1'
  real_T grad3_l;                      // '<S31>/MATLAB Function1'
  real_T x_error;                      // '<S31>/MATLAB Function1'
  real_T y_error;                      // '<S31>/MATLAB Function1'
  real_T z_error;                      // '<S31>/MATLAB Function1'
  real_T y;                            // '<S62>/MATLAB Function1'
  real_T y_g;                          // '<S61>/MATLAB Function1'
  real_T y_i;                          // '<S60>/MATLAB Function1'
  real_T y_c;                          // '<S49>/MATLAB Function1'
  real_T y_k;                          // '<S48>/MATLAB Function1'
  real_T y_m;                          // '<S47>/MATLAB Function1'
  real_T lastTime;
  real_T Derivative;                   // '<S43>/Derivative'
  real_T Derivative_i;                 // '<S44>/Derivative'
  real_T Derivative_g;                 // '<S45>/Derivative'
  real_T Derivative_gu;                // '<S47>/Derivative'
  real_T Derivative_iw;                // '<S49>/Derivative'
  real_T Derivative_d;                 // '<S48>/Derivative'
  real_T q_bar;                        // '<S38>/MATLAB Function'
  real_T Derivative_j;                 // '<S61>/Derivative'
  real_T Derivative_n;                 // '<S62>/Derivative'
  real_T rtb_y_h_g;
  real_T rtb_q_bar_tmp;
  real_T rtb_q_bar_tmp_g;
  real_T rtb_q_bar_tmp_m;
  real_T rtb_p_bar_tmp;
  real_T vd_tmp;
  real_T rtb_ex_idx_1;
  real_T rtb_ex_idx_2;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T smax;
  real_T s;
  int8_T ipiv[6];
  int32_T i;
  int32_T Rt_tmp;
  int32_T R_tmp;
  int32_T B_tmp;
  int32_T i1;
  int32_T jj;
  int32_T j;
  int32_T ix;
  int32_T c_k;
  int32_T jA;
  int32_T c_ix;
  int32_T c;
  int32_T ijA;
  SL_Bus_controller_ros_ue_std_msgs_Float32 BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_controller_ros_ue_std_msgs_Float32 BusAssignment1;// '<Root>/Bus Assignment1' 
  SL_Bus_controller_ros_ue_std_msgs_Float32 BusAssignment2;// '<Root>/Bus Assignment2' 
  B_MATLABFunction1_controller__T sf_MATLABFunction3;// '<S7>/MATLAB Function3'
  B_MATLABFunction1_controller__T sf_MATLABFunction2;// '<S7>/MATLAB Function2'
  B_MATLABFunction1_controller__T sf_MATLABFunction1;// '<S7>/MATLAB Function1'
};

// Block states (default storage) for system '<Root>'
struct DW_controller_ros_ue_T {
  ros_slroscpp_internal_block_P_T obj; // '<S15>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_o;// '<S14>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_b;// '<S13>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_k;// '<S12>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_e;// '<S11>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_g;// '<S10>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S21>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_a;// '<S20>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_on;// '<S19>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_ou;// '<S18>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_l;// '<S17>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_mx;// '<S16>/SourceBlock'
  real_T TimeStampA;                   // '<S43>/Derivative'
  real_T LastUAtTimeA;                 // '<S43>/Derivative'
  real_T TimeStampB;                   // '<S43>/Derivative'
  real_T LastUAtTimeB;                 // '<S43>/Derivative'
  real_T TimeStampA_h;                 // '<S44>/Derivative'
  real_T LastUAtTimeA_o;               // '<S44>/Derivative'
  real_T TimeStampB_h;                 // '<S44>/Derivative'
  real_T LastUAtTimeB_g;               // '<S44>/Derivative'
  real_T TimeStampA_p;                 // '<S45>/Derivative'
  real_T LastUAtTimeA_m;               // '<S45>/Derivative'
  real_T TimeStampB_g;                 // '<S45>/Derivative'
  real_T LastUAtTimeB_f;               // '<S45>/Derivative'
  real_T TimeStampA_e;                 // '<S47>/Derivative'
  real_T LastUAtTimeA_mt;              // '<S47>/Derivative'
  real_T TimeStampB_j;                 // '<S47>/Derivative'
  real_T LastUAtTimeB_fx;              // '<S47>/Derivative'
  real_T TimeStampA_n;                 // '<S49>/Derivative'
  real_T LastUAtTimeA_l;               // '<S49>/Derivative'
  real_T TimeStampB_gr;                // '<S49>/Derivative'
  real_T LastUAtTimeB_h;               // '<S49>/Derivative'
  real_T TimeStampA_nq;                // '<S48>/Derivative'
  real_T LastUAtTimeA_e;               // '<S48>/Derivative'
  real_T TimeStampB_e;                 // '<S48>/Derivative'
  real_T LastUAtTimeB_n;               // '<S48>/Derivative'
  real_T TimeStampA_f;                 // '<S60>/Derivative'
  real_T LastUAtTimeA_d;               // '<S60>/Derivative'
  real_T TimeStampB_f;                 // '<S60>/Derivative'
  real_T LastUAtTimeB_fd;              // '<S60>/Derivative'
  real_T TimeStampA_j;                 // '<S61>/Derivative'
  real_T LastUAtTimeA_n;               // '<S61>/Derivative'
  real_T TimeStampB_f4;                // '<S61>/Derivative'
  real_T LastUAtTimeB_l;               // '<S61>/Derivative'
  real_T TimeStampA_m;                 // '<S62>/Derivative'
  real_T LastUAtTimeA_j;               // '<S62>/Derivative'
  real_T TimeStampB_l;                 // '<S62>/Derivative'
  real_T LastUAtTimeB_b;               // '<S62>/Derivative'
  real_T TimeStampA_fq;                // '<S40>/Derivative'
  real_T LastUAtTimeA_et;              // '<S40>/Derivative'
  real_T TimeStampB_m;                 // '<S40>/Derivative'
  real_T LastUAtTimeB_ba;              // '<S40>/Derivative'
  real_T TimeStampA_a;                 // '<S41>/Derivative'
  real_T LastUAtTimeA_p;               // '<S41>/Derivative'
  real_T TimeStampB_gd;                // '<S41>/Derivative'
  real_T LastUAtTimeB_d;               // '<S41>/Derivative'
  real_T TimeStampA_l;                 // '<S42>/Derivative'
  real_T LastUAtTimeA_g;               // '<S42>/Derivative'
  real_T TimeStampB_p;                 // '<S42>/Derivative'
  real_T LastUAtTimeB_lt;              // '<S42>/Derivative'
};

// Continuous states (default storage)
struct X_controller_ros_ue_T {
  real_T Integrator_CSTATE;            // '<S43>/Integrator'
  real_T Integrator_CSTATE_p;          // '<S44>/Integrator'
  real_T Integrator_CSTATE_m;          // '<S45>/Integrator'
  real_T Integrator_CSTATE_e;          // '<S47>/Integrator'
  real_T Integrator_CSTATE_k;          // '<S49>/Integrator'
  real_T Integrator_CSTATE_j;          // '<S48>/Integrator'
  real_T Integrator_CSTATE_k3;         // '<S60>/Integrator'
  real_T Integrator_CSTATE_c;          // '<S61>/Integrator'
  real_T Integrator_CSTATE_i;          // '<S62>/Integrator'
  real_T Integrator_CSTATE_eh;         // '<S33>/Integrator'
  real_T Integrator1_CSTATE;           // '<S33>/Integrator1'
  real_T Integrator2_CSTATE;           // '<S33>/Integrator2'
  real_T Integrator_CSTATE_cv;         // '<S40>/Integrator'
  real_T Integrator_CSTATE_b;          // '<S41>/Integrator'
  real_T Integrator_CSTATE_o;          // '<S42>/Integrator'
  real_T Integrator_CSTATE_a;          // '<S35>/Integrator'
  real_T Integrator1_CSTATE_g;         // '<S35>/Integrator1'
  real_T Integrator2_CSTATE_a;         // '<S35>/Integrator2'
  real_T Integrator1_CSTATE_i;         // '<S47>/Integrator1'
  real_T Integrator1_CSTATE_j;         // '<S48>/Integrator1'
  real_T Integrator1_CSTATE_n;         // '<S49>/Integrator1'
  real_T Integrator1_CSTATE_b;         // '<S60>/Integrator1'
  real_T Integrator1_CSTATE_p;         // '<S61>/Integrator1'
  real_T Integrator1_CSTATE_pj;        // '<S62>/Integrator1'
  real_T Integrator1_CSTATE_n4;        // '<S40>/Integrator1'
  real_T Integrator1_CSTATE_d;         // '<S41>/Integrator1'
  real_T Integrator1_CSTATE_bd;        // '<S42>/Integrator1'
  real_T Integrator1_CSTATE_gk;        // '<S43>/Integrator1'
  real_T Integrator1_CSTATE_h;         // '<S44>/Integrator1'
  real_T Integrator1_CSTATE_k;         // '<S45>/Integrator1'
};

// State derivatives (default storage)
struct XDot_controller_ros_ue_T {
  real_T Integrator_CSTATE;            // '<S43>/Integrator'
  real_T Integrator_CSTATE_p;          // '<S44>/Integrator'
  real_T Integrator_CSTATE_m;          // '<S45>/Integrator'
  real_T Integrator_CSTATE_e;          // '<S47>/Integrator'
  real_T Integrator_CSTATE_k;          // '<S49>/Integrator'
  real_T Integrator_CSTATE_j;          // '<S48>/Integrator'
  real_T Integrator_CSTATE_k3;         // '<S60>/Integrator'
  real_T Integrator_CSTATE_c;          // '<S61>/Integrator'
  real_T Integrator_CSTATE_i;          // '<S62>/Integrator'
  real_T Integrator_CSTATE_eh;         // '<S33>/Integrator'
  real_T Integrator1_CSTATE;           // '<S33>/Integrator1'
  real_T Integrator2_CSTATE;           // '<S33>/Integrator2'
  real_T Integrator_CSTATE_cv;         // '<S40>/Integrator'
  real_T Integrator_CSTATE_b;          // '<S41>/Integrator'
  real_T Integrator_CSTATE_o;          // '<S42>/Integrator'
  real_T Integrator_CSTATE_a;          // '<S35>/Integrator'
  real_T Integrator1_CSTATE_g;         // '<S35>/Integrator1'
  real_T Integrator2_CSTATE_a;         // '<S35>/Integrator2'
  real_T Integrator1_CSTATE_i;         // '<S47>/Integrator1'
  real_T Integrator1_CSTATE_j;         // '<S48>/Integrator1'
  real_T Integrator1_CSTATE_n;         // '<S49>/Integrator1'
  real_T Integrator1_CSTATE_b;         // '<S60>/Integrator1'
  real_T Integrator1_CSTATE_p;         // '<S61>/Integrator1'
  real_T Integrator1_CSTATE_pj;        // '<S62>/Integrator1'
  real_T Integrator1_CSTATE_n4;        // '<S40>/Integrator1'
  real_T Integrator1_CSTATE_d;         // '<S41>/Integrator1'
  real_T Integrator1_CSTATE_bd;        // '<S42>/Integrator1'
  real_T Integrator1_CSTATE_gk;        // '<S43>/Integrator1'
  real_T Integrator1_CSTATE_h;         // '<S44>/Integrator1'
  real_T Integrator1_CSTATE_k;         // '<S45>/Integrator1'
};

// State disabled
struct XDis_controller_ros_ue_T {
  boolean_T Integrator_CSTATE;         // '<S43>/Integrator'
  boolean_T Integrator_CSTATE_p;       // '<S44>/Integrator'
  boolean_T Integrator_CSTATE_m;       // '<S45>/Integrator'
  boolean_T Integrator_CSTATE_e;       // '<S47>/Integrator'
  boolean_T Integrator_CSTATE_k;       // '<S49>/Integrator'
  boolean_T Integrator_CSTATE_j;       // '<S48>/Integrator'
  boolean_T Integrator_CSTATE_k3;      // '<S60>/Integrator'
  boolean_T Integrator_CSTATE_c;       // '<S61>/Integrator'
  boolean_T Integrator_CSTATE_i;       // '<S62>/Integrator'
  boolean_T Integrator_CSTATE_eh;      // '<S33>/Integrator'
  boolean_T Integrator1_CSTATE;        // '<S33>/Integrator1'
  boolean_T Integrator2_CSTATE;        // '<S33>/Integrator2'
  boolean_T Integrator_CSTATE_cv;      // '<S40>/Integrator'
  boolean_T Integrator_CSTATE_b;       // '<S41>/Integrator'
  boolean_T Integrator_CSTATE_o;       // '<S42>/Integrator'
  boolean_T Integrator_CSTATE_a;       // '<S35>/Integrator'
  boolean_T Integrator1_CSTATE_g;      // '<S35>/Integrator1'
  boolean_T Integrator2_CSTATE_a;      // '<S35>/Integrator2'
  boolean_T Integrator1_CSTATE_i;      // '<S47>/Integrator1'
  boolean_T Integrator1_CSTATE_j;      // '<S48>/Integrator1'
  boolean_T Integrator1_CSTATE_n;      // '<S49>/Integrator1'
  boolean_T Integrator1_CSTATE_b;      // '<S60>/Integrator1'
  boolean_T Integrator1_CSTATE_p;      // '<S61>/Integrator1'
  boolean_T Integrator1_CSTATE_pj;     // '<S62>/Integrator1'
  boolean_T Integrator1_CSTATE_n4;     // '<S40>/Integrator1'
  boolean_T Integrator1_CSTATE_d;      // '<S41>/Integrator1'
  boolean_T Integrator1_CSTATE_bd;     // '<S42>/Integrator1'
  boolean_T Integrator1_CSTATE_gk;     // '<S43>/Integrator1'
  boolean_T Integrator1_CSTATE_h;      // '<S44>/Integrator1'
  boolean_T Integrator1_CSTATE_k;      // '<S45>/Integrator1'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_controller_ros_ue_T_ {
  SL_Bus_controller_ros_ue_geometry_msgs_Point Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S98>/Out1'

  SL_Bus_controller_ros_ue_geometry_msgs_Point Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S20>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Point Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                            //  Referenced by: '<S99>/Out1'

  SL_Bus_controller_ros_ue_geometry_msgs_Point Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                   //  Referenced by: '<S21>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                     //  Referenced by: '<S1>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                                     //  Referenced by: '<S2>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                     //  Referenced by: '<S3>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                              //  Referenced by: '<S94>/Out1'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                     //  Referenced by: '<S16>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                              //  Referenced by: '<S95>/Out1'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                     //  Referenced by: '<S17>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                              //  Referenced by: '<S96>/Out1'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                     //  Referenced by: '<S18>/Constant'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                                              //  Referenced by: '<S97>/Out1'

  SL_Bus_controller_ros_ue_geometry_msgs_Vector3 Constant_Value_cf;// Computed Parameter: Constant_Value_cf
                                                                      //  Referenced by: '<S19>/Constant'

  SL_Bus_controller_ros_ue_std_msgs_Float32 Constant_Value_cn;// Computed Parameter: Constant_Value_cn
                                                                 //  Referenced by: '<S4>/Constant'

  SL_Bus_controller_ros_ue_std_msgs_Float32 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                //  Referenced by: '<S5>/Constant'

  SL_Bus_controller_ros_ue_std_msgs_Float32 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                //  Referenced by: '<S6>/Constant'

  real_T drone1_x_Value;               // Expression: 0.6737
                                          //  Referenced by: '<S22>/drone1_x'

  real_T drone1_y_Value;               // Expression: 0
                                          //  Referenced by: '<S22>/drone1_y'

  real_T drone1_z_Value;               // Expression: -0.12468
                                          //  Referenced by: '<S22>/drone1_z'

  real_T drone2_x_Value;               // Expression: -0.3368
                                          //  Referenced by: '<S22>/drone2_x'

  real_T drone2_y_Value;               // Expression: 0.5834
                                          //  Referenced by: '<S22>/drone2_y'

  real_T drone2_z_Value;               // Expression: -0.12468
                                          //  Referenced by: '<S22>/drone2_z'

  real_T drone3_x_Value;               // Expression: -0.3368
                                          //  Referenced by: '<S22>/drone3_x'

  real_T drone3_y_Value;               // Expression: -0.5834
                                          //  Referenced by: '<S22>/drone3_y'

  real_T drone3_z_Value;               // Expression: -0.12468
                                          //  Referenced by: '<S22>/drone3_z'

  real_T Integrator_IC;                // Expression: 0
                                          //  Referenced by: '<S43>/Integrator'

  real_T Integrator_IC_b;              // Expression: 0
                                          //  Referenced by: '<S44>/Integrator'

  real_T Integrator_IC_a;              // Expression: 0
                                          //  Referenced by: '<S45>/Integrator'

  real_T tool_x_Value;                 // Expression: 0
                                          //  Referenced by: '<S22>/tool_x'

  real_T tool_y_Value;                 // Expression: 0
                                          //  Referenced by: '<S22>/tool_y'

  real_T tool_z_Value;                 // Expression: 0
                                          //  Referenced by: '<S22>/tool_z'

  real_T Integrator_IC_c;              // Expression: 0
                                          //  Referenced by: '<S47>/Integrator'

  real_T Integrator_IC_g;              // Expression: 0
                                          //  Referenced by: '<S49>/Integrator'

  real_T Integrator_IC_j;              // Expression: 0
                                          //  Referenced by: '<S48>/Integrator'

  real_T Integrator_IC_k;              // Expression: 0
                                          //  Referenced by: '<S60>/Integrator'

  real_T Integrator_IC_m;              // Expression: 0
                                          //  Referenced by: '<S61>/Integrator'

  real_T Integrator_IC_gr;             // Expression: 0
                                          //  Referenced by: '<S62>/Integrator'

  real_T kp_x_Value;                   // Expression: 5
                                          //  Referenced by: '<S31>/kp_x'

  real_T kp_y_Value;                   // Expression: 5
                                          //  Referenced by: '<S31>/kp_y'

  real_T kp_z_Value;                   // Expression: 5
                                          //  Referenced by: '<S31>/kp_z'

  real_T center_mass_Value;            // Expression: 2.0
                                          //  Referenced by: '<S23>/center_mass'

  real_T drone1_mass_Value;            // Expression: 1.5
                                          //  Referenced by: '<S23>/drone1_mass'

  real_T drone2_mass_Value;            // Expression: 1.5
                                          //  Referenced by: '<S23>/drone2_mass'

  real_T drone3_mass_Value;            // Expression: 1.5
                                          //  Referenced by: '<S23>/drone3_mass'

  real_T kd_x_Value;                   // Expression: 15
                                          //  Referenced by: '<S28>/kd_x'

  real_T kd_y_Value;                   // Expression: 15
                                          //  Referenced by: '<S28>/kd_y'

  real_T kd_z_Value;                   // Expression: 15
                                          //  Referenced by: '<S28>/kd_z'

  real_T Integrator_IC_n;              // Expression: 0
                                          //  Referenced by: '<S33>/Integrator'

  real_T Integrator1_IC;               // Expression: 0
                                          //  Referenced by: '<S33>/Integrator1'

  real_T Integrator2_IC;               // Expression: 0
                                          //  Referenced by: '<S33>/Integrator2'

  real_T ki_x_Value;                   // Expression: 2
                                          //  Referenced by: '<S28>/ki_x'

  real_T ki_y_Value;                   // Expression: 2
                                          //  Referenced by: '<S28>/ki_y'

  real_T ki_z_Value;                   // Expression: 2
                                          //  Referenced by: '<S28>/ki_z'

  real_T Integrator_IC_aa;             // Expression: 0
                                          //  Referenced by: '<S40>/Integrator'

  real_T Integrator_IC_d;              // Expression: 0
                                          //  Referenced by: '<S41>/Integrator'

  real_T Integrator_IC_at;             // Expression: 0
                                          //  Referenced by: '<S42>/Integrator'

  real_T kp_phi_Value;                 // Expression: 3
                                          //  Referenced by: '<S31>/kp_phi'

  real_T kp_theta_Value;               // Expression: 3
                                          //  Referenced by: '<S31>/kp_theta'

  real_T kp_psi_Value;                 // Expression: 5
                                          //  Referenced by: '<S31>/kp_psi'

  real_T Ixx_Value;                    // Expression: 0.06250784647
                                          //  Referenced by: '<S92>/Ixx'

  real_T Iyy_Value;                    // Expression: 0.06280979995
                                          //  Referenced by: '<S92>/Iyy'

  real_T Izz_Value;                    // Expression: 0.11503523247
                                          //  Referenced by: '<S92>/Izz'

  real_T kd_phi_Value;                 // Expression: 9
                                          //  Referenced by: '<S29>/kd_phi'

  real_T kd_theta_Value;               // Expression: 9
                                          //  Referenced by: '<S29>/kd_theta'

  real_T kd_psi_Value;                 // Expression: 15
                                          //  Referenced by: '<S29>/kd_psi'

  real_T Integrator_IC_o;              // Expression: 0
                                          //  Referenced by: '<S35>/Integrator'

  real_T Integrator1_IC_c;             // Expression: 0
                                          //  Referenced by: '<S35>/Integrator1'

  real_T Integrator2_IC_e;             // Expression: 0
                                          //  Referenced by: '<S35>/Integrator2'

  real_T ki_phi_Value;                 // Expression: 1.4
                                          //  Referenced by: '<S29>/ki_phi'

  real_T ki_theta_Value;               // Expression: 1.4
                                          //  Referenced by: '<S29>/ki_theta'

  real_T ki_psi_Value;                 // Expression: 2
                                          //  Referenced by: '<S29>/ki_psi'

  real_T Constant_Value_l;             // Expression: 0
                                          //  Referenced by: '<S7>/Constant'

  real_T Constant1_Value;              // Expression: pi*2/3
                                          //  Referenced by: '<S7>/Constant1'

  real_T Constant2_Value;              // Expression: -pi*2/3
                                          //  Referenced by: '<S7>/Constant2'

  real_T Integrator1_IC_m;             // Expression: 0
                                          //  Referenced by: '<S47>/Integrator1'

  real_T omega_phi_Value;              // Expression: 8
                                          //  Referenced by: '<S47>/omega_phi'

  real_T epsilon_phi_Value;            // Expression: 1.414
                                          //  Referenced by: '<S47>/epsilon_phi'

  real_T Integrator1_IC_b;             // Expression: 0
                                          //  Referenced by: '<S48>/Integrator1'

  real_T omega_psi_Value;              // Expression: 10
                                          //  Referenced by: '<S48>/omega_psi'

  real_T epsilon_psi_Value;            // Expression: 1.414
                                          //  Referenced by: '<S48>/epsilon_psi'

  real_T Integrator1_IC_e;             // Expression: 0
                                          //  Referenced by: '<S49>/Integrator1'

  real_T omega_theta_Value;            // Expression: 6.9
                                          //  Referenced by: '<S49>/omega_theta'

  real_T epsilon_theta_Value;          // Expression: 1.414
                                          //  Referenced by: '<S49>/epsilon_theta'

  real_T Integrator1_IC_a;             // Expression: 0
                                          //  Referenced by: '<S60>/Integrator1'

  real_T omega_x_Value;                // Expression: 5
                                          //  Referenced by: '<S60>/omega_x'

  real_T epsilon_x_Value;              // Expression: 1.414
                                          //  Referenced by: '<S60>/epsilon_x'

  real_T Integrator1_IC_p;             // Expression: 0
                                          //  Referenced by: '<S61>/Integrator1'

  real_T omega_y_Value;                // Expression: 8
                                          //  Referenced by: '<S61>/omega_y'

  real_T epsilon_y_Value;              // Expression: 1.414
                                          //  Referenced by: '<S61>/epsilon_y'

  real_T Integrator1_IC_h;             // Expression: 0
                                          //  Referenced by: '<S62>/Integrator1'

  real_T omega_z_Value;                // Expression: 5
                                          //  Referenced by: '<S62>/omega_z'

  real_T epsilon_z_Value;              // Expression: 1.414
                                          //  Referenced by: '<S62>/epsilon_z'

  real_T Integrator1_IC_g;             // Expression: 0
                                          //  Referenced by: '<S40>/Integrator1'

  real_T omega_p_Value;                // Expression: 24
                                          //  Referenced by: '<S40>/omega_p'

  real_T epsilon_p_Value;              // Expression: 1.414
                                          //  Referenced by: '<S40>/epsilon_p'

  real_T Integrator1_IC_ck;            // Expression: 0
                                          //  Referenced by: '<S41>/Integrator1'

  real_T omega_q_Value;                // Expression: 20
                                          //  Referenced by: '<S41>/omega_q'

  real_T epsilon_q_Value;              // Expression: 1.414
                                          //  Referenced by: '<S41>/epsilon_q'

  real_T Integrator1_IC_bq;            // Expression: 0
                                          //  Referenced by: '<S42>/Integrator1'

  real_T omega_r_Value;                // Expression: 20
                                          //  Referenced by: '<S42>/omega_r'

  real_T epsilon_r_Value;              // Expression: 1.414
                                          //  Referenced by: '<S42>/epsilon_r'

  real_T Integrator1_IC_ph;            // Expression: 0
                                          //  Referenced by: '<S43>/Integrator1'

  real_T omega_u_Value;                // Expression: 15
                                          //  Referenced by: '<S43>/omega_u'

  real_T epsilon_u_Value;              // Expression: 1.414
                                          //  Referenced by: '<S43>/epsilon_u'

  real_T Integrator1_IC_j;             // Expression: 0
                                          //  Referenced by: '<S44>/Integrator1'

  real_T omega_v_Value;                // Expression: 24
                                          //  Referenced by: '<S44>/omega_v'

  real_T epsilon_v_Value;              // Expression: 1.414
                                          //  Referenced by: '<S44>/epsilon_v'

  real_T Integrator1_IC_o;             // Expression: 0
                                          //  Referenced by: '<S45>/Integrator1'

  real_T omega_w_Value;                // Expression: 10
                                          //  Referenced by: '<S45>/omega_w'

  real_T epsilon_w_Value;              // Expression: 1.414
                                          //  Referenced by: '<S45>/epsilon_w'

};

// Real-time Model Data Structure
struct tag_RTM_controller_ros_ue_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_controller_ros_ue_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[30];
  real_T odeF[3][30];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_controller_ros_ue_T controller_ros_ue_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_controller_ros_ue_T controller_ros_ue_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_controller_ros_ue_T controller_ros_ue_X;

// Block states (default storage)
extern struct DW_controller_ros_ue_T controller_ros_ue_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void controller_ros_ue_initialize(void);
  extern void controller_ros_ue_step(void);
  extern void controller_ros_ue_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_controller_ros_ue_T *const controller_ros_ue_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Scope1' : Unused code path elimination
//  Block '<S7>/Scope2' : Unused code path elimination
//  Block '<S7>/Scope4' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'controller_ros_ue'
//  '<S1>'   : 'controller_ros_ue/Blank Message'
//  '<S2>'   : 'controller_ros_ue/Blank Message1'
//  '<S3>'   : 'controller_ros_ue/Blank Message2'
//  '<S4>'   : 'controller_ros_ue/Blank Message3'
//  '<S5>'   : 'controller_ros_ue/Blank Message4'
//  '<S6>'   : 'controller_ros_ue/Blank Message6'
//  '<S7>'   : 'controller_ros_ue/Control Allocarion'
//  '<S8>'   : 'controller_ros_ue/Controller'
//  '<S9>'   : 'controller_ros_ue/J'
//  '<S10>'  : 'controller_ros_ue/Publish'
//  '<S11>'  : 'controller_ros_ue/Publish1'
//  '<S12>'  : 'controller_ros_ue/Publish2'
//  '<S13>'  : 'controller_ros_ue/Publish3'
//  '<S14>'  : 'controller_ros_ue/Publish4'
//  '<S15>'  : 'controller_ros_ue/Publish5'
//  '<S16>'  : 'controller_ros_ue/Subscribe'
//  '<S17>'  : 'controller_ros_ue/Subscribe1'
//  '<S18>'  : 'controller_ros_ue/Subscribe2'
//  '<S19>'  : 'controller_ros_ue/Subscribe3'
//  '<S20>'  : 'controller_ros_ue/Subscribe4'
//  '<S21>'  : 'controller_ros_ue/Subscribe5'
//  '<S22>'  : 'controller_ros_ue/X_0'
//  '<S23>'  : 'controller_ros_ue/mass'
//  '<S24>'  : 'controller_ros_ue/Control Allocarion/MATLAB Function'
//  '<S25>'  : 'controller_ros_ue/Control Allocarion/MATLAB Function1'
//  '<S26>'  : 'controller_ros_ue/Control Allocarion/MATLAB Function2'
//  '<S27>'  : 'controller_ros_ue/Control Allocarion/MATLAB Function3'
//  '<S28>'  : 'controller_ros_ue/Controller/calc_Thrusts'
//  '<S29>'  : 'controller_ros_ue/Controller/calc_Torques'
//  '<S30>'  : 'controller_ros_ue/Controller/calc_epsilon_d'
//  '<S31>'  : 'controller_ros_ue/Controller/calc_grad'
//  '<S32>'  : 'controller_ros_ue/Controller/calc_Thrusts/MATLAB Function'
//  '<S33>'  : 'controller_ros_ue/Controller/calc_Thrusts/Subsystem'
//  '<S34>'  : 'controller_ros_ue/Controller/calc_Torques/MATLAB Function'
//  '<S35>'  : 'controller_ros_ue/Controller/calc_Torques/Subsystem'
//  '<S36>'  : 'controller_ros_ue/Controller/calc_epsilon_d/MATLAB Function'
//  '<S37>'  : 'controller_ros_ue/Controller/calc_epsilon_d/MATLAB Function1'
//  '<S38>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse'
//  '<S39>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse'
//  '<S40>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator p'
//  '<S41>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator q'
//  '<S42>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator r'
//  '<S43>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator u'
//  '<S44>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator v'
//  '<S45>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator w'
//  '<S46>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/MATLAB Function'
//  '<S47>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator phi'
//  '<S48>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator psi'
//  '<S49>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator theta'
//  '<S50>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator phi/MATLAB Function1'
//  '<S51>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator phi/MATLAB Function2'
//  '<S52>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator phi/MATLAB Function3'
//  '<S53>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator psi/MATLAB Function1'
//  '<S54>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator psi/MATLAB Function2'
//  '<S55>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator psi/MATLAB Function3'
//  '<S56>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator theta/MATLAB Function1'
//  '<S57>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator theta/MATLAB Function2'
//  '<S58>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Rotational kinematic inverse/pseudo second order differentiator theta/MATLAB Function3'
//  '<S59>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/MATLAB Function'
//  '<S60>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator x'
//  '<S61>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator y'
//  '<S62>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator z'
//  '<S63>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator x/MATLAB Function1'
//  '<S64>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator x/MATLAB Function2'
//  '<S65>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator x/MATLAB Function3'
//  '<S66>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator y/MATLAB Function1'
//  '<S67>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator y/MATLAB Function2'
//  '<S68>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator y/MATLAB Function3'
//  '<S69>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator z/MATLAB Function1'
//  '<S70>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator z/MATLAB Function2'
//  '<S71>'  : 'controller_ros_ue/Controller/calc_epsilon_d/Translational kinematic inverse/pseudo second order differentiator z/MATLAB Function3'
//  '<S72>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator p/MATLAB Function1'
//  '<S73>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator p/MATLAB Function2'
//  '<S74>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator p/MATLAB Function3'
//  '<S75>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator q/MATLAB Function1'
//  '<S76>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator q/MATLAB Function2'
//  '<S77>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator q/MATLAB Function3'
//  '<S78>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator r/MATLAB Function1'
//  '<S79>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator r/MATLAB Function2'
//  '<S80>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator r/MATLAB Function3'
//  '<S81>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator u/MATLAB Function1'
//  '<S82>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator u/MATLAB Function2'
//  '<S83>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator u/MATLAB Function3'
//  '<S84>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator v/MATLAB Function1'
//  '<S85>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator v/MATLAB Function2'
//  '<S86>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator v/MATLAB Function3'
//  '<S87>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator w/MATLAB Function1'
//  '<S88>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator w/MATLAB Function2'
//  '<S89>'  : 'controller_ros_ue/Controller/calc_epsilon_d/pseudo second order differentiator w/MATLAB Function3'
//  '<S90>'  : 'controller_ros_ue/Controller/calc_grad/MATLAB Function1'
//  '<S91>'  : 'controller_ros_ue/Controller/calc_grad/MATLAB Function2'
//  '<S92>'  : 'controller_ros_ue/J/J'
//  '<S93>'  : 'controller_ros_ue/J/calc_J_sys'
//  '<S94>'  : 'controller_ros_ue/Subscribe/Enabled Subsystem'
//  '<S95>'  : 'controller_ros_ue/Subscribe1/Enabled Subsystem'
//  '<S96>'  : 'controller_ros_ue/Subscribe2/Enabled Subsystem'
//  '<S97>'  : 'controller_ros_ue/Subscribe3/Enabled Subsystem'
//  '<S98>'  : 'controller_ros_ue/Subscribe4/Enabled Subsystem'
//  '<S99>'  : 'controller_ros_ue/Subscribe5/Enabled Subsystem'

#endif                                 // RTW_HEADER_controller_ros_ue_h_

//
// File trailer for generated code.
//
// [EOF]
//
