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



#### best practice 
- when addressing compilation errors or warnings in our programs, resolve the __first__ issue listed & 
  then compile again 




