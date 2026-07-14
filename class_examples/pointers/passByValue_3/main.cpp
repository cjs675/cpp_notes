#include <iostream>
using namespace std;

// function to square a number (pass by ref) 
void squareByReference(int &n) {
    n = n * n;  // changes og variable 
}
int main() {

    int num = 5;

    cout << "original value of num: " << num << endl;

    squareByReference(num); // num passed by reference 

    cout << "Value of num after function call: " << num << endl;
    
    return 0;
}
