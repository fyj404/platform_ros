#include "ros/ros.h"
#include "std_msgs/String.h"
#include <time.h>
#include<iostream>
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
#include<cmath>




tf2::Quaternion myQuaternion;
ros::Publisher imu[10];
ros::Subscriber eulerSub[10];
ros::Publisher chatter_pub[10];
ros::Subscriber pos_sub[10];
int flag[10];
struct Ori
{
  ros::Time time;
  geometry_msgs::Quaternion orientation;
  geometry_msgs::Vector3 angular_velocity;
} ;
std::queue<Ori> qw[10];
std::queue<geometry_msgs::Vector3>qa[10];
double acc_bias[10][3];
double lastEuler[5][5];
double gyr_bias[10][3];
double lastVel[5][5];
double lastPos[5][5];
ros::Time ct[10];
double deltaTimeOme=160;
double deltaTimeVel=1.00/0.00520;
unsigned int seed = 0;
double vrw=0.002;
double vrn=1.2e-5;
double arw=8.7e-5;
double arn=9.9e-7;

//double M_PI=3.1415926;
double GuassianKernel(double mu, double sigma)
{
  double U1 = static_cast<double>(rand_r(&seed)) / static_cast<double>(RAND_MAX);
  double U2 = static_cast<double>(rand_r(&seed)) / static_cast<double>(RAND_MAX);
  double Z0 = sqrt(-2.0 * ::log(U1)) * cos(2.0*M_PI * U2);
  // scaling
  Z0 = sigma * Z0 + mu;
  return Z0;
}
double getNumber(double x)
{
    double res=GuassianKernel(0,x);
    return res;
}



void euler_sol_idx(const geometry_msgs::PointStamped::ConstPtr &msg,int idx)
{
  double nowdata[3] = {msg->point.x, msg->point.y, msg->point.z};
  double delta[3] = {0, 0, 0};

  if (flag[idx] == 0)
  {
    flag[idx] = 1;
    deltaTimeOme=160;
    ct[idx]=ros::Time::now();
  }
  else
  {
    deltaTimeOme=1.00/(msg->header.stamp.toSec()-ct[idx].toSec());
    ct[idx] = msg->header.stamp;
    for (int i = 0; i < 3; i++)delta[i] = (nowdata[i] - lastEuler[idx][i])*deltaTimeOme;
  }
  for (int i = 0; i < 3; i++)lastEuler[idx][i] = nowdata[i];
  double sqrt_dt=sqrt(std::max(1.00/deltaTimeOme,0.005));
  double sigma_arw=arw/sqrt_dt;
  for(int i=0;i<3;i++){
    delta[i]+=getNumber(1)*sigma_arw+gyr_bias[idx][i];
  }
  double sigma_bias=arn*sqrt_dt;
  for(int i=0;i<3;i++){
    gyr_bias[idx][i]+=getNumber(1)*sigma_bias;
  }
  ROS_INFO("gyr bias: %f, %f, %f", gyr_bias[idx][0], gyr_bias[idx][1], gyr_bias[idx][2]);
  geometry_msgs::Vector3 tmp;
  tmp.x = delta[0];
  tmp.y = delta[1];
  tmp.z = delta[2];
  Ori msgPub;
  msgPub.angular_velocity = tmp;
  msgPub.time=ros::Time::now();
  tf2::Quaternion myQuaternion;
  myQuaternion.setRPY(nowdata[0], nowdata[1], nowdata[2]);
  geometry_msgs::Quaternion quat_msg;
  quat_msg = tf2::toMsg(myQuaternion);
  msgPub.orientation=quat_msg;
  qw[idx].push(msgPub);
}

void euler_sol_idx_copy(const geometry_msgs::Vector3::ConstPtr &msg,int idx)
{
  double nowdata[3] = {msg->x, msg->y, msg->z};
  double delta[3] = {0, 0, 0};

  if (flag[idx] == 0)
  {
    flag[idx] = 1;
    deltaTimeOme=160;
    ct[idx]=ros::Time::now();
  }
  else
  {
    deltaTimeOme=1.00/(ros::Time::now().toSec()-ct[idx].toSec());
    for (int i = 0; i < 3; i++)delta[i] = (nowdata[i] - lastEuler[idx][i])*deltaTimeOme;
  }
  for (int i = 0; i < 3; i++)lastEuler[idx][i] = nowdata[i];
  double sqrt_dt=sqrt(1.00/deltaTimeOme);
  double sigma_arw=arw/sqrt_dt;
  for(int i=0;i<3;i++){
    delta[i]+=getNumber(1)*sigma_arw+gyr_bias[idx][i];
  }
  double sigma_bias=arn*sqrt_dt;
  for(int i=0;i<3;i++){
    gyr_bias[idx][i]+=getNumber(1)*sigma_bias;
  }
  geometry_msgs::Vector3 tmp;
  tmp.x = delta[0];
  tmp.y = delta[1];
  tmp.z = delta[2];
  Ori msgPub;
  msgPub.angular_velocity = tmp;
  msgPub.time=ros::Time::now();
  tf2::Quaternion myQuaternion;
  myQuaternion.setRPY(nowdata[0], nowdata[1], nowdata[2]);
  geometry_msgs::Quaternion quat_msg;
  quat_msg = tf2::toMsg(myQuaternion);
  msgPub.orientation=quat_msg;
  qw[idx].push(msgPub);
}


