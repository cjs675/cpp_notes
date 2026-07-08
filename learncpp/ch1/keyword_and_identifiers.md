## keywords and naming identifiers 

### keywords 
- C++ reserves a set of __92__ words (as of C++23) for its own use 
  - called __Keywords__ 
  - each have a special meaning within the lang 
- [Link to list of identifiers](https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/)

### Identifier naming rules 
- name of a variable (or function, type or other kind of item) aka an __identifier__ 
- rules that must be followed when naming identifiers: 
  - cannot be a keyword (reserved) 
  - can only be compromised of letters (lower/upper case), numbers, and the underscore character 
    - cannot contain symbols nor whitespaces 
  - must begin with a letter (lower/upper case) or an underscore 
    - cannot start w/ a numbers 
  - C++ is __case sensitive__
    - distinguishes between lower & upper case letters 
    - __nvalue__ is different than __nValue__ is different than __NVALUE__ 

### Identifier naming best practices 
- conventional in C++ for vars to begin with a __lowercase__ letter 
  - if the variable name is a single word or acronym, the whole thing should be written in lowercase letters 
```c++

int value; // conventional 

int Value; // unconventional 
int VALUE; // unconventional 
int ValuE; // unconventional 
```
- most often, function names also start with a lowercase letter 
- identifiers that start with a __capital letter__ are typically used for __user-defined types__ 
  - i.e., structs, classes, enums 
- if the variable or function name is multi-word, there are 2 common conventions: 
  - words separated by underscores (__snake_case__)
  - intercapped (__camelCase__)

```c++
int my_variable_name;   // conventional (snake_case) 
int my_function_name(); // conventional (snake_case)

int myVariableName;    // conventional (camelCase) 
int myFunctionName();  // conventional (camelCase) 

int my variable name;  // invalid (whitespace not allowed) 

int MyVariableName;    // unconventional (should start w/ lower case) 
int MyFunctionName;    // unconventional (should start w/ lower case) 
```

- __best practice:__ 
  - when working in an existing program, use the conventions of that program (even if they dont conform to modern best practice) 
    - use modern best practices when you're writing __new__ programs 
    - avoid naming identifiers __starting__ with an underscore 
      - syntactically legal - reserves for OS, lib/compiler use 
  - name of identifiers should make clear what the value they're holding means
  - identifiers should be named in a way that would help someone who has no idea what your code does be able to figure it out as quickly as possible 
  - good rule of thumb: 
    - make length of an identifier proportional to how specific & accessible the identifier is 
      - an identifier that exists only for a few statements (in body of a function) can have a shorter name 
      - an identifier that is accessible from anywhere might benefit from a longer name 
      - an identifier that represents a non-specific number(anything the user provides) can have a shorter name 
      - an identifier that represents a specific value (length of an inseam in mm) should have a longer name 
  - avoid abbreviations (except when they're common & unambiguous(ex. num, cm, idx))
  - for variable declarations, it can be useful to use a common to describe what a variable is going to be used for, or to explain anything else that might not be obvious
```c++
/* Rather than naming the variable numCharsIncludingWhitespaceAndPunctuation 
 * a well placed on comment on or above the declaration line 
 * should help us figure it out
 */
 // a count of the number of chars in a piece of text, including whitespace and punctuation
 int numChars {};
```

