#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    double balance = 0.0;
public:
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }
    void deposit(double amount, double checkAmount) {
        balance += amount;
        balance += checkAmount;
        cout << "Deposited: $" << amount << "In Cash" <<
                "Deposited: $" << checkAmount << "In Checks" << endl;
    }
    void deposit(string accountNum, double amount, string transferType) {
        balance += amount;
        cout << "Deposited: $" << amount << "In: " << accountNum <<
                "Via: " << transferType << " has been completed" << endl;
    }
};

int main() {
    Bank account_1;
    account_1.deposit(1000);
    account1.deposit(2000, 500);

    return 0;
}
