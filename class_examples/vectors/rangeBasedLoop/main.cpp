#include <iostream>
#include <vector> 

using namespace std;


int main() {
    
    vector<int> myVec = { 10, 20, 30, 40 };

    cout << "Vector contents: ";

    // reads as "for every integer 'num' inside 'myVec'...."
    for (int num : myVec) {
        cout << num << " ";
    }
    return 0;
}
