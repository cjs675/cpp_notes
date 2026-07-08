/* 
* Program: Online Shopping Product Inventory
* Author: Chris Silva 
* Date: July 6, 2026
*
* Description: A mock program exemplifying an online shopping retailer 
*              which tracks available (and unavailable) inventory. 
*              Provides methods for performing sales, restocks and 
*              displaying current inventory. 
*/


#include <iostream>

/* macros to define color codes & then reset their usage   
*  we use the RESET directive so our color code terminates at that specified point  
*/
#define RED "\033[31m" 
#define GREEN "\033[32m"  
#define BLUE "\033[34m"
#define BOLDWHITE "\033[1m\033[37m"
#define RESET "\033[0m" 


using namespace std;


class Product {

private: 
    int productId;
    string productName;
    double unitPrice;
    int quantityInStock;

public: 
    // list initialized constructor 
    Product(int id, const string& name, double price, int quantity) 
        : productId(id), productName(name), unitPrice(price), quantityInStock(quantity) {
    }  

    // destructor
    ~Product() {
        cout << "\nProduct object: " << productName <<  RED << " destroyed\n" << RESET;
    }  

    // method to sell product, taking in and integer = desired amount 
    void sellProduct(int amountToSell) {
        cout << "\nRequesting sale of: " << amountToSell << " " << productName << "\n"; 

        // pre-check of available stock of respective product
        if (amountToSell <= quantityInStock) {
            quantityInStock = quantityInStock - amountToSell;
            
            cout << "\n" << GREEN << "Sale Successful" << RESET << " Number of remaining units: " << GREEN << quantityInStock << RESET << "\n";
        }
        else {
            cout << "\n" << RED << "Sale Unsuccessful" << RESET << " - Only: " << RED << quantityInStock << RESET << " units remain" << "\n";
        }
    } 

    // method to restock respective product 
    void restockProduct(int amountToRestock) {
        cout << BLUE <<  "\nRestocking: " << RESET << amountToRestock << " units of " << productName << "\n";

        // update existing inventory with amount restocked
        quantityInStock = quantityInStock + amountToRestock;
        cout << "\nRestock successful: New inventory count of " << productName << " is: " << BLUE <<quantityInStock << RESET << "\n";
    }

    // method to display item info
    void displayProductInfo() {
        cout << BOLDWHITE << "\n----- Product Details ------\n" << RESET;
        cout << "Product ID:           " << productId << "\n";
        cout << "Product Name:         " << productName << "\n";
        cout << "Unit Price:           " << unitPrice << "\n"; 
        cout << "Available Quantity:    " << quantityInStock << "\n"; 
    }
}; 

int main() {
    Product calculator(189283, "TI-84 Plus Calculator", 124.99, 10);
    Product speaker(2590219, "Google Home Speaker", 99.79, 25); 
    Product monitor(387240, "MSI 31in HD Curved Monitor", 325.99, 10);
    
    cout << BOLDWHITE << "\n---- E-RACE STORE INVENTORY -----\n" << RESET;
    calculator.displayProductInfo();
    speaker.displayProductInfo();
    monitor.displayProductInfo();

    calculator.sellProduct(5);
    speaker.sellProduct(25);

    calculator.sellProduct(10); 
    calculator.restockProduct(5);
    speaker.restockProduct(50);

   cout << BOLDWHITE "\n---- E-RACE STORE INVENTORY -----\n" << RESET; 
    calculator.displayProductInfo();
    speaker.displayProductInfo();
    monitor.displayProductInfo();
}
