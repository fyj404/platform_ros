// main.cpp
// ROS node
// Du Jianrui   2022.3.15
// receives images from UE4 through socket, and publishes image messages

#include <ros/ros.h>

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <vector>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<string>
bool receiveImageArray(sockaddr_in& serverAddress, cv::Mat& decodedImage, int& id);

int main(int argc, char** argv)
{
    //------------- ROS -------------
    ros::init(argc, argv, "image_decode1");
    ros::NodeHandle nodeHandle;
    
    // defines ros rate
    double rate = 18.0;
    ros::Rate loopRate(rate);

    // defines image part
    image_transport::ImageTransport imageHandle(nodeHandle);
    image_transport::Publisher imagePublisher = imageHandle.advertise("camera1/image", 20);
    sensor_msgs::ImagePtr imageMessage;
    //------------- ROS -------------

    //------------- socket -------------
    // binds the socket
    sockaddr_in localAddress;
    memset(&localAddress, 0, sizeof(localAddress));
    localAddress.sin_family = AF_INET;        // IPv4
    
    std::string ips="10.63.79.224";
    nodeHandle.param <std::string > ("ip",ips,"10.63.79.224");
    localAddress.sin_addr.s_addr = inet_addr("10.63.79.224");
    localAddress.sin_port = htons(6565);
    //------------- socket -------------

    cv::Mat image;
    while (ros::ok())
    {
        int id;
        if (receiveImageArray(localAddress, image, id))
        {
            ROS_INFO("Image decoded.");
            if (id != 100)
            {
                ROS_INFO("Id Error.");
                continue;
            }
            imageMessage = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
            imagePublisher.publish(imageMessage);
        }
        else
        {
            ROS_INFO("Failure.");
            // return 0;
        }

        loopRate.sleep();
    }
}

bool receiveImageArray(sockaddr_in& serverAddress, cv::Mat& decodedImage, int& id)
{
    // receives image size information first
    char imageNumberString[10];
    int headSocket = socket(PF_INET, SOCK_STREAM, 0);
    ::connect(headSocket, (sockaddr*)&serverAddress, sizeof(sockaddr));
    ::recv(headSocket, imageNumberString, 10, NULL);
    ::close(headSocket);
    int imageSize = atoi(imageNumberString);

    // receives image id next
    char idString[10];
    int idSocket = socket(PF_INET, SOCK_STREAM, 0);
    ::connect(idSocket, (sockaddr*)&serverAddress, sizeof(sockaddr));
    ::recv(idSocket, idString, 10, NULL);
    ::close(idSocket);
    id = atoi(idString);

    // receives image data
    int imageSocket = socket(PF_INET, SOCK_STREAM, 0);
    ::connect(imageSocket, (sockaddr*)&serverAddress, sizeof(sockaddr));
    char* buffer = new char[imageSize];
    std::vector<uchar> encodedImageData;
    int count = imageSize;
    while (count > 0)
    {
        int receiveSize = ::recv(imageSocket, buffer, count, NULL);
        encodedImageData.insert(encodedImageData.end(), buffer, buffer + receiveSize);
        if (-1 == receiveSize)
        {
            ::close(imageSocket);
            return false;
        }
        count -= receiveSize;
        buffer += receiveSize;
    }
    ::close(imageSocket);

    if (count != 0)
    {
        ROS_INFO("Counter error.");
        return false;
    }

    // decodes image
    if (encodedImageData.empty())
    {
        ROS_INFO("Empty image.");
        return false;
    }
    else
    {
        decodedImage = cv::imdecode(encodedImageData, 1);
    }

    if (!decodedImage.empty())
    {
        return true;
    }
    else
    {
        ROS_INFO("Decode failure.");
        return false;
    }
}
