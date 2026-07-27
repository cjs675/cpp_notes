#include <iostream>
using namespace std;

// compute square and cube of a number using templates 
// pass in int, float 

template <class T> 
class Calculator {

private: 
    T num1; 

public: 
    Calculator(T n1) {
        num1 = n1;
    }

    void displayResult() {
        cout << "Number: " << num1 << endl;
        cout << num1 << " Squared = " << square() << endl;
        cout << num1 << " Cubed = " << cube() << endl;
    }
    
    T square() {
        return num1 * num1;
    } 

    T cube() {
        return num
    }
    
};



int main() {
    
    return 0;
}
