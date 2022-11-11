// client_node.h
// client node class
// Du Jianrui   2022.1.30

#pragma once

#include "ros/ros.h"

#include "geometry_msgs/Vector3.h"

#include "client.h"
#include "parsing.h"

class ClientNode
{
public:
    ClientNode(const ros::NodeHandle& nodeHandle,
               const char* serverIp = "127.0.0.1",
               int serverPort = 4321)
    {
        nodeHandle_ = nodeHandle;
        Client client(serverIp, serverPort);
        client_ = client;

        client_.connect();
        initializePublisher();
    }

    void spinOnce()
    {
        parseAndSendData();
        ROS_INFO("Frame received -- %s", frame_);

        //ros::spinOnce();
    }
               
    ~ClientNode()
    {
        client_.disconnect();
    }

private:// lists ROS-related members
    ros::NodeHandle nodeHandle_;

private:
    Client client_;
    char frame_[29];

private: // lists publishers here
    // publisher handles
    ros::Publisher eulerAnglePublisher_;
    ros::Publisher positionPublisherNo0_;
    ros::Publisher positionPublisherNo1_;
    ros::Publisher positionPublisherNo2_;
    ros::Publisher positionPublisherNo3_;
    ros::Publisher bodyRatePublisher_;
    ros::Publisher velocityPublisher_;
    ros::Publisher accelerationPublisher_;
    // messages to publish
    geometry_msgs::Vector3 eulerAngleMessage_;
    geometry_msgs::Vector3 positionMessageNo0_;
    geometry_msgs::Vector3 positionMessageNo1_;
    geometry_msgs::Vector3 positionMessageNo2_;
    geometry_msgs::Vector3 positionMessageNo3_;
    geometry_msgs::Vector3 bodyRateMessage_;
    geometry_msgs::Vector3 velocityMessage_;
    geometry_msgs::Vector3 accelerationMessage_;

private:
    void initializePublisher()
    {
        eulerAnglePublisher_  = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("euler_angle_0", 10);
        positionPublisherNo0_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("position_0", 10);
        positionPublisherNo1_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("position_1", 10);
        positionPublisherNo2_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("position_2", 10);
        positionPublisherNo3_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("position_3", 10);
        bodyRatePublisher_    = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("body_rate", 10);
        velocityPublisher_    = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("velocity", 10);
        accelerationPublisher_= nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("acceleration", 10);
    }

    void parseAndSendData()
    {
        memset(frame_, 0, sizeof(frame_) + sizeof(char));
        client_.receive(frame_);

        DataPack packet = parsePacket(frame_);
        switch (packet.type)
        {
        case 0:
            ROS_INFO("Blank message received.");
            break;
        case 2: // Euler angle frame
            eulerAngleMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            eulerAnglePublisher_.publish(eulerAngleMessage_);
            break;
        case 3:
            switch (packet.id)
            {
            case 0:
                positionMessageNo0_ = convertEigenVectorToRosVector(packet.sourceVector);
                positionPublisherNo0_.publish(positionMessageNo0_);
                break;
            case 1:
                positionMessageNo1_ = convertEigenVectorToRosVector(packet.sourceVector);
                positionPublisherNo1_.publish(positionMessageNo1_);
                break;
            case 2:
                positionMessageNo2_ = convertEigenVectorToRosVector(packet.sourceVector);
                positionPublisherNo2_.publish(positionMessageNo2_);
                break;
            case 3:
                positionMessageNo3_ = convertEigenVectorToRosVector(packet.sourceVector);
                positionPublisherNo3_.publish(positionMessageNo3_);
                break;
            default:
                break;
            }
            break;
        case 4:
            bodyRateMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            bodyRatePublisher_.publish(bodyRateMessage_);
            break;
        case 5:
            velocityMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            velocityPublisher_.publish(velocityMessage_);
            break;
        case 6:
            accelerationMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            accelerationPublisher_.publish(accelerationMessage_);
            break;
        default:
            break;
        }

        client_.disconnect();
        client_.connect();
    }

    geometry_msgs::Vector3 convertEigenVectorToRosVector(const Eigen::Vector3f& vector)
    {
        geometry_msgs::Vector3 result;

        result.x = vector.x();
        result.y = vector.y();
        result.z = vector.z();

        return result;
    }
};
