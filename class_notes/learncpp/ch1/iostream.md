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
- __recall:__ 
  - single quotes used to represent single characters ('a' or '$')
  - double quotes used to represent text (zero or more characters)
- __best practice:__ 
  - prefer __\n__ over __std::endl__ when outputting text to the console 


### __std::cin__ 
- character input 
- reads input from keyboard 
- typically use the __extraction__ operator __>>__ to put the input data in a variable (which can be used in subsequent statements)
```c++
#include <iostream> 

int main() 
{
  std::cout << "Enter a number"; 
  
  int x {};
  
  std::cin >> x;
  std::cout << "You entered " << x << '\n';
  
  return 0
}
```
- __note:__ 
  - no need to output ('\n') when accepting a line of input 
  - user will need to press __enter__ key to have their input accepted & this will move their cursor to the next line of the console 

- just as it is possible to output more than one bit of text in a single line, it's also possible to input more than one value on a single line
[View double char input example](../code_tests/doubleCharIn/main.cpp)

### __std::cin__ is buffered 
- adding data to the __end__ of a buffer & removing it from the front of a buffer ensures data is processed in the same order in which it was added 
  - aka __FIFO__ 
- similarly, _inputting_ data is also a two stage process: 
  1. individual chars entered as input are added to the end of an input buffer (inside __std::cin__)
    - the enter key (pressed to submit the data) also stored as a __'\n'__ character 
  2. the extraction operator '__>>__' removes characters from the front of the input buffer & converts them into a value that is assigned (via copy-assignment) to the associated value 
    - this variable can then be used in subsequent statements 
- each line of input data in the input buffer is terminated by a __'\n'__ character 
[View example showing different extraction methods](../code_tests/diff_extraction/main.cpp)
- __key insight:__
  - __std::cin__ is buffered b/c it allows us to separate the entering of input from the extract of input 
    - we can enter input once and then perform multiple extraction requests on it

#### the basic extraction process 
- simplified view of how __insertion__ operator __>>__ works for input 
  1. if __std::cin__ is not in a good state (e.g. prior extraction failed & __std::cin__ has not yet been cleared), no extraction is attempted 
     and the extraction process aborts immediately 
  2. leading whitespace chars (spaces, tabs, newlines at front of buffer) are discarded from input buffer. this will discard an unexpected newline char 
     remaining from a prior line of input 
  3. if the input buffer is now empty, operator __>>__ will wait for user to enter more data. any leading whitespace is discarded from the generated data 
  4. operator __>>__ then extracts as many consecutive chars as it can, until it encounters either a newline character (representing EOL of input) or a character
     that is not valid for the variable being extracted to
- the result of the extraction process is as follows: 
  - if the extraction __aborted__ in step 1, then no extraction attempt occurred. nothing else happens 
  - if __any__ characters were extracted in step 4 above, extraction is a success. the extracted chars are converted into a value that is then copy-assigned to the variable 
  - if __no__ characters could be extracted in step 4, extraction has __failed__. the object being extracted to is copy-assigned the value __0__ (as of C++11) and any future 
    extractions wil immediately fail (until __std::cin__ is cleared) 
- any non-extracted characters (including newlines) remain available for the next extraction attempt 
- example: 
```c++
int x {};
std::cin >> x;
```
- 3 diff input cases: 
  - if user types in __5a__ and enters, __5a\n__ will be added to the buffer. __5__ will be extracted, converted to an integer, & assigned to the variable __x__ 
    __a\n__ will be left in the input buffer for next extraction 
  - if user types 'b' and enters, __b\n__ will be added to the buffer 
    b/c __b__ is not a valid integer, no characters can be extracted, so this is an __extraction failure__. 
    variable __x__ would be set to __0__ and future extractions will fail until the input stream is cleared 
  - if __std::cin__ is not in a good state due to a prior failed extraction, nothing happens here. the value of variable __x__ is not altered 


### __operator <<__ vs __operator >>__ 
- __std::cin__ and __std::cout__ always go on the left-hand side of the operator 
- __std::cout__ -> output a value
  - uses __<<__ 
  - shows direction data is moving 
  - __std::cout << 4__ moves value __4__ to the console 
- __std::cin__ -> get an input value 
  - uses __>>__ 
  - shows direction the data is moving 
  - __std::cin >> x__ moves the value the user entered into variable __x__
[View example showing three uses of cin & cout](../code_tests/testThreeCinCout/main.cpp)

  



