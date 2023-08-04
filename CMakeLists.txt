cmake_minimum_required(VERSION 3.8)
project(luci_messages)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# find_package(rosidl_default_runtime REQUIRED)
# find_package(rosidl_typesupport_cpp REQUIRED)

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

# setup targets
# include_directories(
#   include
#   ${rclcpp_INCLUDE_DIRS}
#   ${std_interfaces_INCLUDE_DIRS}
# )

# add_library(luci_messages src/library.cpp)

# rosidl_get_typesupport_target(cpp_typesupport_target
#   ${PROJECT_NAME}_msg rosidl_typesupport_cpp)

#   target_link_libraries(luci_messages "${cpp_typesupport_target}")
# rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
# target_link_libraries(${PROJECT_NAME} "${cpp_typesupport_target}") 

# install (TARGETS DESTINATION lib/${PROJECT_NAME})

# install(TARGETS luci_messages DESTINATION lib)
# install(
#   TARGETS ${PROJECT_NAME}
#   LIBRARY DESTINATION lib
#   ARCHIVE DESTINATION lib
#   RUNTIME DESTINATION bin
# )

ament_export_dependencies(rosidl_default_runtime)
ament_package()
