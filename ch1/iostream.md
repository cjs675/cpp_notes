## iostream: cout, cin, endl 

### the input/output library 
- the io library is part of the C++ std lib 
- deals with basic input & output 
- useful for getting input from the keyboard & output data to the console 
- to use the functionality defined w/in the _iostream_ library, must include the _iostream_ header at the top of any code
  file that uses the content defined in the _iostream_ like such:  
```c++
#include <iostream> 

// rest of code that uses iostream functionality here 
```
### std::cout
- the _iostream_ lib contains a few predefined variables for us to use 
- one of most common --> __std::cout__ 
  - allows us to send data to the console to be printed out as text 
  - can print text, numbers, value of variables 
  - uses the __insertion operator__ (__<<__)
```c++
#include <iostream> 

int main
{
    int x{ 5 }; // define integer variable x, initialized with value 5 
    std::cout << x; // print value of x (5) to console 
    return 0; 
    
    // produces the result: 5
}
```

- the __insertion operator__ can also be used multiple times in a single statement to concatenate (link together) 
  multiple pieces of output 
```c++
#include <iostream> // for std::cout

int main() {
    std::cout << "Hello" << "World";
    return 0;
}
```
- __tip:__ 
  - useful to imagine the __<<__ operator (and __>>__ operator) as a conveyor belt that moves data in the direction indicated 
    - in the case where the content is conveyed to __std::cout__, it gets output 
```c++
#include <iostream> // for std::cout 

int main() {
    int x {5}; 
    std::cout << "x is equal to: " << x;
    return 0;
}
``` 

### using __std::endl__ to output a newline 
- separate output statements dont result in separate lines of output on the console 
- if we wish to print separate lines of output to the console, we need to tell the console to move the cursor to the next line 
  - we can achieve this by outputting a _newline__ 
- a __newline__ is an OS-specific character or sequence of characters that moves the cursor to the start of the next line 
  - one way to do so is to output __std::endl__ (which stands for "end line") 
```c++
#include <iostream> 

int main() {
    std::cout << "Hello" << std::endl; // std::endl will cause the cursor to move to the next line 
    std::cout << "My name is Chris" << std::endl;
    
    return 0;
} 
```
- __best practice:__ 
  - output a newline character whenever a line of output is complete 

 ### __std::cout__ is buffered 
- statements in our program request that output be sent to the console 
  - however, that output is typically not sent to the console immediately 
  - instead, the requested output "gets in line" & is stored in a region of memory set aside to collect such requests, 
    called a __buffer__ 
  - periodically, the buffer is __flushed__, meaning all the data collected in the buffer is transferred to its destination 
    in this case, the console 
  - this also means that if our program __crashes, aborts, or is paused__ before the buffer is flushed, any output still waiting 
    in the buffer won't be displayed 
- __unbuffered output__ 
  - each individual output request is sent directly to the output device 
- writing to a buffer is fast, transferring a batch of data to an output device is comparatively slow 
  - buffering can __significantly__ increase performance by batching multiple output requests together to minimize 
    the number of times output has to be sent to the output device 

### __std::endl vs \n__ 
- using __std::endl__ is often inefficient, as it does 2 jobs: 
  - outputs a new line (moving cursor to the next line of the console) 
  - flushes the buffer (which is slow) 
- if we output multiple lines of text ending with __std::endl__, we'll get multiple flushes which is slow & probably unecessary 
- when outputting text to console -> typically no need to explicitly flush the buffer 
  - C++'s output system designed to __self-flush__ periodically 
    - both simpler & more efficient to let it flush itself 
- to output a newline w/o flushing the output buffer, we use __\n__ (inside either single or double quotes) 
  - special symbol the compiler interprets as a __newline__ character 
  - moves the cursor to next line of the console w/o causing a flush, so it'll perform better 
  - also more concise to type & can be embedded into existing double-quoted text 
```c++
#include <iostream> 

int main() {
    int x { 5 };
    std::cout << "x is equal to: " << x << '\n'; // single quoted (by itself) (conventional) 
    std::cout << "Yep." << "\n";    // double quoted (by itself) (unconventional but ok) 
    std::cout << "And that's all, folks!\n"; // between double quotes in existing text (conventional) 
    
    return 0;
} 

```




