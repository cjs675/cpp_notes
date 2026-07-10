#include <iostream>

using namespace std;

int main() {
    int arr[4] = { 10, 30, 45, 60 };
    double sum = 0;
    double avg = 0; 
    int numElements = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array elements: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";    
    }
    cout << endl;

    cout << "Sum of elements: ";
    for (int i = 0; i < 4; i++){
        sum += arr[i];
    }
    cout << sum << endl; 

    cout << "Average of elements: ";
    avg = sum / numElements;
    

    cout << avg << endl;
    return 0;
}
