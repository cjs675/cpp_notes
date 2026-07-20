#include <iostream>
using namespace std;


class Base {
    public: 
        virtual void print() {
                cout << "Base function caled" << endl;
            }
};

class Derived:public Base {
    public: 
        void print() {
            cout << "Derived function is called" << endl;
        }
};


int main() {
    Derived d;
    Base* ptr = &d;  
    ptr -> print();
    return 0;
}
