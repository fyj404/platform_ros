// client_node.h
// client node class
// Du Jianrui   2022.1.30

#pragma once

#include "ros/ros.h"

#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/PointStamped.h"
#include "client.h"
#include "parsing.h"
#include "callback.h"

class ClientNode2
{
public:
    ClientNode2(const ros::NodeHandle& nodeHandle,
                const char* serverIp = "127.0.0.1",
                int serverPort = 4321)
    {
        nodeHandle_ = nodeHandle;
        Client client(serverIp, serverPort);
        client_ = client;

        client_.connect();
        initializePublisher();
        initializeSubscriber();
    }

    void spinOnce()
    {
        parseAndSendData();
        ROS_INFO("Frame received -- %s", frame_);

        ros::spinOnce();
    }
               
    ~ClientNode2()
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
    ros::Publisher positionPublisher404_[5];
    ros::Publisher bodyRatePublisher_;
    ros::Publisher velocityPublisher_;
    ros::Publisher accelerationPublisher_;
    ros::Publisher accelerationPublisher404_;
    // messages to publish
    geometry_msgs::Vector3 eulerAngleMessage_;
    geometry_msgs::Vector3 positionMessageNo0_;
    geometry_msgs::Vector3 positionMessageNo1_;
    geometry_msgs::Vector3 positionMessageNo2_;
    geometry_msgs::Vector3 positionMessageNo3_;
    geometry_msgs::Vector3 bodyRateMessage_;
    geometry_msgs::Vector3 velocityMessage_;
    geometry_msgs::Vector3 accelerationMessage_;

// temporarily for euler angle synchronization
private:
    // subscribers
    ros::Subscriber eulerAngleSubscriberNo1_;
    ros::Subscriber eulerAngleSubscriberNo2_;
    ros::Subscriber eulerAngleSubscriberNo3_;
    EulerAngle eulerAngleCallbackNo1_;
    EulerAngle eulerAngleCallbackNo2_;
    EulerAngle eulerAngleCallbackNo3_;
    // publishers
    ros::Publisher eulerAnglePublisherNo1_;
    ros::Publisher eulerAnglePublisherNo2_;
    ros::Publisher eulerAnglePublisherNo3_;
    ros::Publisher eulerAnglePublisher404_[5];
    geometry_msgs::Vector3 eulerAngleMessageNo1_;
    geometry_msgs::Vector3 eulerAngleMessageNo2_;
    geometry_msgs::Vector3 eulerAngleMessageNo3_;
private:
    void initializeSubscriber()
    {
        eulerAngleSubscriberNo1_ = nodeHandle_.subscribe<geometry_msgs::Vector3>
                               ("euler_angle1", 1, &EulerAngle::callback, &eulerAngleCallbackNo1_);
        eulerAngleSubscriberNo2_ = nodeHandle_.subscribe<geometry_msgs::Vector3>
                               ("euler_angle2", 1, &EulerAngle::callback, &eulerAngleCallbackNo2_);
        eulerAngleSubscriberNo3_ = nodeHandle_.subscribe<geometry_msgs::Vector3>
                               ("euler_angle3", 1, &EulerAngle::callback, &eulerAngleCallbackNo3_);
        eulerAnglePublisherNo1_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                              ("euler_angle_1", 10);
        eulerAnglePublisherNo2_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                              ("euler_angle_2", 10);
        eulerAnglePublisherNo3_ = nodeHandle_.advertise<geometry_msgs::Vector3>
                              ("euler_angle_3", 10);
        eulerAnglePublisher404_[0]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                              ("euler_angle404_0", 10);
        eulerAnglePublisher404_[1]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                              ("euler_angle404_1", 10);
        eulerAnglePublisher404_[2]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                              ("euler_angle404_2", 10);
        eulerAnglePublisher404_[3]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                              ("euler_angle404_3", 10);
    }

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
        
        positionPublisher404_[0]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                                ("position_404_0", 10);
        positionPublisher404_[1]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                                ("position_404_1", 10);
        positionPublisher404_[2]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                                ("position_404_2", 10);
        positionPublisher404_[3]=nodeHandle_.advertise<geometry_msgs::PointStamped>
                                ("position_404_3", 10);
        bodyRatePublisher_    = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("body_rate", 10);
        velocityPublisher_    = nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("velocity", 10);
        accelerationPublisher_= nodeHandle_.advertise<geometry_msgs::Vector3>
                                ("acceleration", 10);
        accelerationPublisher404_=nodeHandle_.advertise<geometry_msgs::PointStamped>
                                ("acceleration404", 10);
    }
    void cp(geometry_msgs::PointStamped &pt,geometry_msgs::Vector3 tmp){
            //pt.header.stamp=ros::Time::now();
            pt.point.x=tmp.x;
            pt.point.y=tmp.y;
            pt.point.z=tmp.z;
    }
    void parseAndSendData()
    {
        memset(frame_, 0, sizeof(frame_) + sizeof(char));
        client_.receive(frame_);

        DataPack packet = parsePacket(frame_);
        geometry_msgs::PointStamped pt;
        pt.header.stamp=ros::Time::now();
        if(packet.type==0)
        {
            ROS_INFO("Blank message received.");
        }
        else if(packet.type==2)
        {
            eulerAngleMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            eulerAnglePublisher_.publish(eulerAngleMessage_);
            cp(pt,eulerAngleMessage_);
            eulerAnglePublisher404_[0].publish(pt);

        }
        else if(packet.type==3){
            
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
            cp(pt,convertEigenVectorToRosVector(packet.sourceVector));
            positionPublisher404_[packet.id].publish(pt);
        }
        else if(packet.type==4){
            bodyRateMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            bodyRatePublisher_.publish(bodyRateMessage_);
        }
        else if(packet.type==5){
            velocityMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            velocityPublisher_.publish(velocityMessage_);
            eulerAngleMessageNo1_ = eulerAngleCallbackNo1_.get();
            eulerAngleMessageNo2_ = eulerAngleCallbackNo2_.get();
            eulerAngleMessageNo3_ = eulerAngleCallbackNo3_.get();
            eulerAnglePublisherNo1_.publish(eulerAngleMessageNo1_);
            eulerAnglePublisherNo2_.publish(eulerAngleMessageNo2_);
            eulerAnglePublisherNo3_.publish(eulerAngleMessageNo3_);
            cp(pt,eulerAngleMessageNo1_);
            eulerAnglePublisher404_[1].publish(pt);
            cp(pt,eulerAngleMessageNo2_);
            eulerAnglePublisher404_[2].publish(pt);
            cp(pt,eulerAngleMessageNo3_);
            eulerAnglePublisher404_[3].publish(pt);
        }
        else if(packet.type==6){
            accelerationMessage_ = convertEigenVectorToRosVector(packet.sourceVector);
            accelerationPublisher_.publish(accelerationMessage_);
            cp(pt,accelerationMessage_);
            accelerationPublisher404_.publish(pt);
        }
        else{
            //
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
