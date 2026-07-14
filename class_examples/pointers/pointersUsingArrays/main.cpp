#include <iostream>
using namespace std;

// simple class representing a student 
class Student {

public: 
    string name;
    int id;

    // constructor to initialize student object 
    Student(string n, int ID) {
        name = n;
        id = ID;
    }

    void display() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

int main() {
    Student students[3] = {
        Student("Allen", 101),
        Student("Charles", 102),
        Student("Norwin", 103)
    };
    // pointer to array of student objects 
    Student* ptr = students;

    // accessing array elements using pointers: \n";
    for (int i = 0; i < 3; i++) {
        (ptr + i) -> display(); // using pointer arithmetic to access elements 
    }
    return 0;
}
