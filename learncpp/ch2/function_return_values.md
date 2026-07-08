## function return values (value-returning functions) 
- consider the following program: 
```c++
#include <iostream> 

int main() {
    // get value from the user 
    std::cout << "Enter an integer: ";
    int num { };
    std::cin >> num;
    
    // print the value doubled 
    std::cout << num << " doubled is: " << num * 2 << '\n';
    
    return 0;
}
```
- the above program is composed of two parts: 
  - get value from user 
  - tell user what double that value is 
- in order to write a function that gets the value from the user, 
  we'd need to have the separate function __return__ the value entered

### return values 
- when writing a user-defined function, we must determine whether the function will return a value back to the caller or not
  - to return a value back to the caller - two things are needed: 
    - function has to indicate what __type__ of value will be returned 
      - done by setting the function's __return type__ 
    - must use a __return statement__ inside the function that will return a value 
      - indicates the specific value being returned to the caller 
      - consists of the __return__ keyword followed by an expression (aka __return expression__) 
        ending with a semicolon
- when the return statement is executed: 
  - the return expression is evaluated to produce a value 
  - the value produced by the return expression is copied back to the caller 
    - this copy is called the __return value__ of the function 
  - the function exits & control returns to the caller 
- the process of returning a copied value back to the caller is named __return by value__ 
- __Note:__ 
  - the return expression produces the value to be returned 
  - the return value is a copy of that value 
- a value-returning function will return a value each time it is called 
- See: [Example of a function that returns an integer value and a program that calls it](../examples/returnAndCallValue/main.cpp) 
  - __Note:__ 
    - return values won't be printed unless the caller sends them to the console via __std::cout__
- Challenge Program: 
  - See: [ReturningValueFromUser](../examples/ReturningValueFromUser/main.cpp)
    - when this program executes, the first statement in __main__ will create an __int__ variable named __num__ 
    - when the program goes to initialize __num__, it will see there is a function call to __getValueFromUser()__ so 
      it will go execute that function 
    - function __getValueFromUser__ asks the user to enter a value & returns that value back to caller __main()__ 
      - this return value is used as the initialization value for variable __num__ 
      - __num__ can be used as many times as needed within __main()__ 


### revisiting main() 
- how it works: 
  - when the program is executed, the OS makes a function call to __main()__ 
  - execution jumps to the top of __main()__ 
  - the statements in __main()__ are executed sequentially 
  - __main()__ then returns an integer (usually 0) and program terminates 
- in C++, there are two special requirements for __main()__: 
  - __main()__ is required to return an __int__ 
  - explicit function calls to __main()__ aren't allowed 
- C __does__ allow __main()__ to be called explicitly, so some C++ compilers will allow this for compatability reasons 
- global variables are initialized prior to the execution of __main__ 
  - if the initializer for such a variable invokes a function, then that function will execute prior to main 
    - (e.g. __Global Variables__)
  

### status codes 
- why do we return __0__ from main()? 
  - the return value from __main()__ is aka a __status code__ (aka exit code, return code)
  - __purpose:__ signal whether the program was successful or not 
- by convention, a status code of 0 means the program ran normally (program executed & behaved as expected) 
- __best practice:__ 
  - __main__ function should return the value 0 if the program ran normally 
- a non-zero status code is often used to indicate some kind of failure 
- the C++ standard defines __3 status codes:__ 
  - 0
  - EXIT_SUCCESS
  - EXIT_FAILURE 
- EXIT_SUCCESS & EXIT_FAILURE are preprocessor macros defined in the <cstdlib> header 
```c++
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE

int main() {
    return EXIT_SUCCESS;
}
```
- if we want to max portability, should only use __0__ or __EXIT_SUCCESS__ to indicate a successful termination, 
  or __EXIT_FAILURE__ to indicate an unsuccessful termination 

### a value-returning function that does not have a return value will produce undefined behavior 
- a function that returns a value is called a __value_returning function__ 
  - a function is value-returning if the return type is anything other than __void__ 
- a value-returning function _must_ return a value of that type (using a return statement), otherwise undefined behavior will result 
- in most cases, compilers will detect if you've forgotten to return a value
  - in more complicated cases it may not be able to properly determine whether the function returns a value or not in all cases 
- __Best Practice:__ 
  - make sure functions with non-void return types return a value in all cases 
  - failure to return a value from a value-returning function __will__ cause undefined behavior 
```c++
#include <iostream> 

int getValueFromUserUB(){ // this function returns an integer value
    std::cout << "Enter an integer: ";
    int input { };
    std::cin >> input;
    
    // note: no return statement
    
    /* this program will produce undefined behavior b/c getValueFromUserUB() 
     * is a value-returning function that does not return a value
     */
}

int main() {
    int num { getValueFromUserUB() }; // initialize num with return value of getValueFromUserUB() 
    
    std::cout << num << " doubled is: " << num * 2 << '\n';
    
    return 0;
}
```

### function main will implicitly return 0 if no return statement is provided 
- only exception to the rule that a value-returning function must return a value via a return statement is for function __main()__ 
  - will implicitly return value 0 if no return statement is provided 
  - best practice is to explicitly return a value from main, both to show intent & for consistency with other functions 


### functions can only return a single value 
- a value-returning function can only return a single value back to the caller each time it is called 
- __Note:__ the value provided in a return statement doesn't need to be literal - it can be the result of any valid expression, 
  including a variable or a call to another function that returns a value 
- there are various ways to work around the limitation of functions only being able to return a single value 

### the function author can decide what the return value means 
- the meaning of the value returned by a function is determined by the function's author 
  - some functions use return values as __status codes__ to indicate whether they succeeded or failed 
  - other functions return a calculated or selected value 
  - other functions return nothing (__void__)
- b/c of the wide variety of possibilities, it's a good idea to document your function with a __comment__ indicating 
  what the return values mean
  - (__ex.__) 
```c++
// function asks user to enter a value 
// return value is the integer entered by the user from the keyboard 
int getValueFromUser() {
    std::cout << "Enter an integer: ";
    int input { };
    std::cin >> input;
    
    return input; // return the value the user entered back to the caller 
}
```


### reusing functions 
```c++
#include <iostream> 

int main() {
    int x { };
    std::cout << "Enter an integer: ";
    std::cin >> x;
    
    int y { };
    std::cout << "Enter another integer: ";
    std::cin >> y;
    
    std::cout << x << " + " << y << " = " << x + y << '\n';
    
    return 0;
}
```
- while this program works, it's a bit redundant 
  - violated __D.R.Y.__ 
  - why? 
    - if we wished to change the text "Enter an integer: " to something else, we'd have to update it in two locations 
    - if we wished to initialize 10 variables instead of 2, would be even more redundant code 
      - making our programs longer & harder to understand + lot of room for types 
- update: (using __getValueFromUser__)
```c++
#include <iostream> 

int getValueFromUser() {
    std::cout << "Enter an integer: ";
    int input { };
    std::cin >> input;
    
    return input; // return the value the user entered back to the caller 


int main() {
    int x { getValueFromUser() };   // first call to getValueFromUser 
    int y { getValueFromUser() };   // second call to getValueFromUser 
    
    std::cout << x << " + " << y << " = " << x + y << '\n';
    
    return 0
}
```
- in this example we call __getValueFromUser__ twice: 
  - once to initialize variable x 
  - once to initialize variable y
- this saves us from duplicating code to get user input & reduces odds of making a mistake 
- once we know __getValueFromUser__ works, we can call it as many times as we desire 