// main.cpp
// ROS node
// Du Jianrui   2022.2.8
// a test for UE4 model validation

#include "ros/ros.h"

#include "std_msgs/Float32.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"

#include <cmath>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_ue");
    ros::NodeHandle nh;

    double rate = 50.0;
    ros::Rate loopRate(rate);

    // defines publishers
    // ros::Publisher thrustPublisher1 = nh.advertise<std_msgs::Float32>
    //                                   ("thrust1", 10);
    // ros::Publisher thrustPublisher2 = nh.advertise<std_msgs::Float32>
    //                                   ("thrust2", 10);
    // ros::Publisher thrustPublisher3 = nh.advertise<std_msgs::Float32>
    //                                   ("thrust3", 10);
    // ros::Publisher eulerAnglePublisher1 = nh.advertise<geometry_msgs::Vector3>
    //                                       ("euler_angle1", 10);
    // ros::Publisher eulerAnglePublisher2 = nh.advertise<geometry_msgs::Vector3>
    //                                       ("euler_angle2",10);
    // ros::Publisher eulerAnglePublisher3 = nh.advertise<geometry_msgs::Vector3>
    //                                       ("euler_angle3", 10);
    ros::Publisher desiredPositionPublisher = nh.advertise<geometry_msgs::Point>
                                              ("nominal_position", 10);
    ros::Publisher desiredEulerAnglePublisher = nh.advertise<geometry_msgs::Point>
                                                ("nominal_euler_angles", 10);
    
    // defines ROS message variables
    // std_msgs::Float32 thrustMessage1;
    // std_msgs::Float32 thrustMessage2;
    // std_msgs::Float32 thrustMessage3;
    // geometry_msgs::Vector3 eulerAngleMessage1;
    // geometry_msgs::Vector3 eulerAngleMessage2;
    // geometry_msgs::Vector3 eulerAngleMessage3;
    geometry_msgs::Point desiredPositionMessage;
    geometry_msgs::Point desiredEulerAngleMessage;

    // defines variables to manipulate
    // float& thrust1 = thrustMessage1.data;
    // float& thrust2 = thrustMessage2.data;
    // float& thrust3 = thrustMessage3.data;
    double& positionX = desiredPositionMessage.x;
    double& positionY = desiredPositionMessage.y;
    double& positionZ = desiredPositionMessage.z;
    double& eulerAngleX = desiredEulerAngleMessage.x;
    double& eulerAngleY = desiredEulerAngleMessage.y;
    double& eulerAngleZ = desiredEulerAngleMessage.z;

    // thrust1 = 19.0f;
    // thrust2 = 19.0f;
    // thrust3 = 25.0f;
    positionX = 0.0;
    positionY = 0.0;
    positionZ = 0.0;
    eulerAngleX = 0.0;
    eulerAngleY = 0.0;
    eulerAngleZ = 0.0;

    double i = 0;

    for(int k=1;k<=100;k++){
        //positionX = 1 * std::sin(i * 2 * M_PI);
        //positionY = 1 * std::cos(i * 2 * M_PI) - 1.0;
        positionZ = 0.01*k;
        desiredPositionPublisher.publish(desiredPositionMessage);
        desiredEulerAnglePublisher.publish(desiredEulerAngleMessage);

        // ROS_INFO("%f  %f  %f", thrust1, thrust2, thrust3);
        ROS_INFO("Desired position: %f, %f, %f", positionX, positionY, positionZ);
        ROS_INFO("Desired Euler angle: %f, %f, %f", eulerAngleX, eulerAngleY, eulerAngleZ);
        ros::spinOnce();
        loopRate.sleep();
    }
    while (ros::ok())
    {
        // thrust1 += 0.015f;
        // thrust2 += 0.0075f;
        // thrust3 += 0.0075f;
        positionX = 0 + 1*std::sin(i * 2 * M_PI);
        positionY = 0 + 1*std::sin(i * 2 * M_PI);
        positionZ = 1 + 0.02 * std::sin(i * 2 * M_PI);
        // positionZ -= 0.01;

        // thrustPublisher1.publish(thrustMessage1);
        // thrustPublisher2.publish(thrustMessage2);
        // thrustPublisher3.publish(thrustMessage3);
        desiredPositionPublisher.publish(desiredPositionMessage);
        desiredEulerAnglePublisher.publish(desiredEulerAngleMessage);

        // ROS_INFO("%f  %f  %f", thrust1, thrust2, thrust3);
        ROS_INFO("Desired position: %f, %f, %f", positionX, positionY, positionZ);
        ROS_INFO("Desired Euler angle: %f, %f, %f", eulerAngleX, eulerAngleY, eulerAngleZ);

        i += 1.0 / rate * 0.02;

        ros::spinOnce();
        loopRate.sleep();
    }
}
