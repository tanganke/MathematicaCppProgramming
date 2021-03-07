cmake_minimum_required(VERSION 3.10)
project(HelloWSTP)

include(../DeveloperKit/WSTP.cmake) # include predefined CMake module
file(GLOB SOURCES *.cpp)			# glob source files
add_WSTP_executable(${PROJECT_NAME})# add excutable target