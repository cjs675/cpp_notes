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

    double accountBalance, depositAm;  

    cout << "\nEnter Initial Balance: $";
    cin >> accountBalance;

    cout << "\nEnter Deposit Amount: $";
    cin >> depositAm;

    cout << "\nInitial Bank Balance: $" << accountBalance << endl;

    acc_1.depositByValue(accountBalance, depositAm);
    cout << "\n[Value] After function call - Actual Balance: $" << accountBalance << endl;

    acc_1.depositByReference(accountBalance, depositAm);
    cout << "\n[Reference] After function call - Actual Balance: $" << accountBalance << endl;

    acc_1.depositByPointer(&accountBalance, depositAm);
    cout << "\n[Pointer] After function call - Actual Balance: $" << accountBalance << endl;


    return 0;
}
