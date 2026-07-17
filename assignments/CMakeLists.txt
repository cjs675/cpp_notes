cmake_minimum_required(VERSION 4.2)
project(assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# --- Assignment 1 ---
add_executable(bankManagementSystem assignment1/bankManagementSystem/main.cpp)
add_executable(calculatorClass assignment1/calculatorClass/main.cpp)
add_executable(threeEmployees assignment1/threeEmployees/main.cpp)

# --- Assignment 2 ---
add_executable(libManagementSystem assignment2/libManagementSystem/main.cpp)
add_executable(onlineShopProductInventory assignment2/onlineShopProductInventory/main.cpp)
add_executable(roomReservationSystem assignment2/roomReservationSystem/main.cpp)

# --- Assignment 3 ---
add_executable(bookClass assignment3/bookClass/main.cpp)
add_executable(MenuItem assignment3/MenuItem/main.cpp)
add_executable(student assignment3/student/main.cpp)

# --- Assignment 4 ---
add_executable(assignment4Vectors assignment4-Vectors/main.cpp)

# --- Classwork / Other ---
add_executable(countEvenAndOdd countEvenAndOddInArray/main.cpp)
add_executable(laptopClass laptopClass/main.cpp)
add_executable(sortArrays sortArraysAscendingDescendingOOP/main.cpp)
add_executable(switchCase switchCaseControlOOPMenu/main.cpp)