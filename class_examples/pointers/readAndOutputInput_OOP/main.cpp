#include <iostream>
using namespace std;

class Number {
private: 
    int num;

public: 
    // constructor
    Number() {
        num = 0;
    }
    // member function to get input 
    void inputNumber(void) {
        cout << "Enter an integer: ";
        cin >> num;
    }
    // member function to display number 
    void displayNumber() {
        cout << "Num: " << num << endl;
    }
};
int main() {
    //declaring object to the class number 
    Number n;
    
    // input & display number using number object 
    n.inputNumber();
    n.displayNumber();

    // declaring pointer to object 
    Number* ptrN;
    ptrN = new Number; // creating & assigning memory

    // printing default value 
    cout << "Default value.." << endl;
    // calling member function with pointer
    ptrN -> displayNumber();

    // input values and print
    ptrN -> inputNumber();
    ptrN -> displayNumber();


    return 0;
}
