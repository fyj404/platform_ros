#include "ros/ros.h"
#include "std_msgs/String.h"

#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Vector3.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>
#include <vector>
#include<queue>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

ros::Publisher camPub[10];
ros::Subscriber camSub[10];
int flag = 0;
int cnt[10];
//double timeD[20]={0,0.1024,0.1024,0.1024,0.1024,0.1024,0.1024,0.1024,0.1024};

void cam_sol_idx(const sensor_msgs::Image::ConstPtr &msg,int idx)
{
  cnt[idx]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub[idx].publish(data);
}

int main(int argc, char **argv)
{

  double imageHz=20;
  ros::init(argc, argv, "ue_read_cam");
  
  ros::NodeHandle nh;
  for(int i=1;i<=6;i++){
    char s[20];
    sprintf(s,"cam%d",i);
    camPub[i]=nh.advertise<sensor_msgs::Image>(s, imageHz);
  }
  
  for(int i=1;i<=6;i++){
    char s[50];
    sprintf(s,"/camera%d/image",i);
    camSub[i]=nh.subscribe<sensor_msgs::Image>(std::string(s), imageHz, boost::bind(&cam_sol_idx,_1,i));
  }
  ros::spin();
  
  return 0;
}