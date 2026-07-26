#include <iostream>
using namespace std;

class Rectangle {

private:
    int i_length;
    int i_width;
    int i_height;
    float f_length;
    float f_width;
    float f_height;
    double d_length;
    double d_width;
    double d_height;

public:

    // Getters & Setters
    void setLength(int l) {
        i_length = l;
    }
    void setWidth(int w) {
        i_width = w;
    }
    void setHeight(int h) {
        i_height = h;
    }
    void setLength(double l) {
        d_length = l;
    }
    void setWidth(double w) {
        d_width = w;
    }
    void setHeight(double h) {
        d_height = h;
    }


    int getIntLength() {
        return i_length;
    }
    int getIntWidth() {
        return i_width;
    }
    int getIntHeight() {
        return i_height;
    }
    double getDoubleLength() {
        return d_length;
    }
    double getDoubleWidth() {
        return d_width;
    }
    double getDoubleHeight() {
        return d_height;
    }

    // Calculates area using integers
    int calculateArea(int l, int w) {
        return l * w;
    }

    // Calculates area using floats
    float calculateArea(float l, float w) {
        return l * w;
    }

    // Calculates area using doubles
    double calculateArea(double l, double w) {
        return l * w;
    }

    // Calculate volume using integers
    int calculateVolume(int l, int w, int h) {
        return l * w * h;
    }

    // Calculate volume using floats
    float calculateVolume(float l, float w, float h) {
        return l * w * h;
    }

    // Calculate volume using doubles
    double calculateVolume(double l, double h, double w) {
        return l * w * h;
    }

};

int main() {
    Rectangle r1;

    cout << "\nArea of Rectangle using Integers: " <<
         r1.calculateArea(10, 13) << endl;
    // Append input float values with 'f' to force compiler
    // to pass in floats
    cout << "Area of Rectangle using Floats: " <<
        r1.calculateArea(15.2f, 9.1f) << endl;
    cout << "Area of Rectangle using Doubles: " <<
        r1.calculateArea(10.284374, 5.9283741) << endl;

    cout << "Volume of Rectangle using Integers: " <<
        r1.calculateVolume(5, 9, 8) << endl;
    cout << "Volume of Rectangle using Floats: " <<
        r1.calculateVolume(8.19f, 12.34f, 29.902f) << endl;
    cout << "Volume of Rectangle using Doubles: " <<
        r1.calculateVolume(34.928324, 17.3849021, 29.01384) << endl;
    return 0;
}
