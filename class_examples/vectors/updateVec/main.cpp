#include <iostream> 

using namespace std;

int main() {
    vector<double> vec{ 1, 2, 3, 4, 5 };

    // initial vector 
    cout << "Initial vector: ";
    for (double i : vec) {
        cout << i << " ";
    } 

    // adding elements 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // vector after insertion
    cout << "\nUpdated vector: ";
    for ( double i : vec) {
        cout << i << " ";
    }
    cout << endl;

    // deleting elements 
    vec.pop_back();
    vec.pop_back();

    // vector after  
    cout << "\nUpdated vector: ";
    for ( double i : vec) {
        cout << i << " ";
    }
    cout << endl; 

    return 0;
}
