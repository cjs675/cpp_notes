## naming collisions & an intro to namespaces 
- C++ requires that all identifiers be non-ambiguous 
- if two identical identifiers are introduces into the same program in a way that the compiler or linker 
  can't tell them apart, the compiler or linker will produce an error 
    - generally referred to as a __naming collision__ 
- if the colliding identifiers are introduced in the same file, the result will be a compiler error 
- if the colliding identifiers are introduced into separate files belonging to the same program, the result 
  will be a linker error 


### an example of a naming collission 
```cpp
// a.cpp

void myFcn(int x) 
{
    std::cout << x;
}
```
```cpp 
// main.cpp 

void myFcn(int x) 
{
    std::cout << 2 * x;
}

int main() 
{
    return 0;
}
```
- when the compiler compiles this program, it will compile _a.cpp_ & _main.cpp_ & each file will compile with no problems 
    - however, when the linker executes, it will link all the definitions in _a.cpp_ and _main.cpp_ together, 
      and discover conflicting definitions for function __myFcn()__ 
    - the linker will then abort with an error 
    - Note: this error occurs even though __myFcn()__ is never called 
- most naming collisions occur in two cases: 
    1. two or more identically named functions (or global vars) are introduced into separate files belonging to the same program.
       this will result in a linker error, as shown above
    2. tow or more identically named functions (or global vars) are introduced into the same file. this will result in a compiler error 
- as programs get larger & use more identifiers, the odds of a naming collision being introduced increases significantly
    - good news: C++ provides plenty of mechanisms for avoiding naming collisions 
    - __local scope:__ which keeps local variables defined inside function from conflicting with each other, is one such mechanism 
        - however, local scope __doesn't__ work for function names 


### scope regions 
- an area of source doe where all declared identifiers are considered distinct from names declared in other scopes 
- two identifiers with same name can be declared in separate scope regions w/o causing a naming conflict 
- within a given scope region, __all__ identifiers must be unique, otherwise a naming collision will result 
- __body__ of a function is one example of a scope region 
    - two identically-named identifiers can be defined in separate functions w/o issue -- b/c each function provides 
      a separate scope regions, there is no collision
    - however, if we try to define __two identically__ named identifiers w/in same function, a naming collision will result & 
      compiler will complain 


### namespaces 
- provides another type of scope regions (called __namespace scope__) that allows you to declare or define names inside of it 
  for the purpose of disambiguation 
- names declared in a namespace are __isolated__ from names declared in other scopes, allowing such names to exist w/o conflict 
- for ex., two functions with identical declarations can be defined inside different namespaces, & no naming collision or ambiuity will occur 
- may only contain declarations and definitions (e.g. variables & fuctions) 
    - executable statements are not allowed unless they're part of a definition (e.g. w/in a function)
- often used to group related identifiers in a large project to help ensure they don't inadvertently collide w/ other identifiers 


### the global namespace 
- in C++, any name that is not defined inside a class, function or a namespace is considered to be part of an implicitly-defined 
  namespaced called the __Global Namespace__ (aka global scope) 
- identifiers declared inside global scope are in scope from the point of declaration to the end of the file 
- although variables can be defined in the global namespace, this should generally __be avoided__ 
- for example:  

```cpp

#include <iostream> // imports declaration of std::cout into global scope

// all of the following statements are part of the global namespace 

void foo();     // okay: function forward definition 
int x;          // compiles but strongly discouraged: non-const global variable definition (w/o initializer) 
int y { 5 };    // compiles but strongly discouraged: non-const global variable definition (with initializer) 
x = 5;          // compile error: executable statements aren't allowed in namespaces 

int main()      // okay: function definition 
{
    return 0;
}

void goo();     // okay: a function forward declaration 

```


### the std namespace 


