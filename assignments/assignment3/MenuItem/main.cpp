#include <iostream> 
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
}; 


int main() {

    MenuItem 
}
