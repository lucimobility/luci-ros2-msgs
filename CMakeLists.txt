cmake_minimum_required(VERSION 3.8)
project(luci_messages)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate the message types
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/LuciJoystick.msg"
  "msg/LuciZoneScaling.msg"
  "msg/LuciJoystickScaling.msg"
 )

 ament_package()
