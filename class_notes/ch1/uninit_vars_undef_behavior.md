## uninitialized variables and undefined behavior 

### uninitialized variables 
- C++ does __not__ auto initialize most variables to a given value (such as zero) 
- when an uninitialized var is given a memory address to store data
  - default value of that variable is whatever (garbage) value happens to __already__ be in that memory address 
- __uninitialized variable__ 
  - variable that has not been given a known value (through initialization or assignment) 
- __initialized__
  - object is given a known value at the point of definition
- __assignment__ 
  - object is given a known value beyond point of definition 
- __uninitialized__ 
  - object has not been given a known value yet  

### undefined behavior 
- the result of executing code whose behavior isn't well-defined by the C++ lang 
  - itc, the C++ lang doesn't have any rules determining what happens if we use the value of a variable that has not been 
    given a known value 
- code implementing __undefined__ behavior may exhibit _any_ of the following forms: 
  - produces different results everytime it is run
  - consistently produces the same __incorrect__ result 
  - behaves inconsistently (sometimes output = correct, sometimes not) 
  - seems like its working but produces incorrect results later in the program 
  - crashes, either immediately or later 
  - works on some compilers but not others 
  - works until you change some other seemingly unrelated code 
- __rule:__ 
  - take care to avoid all situations that result in undefined behavior, such as using uninitialized behavior  

### implementation-defined behavior & unspecified behavior 
- a specific compiler & the associated std lib it comes with are called an __implementation__ 
- in some cases, the C++ lang std allows the implementation to determine how some aspect of the lang will behave, so that 
  the compiler can choose a behavior that is __efficient__ for a given platform 
  - __implementation-defined behavior__ 
    - behavior that is defined by the implementation 
    - must be documented & consistent for a given impl. 
- ex. 
```c++
#include <iostream> 

int main() {
    std::cout << sizeof(int) << '\n'; // print how many bytes of memory an int value takes 
    
    return 0;
}
```


### unspecified behavior 
- behavior is left up to the implementation to define, but the implementation is not required to document the behavior 
- generally want to __avoid__ implementation-defined & unspecified behavior, as it means our program may not work as expected if compiled 
  on a different compiler (or even on the same compiler if we change project settings that affect how the impl. behaves)

