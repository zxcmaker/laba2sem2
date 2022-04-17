cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME sem2lab2)
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB hdrs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*")
file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${srcs} ${hdrs})