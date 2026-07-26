#include <iostream>
#include <string>
using namespace std;

class Bank {
// Balance initiated to zero to guard against garbage values
private:
    double balance = 0.0;
public:
    // Method to deposit cash into account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposited: $" << amount
                 << " In Cash" << endl;
            cout << "Account Balance: $" << balance << endl;
        } else {
           cout << "Error: Deposit Amount must be greater than $0.00" << endl;
        }
    }
    // Method to deposit cash and check into account
    void deposit(double amount, double checkAmount) {
        if (amount > 0 && checkAmount > 0) {
            balance += amount;
            balance += checkAmount;
            cout << "\nDeposited: $" << amount << " In Cash"
                 << "\nDeposited: $" << checkAmount << " In Checks" << endl;
            cout << "Account Balance: $" << balance << endl;
        } else {
           cout << "Error: Deposit Amount must be greater than $0.00" << endl;
        }
    }
    // Method to perform online transfer of a given amount into account
    void deposit(string accountNum, double amount, string transferType) {
        if (!accountNum.empty() && amount > 0) {
            balance += amount;
            cout << "\nTransferred: $" << amount << " via: " << transferType
                 << " to account: " << accountNum << endl;
            cout << "Account Balance: $" << balance << endl;
        } else {
            cout << "Error: Invalid Account Number or Deposit Amount." << endl;
        }
    }
};

int main() {
    // Instantiation of Bank class object
    Bank account_1;

    account_1.deposit(1000);
    account_1.deposit(2000, 500);
    account_1.deposit("SAV1890131", 5000, "Online Transfer");

    return 0;
}
