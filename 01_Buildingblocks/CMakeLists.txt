#cmake_minimum_required(VERSION 3.30)
project(01_Buildingblocks)

#set(CMAKE_CXX_STANDARD 20)

add_executable(01_Buildingblocks main.cpp
        Helpers.h)
target_include_directories(01_Buildingblocks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})