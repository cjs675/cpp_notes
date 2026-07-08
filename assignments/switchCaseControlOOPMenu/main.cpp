#include <iostream> 
#include <string> 

class Menu {
private: 
    int itemsOrdered = 0;
    int totalBill = 0;



// initialize 2D arrays for 3 menus (Bf, Lunch, Dinner) 
    std::string items[3][3] = {
        {"Pancakes", "Omelet", "Fruit Bowl"},
        {"Burger", "Salad", "Wrap"},
        {"Steak", "Pasta", "Salmon"}
    };
    
    int prices[3][3] = {
        {6, 8, 5},
        {10, 9, 8},
        {18, 14, 16}
    };

    public: 
        void processOrder() {
            int mealTime, choice = -1;

            std::cout << "Select Time (0: Breakfast, 1: Lunch, 2: Dinner): ";
            std::cin >> mealTime; 

            if (mealTime < 0 || mealTime > 2) return;

            // while loop for ordering 
            while (choice != 0) {
                std::cout << "\n--- Menu ---\n";

                // traversing chosen array to print 3 options of respective menu 
                for (int i = 0; i < 3; i++) {
                    std::cout << i + 1 << ". " << items[mealTime][i] << " ($" << prices[mealTime][i] << ")\n";
                } 
                std::cout << "0. Checkout\nChoice: ";
                std::cin >> choice;

                //switch statement to handle logic 
                switch (choice) {
                    case 1: case 2: case 3: 
                        totalBill += prices[mealTime][choice -1];
                        itemsOrdered++;
                        std::cout << "Added " << items[mealTime][choice - 1] << ".\n";
                        break;
                    case 0: 
                        break;
                    default: 
                        std::cout << "Invalid choice.\n";
                }
            }
         }
        
        void displayReceipt() const {
            std::cout << "\n--- Receipt ---\n";
            std::cout << "Items: " << itemsOrdered << "\nTotal: $" << totalBill << "\n";
        }
    };

int main() {
   
    Menu order;
    order.processOrder();
    order.displayReceipt();

    return 0;
}

    

