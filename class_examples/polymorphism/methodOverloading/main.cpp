#include <iostream>
using namespace std;

class Rectangle {
    public:  

        void Area() {
            int a;
            int b;
            
            cout << "Enter a length: ";
            cin >> a; 
            cout << "Enter a width: ";
            cin >> b;
            cout << "Area = " << a * b << endl;
        }

        int Area(int x, int y) {
            return x * y;
        }
       
        double Area(double x, double y) {
            return x * y;
        }

        void Volume() {
            int a;
            int b; 
            int c;
            
            cout << "Enter 3 dimensions to calculate volume: ";
            cin >> a;
            cin >> b; 
            cin >> c;

            cout << "Volume = " << a * b * c;
            cout << endl;
        }
        
        int Volume(int x, int y, int z) {
            return x * y * z;
        }

        double Volume(double x, double y, double z) {
            return x * y * z;
        }


}; 

int main() {
    Rectangle r1;
    Rectangle r2;
    Rectangle r3;
    
    r1.Area();
    r2.Area(5, 1);
    r3.Area(5.5, 10.1);  

    r1.Volume(); 
    r2.Volume(5, 10, 6);
    r3.Volume(5.2, 3.6, 8.4);


    return 0;
}
