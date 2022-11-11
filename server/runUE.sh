#!/bin/bash
gnome-terminal -x bash -c "roscore"

sleep 1

gnome-terminal -x bash -c "rosrun client client1"
gnome-terminal -x bash -c "rosrun client client2"
gnome-terminal -x bash -c "rosrun client client3"

sleep 1

gnome-terminal -x bash -c "rosrun server server"

sleep 1

gnome-terminal -x bash -c "rosrun image_decode image_decode1"
gnome-terminal -x bash -c "rosrun image_decode image_decode2"
gnome-terminal -x bash -c "rosrun image_decode image_decode3"

sleep 1

gnome-terminal -x bash -c "rosrun controller_ros_ue controller_ros_ue"

sleep 1

gnome-terminal -x bash -c "rosrun test_ue test_ue"
