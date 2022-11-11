#include "ros/ros.h"
#include "std_msgs/String.h"
#include <time.h>
#include <iostream>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Vector3.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>
#include <vector>
#include <queue>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <iostream>
#include <fstream>
#include<boost/bind.hpp>
double deltaTimeOme = 160;
std::queue<sensor_msgs::Imu> q;
std::queue<geometry_msgs::PointStamped> q2;

std::queue<sensor_msgs::Image> qc1;
std::queue<sensor_msgs::Image> qc2;
void euler_sol_1(const sensor_msgs::Imu::ConstPtr &msg)
{
  q.push(*msg);
}
void pos_sol_1(const geometry_msgs::PointStamped::ConstPtr &msg)
{
  q2.push(*msg);
}
int main(int argc, char **argv)
{
  srand((unsigned int)time(NULL));
  ros::init(argc, argv, "ueCheckNode");
  
  ros::NodeHandle nh;

  ros::Subscriber euler_sub_1 = nh.subscribe("imu1", deltaTimeOme, euler_sol_1);
  ros::Subscriber pos_sub_1 = nh.subscribe("/position_404_0", deltaTimeOme, pos_sol_1);
  //ros::Subscriber cam_sub_1 = nh.subscribe("/position_1", deltaTimeOme, pos_sol_1);
  ros::Rate loop_rate(deltaTimeOme);
  int count = 0;
  ros::spinOnce();
  while (ros::ok())
  {
    if (q.empty() == false && q2.empty() == false)
    {
      sensor_msgs ::Imu m_imu = q.front();
      geometry_msgs::PointStamped m_pos = q2.front();
      std::ofstream foutC("/home/f404/std.txt", std::ios::app);
      foutC.setf(std::ios::fixed, std::ios::floatfield);
      // 保存结果的精度
      foutC.precision(0);
      foutC << m_imu.header.stamp.toSec() * 1e9 << " ";
      foutC.precision(5);
      foutC << m_pos.point.x << " "
            << m_pos.point.y << " "  
            << m_pos.point.z << " "
            << m_imu.orientation.w << " "
            << m_imu.orientation.x << " "
            << m_imu.orientation.y << " "
            << m_imu.orientation.z << std::endl;
      q.pop();
      q2.pop();
    }
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
