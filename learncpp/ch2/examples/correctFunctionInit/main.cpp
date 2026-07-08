#include <iostream>

int getValueFromUser()
{
    int val {}; // val is a local variable  
    std::cout << "Enter a value: ";
    std::cin >> val;
    return val;
}

int main() 
{
    int num { getValueFromUser() }; // main does not need to pass anything 

    std::cout << "You entered " << num << '\n';

    return 0;
}


