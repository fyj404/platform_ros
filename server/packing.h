// packing.h
// Du Jianrui   2022.1.29
// packs data to strings using a protocol

#pragma once

#include <iostream>
#include <cstring>
#include <Eigen/Dense>

void convertFloatToHexString(float sourceNumber, char* targetString);

// defines a structure to store data's information
struct DataPack
{
    // stores the main data
    Eigen::Vector3f sourceVector;
    // stores which rigid body the data belong to
    unsigned int id = 0;
    // stores the data type
    // 0 -- blank message
    // 1 -- thrust, a float number
    // 2 -- Euler angle
    // 3 -- position
    // 4 -- body rate
    // 5 -- linear velocity
    // 6 -- angular acceleration
    // 7 -- linear acceleration
    unsigned int type = 0;
};

DataPack packFloat(float number, unsigned int source);
DataPack packEulerAngle(const Eigen::Vector3f& eulerAngleVector, unsigned int source);
DataPack packPosition(const Eigen::Vector3f& positionVector, unsigned int source);
DataPack packBodyRate(const Eigen::Vector3f& bodyRateVector, unsigned int source);
DataPack packVelocity(const Eigen::Vector3f& velocityVector, unsigned int source);
DataPack packAngularAcceleration(const Eigen::Vector3f& angularAccelerationVector, unsigned int source);
DataPack packLinearAcceleration(const Eigen::Vector3f& linearAccelerationVector, unsigned int source);

void makePacket(const DataPack& data, char* frame);
