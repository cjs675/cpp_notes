#include <iostream>
using namespace std;


int main() {
    // create vars & points 
    int num1, num2, num3, *p1, *p2, *p3;

    //get user input 
    cout << "Enter 1st number: " << endl;
    cin >> num1;
    cout << "Enter 2nd number: " << endl;
    cin >> num2;
    cout << "Enter 3rd number: " << endl;
    cin >> num3;

    // assign to pointers 
    p1 = &num1;
    p2 = &num2;
    p3 = &num3;

    // swap numbers 
    if (*p1 > *p2 && *p1 > *p3) {
        cout << "The largest number is " << *p1 << endl;
    }

    else if (*p2 > *p1 && *p2 > *p3) {
        cout << "The largest number is " << *p2 << endl;
    }
    else {
        cout << "The largest number is " << *p3 << endl;
    }
    return 0;
}
