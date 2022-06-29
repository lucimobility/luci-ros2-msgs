#pragma once
#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
// #include "translator/msg/LuciJoystick.hpp"

#include <iostream>

class TwistToJs : public rclcpp::Node {
private:
  rclcpp::Publisher<translator::luci_joystick>::SharedPtr publisher;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscriber;
  // ros::NodeHandle node_handle;

  // ros::Publisher publisher =
  // node_handle.advertise<translator::luci_joystick>("joystick_topic", 1);
  // ros::Subscriber subscriber = node_handle.subscribe(
  //     "turtle1/cmd_vel", 1, &TwistToJs::twistCallback, this);

public:
  TwistToJs() : Node("js_interface_node") {
    publisher =
        this->create_publisher<translator::luci_joystick>("joystick_topic", 1);
    subscriber = this->create_subscription<geometry_msgs::msg::Twist>(
        "turtle1/cmd_vel", 1,
        [this](geometry_msgs::msg::TwistConstPtr msg) { twistCallback(msg); });
  }
  ~TwistToJs();

  void twistCallback(const geometry_msgs::msg::TwistConstPtr msg);
  void run();
};

TwistToJs::TwistToJs() {
  // ros::init(argc, argv, "js_interface_node");

  // ros::NodeHandle node_handle;
  // publisher = node_handle.advertise<std_msgs::String>("joystick_topic", 1);
  // subscriber = node_handle.subscribe("turtle1/cmd_vel", 1,
  // TwistToJs::twistCallback, this);
}

TwistToJs::~TwistToJs() {}
