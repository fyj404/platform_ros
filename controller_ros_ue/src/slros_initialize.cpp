#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "controller_ros_ue";

// For Block controller_ros_ue/Subscribe
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_222;

// For Block controller_ros_ue/Subscribe1
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_225;

// For Block controller_ros_ue/Subscribe2
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_229;

// For Block controller_ros_ue/Subscribe3
SimulinkSubscriber<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Sub_controller_ros_ue_232;

// For Block controller_ros_ue/Subscribe4
SimulinkSubscriber<geometry_msgs::Point, SL_Bus_controller_ros_ue_geometry_msgs_Point> Sub_controller_ros_ue_235;

// For Block controller_ros_ue/Subscribe5
SimulinkSubscriber<geometry_msgs::Point, SL_Bus_controller_ros_ue_geometry_msgs_Point> Sub_controller_ros_ue_238;

// For Block controller_ros_ue/Publish
SimulinkPublisher<std_msgs::Float32, SL_Bus_controller_ros_ue_std_msgs_Float32> Pub_controller_ros_ue_265;

// For Block controller_ros_ue/Publish1
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Pub_controller_ros_ue_266;

// For Block controller_ros_ue/Publish2
SimulinkPublisher<std_msgs::Float32, SL_Bus_controller_ros_ue_std_msgs_Float32> Pub_controller_ros_ue_267;

// For Block controller_ros_ue/Publish3
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Pub_controller_ros_ue_268;

// For Block controller_ros_ue/Publish4
SimulinkPublisher<std_msgs::Float32, SL_Bus_controller_ros_ue_std_msgs_Float32> Pub_controller_ros_ue_269;

// For Block controller_ros_ue/Publish5
SimulinkPublisher<geometry_msgs::Vector3, SL_Bus_controller_ros_ue_geometry_msgs_Vector3> Pub_controller_ros_ue_270;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

