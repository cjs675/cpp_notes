#include <iostream>
using namespace std;


int main() {
    // creates variable & pointer
    int userInput;
    int* pointer = &userInput;

    // gets user input 
    cout << "Enter a number: " << endl;
    cin >> userInput;

    cout << "Your number is: " << *pointer;


    return 0;
}
