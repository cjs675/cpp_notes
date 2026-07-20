#include <iostream>
using namespace std;

class Addition {
public: 
    int ADD(int x, int y) // function with param
    {
        return  x + y;
    }

    int ADD() {
        string a = "Good";
        string b = "Morning";
        string c = a + b;
        cout << c << endl;
    }
};
int main() {
    Addition obj;

    cout << obj.ADD(128, 15) << endl;
    obj.ADD();


    return 0;
}
