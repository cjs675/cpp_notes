#include <iostream>

int add(int x, int y) // x & y are created & enter scope here 
{
    // x & y are usable only within add() 
    return x + y;

}   // y & x go out of scope & are destroyed here 

int main() 
{
    int a { 5 };    // a is created, initialized, enters scope here 
    int b { 6 };    // b is created, initialized, enters scope here 

    // a & b are usable only w/in main() 

    std::cout << add(a, b) << '\n'; // calls add(5,6) where x = 6, y = 6

    return 0;
}   // b & a go out of scope & are destroyed here 


