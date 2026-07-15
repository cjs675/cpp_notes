cmake_minimum_required(VERSION 4.2)
project(assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignments
        assignment1/bankManagementSystem/main.cpp
        assignment1/calculatorClass/main.cpp
        assignment1/threeEmployees/main.cpp
        assignment2/libManagementSystem/main.cpp
        assignment2/onlineShopProductInventory/main.cpp
        assignment2/roomReservationSystem/main.cpp
        assignment3/main.cpp
        countEvenAndOddInArray/main.cpp
        laptopClass/main.cpp
        sortArraysAscendingDescendingOOP/main.cpp
        switchCaseControlOOPMenu/main.cpp)
