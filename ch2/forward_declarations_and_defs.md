## 2.7 forward declarations & definitions  

```cpp
#include <iostream> 

int main() 
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y) 
{
    return x + y;
}
```
- this program won't compile because the compiler compiles the contents of the code sequentiallyh 
    - when the compiler reaches the function call _add()_, it doesn't know what _add_ is, because it 
      hasn't been defined at that point yet  
- we can solve this problem in 2 ways: 
    1. reorder the function definitions 
    2. use a __forward__ declaration 
- with reordering the definitions, we can place _main_ before the _add_ function 
    - however, this choice isn't always possible 
    - ex. a program could have two functions, _A_, & _B_ - if function A calls B, and function B calls 
      A, then there's no way to order the functions in a way that will make the compiler happy 
    - if we define A first, the compiler will complain it doesn't know what B is 
    - if we define B first, the compiler will complain it doesn't know what A is 
- a __forward declaration__ allows us to tell the compiler about the existence of a function before actually 
  defining the identifier 
    - in the case of functions, this allows us to tell the compiler about the existence of a function before we 
    define the function's body 
    - this way, when the compiler encounters a call to the function, it'll understand that we're making a function
      call & can check to ensure we're calling the function correctly, even if it doesn't yet know how or where 
      the function is defined 
    - to write a forward declaration, we use a __function declaration__ statement (aka a __function prototype__) 
    - the function declaration consists of the function's return type, name, & parameter types terminated with a semicolon 
        - the names of the parameters can be optionally included 
        - the function body is not included in the declaration
    ```cpp
    // function declaration for the add function 
    // function declaration includes return type, name, params & semicolon - no function body
    int add(int x, int y);
    ```
- og program that didn't compile using a function declaration as a forward declaration for function _add_: 
```cpp
#include <iostream> 

int add(int x, int y);  // forward declaration of add() (using a function declaration) 

int main() 
{
    std::cout << "The sum of 3 & 4 is: " << add(3, 4) << '\n';  // this works b/c we forward declared add() above
    return 0;

}

int add(int x, int y) // even though the body of add() isn't defined until here 
{
    return x + y;
}
``` 
- __worth noting__: function declarations don't need to specify names of the params 
    - since they're not considered to be part of the function declaration
    - we could have also written: 
 ```cpp
 int add(int, int); // valid function declaration  
 ```
- however, it is preferred to name out params (using the same names as the actual function) 
    - this allows us to understand what the function params are just by looking at the declaration


### why forward declarations? 
- most often used to tell compiler about the existence of some function that has been defined in a different code file 
    - reordering isn't possible in this scenario b/c the caller & callee are in completely __different__ files 
- can be used to define functions in an order agnostic manner 
    - allows us to define functions in whatever order maximizes organization or reader understanding 
- give us a way to resolve circular deps (times when we have two functions that call each other) 


#### best practice 
- when addressing compilation errors or warnings in our programs, resolve the __first__ issue listed & 
  then compile again 
- keep parameter names in function declarations


### declarations vs. definitions 

- __declaration__: tells the _compiler_ about the existence of an identifier and its associated type info
```cpp
int add(int x, int y); // tells the compiler about a function named "add" that takes two int params 
                       // and returns and int. no body 
int x;                 // tells the compiler about an integer variables named x 
```
- __definition:__ a declaration that actually implements (for functions and types) or instantiates (for variables) the identifier 
```cpp
// b/c this function has a body, it is an implementation of function add() 
int add(int x, int y) 
{
    int z { x + y };    // instantiates variable z

    return z;
}

int x;                  // instantiates variable x
```
- in C++, all definitions are declarations 
    - therefore, __int x;__ is both a definition & a declaration 

- conversely, __not all declarations are definitions__ 
- __pure declarations:__ declarations that aren't definitions 



