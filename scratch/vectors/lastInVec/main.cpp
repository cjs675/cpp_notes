#include <iostream>
#include <vector> 

using namespace std;

// program to get last element in vector 

int main() {
    
    vector<int> vec  = {10, 20, 30, 40, 50};
    
    
    // print original vector  
    cout << "\nOriginal Vector: " << endl;
    for (int i : vec) {
        cout <<  i << endl;
    }
    // always ensure vec has elements first 
    if (!vec.empty()) {
        // method 1: .back() (recommended) 
        int last = vec.back();

        // method 2: indexing 
        int last_idx = vec[vec.size() -1];

        // method 3: .at() (safe) 
        int last_at = vec.at(vec.size() - 1); 


        cout << "\nLast element in vec using .back(): " << last <<  endl;  
        cout << "\nLast element in vec using indexing: " << last_idx << endl; 
        cout << "\nLast element in vec using .at(vec.size() - 1): " << last_at << endl;
    } 


    return 0;
}
