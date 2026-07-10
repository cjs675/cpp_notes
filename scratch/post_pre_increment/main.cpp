#include <iostream>

using namespace std;

int main() {

    int postfix_age = 5;
    int prefix_age = 5;

    cout << "== POSTFIX (age++) ==" << endl;
    // prints 5, then immediately updates the var to 6 in bg
    cout << "Taking photo: " << postfix_age++ << endl;
    // now look at variable itself 
    cout << "Actual age now:  " << postfix_age << endl;

    cout << "\n== PREFIX (++age) ==" << endl;
    // updates var to 6 first, then takes photo & prints it 
    cout << "Taking photo: " << ++prefix_age << endl; 
    // now we look at variable itself 
    cout << "Actual age now:  " << prefix_age << endl;

    return 0;
}
