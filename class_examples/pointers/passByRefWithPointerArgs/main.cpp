#include <iostream>
using namespace std;

void changeValue(int * x) {
    * x = 100;
}
int main() {
    int a = 50;
    changeValue(&a);

    cout << "New value of a: " << a;
    return 0;
}
