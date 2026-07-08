#include <iostream> 

using namespace std;

int main() {
    int arr[5] = {12, 45, 23, 51, 19};
    int max = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Original Array: " << arr;
    cout << "Max Element = " << max;

    return 0;
}
