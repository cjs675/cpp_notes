#include <iostream> 

using namespace std;

int main() {
    vector<int> num {1, 2, 3, 4, 5 };

    cout << "Initial Vector: ";
    
    for (const int& i : num) {
        cout << i << " "; 
    }

    num.at(1) = 9;
    num.at(4) = 7;

    cout << "\nUpdated Vector: ";

    for (const int& i : num) {
        cout << i << " ";
    } 
    cout << endl;

    return 0;


}
