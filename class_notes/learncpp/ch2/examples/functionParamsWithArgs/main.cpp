#include <iostream> 

// this function takes no parameters 
// it doesn't rely on the caller for anything 
void doPrint() 
{
    std::cout << "In doPrint()\n";
}

// this function takes one integer parameter named x 
// the caller will supply the value of x 
void printValue(int x) 
{
    std::cout << x << '\n';
}

// this function has two integer parameters, one named x & one named y 
// the caller will supply the value of both x & y 
int add(int x, int y) 
{
    return x + y;
} 

int main() 
{
    doPrint(); // this call has no args 
    printValue(6);  // 6 is the arg passed to the function printValue
    std::cout << add(2, 3) << '\n';  // 2 & 3 is passed into the add function and returned via std::cout 

    return 0;
} 
