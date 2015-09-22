cmake_minimum_required(VERSION 3.3)
project(Clusters)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Point.h Point.cpp Cluster.h Cluster.cpp)
add_executable(Clusters ${SOURCE_FILES})