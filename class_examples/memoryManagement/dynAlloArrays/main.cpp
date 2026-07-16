#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int *marks = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks[i];
    }

    cout << "\nStudent Marks: \n";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }

    delete[] marks;
    return 0;
}
