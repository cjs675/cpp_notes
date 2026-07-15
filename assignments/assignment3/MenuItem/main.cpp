#include <iostream>  
#include <string>

using namespace std;


class MenuItem {
    
private: 
    string itemName;
    double price;
    int quantity;

public:  
    // Parameterized constructor 
    MenuItem(const string& item, double price, int amount) 
        : itemName(item), price(price), quantity(amount) {}   
    /* 
    * Method to display order cost, calulated as 
    * price by quantity 
    */
    void displayOrder() const {
        cout << itemName << " x " << quantity  << " = " << (price * quantity) << "\n";
    }
    
    /*
    * Method to return item total as a
    * cost of type double   
    */
    double getItemTotal() const {
        return price * quantity;
    }
}; 


int main() {

    double billTotal = 0.00; 

    // create array of 5 orders using an initializer list 
    MenuItem orders[5] = {
        MenuItem("Lamb chops", 23.50, 2),
        MenuItem("Kielbasa and Jasmine Rice", 15.99, 1),
        MenuItem("Supreme Pizza", 29.99, 2),
        MenuItem("New York-Style Cheesecake", 12.99, 1),
        MenuItem("Salmon", 21.99, 1)
    }; 

    cout << "\n"; 

    /* For loop to display list & calculate total  
    *  which iterates through every order of each 
    *  individual item 
    */
    for (int i = 0; i < 5; i++) { 
        orders[i].displayOrder();
        billTotal += orders[i].getItemTotal();
    }
    cout << "-------------------------------------";
    cout << "\nBill Total: " << billTotal << "\n";

    return 0;
}
