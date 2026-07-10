#include <iostream> 
#include <vector> 

using namespace std;

// define a simple class 
class Student {

public: 
    string name;
    int age;

    // constructor

    Student(string n, int a) {
        name = n;
        age = a;
    }

    // function to display student details 
    void display() {
        cout << "Name: " << name << " , Age: " << age << endl;
    }
}; 


int main() {
    // create vector to store Student objects 
    vector<Student> students;

    // adding objects to the vector
    students.push_back(Student("Katring", 25));
    students.push_back(Student("Chris", 25));

    // display details of all students in the vector 
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    } 

    return 0;
}
