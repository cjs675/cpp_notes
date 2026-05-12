## whitespace and basic formatting 
- term that refers to the characters that are used for __formatting__ purposes 
- in C++, primarily refers to: 
  - spaces 
  - tabs 
  - newlines 
- generally used for 3 things: 
  - separating certain language elements 
  - inside text 
  - formatting code 

### some language elements must be whitespace-separated 
- syntax of the lang requires that some elements are separated by whitespace 
- mostly occurs when two keywords or identifiers must be places consecutively, so the compiler can tell them apart
```c++
int x; // int and 
```
- a function's __return type__ and __name__ must be whitespace separated 

```c++
int main(); // int and main must be whitespace separated 
```
- when whitespace is required as a separator, the compiler doesnt care how much whitespace is used, as long as some exists
- single-line comments are terminated by a newline
<br>
<br>
- preprocessor directives (e.g. #include <iostream>) must be placed on __separate__ lines 
```c++
#include <iostream>
#include <string>
```

### quoted text takes the amount of whitespace literally 
- inside quoted text, the amount of whitespace is taken literally 
```c++
std::cout << "Hello world";
```
- is different than: 
```c++
std::cout << "Hello             World";
```
- newlines are __not__ allowed in quoted text: 
```c++
std::cout << "Hello "
          world"; // not allowed
```
### using whitespace to format code  
- whitespace is generally ignored 
  - this means we can use whitespace wherever we like to format out code in order to make it easier to read
  - statements may be split over multiple lines if desired 
- __ex.__ the following is harder to read than the succeeding alternative:
```c++
#include <iostream> 
int main() {std::cout<<"Hello World";return 0;}
```
```c++
#include <iostream>

int main() {
    std::cout << "Hello World";
    
    return 0;
}
```

### basic formatting 
- unlike other langs, C++ __doesn't__ enforce any kind of formatting restrictions 
  - for this reason, it is said that C++ is a __whitespace-independent__ language
- __recommendation:__
  - set tabs to 4 spaces worth of indentation 
- each statement with curly braces should start one tab in from the beginning of the function it belongs to 
```c++
int main() {
    std::cout << "hello COP3003\n"; // tabbed in one tab 
    std::cout << "nice to meet you.\n"; // tabbed in one tab 
}
```
- lines shouldn't be too long 
  - typically, __80 characters__ has been the defacto standard for max length a line should be 
```c++
int main() {
    
    std::cout << "An example of a long line which by any and all means should be"
                 "separated out\n"; // text aligned with prior for continuation
                                    // makes lines easier to read 
}
```
- if a long line is split with an operator (eg. << or +) the operator should be placed at the beginning of the next line, 
  instead of the current line
  - allows aligning of the operator on the left making code easier to read 
```c++
std::cout << 3 + 4
    + 5 + 6
    * 7 * 8;
```
- use whitespace to make code easier to read by aligning values or comments or adding spacing between blocks of code 
```c++
cost            = 57;
pricePerItem    = 24;
valuie          = 5;
numberOfItems   = 17;
```

```c++
std::cout << "Hello COP3003\n";                 //cout lives in the iostream lib
std::cout << "It is very nice to meet you\n";   // these comments are easier to read 
std::cout << "Indeed\n";                        // especially when all lined up 
```

```c++
// cout lives in the iostream lib
std::cout << "hello COP3003\n";

// these comments are easier to read 
std::cout << "it is very nice to meet you\n";

// when separated by whitespace 
std::cout << "Indeed\n";
```

#### best practice 
- when working in an existing project, be consistent with whatever style has already been adopted 


### automatic formatting 
- most modern IDEs will help format code as it is typed in 
- however when adding/removing/pasting block of code w/ different formatting, existing formatting can get messed up
  - modern IDEs typically contain an auto-format feature that can reformat a selection or an entire file 


### style guides 
- concise, opinionated document containing programming conventions, formatting guidelines & best practices 
  - __goal:__ ensure all devs on a project are programming in a consistent manner 
- some commonly referenced C++ style guides include: 
  - [C++ core guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
  - [Google](https://google.github.io/styleguide/cppguide.html)
  - [LLVM](https://llvm.org/docs/CodingStandards.html)
  - [GCC/GNU](https://gcc.gnu.org/codingconventions.html)



