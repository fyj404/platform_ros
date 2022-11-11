#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "controller_ros_ue_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block controller_ros_ue/Subscribe
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_222;

// For Block controller_ros_ue/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_225;

// For Block controller_ros_ue/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_229;

// For Block controller_ros_ue/Subscribe3
extern SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_232;

// For Block controller_ros_ue/Subscribe4
extern SimulinkSubscriber<geometry_msgs::Point, SL_Bus_controller_ros_ue_geometry_msgs_Point> Sub_controller_ros_ue_235;

// For Block controller_ros_ue/Subscribe5
extern SimulinkSubscriber<geometry_msgs::Point, SL_Bus_controller_ros_ue_geometry_msgs_Point> Sub_controller_ros_ue_238;

// For Block controller_ros_ue/Publish
extern SimulinkPublisher<std_msgs::Float32, SL_Bus_controller_ros_ue_std_msgs_Float32> Pub_controller_ros_ue_265;

// For Block controller_ros_ue/Publish1
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Pub_controller_ros_ue_266;

// For Block controller_ros_ue/Publish2
extern SimulinkPublisher<std_msgs::Float32, SL_Bus_controller_ros_ue_std_msgs_Float32> Pub_controller_ros_ue_267;

// For Block controller_ros_ue/Publish3
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Pub_controller_ros_ue_268;

// For Block controller_ros_ue/Publish4
extern SimulinkPublisher<std_msgs::Float32, SL_Bus_controller_ros_ue_std_msgs_Float32> Pub_controller_ros_ue_269;

// For Block controller_ros_ue/Publish5
extern SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Pub_controller_ros_ue_270;

void slros_node_init(int argc, char** argv);

#endif
