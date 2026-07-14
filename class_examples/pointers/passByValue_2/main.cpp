#include <iostream>
using namespace std;

// function to square a number (pass by value) 
int squareByValue(int n) {
    n = n * n;  // changes local copy only 
    return n;
}


int main() {
    int num = 5;

    cout << "Original value of num: " << num << endl;

    int result = squareByValue(num); // num passed by value 

    cout << "Value of returned function: " << result << endl;
    cout << "Value of num after function call: " << num << endl;


    return 0;
}
