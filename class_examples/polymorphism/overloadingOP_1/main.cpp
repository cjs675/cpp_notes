#include <iostream>

using namespace std;

class Count {
    private: 
        int value;

    public: 
        Count() : value(5) {}

        void operator++ () {

        }

        void display() const {
            cout << "Count value: " << value << endl;
        }
};
int main() {
    Count c;
    c.display();
    ++c;
    c.display();


    return 0;
}
