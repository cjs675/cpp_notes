## 1.1 statements & structure of a program 

- statement = type of ixn that cause the program to perform some action 
  - most common type of ixn in a C++ program 
  - smallest independent unit of computation in C++ lang 
- many types: 
  - declaration 
  - jump
  - expression
  - compound 
  - selection (conditionals)
  - iteration (loops)
  - try blocks 
- statements typically grouped into units called __functions__ 
  - collection of statements that get executed sequentially 
- __every__ C++ program must have a special function named __main__ 
  - when program is run - statements inside of __main__ are executed in sequential order 
- programs typically terminate after last statement inside function __main__ has been executed  
- name of function --> its __identifier__

### dissecting hello world 

```c++
#include <iostream> 

int main() 
{
    std::cout << "Hello World";
    return 0;
}
```
- __line 1__: preprocessor directive 
  - indicates we'd like to use the contents of the __iostream__ library 
    - allows us to read & write text from/to the console 
    - required in order to use __std::cout__ 
- __line 3__: tells compiler we're going to define a function whose name (identifier) is __main__ 
  - will produce a value whose type is __int__ 
  - brackets after tell compiler which lines are part of the main function (function body)
  - we then use the __character output__ function of the standard library (__std::cout__) 
- __line 6__: a return statement 
  - when an executable program finishes running, the program sends a value back to the OS in order to indicate whether it ran successfully or not 
    - this particular statements returns the __integer__ value __0__ to the OS, indicating everything went okay 
