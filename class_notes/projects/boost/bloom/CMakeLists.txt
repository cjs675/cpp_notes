cmake_minimum_required(VERSION 3.15) 
project(BloomProject) 

# set standard c++ version 
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

# find the packages installed
find_package(Boost CONFIG REQUIRED COMPONENTS bloom) 
find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED) 

# create executable 
add_executable(main main.cpp) 

# link libs to executable 
target_link_libraries(main PRIVATE 
    Boost::bloom
    fmt::fmt-header-only
    nlohmann_json::nlohmann_json
)
