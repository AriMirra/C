cmake_minimum_required(VERSION 3.6)
project(CFromJava)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ParkingCar/Car.c ParkingCar/Car.h ParkingCar/Parking.c ParkingCar/Parking.h DynamicMemory/DinamicMemory.c DynamicMemory/DinamicMemory.h TPCuatrimestral/Exercise1/provider.c TPCuatrimestral/Exercise1/provider.h)
add_executable(CFromJava ${SOURCE_FILES})