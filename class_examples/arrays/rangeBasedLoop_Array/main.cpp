#include <iostream>
using namespace std;


int main() {
    
    int arr[] = { 100, 200, 300, 400, 500 };

    cout << "Vector Contents: ";

    for (int num : arr) {
        cout << num << " ";
    } 
    cout << endl;
    return 0;
}
