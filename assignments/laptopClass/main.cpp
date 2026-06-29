#include <iostream>  
#include <string>

using namespace std;

class Laptop {
    private: 
        string Brand; 
        string Processor;
        float Price; 
        bool studentStatus;  


    // setters 
    public: 
        // string setters set to pass a reference to a string set as a constant 
        void setBrand(const string& s) {
            Brand = s;
        } 
        void setProcessor(const string& s) {
            Processor = s;
        }

        // primitive types like int, double, bool (lightweight) & can do w/o references 
        void setPrice(double p) {
            Price = p;
        }

        void setStudentStatus(bool s) {
            studentStatus = s;
        } 

    // getters 
       string getBrand() {
           return Brand;
       }

       string getProcessor() {
           return Processor;
       }
    
       double getPrice() {
           return Price;
       } 

       bool returnStudentStats() {
           return studentStatus;
       }
        



       void inputSpecs() {
           cout << "Enter a brand "
       }

        // custom method to print object's detials 
        void displaySpecs() {
            cout << "\n----- Laptop Specifications ------\n" << endl;
            cout << "Brand: " << Brand << endl;
            cout << "Processor: " << Processor << endl;
            cout << "Price: $" << Price << endl;

            // ternary operator used for displaying student status  
            cout << "Student Discount: " << (studentStatus ? "Yes" : "No") << endl; 
            cout << "Discount after Price: $" << calculateDiscount();
            cout << "\n----------------------------------\n" << endl;
        }

        double calculateDiscount() {  
            if (studentStatus) { 
                // return price at 20% discount 
                return Price * 0.80;
            } 
            // return regular base price if not a student
            return Price;
        }
};




int main() {
    Laptop laptopOne;

    laptopOne.setBrand("Dell"); 
    laptopOne.setProcessor("Intel I9"); 
    laptopOne.setPrice(2349.99);
    laptopOne.setStudentStatus(false);

    Laptop laptopTwo; 
    laptopTwo.setBrand("System76");
    laptopTwo.setProcessor("Intel Core Ultra 5 325");
    laptopTwo.setPrice(1849.00);
    laptopTwo.setStudentStatus(true);

    Laptop laptopThree;
    laptopThree.setBrand("Framework");
    laptopThree.setProcessor("Intel Core Ultra 3");
    laptopThree.setPrice(1599.99);
    laptopThree.setStudentStatus(true);

    laptopOne.displaySpecs(); 
    laptopTwo.displaySpecs(); 
    laptopThree.displaySpecs(); 

    return 0;
}


