cmake_minimum_required(VERSION 4.3)
project(drone_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(drone_Project
        program4_driver.cpp
        drone.cpp
        drone_utils.cpp
)