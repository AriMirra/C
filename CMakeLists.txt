cmake_minimum_required(VERSION 3.6)
project(CFromJava)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ParkingCar/Car.c ParkingCar/Car.h ParkingCar/Parking.c ParkingCar/Parking.h DynamicMemory/DinamicMemory.c DynamicMemory/DinamicMemory.h TPCuatrimestral/Exercise1/Provider.c TPCuatrimestral/Exercise1/Provider.h TPCuatrimestral/Exercise1/Manufacturer.c TPCuatrimestral/Exercise1/Manufacturer.h TPCuatrimestral/Exercise1/Appliance.c TPCuatrimestral/Exercise1/Appliance.h TPCuatrimestral/Exercise1/Catalogue.c TPCuatrimestral/Exercise1/Catalogue.h TPCuatrimestral/Exercise1/Invoice.c TPCuatrimestral/Exercise1/Invoice.h TPCuatrimestral/Exercise1/Label.c TPCuatrimestral/Exercise1/Label.h TPCuatrimestral/Exercise1/ShoppingCart.c TPCuatrimestral/Exercise1/ShoppingCart.h TPCuatrimestral/Exercise1/ShoppingCartLine.c TPCuatrimestral/Exercise1/ShoppingCartLine.h TPCuatrimestral/Exercise1/InvoiceLine.c TPCuatrimestral/Exercise1/InvoiceLine.h)
add_executable(CFromJava ${SOURCE_FILES})