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
        d_length = w;
    }
    void setHeight(double h) {
        d_length = h;
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
    Rectangle r2;
    Rectangle r3;

    r1.calculateArea(10, 13);
    r1.calculateVolume(5, 9, 8);
    r1.calculateArea(15.2, 9.1);
    r1.calculateVolume(8.19, 12.34, 29.902);
    
    return 0;
}
