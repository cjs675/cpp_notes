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