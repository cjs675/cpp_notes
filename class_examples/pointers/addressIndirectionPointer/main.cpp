#include <iostream>
using namespace std;


int main() {
    int  a = 7;  // assign 7 to a
    int *aPtr = &a; // init aPtr with address of int variable a

    cout << "The address of a is: " << &a
         << "\nThe value of aPtr is " << aPtr;

    cout  << "\nThe value of a is " << a
          << "\nThe value of *aPtr is " << *aPtr << endl;
    return 0;
}
