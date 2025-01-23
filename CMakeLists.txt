cmake_minimum_required(VERSION 3.12.4)
project(uas_vio)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(Threads REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

include(FindOpenMP)
if(OPENMP_FOUND)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else(OPENMP_FOUND)
  message("ERROR: OpenMP could not be found.")
endif(OPENMP_FOUND)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

include_directories(include)
include_directories(SYSTEM)
include_directories(${EIGEN3_INCLUDE_DIR})


add_executable(vio_node src/vio_node.cpp)
target_compile_options(vio_node PRIVATE ${OpenMP_FLAGS})
target_link_libraries(vio_node ${OpenMP_LIBS} Threads::Threads)
ament_target_dependencies(vio_node rclcpp nav_msgs geometry_msgs sensor_msgs std_msgs)

install(TARGETS vio_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
