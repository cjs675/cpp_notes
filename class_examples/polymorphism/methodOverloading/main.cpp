#include <iostream>
using namespace std;

class Rectangle {
    public:  

        void Area() {
            int a;
            int b;
            
            cout << "\nEnter a length & width: "; 
            cin >> a;
            cin >> b;
            cout << "\nArea = " << a * b << endl;
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
            
            cout << "\nEnter 3 dimensions to calculate volume: ";
            cin >> a;
            cin >> b; 
            cin >> c;

            cout << "\nVolume = " << a * b * c << endl; 
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
    
    r1.Area(); 
    r1.Volume();
   
    cout << "\n ------- Overloaded Method Calculations --------\n";
    cout << "Area (int) = " << r1.Area(5, 12) << endl;
    cout << "Area (double) = " << r1.Area(3.8, 10.1) << endl;
    
    cout << "Volume (int) = " << r1.Volume(5, 10, 15) << endl;
    cout << "Volume (int) = " << r1.Volume(8.9, 12.77, 14.32) << endl;

    return 0;
}
