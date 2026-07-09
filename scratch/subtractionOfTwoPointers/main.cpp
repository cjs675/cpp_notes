#include <iostream> 

using namespace std;

int main() {
    int n = 100;
    int* ptr = &n;

    cout << "Address stored in ptr: " << ptr << endl;
    ptr = ptr - 1;
    cout << "Subtract 1 from ptr: " << ptr << endl; 

    return 0;
}
