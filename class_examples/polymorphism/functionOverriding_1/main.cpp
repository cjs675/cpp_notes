#include <iostream>
using namespace std;

class Animal {
    public: 
        virtual void makeSound() {
            cout << "Some generic animal sound" << endl;
        }
};

class Dog : public Animal {
    public: 
        void makeSound() override {
            cout << "Bark" << endl;
        }
};

class Cat : public Animal {
    public: 
        void makeSound() override {
            cout << "Meow" << endl;
        }
};


int main() {
    Animal* animalPtr; 


    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr -> makeSound();

    animalPtr = &cat;
    animalPtr -> makeSound();


    Animal a;
    a.makeSound(); 

    return 0;
}
