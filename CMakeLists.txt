cmake_minimum_required(VERSION 3.6)
project(CFromJava)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ParkingCar/main.c ParkingCar/Car.c ParkingCar/Car.h ParkingCar/Parking.c ParkingCar/Parking.h DynamicMemory/DinamicMemory.c DynamicMemory/DinamicMemory.h)
add_executable(CFromJava ${SOURCE_FILES})