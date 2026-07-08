## void functions (non-value returning functions) 

### void return values 
- functions aren't required to return a value back to the caller 
- to tell the compiler that a function does not return a value, a return type of __void__ is used  
- a function that does not return a value aka a __non-value returning function__ (or a __void__ function)
```c++
#include <iostream>

// void means the functions does not return a value back to the caller 
void printHi() {
    std::cout << "Hi" << '\n';
    
    // this function does not return a value so no return statement is needed 
}
int main() {
    printHi();  // okay: function printHi() is called, no value is returned 
    
    return 0;
}
```
- in the above example, __printHi__ function has the useful behavior of printing "Hi" 
  - yet it doesnt return anything back to the caller 
  - for this reason __printHi__ is given a __void__ return type 
- when __main__ calls __printHi__, the code in __printHi__ executes & "Hi" is printed 
  - at the end of __printHi__, control returns to main & the program proceeds 

### void functions dont need a return statement 
- a void function will automatically return to the caller at the end of the function 
  - no return statement is required 
- return statements may be used in void functions 
  - will cause the function to return to the caller at the point where the return statement is executed 
    - this is the same thing that happens at the end of the function anyway, so its redundant 

- __best practice__ 
  - do not put a return statement at the end of a non-value returning function 

### void functions can't be used in expressions that require a value  
- some types of expressions require values 
- __ex.__ 
```c++
#include <iostream> 

int main() {
    
    std::cout << 5;     // ok: 5 is a literal value that's being sent to the console to be printed 
    std::cout << ;      // compile error: no value provided 
}
``` 
- in the above program, the value to be printed needs to be provided on the right-side of the __std::cout <<__ 
  - if no value is provided, the compiler will produce a syntax error 
  - since the second call to __std::cout__ doesn't provide a value to be printed, this causes an error 

- consider the following program: 
```c++
#include <iostream> 

// void means the function doesnt return a value to the caller 
void printHi() {
    
    std::cout << "Hi" << '\n';
}

int main() {
    
    printHi();  // okay: function printHi() is called, no value is returned 
    
    std::cout << printHi(); // compile error 
    
    return 0;
}
```
- the first call to __printHi()__ is called in a context which does not require a value 
  - since the function doesnt return a value, this is fine 
- the second call to __printHi()__ wont compile
  - function __printHi()__ has a __void__ return type, meaning it doesnt return a value 
  - however, the statement is trying to send the return value of __printHi__ to __std::cout__ to be printed 
  - __std::cout__ doesnt know how to handle this 
  - consequently, the compiler will flag this as an error 

### returning a value from a void function is a compile error 
- trying to return a value from a non-value returning function will result in a compilation error: 
```c++
#include <iostream> 

// this function is non-value returning 
void printHi() {
    
    std::cout << "In printHi()" << '\n';
    
    return 5;   // compile error: we're trying to return a value 
}
```

