// program to insert & display data entered using pointer notation

#include <iostream>
using namespace std;


int main() {
    float arr[5];

    // insert data using pointer notation
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        // store input number in arr[i]
        cin >> *(arr + i);
    }

    // display data using pointer notation 
    cout << "Displaying data: " << endl;
    for (int i = 0; i < 5; i++) {
        //display value of arr[i]
        cout << *(arr + i) << endl;

    }
    return 0;
}
