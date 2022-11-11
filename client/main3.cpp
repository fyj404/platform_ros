// main.cpp
// ROS node
// Du Jianrui   2022.1.30
// parses messages from UE4 server, then sends to ROS network

#include "ros/ros.h"

#include "client_node.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "client3");
    ros::NodeHandle nh;

    double rate = 500.0;
    ros::Rate loopRate(rate);
    std::string ips;
    nh.param<std::string>("ip",ips,"10.63.79.224");
    ClientNode client(nh,ips.c_str(), 11434);
    // struct sockaddr_in serv_addr;
    // memset(&serv_addr, 0, sizeof(serv_addr));
    // serv_addr.sin_family = AF_INET;
    // serv_addr.sin_addr.s_addr = inet_addr("192.168.25.1");
    // serv_addr.sin_port = htons(1234);

    while(ros::ok())
    {
        // int sock = socket(AF_INET, SOCK_STREAM, 0);
        // connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        // char testString[29] = "";
        // read(sock, testString, sizeof(testString)-1);
        // ROS_INFO("%s", testString);

        client.spinOnce();
        loopRate.sleep();
    }
}
