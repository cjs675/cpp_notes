# intro to the preprocessor 

- prior to compilation, each code (.cpp) file goes through __preprocessing__ phase 
- in this phase, a program called the __preprocessor__ makes various changes to the text of the code file 
- the preprocessor doesn't actually modify the OG code files in any way 
    - rather --> all changes made by the preprocessor happen either temporarily in-memory or using temporary 
      files 
- strips out comments, ensures each code file ends in a newline 
- processes __#include__ directives 
- when the preprocessor has finished processing a code file, the result is called a __translation unit__ 
    - this translation unit is what is then compiled by the compiler 
- __translation:__ the entire process of preprocessing, compiling, linking 


### preprocessor directives 
- when the preprocessor runs, it scans throughthe code file (top to bottom) looking for preprocessor directives 
- __preprocessor directives__ (often just called directives) are instructions that start with a # symbol and end 
  with a newline 
  - tell the preprocessor to perform certain text manipulation tasks 
- the final output of the preprocessor contains __no directives__ -- only the output of the processed directive 
  is passed to the compiler 


### #Include 

- when we _#include_ a file, the preprocessor replaces the #include directive with contents of the included file 
- the included contents are then preprocessed, then the rest of the file is preprocessed
- consider the following program: 

```cpp

#include <iostream> 

int main() 
{
    std::cout << "Hello world";
    return 0;
}
```
- when the preprocessor runs on the above program, it will replace __#include <iostream>__ with the contents of the 
  file named "iostream" and then preprocess the included content and the rest of the file 

