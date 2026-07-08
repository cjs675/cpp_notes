## intro to literals and operators 

### literals 
- aka a __literal constant__ is a fixed value that has been inserted directly into source code 
- have both a value and a type 
- unlike a variable (whose value can be set & changed through initialization and assignment respectively) 
  the value of a literal is fixed and __cannot__ be changed 
- the literal __5__ always has the value __5__ 
  - such is why literals are called constants 
```c++
// Hello World is a literal (string literal)  
std::cout << "Hello World";
// 5 is a literal 
int x { 5 };
```
- the following program shows the difference between literals and variables 
```c++
#include <iostream> 

int main() {
    
    std::cout << 5 << '\n';     // print the value of a literal 
    
    int x { 5 };
    std::cout << x << '\n';     // print the value of a variable 
    return 0;
}
```
- on __line 5__ we print the value __5__ to the console
  - when the compiler compiles this, it will generate code that causes __std::cout__ to print the value __5__ 
  - this value __5__ is compiled into the executable & can be used directly 
- on __line 7__ we create a variable named __x__ and initializing it with the value __5__ 
  - the compiler will generate code that copies the literal value __5__ into whatever memory location is given to __x__ 
  - on __line 8__, when __x__ is printed, the compiler will generate code that causes __std::cout__ to print the value 
    at the memory location of __x__ (which has value 5) 
- therefore, both output statements do the __same thing__ 
  - itc of the literal, the value __5__ can be printed directly
  - itc of the variable, the value __5__ must be fetched from the memory the variable represents 
- this also explains why a literal is __constant__ while a variable can be changed 
  - a literal's value is placed directly in the executable, & the executable itself can't be changed 
    after it is created 
  - a variable's value is placed in __memory__, and the value of memory can be changed while the 
    executable is running 

### operators 
```
2 + 3 --> 2 & 3 = operands 
      --> +     = operator 
```
- in C++, operations work as expected: 
```c++
#include <iostream> 

int main() {
    
    std::cout << 1 + 2 << '\n';
    
    return 0;
}
```
- __return value__ 
  - the output value of an operation 
- in C++, __assignment__ (=) is an operator as well, as are: 
  - insertion (<<)
  - extraction (>>)
  - equality (==)
- types of operators: 
  - __unary__ 
    - act on one operand 
    - ex. __-__ 
    - given __-5__, __operator-__ takes literal operand __5__ and flips its sign to produce new output value __-5__ 
  - __binary__ 
    - act on two operands (left & right) 
    - ex. __+__ 
    - given __3 + 4__, __operator+__ takes left operand __3__ and right operand __4__ and applies addition to produce 
      new output value __7__ 
    - ex. insertion (<<) & extraction (>>)
    - take __std::cout__ or __std::cin__ on left side, & the value to output or variable to input to on the right side 
  - __ternary__ 
    - act on three operands 
    - ex. (conditional operator) 
  - __nullary__ 
    - act on zero operands 
    - ex. (throw operator)

### chaining operators 
- operators can be chained together such that the __output__ of one operator can be used as __input__ for another 
  operator 
- (ex.) 
    -  given the following: ```2 * 3 + 4``` 
      - multiplication operator goes first & converts left operand __2__ and right operand __3__ into return value __6__ 
      - becomes left operand for the plus operator 
      - next, plus operator executes, converting left operand __6__ and right operand __4__ into new value __10__ 
- follow __PEMDAS__ 

### return vals & side effects 
- most operators in C++ just use their operands to calculate a return value 
  - very few operators that don't produce return values (__delete__ and __throw__)
- some operators have additional behaviors 
- an operator (or function) that has some observable effect beyond producing a return value is said to have 
  a __side effect__
  - in C++, the term "side effect" is defined as an observable effect of an operator or function beyond producing
    a value 
    - (ex.) ```x = 5``` 
      - has side effect of assigning value __5__ to variable __x__ 
    - (ex.)
```c++
std::cout << 5
``` 
- has side effect of printing __5__ to the console 
 