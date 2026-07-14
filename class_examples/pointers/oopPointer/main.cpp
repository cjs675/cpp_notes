#include <iostream>
using namespace std;

class Student {

public: 
    string name;
    int age;

    void display() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};


int main() {
    Student s1;
    Student *ptr = &s1; // pointer to object 

    ptr -> name = "Alice";
    ptr -> age = 20;

    ptr -> display();   // Accessing class members using pointer 
    return 0;
}
