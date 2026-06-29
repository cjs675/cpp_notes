#include <iostream> 

// definition of user-defined function doPrint() 
// doPrint() is the called function in this example 
void doPrint() 
{
    std::cout << "In doPrint()\n";
}

// definition of user-defined function main() 
int main()  
{
    std::cout << "Starting main()\n"; 
    // interrupt main() by making a function call to doPrint() 
    // main() is the caller 
    doPrint();

    // this statement is executed after doPrint() ends 
    std::cout << "Ending main()\n";

    return 0;
}

