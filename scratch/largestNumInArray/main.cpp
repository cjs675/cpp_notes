#include <iostream>

using namespace std;

int main() { 
    int arr_1[5] = {12, 45, 23, 51, 19};
    int max = arr_1[0]; 
    int min = arr_1[0];

    for (int i = 1; i < 5; i++) { 
        if (arr_1[i] > max) {
            max = arr_1[i];  

        if (arr_1[i] < max) {
            min = arr_1[i];
            }
        }
    }   

    for (int i = 0; i < 5; i++) {
        cout << arr_1[i] << " ";
    }
    cout << "\nMax Element = " << max << endl; 
    cout << "\nMin Element = " << min << endl;
    
    return 0;
}
