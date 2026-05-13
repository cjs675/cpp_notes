## intro to functions 
- a __function__ is a reusable sequence of statements designed to do a particular job 
- every executable program must have a function named __main()__ 
  - where the program starts execution when it is run 
  - as programs get larger, putting all the code inside __main()__ becomes harder to manage 
- functions provide a way to split our programs into small, modular chunks that are easier to organize, test and use 
- C++ __std lib__ comes with plenty or already-written functions for us to use 
- __user-defined functions__ 
  - functions written by oneself 
- a program will be executing statements sequentially inside one function when it encounters a function call
  - __function call__ 
    - tells CPU to interrupt current function & execute another function 
    - essentially puts a bookmark at current point of execution 
    - executes function named in function call 
    - aka an __invocation__
    - __returns__ to point it bookmarked & resumes execution  
- __caller:__ function initiating the function call 
- __callee:__ function being called (executed) 

### example of a user defined function 

```c++
returnType functionName() // function header - tells compiler about existence of the function
{
    // function body      (tells compiler what the function does) 
}
```
- just as variables have names, so do user-defined functions 
  - the _functionName_ is the __identifier__ of our user-defined function 
  - the parentheses after the identifier tell the compiler that a function is being defined 
- to __call__ a function, we use the function's name followed by a set of parentheses (e.g. __functionName()__)
- [See example illustrating a user-defined function being defined and called]()



