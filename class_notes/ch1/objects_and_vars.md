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

### random access memory 
- main memory in a computer 
- when a program is run, system loads it into RAM 
- any data that is hardcoded into the program itself (e.g. text such as "Hello, world") is loaded at this point 
- OS also reserves some additional RAM for the program to use while its running 
  - common uses for RAM: 
    - store values entered by user 
    - store data read in from file/network 
    - store values calculated while the program 
  - so they can be used again later 

### objects & variables 
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


### variable definition 
- __definition__ 
  - declaration statement used to tell compiler we want to use a variable in our program 
```c++
int x; // define a variable named x (of type int) 
```
- at compile time, when encountering the statement above, the compiler makes a note to itself that we want 
  a variable with name __x__ & that the variable has data type __int__ 
  - compiler determines how much memory the object will need, in what kind of storage the object will be placed (RAM or CPU register), 
    where it will be placed relative to other objects, when it will be created & destroyed, etc. 

```c++
// full program containing a variable definition statement 
int main()
{
    int x; // definition of variable x 
    
    return 0;
}
```

### variable creation 
- at __runtime__ (when program is loaded into memory & run) each object is given an actual storage location (RAM, register) that it can use to store values 
  - __allocation__ process of reserving storage for an object's use 
    - once allocation has occurred, object has been created & can be used 
  - __ex.__ 
    - say variable __x__ is instantiated at memory location __140__ 
      - whenever the program uses variable __x__, it will access the value in memory location __140__ 
- an object is _created_ once actual storage has been reserved for the object's use 

### data types 
- determines what kind of value (e.g. a number, letter, text, etc.) the object will store 
- __key insight__: the data type of an object must be known at compile-time (so the compiler knows how much memory that object requires) 
- __integer__ type 
  - number that can be written without a fractional component (4, 27, 0, -2, -12) 

### defining multiple variables 
- possible to define multiple variables __of the same type__ in a single statement by separating the names with a comma 
- following is the same: 
```c++
int a;
int b;

int a, b;
```
- variables of different types must be defined in separate statements 
```c++
int a, double b; // wrong (compiler error) 

int a; double b; // correct (not recommended) 

// correct & recommended (easier to read) 
int a;
double b;
```
- __best practice__ 
  - define each variable in a separate statement on its own line 
  - use single-line comment to document what it is used for 

- __tldr;__ 
  - objects used to access memory 
  - named object -> variable 
  - each variable has: 
    - identifier
    - type (used to determine how the value in memory should be interpreted)
    - value 
  - variables created at runtime, when memory is allocated for their use 





