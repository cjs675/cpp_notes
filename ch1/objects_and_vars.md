## 1.3 -- intro to objects & vars 

- __data__: any info that can be moved, processed or stored by a computer 
- recall: 
  - programs are collections of ixns that manipulate data to produce a desired result 
- a program can acquire data to work with in many ways: 
  - from a file 
  - from a db 
  - over a network 
  - from user providing input on a keyboard 
  - from the programmer putting data directly into the source code of the program itself 
- __value__: a single piece of data 
  - common examples include: 
    - numbers (not quoted)
    - characters (placed between single quotes)
      - only a single symbol may be used 
      - 'H' or '$'
    - text (must be placed between double quotes)
      - "Hello" 
  - values placed directly into the source code known as __literals__ 
```c++
// for std::cout
#include <iostream> 

int main()
{
    std::cout << 5;         // print the literal number '5';
    std::cout << -6.7;      // print the literal number '-6.7';
    std::cout << 'H';       // print the literal character 'H';
    std::cout << "Hello";   // print the literal text 'Hello'
    
    return 0;
}
```

## random access memory 
- main memory in a computer 
- when a program is run, system loads it into RAM 
- any data that is hardcoded into the program itself (e.g. text such as "Hello, world") is loaded at this point 
- OS also reserves some additional RAM for the program to use while its running 
  - common uses for RAM: 
    - store values entered by user 
    - store data read in from file/network 
    - store values calculated while the program 
  - so they can be used again later 

## objects & variables 
- in C++, __direct memory access is discouraged__ 
- instead -> access memory indirectly through an object 
  - __object__ 
    - represents region of storage (RAM or register) that can hold a value 
    - also have associated properties 
  - "go get the value stored by this object" & we then let the compiler figure out how where & how to retrieve the value 
    - we can thus focus on using objects to store & retrieve values & not worry about where in memory those objects are actually being placed 
- __variable__ 
  - object with a name 
- an __object__ is used to store a value in memory 
  - a variable is an object that has a name (identifier) 






