/* 
* Program: Calculator 
* Author: Chris Silva 
* Date: June 30, 2026
*
* Description: A simple calculator that accepts two numerical inputs 
*              and outputs the result of addition, subtraction, 
               multiplication or division.
*/

#include <iostream> 


class Calculator {  

private: 
    double num1;
    double num2; 

public: 
    
    // Setters used to set values by the object 
   void setNums(double a, double b) {
       num1 = a;
       num2 = b;
    }
        
    // Takes two double-precision numbers, adds them & returns the result 
    double addNums() {
        return num1 + num2;
    }
        
    // Takes two double precision numbers, subtracts them & returns the result 
     double subNums() {
        return num1 - num2;
    }

    // Takes two double precision numbers, multiplies them & returns the result 
    double multiplyNums() {
        return num1 * num2;
    }

    // Takes two double precision numbers, divides them & returns the result 
    double divNums() {
        return num1 / num2;
    }
};

int main() { 
    
    // Initialization of variables to store input 
    double num1 {};
    double num2 {};
   
    // Receive input from user 
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Instantiation of Calculator object 
    Calculator Calc;    

    // Object setter called to load input into object 
    Calc.setNums(num1, num2);

    std::cout << "\n--- Calculator Results ---\n";
    std::cout << "Addition: " << Calc.addNums() << "\n";
    std::cout << "Subtraction: " << Calc.subNums() << "\n";
    std::cout << "Multiplication: " << Calc.multiplyNums() << "\n";
    std::cout << "Division: " << Calc.divNums() << "\n";

    // Object method calls 
    Calc.addNums();
    Calc.subNums();
    Calc.multiplyNums();
    Calc.divNums();

    return 0;

}
