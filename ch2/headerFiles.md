## header files 

- manually adding a few forward declarations to top of each file isnt so bad 
    - as programs grow larger, having to manyally add a large number of (possibly different) forward 
      declarations to top of each file becomes extremely tedious
    - for ex., if we have a 5 file program, each of which requires 10 forward declarations, we'd need to 
      copy/paste in 50 forward declarations
- to address this issue, C++ programs take a different approach 


### header files 
- C++ code files are not the only files commonly seen in C++ programs 
    - other type of file is called a __header file__ 
        - usually have a __.h__ extension
        - will occasionally see them with a __.hpp__ extension or none at all 

### using std lib header files 
- consider the following program: 
```cpp
#include <iostream> 

int main() 
{
    std::cout << "Hello, world";

    return 0;
}
```
- this program prints text to the consolve using _std::cout_ 
    - however, this program never provided a definition or declaration for __std::cout__, so how does the compiler 
      know what _std::cout_ is? 
        - A: _std::cout_ has been forward declared in the "iostream" header file 
        - when we __#include <iostream>__, we're requesting that the preprocessor copy all of the content (including
          forward declarations for std::cout) from the file names __"iostream"__ into the file doing the #include 

### key insight 
- header files allow us to put declarations in one place & then import them wherever we need them 
    - can save a lot of typing in multi-file programs 


### using header files to propogate forward declarations 