- __key insight:__ 
    - each translation unit typically consists of a single code (.cpp) file and all header files it #includes 
      (applied recursively, since header files can #include other header files) 

### macro defines 
- the _#define_ directive can be used to create a macro 
- in C++, a __macro__ is a rule that defines how input text is converted into replacement output text 
    - two basic types: 
        1. object-like macros 
        2. function-like macros  
- __function-like macros__ act like functions, and serve a similar purpose 
    - their use is generally considered __unsafe__, and almost anything they do can be done by a normal function 
- __object-like macros__ can be defined in one of two ways:  

```
#define IDENTIFIER 
#define IDENTIFIER substitution_text 
```
- b/c these (above) are preprocessor directives, (not statements) neither form ends with a semicolon 
- the identifier for a macro uses the same naming rules as normal identifiers: 
    - can use letters, numbers, underscores
    - cannot start with a number
    - should not start with an underscore 
- by convention, macro names are typically all uppercase, separated by underscores 

### object-like macros with substitution text 
- when the preprocessor encounters this directive, an association is made between the macro identifier and 
  _substitution_text_ 
    - all further occurrences of the macro identifier (outside of use in other preprocessor commands) are replaced 
      by the _substitution_text_ 
- object-like macros with substitution text are now mostly seen in legacy code, and is recommended to __avoid__ whenever possible 
    - global constants across multiple files can be shared instead (using inline variables) 

- consider the following program:  
```cpp

#include <iostream> 

#define MY_NAME "Alex"

int main() 
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}
```
- the preprocessor converts the above into the following: 
```cpp 
// the contents of iostream are inserted here 

int main() 
{
    std::cout << "My name is: " << "Alex" << '\n';

    return 0;
}
```
- which, when run, prints the output: ```My name is: Alex```  


### object-like macros w/o substitution text 
- object-like macros can also be defined w/o substitution text 
- for example: 
```cpp 
#define USE_YEN
```
- macros of this form work as expected: most further occurrences of the identifier is removed and replaced by nothing 
- while they may be useless for doing text substitution, doing so isn't what this form of directive is generally used for 
- unlike object-like macros with substitution text, macros of this form are generally considered __acceptable__ to use 


### conditional compilation 
- the _conditional compilation_ preprocessor directive allows you to specify under what conditions something will or won't 
  compile 
- quite a few conditional compilation directives, such as: 
    - _#ifdef_ 
    - _#ifndef_ 
    - _#endif_ 

- _#ifdef_ preprocessor directive allows the preprocessor to check whether an identifier has been previously defined via #define 
    - if so, the code between the #ifdef and matching #endif is compiled 
    - if not, the code is ignored 

- consider the following program: 
```cpp

#include <iostream> 

#define PRINT_JOE  

int main() 
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined 
#endif

#ifdef PRINT_BOB 
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined 
#endif

    return 0;
}
```
- b/c PRINT_JOE has been #defined, the line ```std::cout << "Joe\n"``` will be compiled 
    - b/c PRINT_BOB has not been #defined, the line ```std::cout << "Bob\n"``` will be ignored 
---
- #ifndef is the opposite of #ifdef, in that it allows you to check whether an identifier has _NOT_ been #defined yet 
```cpp

#include <iostream> 

int main() 
{
#ifndef PRINT_BOB
    std::cout << "Bob\n";
#endif

    return 0;
}
```
- this program prints "Bob", b/c PRINT_BOB was never #defined 

#### if 0
- one more common use of conditional compilation involves using _#if 0_ to exclude a block of code from being compiled 
  (as if it were inside a comment block): 

```cpp
#include <iostream> 

int main() 
{
    std::cout << "Joe\n";

#if 0 // dont compile anything starting here 
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif // until this point 

    return 0;
}
```
- the above code only prints "Joe", b/c "Bob" and "Steve" are excluded from compilation if the _#if 0_ preprocessor directive
- provides convenient way to "comment out" code that contains multi-line comments (which can't be commented out using another 
  multi-line comment due to multi-line comments being non-nestable) 
```cpp
#include <iostream> 

int main() 
{
    std::cout << "Joe\n";

#if 0   // dont compile anything starting here 
    std::cout << "Bob\n";
    /* Some 
     * multi-line
     * comment here 
    */
    std::cout << "Steve\n";
#endif // until this point 

    return 0;
}
```
- to temporarily re-enable code that has been wrapped in an __#if 0__, can change the __#if 0__ to __#if 1__ 


### macro substitution within other preprocessor commands 
- in most cases, macro substitution doesn't occur when a macro identifier is used within another preprocessor command 
    - one exception to this rule: 
        - most forms of #if and #elif do macro substitution w/in the preprocessor command 
```cpp
#define FOO 9 // macro substitution

#ifdef FOO // this FOO does not get replaced with 9 b/c it's part of another preprocessor directive
    std::cout << FOO << '\n';   // this FOO gets replaced with 9 b/c it's part of the normal code 
#endif
```

### the scope of #defines 
- directives are resolved before compilation, from top to bottom on a file-by-file basis 
- consider the following program: 

```cpp
#include <iostream> 

void foo() 
{
#define MY_NAME "Alex" 
}

int main() 
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}
```
- even though it looks like _#define MY_NAME "Alex"_ is defined inside function _foo_, the preprocessor doesn't understand 
  C++ concepts like functions 
  - therefore, this program behaves identically to one where _#define MY_NAME "Alex"_ was defined either before or 
    immediately after function _foo_ 
- to avoid confusion, will generally want to __#define__ identifiers outside of functions 
- b/c and #include directive replaces the #include directive with the content of the included file, an #include can copy directives 
  from the included file into the current file 
    - these directives will then be processed in order 
- for example, the following also behaves identically to the prior examples: 
```cpp
// Alex.h
#define MY_NAME "Alex" 
```
---
```cpp
// main.cpp
#include "Alex.h" // copies #define MY_NAME from Alex.h here 
#include <iostream>

int main() 
{
    std::cout << "My name is: " << MY_NAME << '\n'; // preprocessor replaces MY_NAME with "Alex" 

    return 0;
}
```
- once the preprocessor has finished, all defined identifiers from that file are discarded 
    - this means that directives are only valid from the point of definition to the end of file in which they are defined 
- directives defined in one file do not have any impact on other files (unless they are #included into another file)  
- for example: 

```cpp
// function.cpp
#include <iostream> 

void doSomething() 
{
#ifdef PRINT 
    std::cout << "Printing!\n";
#endif
#ifndef PRINT
    std::cout << "Not printing!\n";
#endif
}
``` 
```cpp
// main.cpp 
void doSomething(); // forward declaration for function doSomething() 

#define PRINT 
int main() 
{
    doSomething();

    return 0;
}
``` 
- the above program will print: 
```cpp
Not printing! 
```
- even though PRINT was defined in _main.cpp_, that doesn't have any impact on any of the code in _function.cpp_  
    - (PRINT is only #defined from the point of definition to the end of main.cpp)
