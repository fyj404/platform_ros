// packing.cpp
// Du Jianrui   2022.1.29
// packs data to strings using a protocol

#include "packing.h"

void convertFloatToHexString(float sourceNumber, char* targetString)
{
    char buffer[4][3];

    // converts a float number to its hex form
    unsigned char* variableHex = (unsigned char*)&sourceNumber;
    // writes the hex to 4 char strings
    for (int i = 0; i < 4; ++i)
    {
        sprintf(buffer[i], "%02x", variableHex[i]);
    }
    // clears the target string
    strcpy(targetString, "");
    // merges 4 strings
    for (int i = 0; i < 4; ++i)
    {
        strcat(targetString, buffer[i]);
    }
}

DataPack packFloat(float number, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 1;
    result.sourceVector.x() = number;
    result.sourceVector.y() = number;
    result.sourceVector.z() = number;

    return result;
}

DataPack packEulerAngle(const Eigen::Vector3f& eulerAngleVector, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 2;
    result.sourceVector = eulerAngleVector;

    return result;
}

DataPack packPosition(const Eigen::Vector3f& positionVector, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 3;
    result.sourceVector = positionVector;

    return result;
}

DataPack packBodyRate(const Eigen::Vector3f& bodyRateVector, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 4;
    result.sourceVector = bodyRateVector;

    return result;
}

DataPack packVelocity(const Eigen::Vector3f& velocityVector, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 5;
    result.sourceVector = velocityVector;

    return result;
}

DataPack packAngularAcceleration(const Eigen::Vector3f& angularAccelerationVector, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 6;
    result.sourceVector = angularAccelerationVector;

    return result;
}

DataPack packLinearAcceleration(const Eigen::Vector3f& linearAccelerationVector, unsigned int source)
{
    DataPack result;

    result.id = source;
    result.type = 7;
    result.sourceVector = linearAccelerationVector;

    return result;
}

void makePacket(const DataPack& data, char* frame)
{
    frame[0] = '#';
    frame[1] = 48 + data.id;
    frame[2] = 48 + data.type;

    char tempString[9];
    convertFloatToHexString(data.sourceVector.x(), tempString);
    for (int i = 0; i < 8; i++)
    {
        frame[i + 3] = tempString[i];
    }
    convertFloatToHexString(data.sourceVector.y(), tempString);
    for (int i = 0; i < 8; i++)
    {
        frame[i + 11] = tempString[i];
    }
    convertFloatToHexString(data.sourceVector.z(), tempString);
    for (int i = 0; i < 8; i++)
    {
        frame[i + 19] = tempString[i];
    }

    frame[27] = '*';
    frame[28] = '\0';
}
