cmake_minimum_required(VERSION 3.6)
project(ComplexNumber)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ComplexNumber.c ComplexNumber.h Test.c)
add_executable(ComplexNumber ${SOURCE_FILES} Test.c)
