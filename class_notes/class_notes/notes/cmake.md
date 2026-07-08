## cmake 

- platform independent build system generator 
- write config file: __CMakeLists.txt__ describing: 
  - project sources, libs, paths, options 
- run __CMake__ to generate native build files for your platform 
- use native tool (__make__) to compile & link
- same __CMake__ config works on diff os'es & compilers 
- __CMake__ reads __CMakeLists.txt__ & generates build files (makefiles) 

## common processes in cmake 
```
add_executable(myapp
  main.cpp
  foo.cpp
  bar.cpp
  baz.cpp
```
```
// add include dirs 
target_include_directories(myaapp PRIVATE include) 

// in this way, headers in include/ can be used like #include "foo.hpp" 
```
```
// add compiler flags 
targer_compile_options(myapp PRIVATE -Wall -Wextra -pedantic)
```
## typical workflow 
- create __CMakeLists.txt__ in project root 
- (optional) create __src/__, __include/__, etc & reference them from CMake
- configure: 
```
mkdir build 
cd build 
cmake ..
cmake --build 
```
- rebuild __after__ code changes by re-running __cmake --build__ 
