#include <iostream> 
using namespace std;

class Rectangle{

    private: 
        int length;
        int width;

    public: 
        Rectangle() {}; 
    
    // creates copies of the original values 
    // leaving the original unmodified 
    void AreaValue(int l, int w) {
        l = 10; 
        w = 3;
        int area = l * w; 

        cout << "\nPass by Value: "  << area << endl;
    } 
    
    // accesses original data members and 
    // changes their state
    void AreaReference(int &l, int &w) {
        l = 10;
        w = 3;
        int area = l * w;
        cout << "\nPass by Reference: " << area << endl;

    }
    
    // accesses original data members via 
    // their memory address and changes their state  
    // by dereference 
    void AreaPointer(int *l, int *w) { 
        *l = 10; 
        *w = 3;
        int area = (*l) * (*w);
        cout << "\nPass by Pointer: " << area << endl;
    }

};

int main() { 
    Rectangle r1;
    int a, b;

    cout << "\nEnter two values: " << endl;
    cin >> a;
    cin >> b; 

    cout << "In main: " << a * b << endl;

    // pass by value 
    r1.AreaValue(a, b); 
    // a & b --> unchanged since AreaValue only modifies copies 
    cout << "\nIn main: " << a * b << endl;

    // pass by reference 
    r1.AreaReference(a, b);
    // a & b --> changed to 10 & 3
    cout << "\nIn main: " << a * b << endl;

    // pass by pointer 
    r1.AreaPointer(&a, &b);
    // a & b --> stay as 10 & 3
    cout << "\nIn main: " << a * b << endl;
    
    return 0;
}
