// parsing.cpp
// Du Jianrui   2022.1.30
// parses received strings to origin data

#include "parsing.h"

#include "ros/ros.h"

float convertHexStringToFloat(const char* sourceString)
{
    char bufferString[4][3];
    long bufferInteger[4];
    char* end = nullptr;

    for (int i = 0; i < 4; ++i)
    {
        // seperates the string to 4 hex strings
        bufferString[i][0] = sourceString[2 * i];
        bufferString[i][1] = sourceString[2 * i + 1];
        bufferString[i][2] = '\0';

        // converts each hex string to a corresponding integer
        bufferInteger[i] = strtol(bufferString[i], &end, 16);
    }

    // converts the hex integers to a float
    unsigned char targetCharBuffer[] = { bufferInteger[0], bufferInteger[1], bufferInteger[2], bufferInteger[3] };
    float* targetFloat = (float*)targetCharBuffer;

    return *targetFloat;
}

DataPack parsePacket(const char* frame)
{
    DataPack parsedData;

    if (frame[0] == '#' && frame[27] == '*')
    {
        parsedData.id = (unsigned int)frame[1] - 48;
        parsedData.type = (unsigned int)frame[2] - 48;

        char tempString[9] = "";
        for (int i = 0; i < 8; ++i)
        {
            tempString[i] = frame[i + 3];
        }
        parsedData.sourceVector.x() = convertHexStringToFloat(tempString);
        for (int i = 0; i < 8; ++i)
        {
            tempString[i] = frame[i + 11];
        }
        parsedData.sourceVector.y() = convertHexStringToFloat(tempString);
        for (int i = 0; i < 8; ++i)
        {
            tempString[i] = frame[i + 19];
        }
        parsedData.sourceVector.z() = convertHexStringToFloat(tempString);

        return parsedData;
    }
    else
    {
        ROS_INFO("Incomplete packet received!");

        parsedData.id = 0;
        parsedData.type = 0;
        parsedData.sourceVector = Eigen::Vector3f::Zero();

        return parsedData;
    }
}
