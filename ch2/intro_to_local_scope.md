## intro to local scope 

### local variables 
- __local variables__ 
  - variables defined inside the body of a function 
```c++
int add(int x, int y) {
    
    int z{ x + y }; // z is a local variable 
    
    return z;
}
```
- function params are also considered to be local variables 
```c++
int add(int x, int y) // function parameters x & y are local variables 
{
    int z { x + y };
    
    return z;
}
```

### local variable lifetime
- function params are created & initialized when the function is entered, & variables w/in function body are created 
  & initialized at the __point of definition__ 
```c++
int add(int x, int y) // x & y are created & initialized here 
{
    int z { x + y };  // z created & initialized here 
    
    return z;
}
``` 
- __Q:__ when is an instantiated variable destroyed? 
  - __A:__ local variables are destroyed in the opposite order of creation, at the end of the set of curly braces in 
            which it is defined 
    - function parameters are destroyed at the end of the function 
```c++
int add(int x, int y) {
    
    int z{ x + y };
    
    return z;
} // z, y & x are destroyed here 
```
- an object's __lifetime__ is defined to be the time between its creation & destruction
- __Note:__
  - variable creation & destruction happen when the program is running (during runtime) instead of compile time 
  - therefore, lifetime is a __runtime property__ 
```c++
#include <iostream> 
void doSomething()
{
    std::cout << "Hello\n";
}

int main() 
{
    int x { 0 };    // x's lifetime begins here 
    
    doSomething();  // x is still alive during this function call 
    
    return 0;
}   // x's lifetime ends here 
```
- in the above program, the lifetime of __x__ runs from the point of definition to the end of the function __main__ 
  - this includes the time spent during the execution of function __doSomething__ 

### what happens when an object is destroyed? 
- in most cases -> nothing 
  - the object simply becomes invalid 
- any use of an object after it has been destroyed will result in undefined behavior 
- at some point after destruction, the memory used by the object will be __deallocated__ (freed up for reuse) 

### local scope (block scope) 
- an identifier's __scope__ determines where the identifier can be seen & used w/in the source code 
- when an identifier can be seen & used, we say it is __in scope__ 
- when an identifier cannot be seen, we cannot use it & it is said to be __out of scope__ 
- scope is a __compile time__ property, and trying to use an identifier when it is __not__ in scope will result in a compile error 
- the identifier of a local variable has __local scope__ 
  - an identifier with __local scope__ (aka __block scope__) is usable from the point of definition to the end of the innermost pair 
    of curly braces containing the identifier 
    - for function parameters, at the __end__ of the function 
    - this ensures local variables cannot be used _before_ the point of definition or _after_ they are destroyed 
- local variables defined in one function are also __not__ in scope in other functions that are called 

```cpp
#include <iostream>

// x is not in scope anywhere in this function 
void doSomething() 
{
    std::cout << "Hello\n";
}

int main() 
{
    // x cannot be used here b/c it's not in scope yet 
    int x { 0 };    // x enters scope here & can now be used w/in this function 
    
    doSomething();
    
    return 0;
}   // x goes out of scope here & can no longer be used 
```

### "Out of scope" vs "going out of scope" 
- an identifier is __out of scope__ anywhere it cannot be accessed w/in the code 
  - in the example above, the identifier __x__ is in scope from its point of definition to the end of the __main__ function 
  - the identifier __x__ is out of scope outside of that code region 
- the term "going out of scope" is typically applied to objects rather than identifiers 
  - an object is said to go out of scope at the end of the scope (curly brace) in which the object was instantiated 
  - in the example above, the object named __x__ goes out of scope at the end of the function __main__ 
- a local variable's lifetime ends at the point where it goes out of scope, so local variables are destroyed at this point 
- __Note:__ not all types of variables are destroyed when they go out of scope 


### example of scope & lifetimes 
- __recall:__ 
  - lifetime is a runtime property
  - scope is a compile-time property 
- [See Example](../examples/lifetimesAndScope/main.cpp)

### functional separation 
- considering the following program: (similar to program above) 

```cpp
#include <iostream>

int add(int x, int y) // add's x & y are created & enter scope here 
{
    // add's x & y are visible/usable w/in this function only
    return x + y;
}  // add's x & y go out of scope & are destroyed here 

int main() 
{
    int x { 5 };    // main's x is created, initialized & enters scope here 
    int y { 6 };    // main's y is created, initialized & enters scope here 

    // main's x & y are usable w/in this function only 
    std::cout << add(x, y) << '\n'; // calls function add() with x = 5, y = 6 

    return 0;

}   // main's x & y go out of scope & are destroyed here    

```
- even though function __main__ and __add__ both have variables named x & y, they are distinct
    - x & y in main have nothing to do with x & y in add 
- when inside of function __main__, the names x & y refer to main's locally scoped variables x & y
    - these variables can only be seen (and used) inside of __main__ 
    - same with __add__ -> variables w/in can only be seen & used by add 
- in short, neither __add__ nor __main__ know that the other function has variables w/ same names 
    - b/c scopes dont overlap, its always clear to the compiler which x & y are being referred to at any time 

#### key insight 
 - names used for function params or variables declared in a function body are only visible 
    w/in the function that declares them 
    - this means local variables w/in a function can be named w/o regard for the names of variables 
      in other functions 
    - helps keep functions independent 

### where to define local variables  
- in modern cpp, __best practice:__ local variables inside function body should be defined as close to their first use as reasonable 
```cpp
#include <iostream> 

int main() 
{
    std::cout << "Enter an integer";
    int x { };      // x defined here 
    std::cin >> x;  // and used here

    std::cout << "Enter another integer";
    int y { };      // y is defined here 
    std::cin >> y;  // and used here 

    int sum{ x + y }; // sum can be initialized with intended value 
    std::cout << "The sum is: " << sum << '\n';

    return 0;
}
```
#### best practice
- define local variables as close to their first use as reasonable 


### when to use function params vs local variables 
- function parameter should be used when the caller will pass in the initialization value as an argument 
- a local variable should be used otherwise 
- using a function parameter when a local variable should be used leads to code looking like this: 
```cpp
`
