## why functions are useful & how to use them effectively 

### why use functions 
- why can't we put all the code inside the _main_ function? 
    - doable for simple programs 
- functions provide number of benefits that make them extremely useful in programs of non-trivial length or complexity 

### organization 
- as programs grow in complexity, having all code live inside main() becomes increasingly complicated 
- a function is almost like a mini-program that can be written separately from main w/o having to think 
  about rest of program while we write it 
- allows us to reduce complicated program into smaller, more manageable chunks, reducing overall complexity of our program

### reusability 
- once a function is written, it can be called multiple times w/in the program
- avoids duplicate code (DRY) & minimizes probability of copy/paste errors 
- functions can also be shared w/ other programs, reducing amount of code needed to be written from scratch 

### testing 
- b/c functions reduce code reduncandy, there's less code to test in the first place 
- also b/c functions are self-contained, once we've tested a function to ensure it works, we don't need 
  to test it again unless it is changed 
- this reduces the amount of code to be tested at one time, making it much easier to find bugs 

### extensibility 
- when we need to extend our program to handle a case it didn't handle before, functions allow us 
  to make the change in one place & have that change take effect every time the function is called 

### abstraction 
- in order to use a function, only need to know its name, inputs, outputs & where it lives 
- don't need ot know how it works, or what other code its dependent upon to use it 
- this lowers the amount of knowledge required to use other people's code (including everything in stdLib)

### effectively using functions 
- groups of statements that appear more than once in a program should generally be made into a function 
    - ex. if we're reading input from a user multiple times in the same way --> great candidate for a function 
        - output something multiple times in the same way --> great candidate for a function 
- code that has a well-defined set of inputs & outputs is a good candidate for a function (particularly if its complicated) 
    - ex. if we have a list of items we wish to sort, the code to do the sorting would make a great function,
          even if its done only once 
         - the input is the unsorted list, output = sorted list 
- function should generally perform one (__and only one__) task 
- when a function becomes to long, complicated, or hard to understand, it can be split up into multiple __sub-functions__ 
    - aka __refactoring__ 

