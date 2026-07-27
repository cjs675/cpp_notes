#include <iostream>
using namespace std;


template <typename T> 
T add(T a, T b, T c) {
    return a + b + c;
}


template <typename T> 
T mul(T a, T b) {
    return a * b;
}



int main() {
   cout << add(2, 3, 4) << endl;
   cout << add(2.3, 4.2, 6.9) << endl;
   cout << mul(30, 4) << endl;
   cout << mul(2.5, 2.5);

    return 0;
}
