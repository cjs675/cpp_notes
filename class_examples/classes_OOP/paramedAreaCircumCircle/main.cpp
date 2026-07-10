#include <iostream> 

using namespace std;

class Employee {

public: 
    int id;
    string name;
    float salary;

    Employee(int i, string n, float s) {
        id = i;
        name = n;
        salary = s;
    }

    void display() 
    {
        cout << "*****************" << endl;  
        cout << "Employee ID :" << id << endl;
        cout << "Employee Salary :" << salary << endl;
        cout << "*****************" << endl;
    }
};


int main() { 
    // To do: 
    // figure out how to store classes in arrays 
    // ex. creating 800th employee
    // measure performance 
    Employee e1 = Employee(201, "Joel", 99000);
    Employee e2 = Employee(202, "Chris", 215000); 

    e1.display();
    e2.display();

    return 0;
}

