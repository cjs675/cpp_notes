#include <iostream> 

int getValueFromUser() // return the value entered by user as an integer
{
    std::cout << "Enter an integer: ";
    int input { };
    std::cin >> input;

    return input; // return the value the user entered back to the caller 
}

int main() 
{
    int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()  
    
    std::cout << num << " doubled is: " << num * 2 << '\n';

    return 0;
}


                  