void pos_sol_idx(const geometry_msgs::PointStamped::ConstPtr &msg,int idx)
{
  if(flag[3+idx]==0)
  {
    flag[idx+3] = 1;
    deltaTimeOme=160;
    ct[idx+3]=ros::Time::now();
  }
  else{
    deltaTimeOme=1.00/(msg->header.stamp.toSec()-ct[idx].toSec());
    ct[idx] = msg->header.stamp;
  }
  double delta[3] = {msg->point.x, msg->point.y, msg->point.z};
  double sqrt_dt=sqrt(std::max(1.00/deltaTimeOme,0.005));
  double sigma_vrw=vrw/sqrt_dt;
  for(int i=0;i<3;i++){
    delta[i]+=getNumber(1)*sigma_vrw+acc_bias[idx][i];
  }
  double sigma_bias=vrn/sqrt_dt;
  for(int i=0;i<3;i++){
    acc_bias[idx][i]+=getNumber(1)*sigma_bias;
  }
  ROS_INFO("acc bias: %f, %f, %f", acc_bias[idx][0], acc_bias[idx][1],acc_bias[idx][2]);
  geometry_msgs::Vector3 linear_acceleration;
  linear_acceleration.x=delta[0];
  linear_acceleration.y=delta[1];
  linear_acceleration.z=delta[2];
  qa[idx].push(linear_acceleration);
}
int main(int argc, char **argv)
{
  srand((unsigned int)time(NULL));
  ros::init(argc, argv, "ue_read_node");
  
  ros::NodeHandle nh;
  for(int i=0;i<9;i++)ct[i]=ros::Time::now();
  for(int i=1;i<=3;i++){
    char s[30];
    sprintf(s,"euler_angle404_%d",i);
    eulerSub[i]=nh.subscribe<geometry_msgs::PointStamped>(std::string(s), 160, boost::bind(&euler_sol_idx,_1,i));
    sprintf(s,"imu%d",i);
    chatter_pub[i] = nh.advertise<sensor_msgs::Imu>(std::string(s), deltaTimeOme);
  }

  
  for(int i=1;i<=1;i++)
  {
    pos_sub[i] = nh.subscribe<geometry_msgs::PointStamped>("/acceleration404", deltaTimeOme, boost::bind(&pos_sol_idx,_1,i) );
  }
  
  ros::Rate loop_rate(deltaTimeOme*10);
  ros::spinOnce();
  ros::Time tomorrow = ros::Time::now();
  while (ros::ok())
  {
    for(int i=1;i<=3;i++)
    {
        sensor_msgs::Imu msg;
        if(qw[i].empty()==false&&qa[i].empty()==false)
        {
            geometry_msgs::Quaternion orientation=qw[i].front().orientation;
            geometry_msgs::Vector3 angular_velocity=qw[i].front().angular_velocity;
            geometry_msgs::Vector3 linear_acceleration=qa[i].front();
            msg.orientation=orientation;
            msg.angular_velocity=angular_velocity;
            msg.linear_acceleration=linear_acceleration;
            msg.header.stamp=qw[i].front().time;
            chatter_pub[i].publish(msg);
            qw[i].pop();
            qa[i].pop();
        }
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  
  

  return 0;
}


/*
ros::Subscriber euler_sub_2 = nh.subscribe("euler_angle_2", deltaTimeOme, euler_sol_2);
  ros::Subscriber euler_sub_3 = nh.subscribe("euler_angle_3", deltaTimeOme, euler_sol_3);
void euler_sol_1(const geometry_msgs::Vector3::ConstPtr &msg)
{
  
  double nowdata[3] = {msg->x, msg->y, msg->z};
  double delta[3] = {0, 0, 0};
  if (flag[1] == 0)
  {
    flag[1] = 1;
    deltaTimeOme=160;
    ct[1]=ros::Time::now();
  }
  else
  {
    deltaTimeOme=1.00/(ros::Time::now().toSec()-ct[1].toSec());
    for (int i = 0; i < 3; i++)
      delta[i] = (nowdata[i] - lastEuler[1][i])*deltaTimeOme;
    for(int i=0;i<3;i++){

      if(delta[i]>50 || delta[i]<-50){
        ROS_INFO("I heard: [%lf  %lf %lf  %lf %lf %lf]", msg->x, msg->y, msg->z,delta[0],delta[1],delta[2]);
      }
    }
  }
  for (int i = 0; i < 3; i++)
    lastEuler[1][i] = nowdata[i];
  double sqrt_dt=sqrt(1.00/deltaTimeOme);
  double sigma_arw=arw/sqrt_dt;
  for(int i=0;i<3;i++){
    delta[i]+=getNumber(1)*sigma_arw+gyr_bias[i];
  }
  double sigma_bias=arn*sqrt_dt;
  for(int i=0;i<3;i++){
    gyr_bias[i]+=getNumber(1)*sigma_bias;
  }
  geometry_msgs::Vector3 tmp;
  tmp.x = delta[0];
  tmp.y = delta[1];
  tmp.z = delta[2];
  Ori msgPub;
  msgPub.time.data=ros::Time::now();
  msgPub.angular_velocity = tmp;
  tf2::Quaternion myQuaternion;
  myQuaternion.setRPY(nowdata[0], nowdata[1], nowdata[2]);
  geometry_msgs::Quaternion quat_msg;
  quat_msg = tf2::toMsg(myQuaternion);
  msgPub.orientation=quat_msg;
  q[0].push(msgPub);
  //imu1.publish(tmp);
}

void euler_sol_2(const geometry_msgs::Vector3::ConstPtr &msg)
{
  double nowdata[3] = {msg->x, msg->y, msg->z};
  double delta[3] = {0, 0, 0};

  if (flag[2] == 0)
  {
    flag[2] = 1;
    deltaTimeOme=160;
    ct[2]=ros::Time::now();
  }
  else
  {
    deltaTimeOme=1.00/(ros::Time::now().toSec()-ct[2].toSec());
    for (int i = 0; i < 3; i++)
     delta[i] = (nowdata[i] - lastEuler[2][i])*deltaTimeOme;
  }
  for (int i = 0; i < 3; i++)
    lastEuler[2][i] = nowdata[i];
  geometry_msgs::Vector3 tmp;
  tmp.x = delta[0];
  tmp.y = delta[1];
  tmp.z = delta[2];
  Ori msgPub;
  msgPub.time.data=ros::Time::now();
  msgPub.angular_velocity = tmp;
  tf2::Quaternion myQuaternion;
  myQuaternion.setRPY(nowdata[0], nowdata[1], nowdata[2]);
  geometry_msgs::Quaternion quat_msg;
  quat_msg = tf2::toMsg(myQuaternion);
  msgPub.orientation=quat_msg;
  q[1].push(msgPub);
  imu2.publish(tmp);
}
void euler_sol_3(const geometry_msgs::Vector3::ConstPtr &msg)
{
  double nowdata[3] = {msg->x, msg->y, msg->z};
  double delta[3] = {0, 0, 0};

  if (flag[3] == 0)
  {
    flag[3] = 1;
    deltaTimeOme=160;
    ct[3]=ros::Time::now();
  }
  else
  {
    deltaTimeOme=1.00/(ros::Time::now().toSec()-ct[2].toSec());
    for (int i = 0; i < 3; i++)
      delta[i] = (nowdata[i] - lastEuler[3][i])*deltaTimeOme;
  }
  for (int i = 0; i < 3; i++)
    lastEuler[3][i] = nowdata[i];
  geometry_msgs::Vector3 tmp;
  tmp.x = delta[0];
  tmp.y = delta[1];
  tmp.z = delta[2];
  Ori msgPub;
  msgPub.angular_velocity = tmp;
  msgPub.time.data=ros::Time::now();
  tf2::Quaternion myQuaternion;
  myQuaternion.setRPY(nowdata[0], nowdata[1], nowdata[2]);
  geometry_msgs::Quaternion quat_msg;
  quat_msg = tf2::toMsg(myQuaternion);
  msgPub.orientation=quat_msg;
  q[2].push(msgPub);
  imu3.publish(tmp);
}

void pos_sol_1(const geometry_msgs::Vector3::ConstPtr &msg)
{
  double delta[3] = {msg->x, msg->y, msg->z};
  double sqrt_dt=sqrt(1.00/deltaTimeOme);
  double sigma_vrw=vrw/sqrt_dt;
  for(int i=0;i<3;i++){
    delta[i]+=getNumber(1)*sigma_vrw+acc_bias[i];
  }
  double sigma_bias=vrn/sqrt_dt;
  for(int i=0;i<3;i++){
    acc_bias[i]+=getNumber(1)*sigma_bias;
  }
  geometry_msgs::Vector3 linear_acceleration;
  linear_acceleration.x=delta[0];
  linear_acceleration.y=delta[1];
  linear_acceleration.z=delta[2];
  qa[0].push(linear_acceleration);
}*/
