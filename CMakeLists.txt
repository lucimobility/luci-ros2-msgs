# Set min CMAKE version
cmake_minimum_required(VERSION 3.16)
# Project name must match package name in package.xml
project(luci_messages)

# Get ROS2 cmake macros
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Set msg files to be converted to .h
set(msg_files
"msg/LuciJoystick.msg"
"msg/LuciZoneScaling.msg"
"msg/LuciJoystickScaling.msg"
"msg/LuciDriveMode.msg"
)

# Generate the message types
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

# Inform packages importing this "library" that the runtime library is needed
ament_export_dependencies(rosidl_default_runtime)
ament_package()
