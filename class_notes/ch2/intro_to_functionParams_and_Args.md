## intro to function parameters & arguments 

### function parameters & arguments 
- in many cases, its useful to be able to pass information to a function being called so that the function has data to work with 
  - ex. if we wished to write a function to add two numbers, we need some way to tell the function which two numbers to add when we call it 
    - otherwise, how would the function know what to add? 
    - this is accomplished via function parameters & arguments  
- __function parameter__ 
  - variable used in the header of a function 
  - work almost identically to variables defined inside the function with __one difference__: 
    - they are initialized with a value provided by the caller of the function 
  - defined in function headers by placing them in between the parenthesis after the function name, with multiple parameters being separated 
    by commas 
```c++
// this function takes no parameters 
// it doesn't rely on the caller for anything 
void doPrint() {
 
    std::cout << "In doPrint()\n";
}
// this function takes on integer param named x 
// the caller will supply the value of x 
void printValue(int x) {
    
    std::cout << x << '\n';
}

// this function has two integer params, one named x & one named y 
// the caller will supply the value of both x & y 
int add(int x, int y) {
    
    return x + y;
}
```
- __argument__ 
- value passed _from_ the caller _to_ the function when a function call is made
- multiple arguments are separated by commas 
```c++
doPrint();  // this call has no arguments 
printValue(6);  // 6 is the argument passed to function printValue()
add(2, 3);  // 2 & 3 are the arguments passed to function add() 
```

### how parameters & arguments work together 
- when a function is called, all of the parameters of the function are created as variables 
  - value of each of the arguments is _copied_ into the matching parameter (using __copy initialization__)
  - this process aka __pass by value__ 
- function parameters that utilize pass by value are called __value parameters__ 
```c++
#include <iostream> 

// this function has two integer parameters, one named x & one named y
// the values of x & y are passed in by the caller 
void printValues(int x, int y) {
    
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int main() {
    
    printValues(6, 7);  // this function call has two arguments, 6 & 7
    
    return 0;
}
```
- when function _printValues_ is called with args 6 & 7, _printValue's_ parameter x is created & initialized with the value of 6
  and _printValue's_ parameter y is created & initialized with the value of 7 

```c++
#include <iostream> 

int getValueFromUser() {
    
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    
    return input;
}

void printDouble(int value) // this function now has an integer parameter 
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main() {
    
    int num { getValueFromUser() };
    printDouble(num)
    
    return 0;
}
```
- in the above program, variable _num_ is first initialized with the value entered by the user 
  - then, function __printDouble__ is called, & the value of arg _num_ is copied into the _value_ parameter of function __printDouble__ 
  - function __printDouble__ then uses the value of parameter __value__ 



### using return values as arguments 
- we can simplify the above program as follows: 
```c++
#include <iostream> 

int getValueFromUser() {
    
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    
    return input;
}

void printDouble(int value) {
    
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main() {
    
    printDouble(getValueFromUser());
    
    return 0;
}
```
- the above program now uses the return value of function __getValueFromUser__ directly as an argument to function __printDouble__ 


### how params and return values work together 
- by using both parameters and a return value, we can create functions that take __data__ as input, do some calculation with it, & return 
  the value to the caller 
```c++
#include <iostream> 

// add() takes two integers as params, returns the result of their sum
// the values of x & y are determined by the function that calls add() 
int add(int x, int y) {
    
    return x + y;
}

// main takes no parameters
int main() {
    
    std::cout << add(4, 5) << '\n'; // args 4 & 5 are passed to the function add() 
    
    return 0;
}
``` 
- in the second statement within [functionsWithArgs2](./examples/functionParamsWithArgs2)program, the args are expressions that get evaluated __before__ being passed in 
  - in this case, 1 + 2 evaluates to 3, so 3 is copied to parameter x 
  - 3 * 4 evaluates to 12, so 12 is copied to parameter y 
  - _add(3, 12)_ resolves to 15


### unreferenced parameters & unnamed parameters 
- in certain cases, we'll encounter functions that have parameters that aren't used in the body of the function 
  - aka __unreferenced parameters__ 
  - __ex.__ 
```c++
void doSomething(int count) // warning: unreferenced parameter count 
{
    // this function used to do something with count but isn't used any longer 
}

int main()
{
    doSomething(4);
    
    return 0;
}
```
- just like unused local variables, compiler will probably warn that variable __count__ has been defined but not used 
- in a function def, the name of a function parameter is __optional__ 
  - therefore, in cases where a function parameter needs to exist but is not used in the body of the function, we can simply __omit__ the name 
  - a parameter w/o a name is called an __unnamed parameter__ 
```c++
void doSomething(int) // ok: unnamed parameter will not generate a warning 
{
    
}
```
- __Google C++__ style guide recommends using a comment to document what the unnamed parameter was: 
```c++
void doSomething(int /*count*/)
{
    
}
```

### cases where having an unused parameter might be useful 
- in the case we're writing a function with a single parameter, perhaps in the future the function is updated in some way, and 
  the value of the parameter is no longer needed 
  - if the now-unused function parameter were simply removed, then every existing call to the function would break (b/c the function
    call would be supplying more agrs than the function accepts)
  - would require finding every call to the function & remove the unneeded arg - lots of work & retesting 
  - so, we might leave the parameter as is & have it do nothing 
- when we need to determine something from the type (rather than the value) of a __type template parameter__

- __best practice:__ 
  - when a function parameter exists but is not used in the body of the function, do __not__ give it a name 
    - can optionally put a name inside a comment 

### conclusion 
- function params & return vals are key mechanisms by which functions can be written in a reusable way, as it 
  allows us to write functions that can perform tasks  & return retrieved or calculated results back to the 
  caller w/o knowing what the specific inputs/outputs are ahead of time 

