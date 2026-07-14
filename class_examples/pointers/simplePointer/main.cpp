#include <iostream>
using namespace std;


int main() {
    int num = 20;
    int *p = &num;

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Pointer p holds: " << p << endl;
    cout << "Value at address stored in p: " << *p << endl;


    return 0;
}
