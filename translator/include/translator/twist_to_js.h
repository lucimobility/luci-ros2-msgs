#pragma once
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <translator/luci_joystick.h>

#include <iostream>

class TwistToJs
{
  private:
    ros::NodeHandle node_handle;

    ros::Publisher publisher = node_handle.advertise<translator::luci_joystick>("joystick_topic", 1);
    ros::Subscriber subscriber = node_handle.subscribe("turtle1/cmd_vel", 1, &TwistToJs::twistCallback, this);

  public:
    TwistToJs();
    ~TwistToJs();

    void twistCallback(const geometry_msgs::TwistConstPtr& msg);
    void run();
};

TwistToJs::TwistToJs()
{
    // ros::init(argc, argv, "js_interface_node");

    // ros::NodeHandle node_handle;
    // publisher = node_handle.advertise<std_msgs::String>("joystick_topic", 1);
    // subscriber = node_handle.subscribe("turtle1/cmd_vel", 1, TwistToJs::twistCallback, this);
}

TwistToJs::~TwistToJs() {}
