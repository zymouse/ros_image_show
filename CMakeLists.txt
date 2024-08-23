cmake_minimum_required(VERSION 3.8)
project(ros2_image_show)

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  src/ros2_image_show.cpp
)

rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "image_subscriber::ImageSubscriber"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

# install
ament_auto_package(
  INSTALL_TO_SHARE
  launch
)
