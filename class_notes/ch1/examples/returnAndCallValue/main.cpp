#include <iostream> 

// int is the return type 
// function will return some integer value back to the caller 
int returnFive() 
{
    // the return statement provides the value that will be returned 
    return 5;
}

int main() 
{
    std::cout << returnFive() << '\n';      // prints 5
    std::cout << returnFive() + 2 << '\n';  // prints 7
                                            
    returnFive();   
    return 0;
}                                            
