#include <iostream>
using namespace std;

class Deposit {

    public:     
        Deposit () {}  
        
        // pass by value 
        // makes a local clone 
        void depositByValue(double b, double depositAm) { 
            b = b + depositAm;
            cout << "\n[Value] Inside function - Balance after deposit: $" << b << endl; 
        }
        // pass by reference 
        // modifies original value residing at respective 
        // memory address 
        void depositByReference(double &b, double depositAm) {
            b = b + depositAm;
            cout << "\n[Reference] Inside function - Balance after deposit: $" << b << endl;
        }
        // pass by pointer 
        // modifies original value by accessing it via 
        // its memory address 
        void depositByPointer(double *b, double depositAm) {
            *b = *b + depositAm;
            cout << "\n[Pointer] Inside function - Balance after deposit: $" << *b << endl;
        }
}; 

int main() {
    Deposit acc_1;

    double balance, depositAm;  

    cout << "\nEnter Initial Balance: $";
    cin >> balance;

    cout << "\nEnter Deposit Amount: $";
    cin >> depositAm;

    cout << "\nInitial Bank Balance: $" << balance << endl;

    acc_1.depositByValue(balance, depositAm);
    cout << "\n[Value] After function call - Actual Balance: $" << balance << endl;

    acc_1.depositByReference(balance, depositAm);
    cout << "\n[Reference] After function call - Actual Balance: $" << balance << endl;

    acc_1.depositByPointer(&balance, depositAm);
    cout << "\n[Pointer] After function call - Actual Balance: $" << balance << endl;


    return 0;
}
