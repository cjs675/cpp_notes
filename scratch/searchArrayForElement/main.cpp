#include <iostream>

using namespace std;


int main() {
    int arr[6] = { 10, 20, 30, 40, 50, 60 };
    int key;
    bool found = false;

    cout << "Enter number to search: ";
    cin >> key;

    for (int i = 0; i < 6; i++) {
        if (arr[i] == key) {
            cout << "Found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Not found in array";
    }
    return 0;
}
