#include <iostream> 
#include <vector> 

using namespace std;

int main() {
    vector<double> num { 1, 2, 3, 4, 5 };
    cout << "Initial Vector: ";

    for ( int i : num) {
        cout << i << " "; 
    }

    // add integers 6 & 7 to vector 
    num.push_back(6);
    num.push_back(7);

    cout << "\n Updated Vector: ";
    for ( double i : num) {
        cout << i << " ";
    }  
    cout << endl;

    return 0;
}
