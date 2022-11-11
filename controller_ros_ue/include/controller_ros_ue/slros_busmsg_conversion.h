#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Float32.h>
#include "controller_ros_ue_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_controller_ros_ue_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_controller_ros_ue_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_controller_ros_ue_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_controller_ros_ue_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(std_msgs::Float32* msgPtr, SL_Bus_controller_ros_ue_std_msgs_Float32 const* busPtr);
void convertToBus(SL_Bus_controller_ros_ue_std_msgs_Float32* busPtr, std_msgs::Float32 const* msgPtr);


#endif
