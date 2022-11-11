//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: controller_ros_ue_types.h
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
#ifndef RTW_HEADER_controller_ros_ue_types_h_
#define RTW_HEADER_controller_ros_ue_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_controller_ros_ue_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_controller_ros_ue_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_controller_ros_ue_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_controller_ros_ue_std_msgs_Float32_
#define DEFINED_TYPEDEF_FOR_SL_Bus_controller_ros_ue_std_msgs_Float32_

// MsgType=std_msgs/Float32
struct SL_Bus_controller_ros_ue_std_msgs_Float32
{
  real32_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_controller_ros_ue_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_controller_ros_ue_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_controller_ros_ue_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_controller_ros_ue_T_ P_controller_ros_ue_T;

// Forward declaration for rtModel
typedef struct tag_RTM_controller_ros_ue_T RT_MODEL_controller_ros_ue_T;

#endif                                 // RTW_HEADER_controller_ros_ue_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
