#include <iostream> 

int main() 

{
    std::cout << "Enter two numbers separated by a space: ";

    int x {}; // def var x to hold user input (and value-initialize it) 
    int y {}; // def var y to hold user input (and value-initialize it) 
    
    std::cin >> x >> y; // get two numbers & store in var x & y respecitvely 
    std::cout << "\nYou entered " << x << " and " << y << '\n';

    return 0;
}
