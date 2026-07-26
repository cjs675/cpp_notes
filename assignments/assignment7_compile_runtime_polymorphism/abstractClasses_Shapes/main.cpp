#include <iostream>
#include <string>
// Numbers library used to call constant of pi
#include <numbers>
using namespace std;

const double PI = std::numbers::pi;

// Abstract base class
class Shape {
public:
    // A pure virtual function
    // Every derived class must instantiate its own version
    // instead of inheriting the one defined in the base class
    virtual double area() = 0;
    virtual void draw() = 0;

    virtual ~Shape() {
        cout << "Shape Deleted!!" << endl;
    }
};
// Derived Class (1)
class Circle : public Shape {
private:
    double radius;
public:
    // Constructor used to initialize radius
    Circle (double r) : radius(r) {}

    // Overriding the pure virtual function
    // of the Shape class
    double area() override {
        return PI * radius * radius;
    }
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
    // Destructor to free memory allocated to Circle class
    ~Circle() {
        cout << "Circle memory freed" << endl;
    }
};

// Derived Class (2)
class Square : public Shape {
private: double sideLength;

public:
    // Constructor used to initialize length of side
    Square (double s) : sideLength(s) {}

    // Overriding the pure virtual function
    // of the Shape Class
    double area() override {
        return sideLength * sideLength;
    }

    void draw() override {
        cout << "Drawing a Square" << endl;
    }

    // Destructor to free memory allocated to Square class
    ~Square() {
        cout << "Square memory freed" << endl;
    }
};

int main() {
    // Pointer of Shape class created and allocated
    // to a derived object using 'new'
    Shape* shape_1 = new Circle(12.5);
    Shape* shape_2 = new Square(9.7);

    shape_1 -> draw();
    cout << "Area: " << shape_1 -> area() << "\n" << endl;

    shape_2 -> draw();
    cout << "Area: " << shape_2 -> area() << "\n" << endl;

    // Cleanup of allocated memory
    cout << "Cleaning up allocated memory...." << endl;
    delete shape_1;
    delete shape_2;
    
    return 0;
}
