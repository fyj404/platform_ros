// server_node.h
// server node class
// Du Jianrui   2022.1.29

#pragma once

#include "ros/ros.h"

#include "client.h"
#include "packing.h"
#include "callback.h"

class ServerNode
{
public:
    ServerNode(const ros::NodeHandle& nodeHandle,
               const char* serverIp = "127.0.0.1",
               int serverPort = 1234)
    {
        nodeHandle_ = nodeHandle;
        Client server(serverIp, serverPort);
        server_ = server;

        server_.connect();
        initializeSubscriber();
        // initializeServerConnection();
    }

    void spinOnce()
    {
        sendThrustNo1();
        sendThrustNo2();
        sendThrustNo3();

        sendEulerAngleNo1();
        sendEulerAngleNo2();
        sendEulerAngleNo3();
        
        ros::spinOnce();
    }

    ~ServerNode()
    {
        server_.disconnect();
    }

private: // lists ROS-related members
    ros::NodeHandle nodeHandle_;

private:
    Client server_;
    char frame_[29];
    
private: // lists subscribers here
    // subscriber handles
    ros::Subscriber thrustSubscriberNo1_;
    ros::Subscriber thrustSubscriberNo2_;
    ros::Subscriber thrustSubscriberNo3_;
    ros::Subscriber eulerAngleSubscriberNo1_;
    ros::Subscriber eulerAngleSubscriberNo2_;
    ros::Subscriber eulerAngleSubscriberNo3_;
    ros::Subscriber positionSubscriber_;
    ros::Subscriber bodyRateSubscriber_;
    ros::Subscriber velocitySubscriber_;
    ros::Subscriber angularAccelerationSubscriber_;
    ros::Subscriber linearAccelerationSubscriber_;
    // subscriber callback instances
    Thrust thrustCallbackNo1_;
    Thrust thrustCallbackNo2_;
    Thrust thrustCallbackNo3_;
    EulerAngle eulerAngleCallbackNo1_;
    EulerAngle eulerAngleCallbackNo2_;
    EulerAngle eulerAngleCallbackNo3_;
    Position positionCallback_;
    BodyRate bodyRateCallback_;
    Velocity velocityCallback_;
    AngularAcceleration angularAccelerationCallback_;
    LinearAcceleration linearAccelerationCallback_;

private:
    void initializeSubscriber()
    {
        thrustSubscriberNo1_           = nodeHandle_.subscribe<std_msgs::Float32>
                                         ("thrust1", 1, &Thrust::callback, &thrustCallbackNo1_);
        thrustSubscriberNo2_           = nodeHandle_.subscribe<std_msgs::Float32>
                                         ("thrust2", 1, &Thrust::callback, &thrustCallbackNo2_);
        thrustSubscriberNo3_           = nodeHandle_.subscribe<std_msgs::Float32>
                                         ("thrust3", 1, &Thrust::callback, &thrustCallbackNo3_);
        eulerAngleSubscriberNo1_       = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("euler_angle1", 1, &EulerAngle::callback, &eulerAngleCallbackNo1_);
        eulerAngleSubscriberNo2_       = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("euler_angle2", 1, &EulerAngle::callback, &eulerAngleCallbackNo2_);
        eulerAngleSubscriberNo3_       = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("euler_angle3", 1, &EulerAngle::callback, &eulerAngleCallbackNo3_);
        positionSubscriber_            = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("position", 1, &Position::callback, &positionCallback_);
        bodyRateSubscriber_            = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("body_rate", 1, &BodyRate::callback, &bodyRateCallback_);
        velocitySubscriber_            = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("velocity", 1, &Velocity::callback, &velocityCallback_);
        angularAccelerationSubscriber_ = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("angular_acceleration", 1, &AngularAcceleration::callback, &angularAccelerationCallback_);
        linearAccelerationSubscriber_  = nodeHandle_.subscribe<geometry_msgs::Vector3>
                                         ("linear_acceleration", 1, &LinearAcceleration::callback, &linearAccelerationCallback_);
    }

    // void initializeServerConnection()
    // {
    //     server_.listen();
    //     ROS_INFO("Waiting for connection...");
    // }

    void sendThrustNo1()
    {
        float thrustNo1 = convertRosFloatToFloat(thrustCallbackNo1_.get());
        DataPack thrustPackNo1 = packFloat(thrustNo1, 1);
        makePacket(thrustPackNo1, frame_);
        server_.send(frame_);
        ROS_INFO("Frame sent: %s", frame_);
        server_.disconnect();
        server_.connect();
    }

    void sendThrustNo2()
    {
        float thrustNo2 = convertRosFloatToFloat(thrustCallbackNo2_.get());
        DataPack thrustPackNo2 = packFloat(thrustNo2, 2);
        makePacket(thrustPackNo2, frame_);
        server_.send(frame_);
        ROS_INFO("Frame sent: %s", frame_);
        server_.disconnect();
        server_.connect();
    }

    void sendThrustNo3()
    {
        float thrustNo3 = convertRosFloatToFloat(thrustCallbackNo3_.get());
        DataPack thrustPackNo3 = packFloat(thrustNo3, 3);
        makePacket(thrustPackNo3, frame_);
        server_.send(frame_);
        ROS_INFO("Frame sent: %s", frame_);
        server_.disconnect();
        server_.connect();
    }

    void sendEulerAngleNo1()
    {
        Eigen::Vector3f eulerAngleNo1 = convertRosVectorToEigenVector(eulerAngleCallbackNo1_.get());
        DataPack eulerAnglePackNo1 = packEulerAngle(eulerAngleNo1, 1);
        makePacket(eulerAnglePackNo1, frame_);
        server_.send(frame_);
        ROS_INFO("Frame sent: %s", frame_);
        server_.disconnect();
        server_.connect();
    }

    void sendEulerAngleNo2()
    {
        Eigen::Vector3f eulerAngleNo2 = convertRosVectorToEigenVector(eulerAngleCallbackNo2_.get());
        DataPack eulerAnglePackNo2 = packEulerAngle(eulerAngleNo2, 2);
        makePacket(eulerAnglePackNo2, frame_);
        server_.send(frame_);
        ROS_INFO("Frame sent: %s", frame_);
        server_.disconnect();
        server_.connect();
    }

    void sendEulerAngleNo3()
    {
        Eigen::Vector3f eulerAngleNo3 = convertRosVectorToEigenVector(eulerAngleCallbackNo3_.get());
        DataPack eulerAnglePackNo3 = packEulerAngle(eulerAngleNo3, 3);
        makePacket(eulerAnglePackNo3, frame_);
        server_.send(frame_);
        ROS_INFO("Frame sent: %s", frame_);
        server_.disconnect();
        server_.connect();
    }

    float convertRosFloatToFloat(const std_msgs::Float32& rosFloat)
    {
        return rosFloat.data;
    }

    Eigen::Vector3f convertRosVectorToEigenVector(const geometry_msgs::Vector3& rosVector)
    {
        Eigen::Vector3f result;

        result.x() = rosVector.x;
        result.y() = rosVector.y;
        result.z() = rosVector.z;

        return result;
    }
};
