// write c++ program that dynamically allocates memory for n employee 
// salaries & finds avg salary 



#include <iostream>
using namespace std;


class Employee { 
    
    private: 
        int employees;
        float *salary;
        
    public: 
        Employee(int e)  {
            salary = new int[employees]; 
        }


    void input() {
        cout << "\nEnter " << salary << " salary: \n";
        for (int i = 0; i < employees; i++) {
            cin >> salary[i];
        }
    } 



};
int main() {
    
    return 0;
}
