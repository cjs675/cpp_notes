## variable assignment & initialization 
- preferred to define __one variable__ per line 
```c++
int main() {
    int x;    // define an integer variable named x (preferred) 
    int y, z; // define two integer variables, named y & z 
    
    return 0;
}
```

### variable assignment 
- after variable has been defined → can give it a value in a __separate__ statement using the __=__ operator 
  - this process known as __assignment__ 
  - __=__: assignment operator 
```c++
int main() {
    int width;  // define an integer variable named width
    width = 5;  // assignment of value 5 into variable width 
    
    // variable width now has value 5
    return 0;
}
```
- by default, assignment copies the value on the right-hand side of the = operator to the variable on the left-hand side of the operator 
  - aka __copy assignment__ 
- once a variable has been given a value, the value of the variable can be printed via __std::cout__ & the __<<__ operator 
- assignment can be used whenever we wish to change the value held by a variable 
```c++
#include <iostream>

int main() {
    int width;  //define variable named width 
    width = 5;  // copy assigment of value 5 into variable width 
    
    std::cout << width; // prints 5 
    
    width = 7;  // change value 
    
    return 0; 
}
```
- normal variables can only hold __one__ value at a time

### variable initialization 
- one downside of assignment is that assigning a value to a just-defined object requires __two__ statements: 
  - one to define the variable 
  - one to assign the value 
    - these two steps can be __combined__ 
- when an object is defined, we can optionally provide an initial value for the object 
- __initialization__ 
  - process of specifying an initial value for an object 
  - syntax used to initialize an object is called an __initializer__ 
```c++
#include <iostream>

int main() {
    int width { 5 };    // define variable width & initialize with initial value 5
    std::cout << width; // prints 5
    
    return 0;
}
```

### different forms of initialization 
- 5 common forms of initialization in C++ 
```c++ 
// default initialization (no initializer)
int a;   

// traditional initialization forms:  
int b = 5;   // copy initialization (initial value after equals sign) 
int c ( 6 ); // direct initialization (initial value in parentheses) 

// modern initialization forms (preferred): 
int d { 7 };    // direct-list-initialization (initial value in braces) 
int e { };      // value initialization (empty braces) 
```
- as of __C++17__ 
  - copy/direct/direct-list initialization behave identically in most cases 


### other forms of initialization 
- aggregate initialization 
- copy-list initialization 
- reference initialization 
- static-initialization, constant-initialization, dynamic-initialization 
- zero-initialization 

### default initialization 
- when no initializer is provided (such as for variable a above) 
  - performs no initialization 
  - leaves variable with an indeterminate value 

### copy-initialization 
- when an initial value is provided after an equals sign r
```c++
int width = 5; // copy initialization of value 5 into variable width 
```
- copies the value on the right hand side of the equals into the variable being created on the left-hand side 
- in the above snippet, variable __width__ will be initialized with value 5 
- used whenever values are implicitly copied, such as when passing args to a function by value, 
  returning from a function by value, or catching exceptions by value 

### direct initialization 
- when an initial value is provided inside parentheses 
```c++
int width ( 5 ); // direct initialization of value 5 into variable width 
```
- used when values are explicitly cast to another type (e.g. via __static_cast__) 

### list-initialization 
- __modern__ way to initialize objects in C++ 
- aka __uniform__ or __brace__ initialization  
- provides a way to initialize objects with a list of values rather than a single value 
- comes in two forms: 
```c++
int width { 5 };    // direct list initialization of initial value 5 into variable width (preferred) 
int height = { 6 }; // copy-list initialization of initial value 6 into variable height (rarely used) 
```
- introduced to provide a initialization syntax that works in almost all cases, behaves consistently & has an 
  unambiguous syntax that makes it easy to tell an object is being initialized 
- __key insight__: 
  - when we see __{ }__ we know an object is being __list-initialized__ 

#### list-initialization disallows narrowing conversions 
- one of primary benefits of __list-initialization__ is that "narrowing conversions" aren't allowed 
  - i.e., if we try to list-initialize a variable using a value that the variable can't safely hold, the compiler is required to produce 
    a diagnostic (compilation error or warning) to notify us 
  - ex. 
