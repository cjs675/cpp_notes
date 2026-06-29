#include <iostream> 

int main() 
{
    // ask user for a number 
    std::cout << "Enter a number: "; 
    // def var x to hold user input & initialize it  
    int x {};
    // get number from keyboard & store it in variable x 
    std::cin >> x; 

    std::cout << "\nYou entered " << x << '\n';
    return 0;
}
