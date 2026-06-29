/* TODO: 
 *  create a program that asks the user for an integer, waits for input 
 *  then outputs input of the number times two 
 *
 *  Program should produce the following: 
 *
 *  Enter an integer: 4
 *  Double that number is: 8
 */ 
#include <iostream> 

int main() 
{
    std::cout << "Enter an integer: ";
    
    // define variable num as an integer variable 
    int num {};  

    // get integer value from user's keyboard
    std::cin >> num;

    // define a new variable and initialize it with num * 2   
    // int doubleNum { num * 2 };
    /* while using a separate variable works, we can also do 
     * without creating a new variable to store a value which 
     * is only used one  
     */
    
    // print value of the doubled variable 
    //  std::cout << "Double that number is: " << doubleNum << '\n';  

    //  instead, use an expression to multiply num * 2 at the point where 
    //  it will be printed 
    std::cout << "Double that number is: " << num * 2 << '\n'; 
    return 0;
}
