#include <iostream> 

using namespace std;

int main() {
    int  arr[5] = {12, 45, 23, 51, 19}; 
    int max = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Original Array: ";
    for (int i = 0; i < 5; i++) {
        // print each element with a space 
        cout << arr[i] << " ";
    }

    cout << "\nMax Element = " << max << endl;

    return 0;
}
