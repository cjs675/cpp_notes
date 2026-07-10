#include <iostream> 
#include <vector> 

using namespace std;

class Rectangle {

public: 
    double length;
    double width;

    // constructor 
    Rectangle( double l, double w ) {
        length = l;
        width = w;
    }

    // function to calculate area 
    double calcArea() {
       return length * width;;
    }

    // function to calculate perimeter 
    double calcPerim() {
        return length * 2 + width * 2;
    }

    // function to display area  
    void displayArea() {
        cout << "Area: " << calcArea() << endl; 
    } 

    void displayPerim() {
        cout << "Perimeter: " << calcPerim() << endl;
    }
};

int main() {

    Rectangle myRect(5.0, 3.0);

    myRect.displayArea();
    myRect.displayPerim();

}