```c++
int main() {
    // an integer can only hold non-fractional values
    // initializing an int with fractional value (4.5) requires the compiler to convert (4.5) to a value an int can hold 
    // such a conversion is a narrowing conversion, since the fractional part of the value will be lost 
    
    int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversions 
    
    int w2 = 4.5; // compiles: w2 copy-initialized to value 4 
    int w3 (4.5); // compiels: w3 direct-initialized to value 4
    
    return 0;
}
```
- such restriction on narrowing conversions only applies to the list-initialization, not to any subsequent assignments to the variable 
```c++
int main() {
    int w1 { 4.5 }; // compile error: list-iniit does not allow narrowing conversion of 4.5 to 4
    
    w1 = 4.5;       // okay: copy-assignment allows narrowing conversion of 4.5 to 4
    
    return 0;
}
```

#### value-initialization and zero initialization 
- when a variable is initialized using an empty set of braces, a special form of list initialization called __value-initialization__ takes place 
  - in most cases, will implicitly initialize the variable to zero (or wtv value is closest to zero for a given type)
    - in cases where zeroing occurs, this is called __zero-initialization__ 
```c++
int width {}; // value initialization / zero-initialization to value 0
```
- for __class__ types, value initialization (and default initialization) may instead initialize the object to pre-defined default vals (which may be non-zero) 


### List initialization is the preferred form of initialization in modern C++ 
- list initialization (including value initialization) is __generally__ preferred over other initialization forms 
  - works in most cases (therefore most consistent) 
  - disallows narrowing conversions (normally not wanted) 
  - supports initialization with list of values 
- __best practice__ 
  - prefer direct-list-initialization or value initialization to initialize variables 

#### when should I initialize with { 0 } vs {}?  
- use __direct list initialization__ when you're actually using the initial value 
```c++
int x { 0 };    // direct list initialization with value 0
std::cout << x; // 0 value being used here 
```
- use __value initialization__ when the object's value is __temporary__ and will be replaced: 
```c++
int x {};       // value initialization
std::cin >> x;  // we're immediately replacing that value so an explicit 0 would be meaningless 
```

### initialize your variables 
- initialize variables __upon creation__ 
  - may choose to ignore this advice for a specific reason 
  - ex. --> performance critical section of code that uses a lot of variables 
  - choice is okay as long as its made _deliberately_ 
- __best practice__ 
  - initialize variables upon creation 

### instantiation 
- creation (allocation) and initialization 
- an instantiated object is sometimes called an __instance__ 
- most often applies to class type objects 

#### initializing multiple variables 
```c++
int a, b; // create variables a & b, but do not initialize them (not preferred) 

int a = 5, b = 6;       // copy initialization 
int c ( 7 ), d ( 8 );   // direct initialization
int e { 9 }, f { 10 };  // direct list initialization 
int i { }, j { };       // value initialization 
```
- __common pitfalls when initializing:__ 
```c++
int a, b = 5;     // wrong: a is not initialized to 5
int a = 5, b = 5; // correct: a & b are initialized to 5
```
- each variable __can only__ be initialized by its __own__ initializer 

#### the __[[maybe_unused]]__ attribute (C++17) 
- allow us to have unused variables without having compiler throw warnings/errors 
```c++
#include <iostream>

int main() {
    [[maybe_unused]] double pi { 3.14159 };    // Dont complain if pi is unused 
    [[maybe_unused]] double gravity { 9.8 };   // Dont complain if gravity is unused  
    [[maybe_unused]] double phi { 1.61803 };   // Dont complain if phy is unused 
    
    std::cout << pi << '\n';
    std::cout << phi << '\n';
    
    // compiler wont throw a warning about gravity being unused 
    
    return 0;
}
```
- should only be applied to selectively to variables that have a specific & legitimate reason for being unused 
  - e.g, b/c need a list of named values, but which specific values are actually used in a given program may vary 
  - otherwise, unused vars should be removed from the program 






