/* 
* Program: Employee Management System 
* Author: Chris Silva 
* Date: June 30, 2026
*
* Description: Program that stores details on three employees & then displays 
*              relevant details on each employee along with a bonus.
*/



#include <iostream> 
#include <string> 

class Employee {

// Explicit access method of employees set to public 
public:
    
    std::string name;
    int id;
    double salary;

    // Method which calculates & display the bonus for each employee
    void calcAndDisplayBonus() {
        double bonus {};

        // First condition: Salary <= $5000
        if (salary <= 5000) {
            bonus = salary * 0.15;
        }
        // Second condition: $5000 < Salary < $10000 
        else if (salary > 5000 && salary <= 10000) {
            bonus = salary * 0.13;
        }
        // Third condition: Salary > $10000 
        else { 
            bonus = salary * 0.10;
        }

        // Display of bonus for a given salary amount 
        std::cout << "Employee Bonus: $" << bonus << "\n";
    }


    // Method which displays input about employees
    void displayInfo() {
        std::cout << "Employee Name: " << name << "\n";
        std::cout << "Employee ID: " << id << "\n";
        std::cout << "Employee Salary: $" << salary << "\n";

        // Method call on calcAndDisplayBonus() to display bonus to respective Employee
        calcAndDisplayBonus();

        std::cout << "-----------------------------\n";
    }
};


int main() { 

    // Instantiation of Employee objects 
    Employee Emp1;
    Employee Emp2;
    Employee Emp3;
    
    // Input handling 
    std::cout << "Enter Employee 1 (Name ID Salary): ";
    std::cin >> Emp1.name >> Emp1.id >> Emp1.salary;
    
    std::cout << "Enter Employee 2 (Name ID Salary): ";
    std::cin >> Emp2.name >> Emp2.id >> Emp2.salary; 

    std::cout << "Enter Employee 3 (Name ID Salary): ";
    std::cin >> Emp3.name >> Emp3.id >> Emp3.salary;

    std::cout << "\n--- Employee Details ---\n";
    
    Emp1.displayInfo();
    Emp2.displayInfo();
    Emp3.displayInfo();

}
