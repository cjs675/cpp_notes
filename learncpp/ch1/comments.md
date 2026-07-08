## comments 

- **single line comments** 
```c++
std::cout << "Hello COP3003"; // Everything from here to EOL is ignored 
```
- single line comments typically used to make quick comments about a __single__ line of code 
- often placed above the line it is commenting as such: 
```c++
// preprocessor directive 
#include <iostream> 
// main function 
int main() 
    // charachter output function 
{
    std::cout << "Hello COP 3003";
    // return statement   
    return 0;
}
``` 

- __multiline comments__
- /* & */

```c++
/* This is a multiline comment.
   This line will be ignored. 
   So will this one. 
 */
```
- not to be used within other multi-line comments 

- __good__ comments give readers a good idea of what the library, program or function is trying to accomplish w/o having to look at the actual code 
  - user can then tell at a glance whether the code is relevant to what he or she is trying to accomplish 
- _within_ a library program, or function, comments can be used to describe _how_ the code is going to accomplish its goal 
  - give user an idea of how the code is going to accomplish its goal w/o having to understand what each individual line of code does 
- at the __statement__ level, comments should be used to describe __why__ the code is doing something 
  - a __bad__ statement comment explains __what__ the code is doing 

- __Bad__ comment: 
```c++
// Set sight range to 0
sight = 0;
```
- Reason: can already see sight is being set to 0 by looking at statement 
- __Good__ comment: 
```c++
// The player just drank a potion of blindness & cannot see anything 
sight = 0;
```
- Reason: now we know why the player's sight is being set to 0 

- comments are often times a great way to remind yourself (or others) the reason one decision was made instead of another  
- comments should be written in a way that make sense to someone who has no idea what the code does 
- __don't__ assume you'll remember why you made specific choices 

- at the library, program or function level -> use comments to describe _what_ 
- inside the library, program, or function -> use comments to describe _how_ 
- at the statement level -> use comments to describe _why_ 