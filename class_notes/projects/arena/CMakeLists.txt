cmake_minimum_required(VERSION 3.15) 
project(ArenaProject)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED on) 

# find packages 
find_package(Boost CONFIG REQUIRED COMPONENTS pool) 
find_package(fmt CONFIG REQUIRED) 

# executable 
add_executable(main src/main.cpp) 

# link 
target_link_libraries(main PRIVATE Boost::pool fmt::fmt)
