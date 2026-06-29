#include <iostream> 

int main() 
{
    // define an int var named x 
    int x; // this var is uninitialized b/c it has yet to be given a value 
    
    // print value of x to the screen
    std::cout << x << '\n'; // who know's what we'll get b/c x is uninitialized
    
    return 0;
}
