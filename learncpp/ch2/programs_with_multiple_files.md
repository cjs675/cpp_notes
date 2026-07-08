## programs with multiple code files 

- as programs get larger, its common to split them into multiple files for organizational or reusability purposes 

### for GCC 
- to compile program with multiple files: need to include all relevant code files on the compiler line 
    - ex. _g++ main.cpp add.cpp multiply.cpp -o main_ 

### a multi file example 
- see: [Multi File Example](./examples/multiFileExample/main.cpp)
- the compiler compiles each file individiually 
    - it doesn't know about the contents of other code files, or remember anything it has seen from compiled 
      code files 
    - even though the compiler may have seen the definition of function _add_ previously (if it compiled add.cpp first), 
      it doesn't remember 
- this limited __visibility__ and short memory is intentional for a few reasons: 
    - it allows source files of a project to be compiled in any order 
    - when we change a source file, only that source file needs to be recompiled 
    - it reduces the possibility of naming conflicts between identifiers in different files 

- b/c the compiler compiles each code file individually (and then forgets what it has seen), each code 
  file that uses __std::cout__ or __std::cin__ needs to __#include <iostream>__ 

### key insight 
- when an identifier is used in an expression, the identifier must be connected to its defintion 
    - if the compiler has seen neither a forward declaration nor a definition for the identifier in the file being compiled, 
      it will error at the point where the identifier is used 
    - otherwise, if a definition exists in the same file, the compiler will connect the use of the identifier to its definition 
    - otherwise, if a definition exists in a different file (and is visible to the linker) the linker will connect the use of 
      the identifier to its definition 
    - otherwise, the linker will issue an error indicating that it couldn't find a definition for the identifier 

### summary 
- C++ is designed so that each source file can be compiled independently, with no knowledge of what is in other files 
    - therefore, the __order__ in which files are compiled should not be relevant 
- when we create a new code (.cpp) file, will need to add it to project so that it gets compiled 



