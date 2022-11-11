// callback.h
// callback functions
// Du Jianrui   2022.1.29

#pragma once

#include "std_msgs/Float32.h"
#include "geometry_msgs/Vector3.h"

class Thrust
{
public:
    void callback(const std_msgs::Float32::ConstPtr& msg)
    {
        thrust_ = *msg;
    }

    std_msgs::Float32 get() const
    {
        return thrust_;
    }

private:
    std_msgs::Float32 thrust_;
};

class EulerAngle
{
public:
    void callback(const geometry_msgs::Vector3::ConstPtr& msg)
    {
        eulerAngle_ = *msg;
    }

    geometry_msgs::Vector3 get() const
    {
        return eulerAngle_;
    }

private:
    geometry_msgs::Vector3 eulerAngle_;
};

class Position
{
public:
    void callback(const geometry_msgs::Vector3::ConstPtr& msg)
    {
        position_ = *msg;
    }

    geometry_msgs::Vector3 get() const
    {
        return position_;
    }

private:
    geometry_msgs::Vector3 position_;
};

class BodyRate
{
public:
    void callback(const geometry_msgs::Vector3::ConstPtr& msg)
    {
        bodyRate_ = *msg;
    }

    geometry_msgs::Vector3 get() const
    {
        return bodyRate_;
    }

private:
    geometry_msgs::Vector3 bodyRate_;
};

class Velocity
{
public:
    void callback(const geometry_msgs::Vector3::ConstPtr& msg)
    {
        velocity_ = *msg;
    }

    geometry_msgs::Vector3 get() const
    {
        return velocity_;
    }

private:
    geometry_msgs::Vector3 velocity_;
};

class AngularAcceleration
{
public:
    void callback(const geometry_msgs::Vector3::ConstPtr& msg)
    {
        angularAcceleration_ = *msg;
    }

    geometry_msgs::Vector3 get() const
    {
        return angularAcceleration_;
    }

private:
    geometry_msgs::Vector3 angularAcceleration_;
};

class LinearAcceleration
{
public:
    void callback(const geometry_msgs::Vector3::ConstPtr& msg)
    {
        linearAcceleration_ = *msg;
    }

    geometry_msgs::Vector3 get() const
    {
        return linearAcceleration_;
    }

private:
    geometry_msgs::Vector3 linearAcceleration_;
};
