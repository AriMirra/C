cmake_minimum_required(VERSION 3.6)
project(CFromJava)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Car.c Car.h Parking.c Parking.h)
add_executable(CFromJava ${SOURCE_FILES})