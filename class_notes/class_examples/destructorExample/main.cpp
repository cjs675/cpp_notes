#include <iostream>  
// #include <conio.h> 

using namespace std;

class Hello {

public: 
    // constructor 
    Hello() {
        cout << "Constructor function is called" << endl;
    }

    // destructor
    ~Hello() {
        cout << "Destructor function is called" << endl;
    }

    void display() {
        cout << "Hello World...." << endl;
    }
}; 


int main() {
    // object created 
    Hello obj;
    obj.display();
    obj.display();
}
