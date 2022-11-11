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
  ros::init(argc, argv, "ueReadCam");
  
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



/*
camPub_1=nh.advertise<sensor_msgs::Image>("cam1", imageHz);
  camPub_2=nh.advertise<sensor_msgs::Image>("cam2", imageHz);
  camPub_3=nh.advertise<sensor_msgs::Image>("cam3", imageHz);
  camPub_4=nh.advertise<sensor_msgs::Image>("cam4", imageHz);
  camPub_5=nh.advertise<sensor_msgs::Image>("cam5", imageHz);
  camPub_6=nh.advertise<sensor_msgs::Image>("cam6", imageHz);
  ros::Subscriber cam_1 = nh.subscribe("/camera1/image", imageHz, cam_sol_1);
  ros::Subscriber cam_2 = nh.subscribe("/camera2/image", imageHz, cam_sol_2);
  ros::Subscriber cam_3 = nh.subscribe("/camera3/image", imageHz, cam_sol_3);
  ros::Subscriber cam_4 = nh.subscribe("/camera4/image", imageHz, cam_sol_4);
  ros::Subscriber cam_5 = nh.subscribe("/camera5/image", imageHz, cam_sol_5);
  ros::Subscriber cam_6 = nh.subscribe("/camera6/image", imageHz, cam_sol_6);
void cam_sol_1(const sensor_msgs::Image::ConstPtr &msg)
{
  cnt[1]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub_1.publish(data);
}
void cam_sol_2(const sensor_msgs::Image::ConstPtr &msg)
{
  cnt[2]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub_2.publish(data);
}
void cam_sol_3(const sensor_msgs::Image::ConstPtr &msg)
{
  cnt[3]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub_3.publish(data);
}
void cam_sol_4(const sensor_msgs::Image::ConstPtr &msg)
{
  cnt[4]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub_4.publish(data);
}
void cam_sol_5(const sensor_msgs::Image::ConstPtr &msg)
{
  cnt[5]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub_5.publish(data);
}
void cam_sol_6(const sensor_msgs::Image::ConstPtr &msg)
{
  cnt[6]++;
  sensor_msgs::Image data=*msg;
  data.header.stamp=ros::Time::now();
  camPub_6.publish(data);
}*/
