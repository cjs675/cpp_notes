#include <iostream>
using namespace std;

int main() { 
    int arr[5] = { 2, 51, 19, 100, 10 };
    int min = arr[0];

    for (int i = 1; i < 5; i++){
        if (arr[i] < min) {
            min = arr[i];
        } 
    } 

    cout << "Original Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nSmallest Element: " << min << endl;

    return 0;
}
