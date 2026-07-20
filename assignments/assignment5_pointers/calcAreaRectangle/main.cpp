#include <iostream> 
using namespace std;

class Rectangle{

    private: 
        int length;
        int width;

    public: 
        Rectangle(int l, int w) : length(l), width(w) {}; 

    void AreaValue(int l, int w) {
        int area = l * w; 

        cout << "Pass-by-value: "  << area << endl;
    } 

    int AreaReference() {

    }
    
    int AreaPointer() {

    }

};





int main() {
    
    return 0;
}
