#include <iostream> 
#include <math.h>

using namespace std;

// area = (pi r)^2
// circumference (2 * pi * r) 

class Circle {

public: 
    double pi = 3.14;
    double radius;


    Circle() {
        radius = 5.5; 
        float square = pow(pi, radius);

        cout << "Area = " << square << endl;
        cout << "Circumference = " << 2 * pi * radius << endl;

    }
};


int main() {

    Circle();
}
