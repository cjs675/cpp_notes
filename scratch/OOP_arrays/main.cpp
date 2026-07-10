#include <iostream>

using namespace std;

class Employee {
    int id;
    char name[30];
public: 

    void getData() {
        cout << "Enter ID: " << endl;
        cin >>  id;
        
        cout << "Enter Name: " << endl;
        cin >> name;
    }

    void putData() {
        cout <<  id << " ";
        cout <<  name << " " << endl;

    }
};
int main() { 
    Employee emp_1;
    emp_1.getData();
    emp_1.putData();
    
    return 0;
}
