#include <iostream>
#include <string> 

using namespace std;

// base class 
class Animal {
public: 
    string name;

    void eat() {
        cout << name << " is eating.\n";
    }
};

// derived class 

// syntax: class Derived : visibility_mode Base
class Dog : public Animal {
public: 
    // body of derived class 
    void bark() {
        // can access 'name' b/c it was inherited publicly from Animal
        cout << name << " says WOOF!!\n";
    }
};


int main() {
    Dog myDog;

    // we can use the base class variables 
    myDog.name = "Buddy";

    // base class method
    myDog.eat();

    // derived class method 
    myDog.bark();


    return 0;
}
