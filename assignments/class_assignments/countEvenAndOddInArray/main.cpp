#include <iostream> 

using namespace std;

class EvenOdd {
public: 
    int arr[5];
    int e_count;
    int o_count;

    // constructor
    EvenOdd() {
        e_count = 0;
        o_count = 0;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    void calcEven() {
        e_count = 0; // Reset count
        for (int i = 0; i < 5; i++) {
            if (arr[i] % 2 == 0) {
                e_count++;
            }
        }
    }

    void calcOdd() {
        o_count = 0; // Reset count
        for (int i = 0; i < 5; i++) {
            if (arr[i] % 2 != 0) {
                o_count++;
            }
        }
    }
};
int main() {
    EvenOdd calculation;

    cout << "\nEnter 5 integers: \n" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> calculation.arr[i];
    }
    
    // Calculate even and odd counts using member functions
    calculation.calcEven();
    calculation.calcOdd(); 

    cout << "\nEven elements: " << calculation.e_count << "\n";
    cout << "\nOdd elements: " << calculation.o_count << "\n";
    
    return 0;
}
