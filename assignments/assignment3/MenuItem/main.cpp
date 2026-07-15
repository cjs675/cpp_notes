#include <iostream>  
#include <string>

using namespace std;


class MenuItem {
    
private: 
    string itemName;
    double price;
    int quantity;

public: 
    MenuItem() : itemName(""), price(0.00), quantity(0) {};
    MenuItem(const string& item, double price, int amount) 
        : itemName(item), price(price), quantity(amount) {}  

    void displayOrder() const {
        cout << itemName << " x " << quantity  << " = " << (price * quantity) << "\n";
    }
    
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

    // loop to display list & calculate total 
    for (int i = 0; i < 5; i++) { 
        orders[i].displayOrder();
        billTotal += orders[i].getItemTotal();
    }
    cout << "-------------------------------------";
    cout << "\nBill Total: " << billTotal << "\n";

    return 0;
}
