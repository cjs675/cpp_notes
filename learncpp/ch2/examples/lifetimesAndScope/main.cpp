#include <iostream>

int add(int x, int y) // x & y are created & enter scope 
{
    // x and y are usable only w/in add() 
    return x + y;
}   // y and x go out of scope and are destroyed here 

int main() 
{
    int a { 5 };    // a is created, initialized & enters scope here 
    int b { 6 };    // b is created, initialized & enters scope here 

    // a and b are only usable w/in main 

    std::cout << add(a, b) << '\n'; // calls add(5, 6) where x = 5 & y = 6
    
    return 0;

}   // b & a go out of scope & are destroyed here 




