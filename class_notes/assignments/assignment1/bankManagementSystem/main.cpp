/* 
* Program: Bank Account 
* Author: Chris Silva 
* Date: June 30, 2026
*
* Description: Program that defines a class for storing details of three employees 
*/



#include <iostream> 
#include <string> 

class BankAccount {

public: 
    std::string name;
    int accountNum;
    double balance;

    // Method to handle deposits 
    void deposit(double amount) {
        if (amount > 0) {

            // update balance to be incremented by input deposit amount 
            balance += amount; 

            std::cout << "Deposit Successful! New Balance: $" << balance << "\n";
        }

        // handle negative input deposit amounts 
        else {
            std::cout << "Deposit Failed: Amount must be > 0 \n";
        }
    }

    // Method to handle withdrawls 
    void withdraw(double amount) { 

        if (amount > balance) {
            std::cout << "Withdrawl Failed: Insufficient funds. \n";
        }

        else if (amount <= 0) {
            std::cout << "Withdrawl failed: Amount must be > 0.\n";
        }

        // update balance to be decremented by input withdrawl amount 
        else {
            balance -= amount;
            std::cout << "Withdrawl Successful. Remaining Balance: $" << balance << "\n";
        }
    }

    // Method to display customer details after transactions 
    void displayDetails() {
        std::cout << "\nCustomer Name: " << name << "\n";
        std::cout << "Account Number " << accountNum << "\n";
        std::cout << "Current Balance: $" << balance << "\n";
        std::cout << "---------------------\n";
    }
}; 


int main() {
    // Instantiation of customer of BankAccount class 
    BankAccount Customer;

    // Receive initial Customer info 
    std::cout << "Enter Customer (Name AccountNumber OpeningBalance): ";
    std::cin >> Customer.name >> Customer.accountNum >> Customer.balance;

    std::cout << "\n--- Transaction for " << Customer.name << " ----\n"; 

    // Double precision variables to hold user's transaction amount
    double depositAmount {};
    double withdrawAmount {};


    // Prompt user for deposit amount to then process  
    std::cout << "Enter amount to deposit: $";
    std::cin >> depositAmount;
    // pass given amount to deposit method 
    Customer.deposit(depositAmount);

    // Prompt user for withdrawl amount to then process 
    std::cout << "Enter amount to withdrawl: $";
    std::cin >> withdrawAmount;
    // pass given amount to withdraw method 
    Customer.withdraw(withdrawAmount);

    // Display transaction details 
    Customer.displayDetails();

    return 0;
}
