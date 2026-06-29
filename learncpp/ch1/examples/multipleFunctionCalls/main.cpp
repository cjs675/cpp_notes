#include <iostream> 

void doPrint() 
{
    std::cout << "In doPrint()\n";
}

// definition of function main 
int main() 
{
    std::cout << "Starting main()\n";
    doPrint(); // doPrint() called for first time 
    doPrint(); // doPrint() called for second time 
    std::cout << "Ending main()\n";

    return 0;

}
