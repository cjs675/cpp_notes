cmake_minimum_required(VERSION 3.15) 
project(SecurityProject) 

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

# find our vcpkg deps 
find_package(Boost CONFIG REQUIRED COMPONENTS bloom) 
find_package(fmt CONFIG REQUIRED) 
find_package(nlohmann_json CONFIG REQUIRED) 

# create exe & tell cmake about all of source files 
add_executable(main
    src/main.cpp
    src/blacklist.cpp
)

# tell cmake where to find custom headers 
target_include_directories(main PRIVATE include) 

# link the libs 
target_link_libraries(main PRIVATE
    Boost::bloom
    fmt::fmt
    nlohmann_json::nlohmann_json
)
