#include <iostream>
using namespace std;

class Shape {
    public: 
        virtual double area() {
            return 0;
        }
};

class Rectangle : public Shape {
    private: 
        double width, height;
    public: 
        Rectangle(double w, double h) : width(w), height(h)  {}  

        double area() override {
            return width * height;
        }
};

class Triangle : public Shape {
    private: 
        double base, height;

    public: 
        Triangle(double b, double h) : base(b), height(h) {}

        double area() override {
            return 0.5 * base * height;
        }
};


int main() {
    
    return 0;
} 

Shape* shape1 = new Rectangle(5, 10);
Shape* shape2 = new Triangle(4, 6);

cout << "Area of Rectangle: " << shape1 -> area() << endl;
cout << "Area of Triangle: " << shape2 -> area() << endl;

delete shape1;
delete shape2;
