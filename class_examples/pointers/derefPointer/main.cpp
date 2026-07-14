#include <iostream>
using namespace std;


int main() {
    int y = 9;
    int *yptr = &y;

    cout << y << " " << *yptr << endl;

    cin >> *yptr; // take input & store directly into y via pointer 
    cout << y;


    return 0;
}
