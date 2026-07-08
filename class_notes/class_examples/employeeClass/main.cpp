/* 
* Program: Employee class with public & private member variables 
* Author: Chris Silva 
* Date: July 1, 2026
*
* Description: Program that creates a class called Employee with public member 
*              variables for name & private member variables for age, pay per 
*              month & counter. 
*              Implements member functions to set & get values of these variables.
*/



#include <iostream> 
#include <string> 


using namespace std;

class Employee {

// Explicit access method of employees set to public 

public:
    std::string name;

private:
    
    int age;
    double salaryPerMonth;
    std::string country; 


    

    // include get & set functions  
    void setName(const string& s) { 
        name = s; 
    }   

    void setAge(int a) {
        age = a;
    }

    void setSalaryPerMonth(double s) {
        salaryPerMonth = s;
    }

    void setCountry(const string& c) {
        country = c;
    } 



    int getAge() {
        return age;
    } 

    double getSalaryPerMonth() {
        return salaryPerMonth;
    }

    string getCountry() {
        return country; 
    }
    

    // Method which displays input about employees
    void displayInfo() {
        std::cout << "Employee Name: " << name << "\n";
        std::cout << "Employee age: " << Employee.age << "\n";
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
    std::cin >> Emp1.name >> Emp1.age>> Emp1.salaryPerMonth;
    
    std::cout << "Enter Employee 2 (Name ID Salary): ";
    std::cin >> Emp2.name >> Emp2.id >> Emp2.salary; 

    std::cout << "Enter Employee 3 (Name ID Salary): ";
    std::cin >> Emp3.name >> Emp3.id >> Emp3.salary;

    std::cout << "\n--- Employee Details ---\n";
    
    Emp1.displayInfo();
    Emp2.displayInfo();
    Emp3.displayInfo();

}
