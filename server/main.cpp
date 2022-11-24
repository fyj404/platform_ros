// main.cpp
// ROS node
// Du Jianrui   2022.1.29
// packs messages from ROS network, then sends to the client

#include "ros/ros.h"

#include "server_node.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;

    double rate = 100.0;
    ros::Rate loopRate(rate);
    std::string ips="192.168.159.1";
    nh.param<std::string>("ip",ips,"192.168.159.1");
    ServerNode server(nh, ips.c_str(), 2341);

    while(ros::ok())
    {
        server.spinOnce();
        loopRate.sleep();
    }
}
