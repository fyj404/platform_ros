// main.cpp
// ROS node
// Du Jianrui   2022.2.8
// a test for UE4 model validation

#include "ros/ros.h"

#include "std_msgs/Float32.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"

#include <cmath>
unsigned int seed = 0;
double GuassianKernel(double mu, double sigma)
{
  double U1 = static_cast<double>(rand_r(&seed)) / static_cast<double>(RAND_MAX);
  double U2 = static_cast<double>(rand_r(&seed)) / static_cast<double>(RAND_MAX);
  double Z0 = sqrt(-2.0 * ::log(U1)) * cos(2.0*M_PI * U2);
  // scaling
  Z0 = sigma * Z0 + mu;
  return Z0;
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_ue");
    ros::NodeHandle nh;

    double rate = 50.0;
    int debug=0;
    ros::Rate loopRate(rate);
    ros::Publisher desiredPositionPublisher = nh.advertise<geometry_msgs::Point>
                                              ("nominal_position", 10);
    ros::Publisher desiredEulerAnglePublisher = nh.advertise<geometry_msgs::Point>
                                                ("nominal_euler_angles", 10);
    
    // defines ROS message variables
    
    geometry_msgs::Point desiredPositionMessage;
    geometry_msgs::Point desiredEulerAngleMessage;

    // defines variables to manipulate
    
    double& positionX = desiredPositionMessage.x;
    double& positionY = desiredPositionMessage.y;
    double& positionZ = desiredPositionMessage.z;
    double& eulerAngleX = desiredEulerAngleMessage.x;
    double& eulerAngleY = desiredEulerAngleMessage.y;
    double& eulerAngleZ = desiredEulerAngleMessage.z;

    
    positionX = 0.0;
    positionY = 0.0;
    positionZ = 0.0;
    eulerAngleX = 0.0;
    eulerAngleY = 0.0;
    eulerAngleZ = 0.0;

    double i = 0;

    for(int k=1;k<=200;k++){
        positionX = 0.00*k;
        positionY = 0.00*k;
        positionZ = -0.005*k;
        desiredPositionPublisher.publish(desiredPositionMessage);
        desiredEulerAnglePublisher.publish(desiredEulerAngleMessage);

        // ROS_INFO("%f  %f  %f", thrust1, thrust2, thrust3);
        ROS_INFO("Desired position: %f, %f, %f", positionX, positionY, positionZ);
        ROS_INFO("Desired Euler angle: %f, %f, %f", eulerAngleX, eulerAngleY, eulerAngleZ);
        ros::spinOnce();
        loopRate.sleep();
    }
    for(int k=1;k<=800;k++){
        int opt=1;
        if((k/100)%2==0)opt*=-1;
        positionX += abs(GuassianKernel(0,0.002))*opt;
        positionY += abs(GuassianKernel(0,0.002))*opt;
        positionZ += abs(GuassianKernel(0,0.002))*opt;
        eulerAngleX+=abs(GuassianKernel(0,0.0015))*opt;
        eulerAngleY+=abs(GuassianKernel(0,0.0015))*opt;
        eulerAngleZ+=abs(GuassianKernel(0,0.0015))*opt;
        desiredPositionPublisher.publish(desiredPositionMessage);
        desiredEulerAnglePublisher.publish(desiredEulerAngleMessage);
        // ROS_INFO("%f  %f  %f", thrust1, thrust2, thrust3);
        ROS_INFO("Desired position: %f, %f, %f", positionX, positionY, positionZ);
        ROS_INFO("Desired Euler angle: %f, %f, %f", eulerAngleX, eulerAngleY, eulerAngleZ);
        ros::spinOnce();
        loopRate.sleep();
    }
    positionX = 0.0;
    positionY = 0.0;
    positionZ = -1.0;
    eulerAngleX = 0.0;
    eulerAngleY = 0.0;
    eulerAngleZ = 0.0;
    desiredPositionPublisher.publish(desiredPositionMessage);
    desiredEulerAnglePublisher.publish(desiredEulerAngleMessage);
    while (ros::ok())
    {
        // thrust1 += 0.015f;
        // thrust2 += 0.0075f;
        // thrust3 += 0.0075f;
        positionX = 0 + 2*std::sin(i * 2 * M_PI);
        positionY = 0 + 2*std::sin(i * 2 * M_PI);
        positionZ = -1;
       
        desiredPositionPublisher.publish(desiredPositionMessage);
        desiredEulerAnglePublisher.publish(desiredEulerAngleMessage);

        // ROS_INFO("%f  %f  %f", thrust1, thrust2, thrust3);
        ROS_INFO("Desired position: %f, %f, %f", positionX, positionY, positionZ);
        ROS_INFO("Desired Euler angle: %f, %f, %f", eulerAngleX, eulerAngleY, eulerAngleZ);
        i += 1.0 / rate * 0.01;

        ros::spinOnce();
        loopRate.sleep();
    }
}
