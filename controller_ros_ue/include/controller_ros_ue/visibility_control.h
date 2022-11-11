#ifndef CONTROLLER_ROS_UE__VISIBILITY_CONTROL_H_
#define CONTROLLER_ROS_UE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CONTROLLER_ROS_UE_EXPORT __attribute__ ((dllexport))
    #define CONTROLLER_ROS_UE_IMPORT __attribute__ ((dllimport))
  #else
    #define CONTROLLER_ROS_UE_EXPORT __declspec(dllexport)
    #define CONTROLLER_ROS_UE_IMPORT __declspec(dllimport)
  #endif
  #ifdef CONTROLLER_ROS_UE_BUILDING_LIBRARY
    #define CONTROLLER_ROS_UE_PUBLIC CONTROLLER_ROS_UE_EXPORT
  #else
    #define CONTROLLER_ROS_UE_PUBLIC CONTROLLER_ROS_UE_IMPORT
  #endif
  #define CONTROLLER_ROS_UE_PUBLIC_TYPE CONTROLLER_ROS_UE_PUBLIC
  #define CONTROLLER_ROS_UE_LOCAL
#else
  #define CONTROLLER_ROS_UE_EXPORT __attribute__ ((visibility("default")))
  #define CONTROLLER_ROS_UE_IMPORT
  #if __GNUC__ >= 4
    #define CONTROLLER_ROS_UE_PUBLIC __attribute__ ((visibility("default")))
    #define CONTROLLER_ROS_UE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CONTROLLER_ROS_UE_PUBLIC
    #define CONTROLLER_ROS_UE_LOCAL
  #endif
  #define CONTROLLER_ROS_UE_PUBLIC_TYPE
#endif
#endif  // CONTROLLER_ROS_UE__VISIBILITY_CONTROL_H_
// Generated 23-Aug-2022 08:05:38
// Copyright 2019-2020 The MathWorks, Inc.
