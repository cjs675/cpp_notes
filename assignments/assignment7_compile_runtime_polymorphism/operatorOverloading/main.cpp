#include <iostream>
#include <string>
using namespace std;

class Racer {
private:
    string name;
    double time;

public:
    // Constructor to set up a Driver using a member-initialized list
    Racer(string driverName, double driverTime)
        : name(driverName), time(driverTime) {}

    // Overloading the '<' operator
    // Compare the times of different drivers
    // We pass in the time of a given Racer as a reference,
    // Set to constant so it doesn't get modified
    bool operator<(const Racer& R2) {
        // if-else block to check if a given Racer's time is < another's
        if (time < R2.time) {
            return true;
        } else {
            return false;
        }
    }
    string getName() {
        return name;
    }
    double getTime() {
        return time;
    }
};

int main() {
    // Instantiate two Racer objects
    Racer racer_1("Mckormick", 3.2993);
    Racer racer_2("Jones", 4.1932);

    if (racer_1 < racer_2) {
        cout << "\n" <<  racer_1.getName() << " had the fastest lap!" << endl;
        cout << "Time: " << racer_1.getTime() << endl;
        cout << "\n" << racer_2.getName() << " Time: " << racer_2.getTime() << endl;
    } else {
        cout << racer_2.getName() << " had the fastest lap!" << endl;
        cout << "Time: " << racer_2.getTime() << endl;
        cout << "\n" << racer_1.getName() << " Time: " << racer_1.getTime() << endl;
    }

    return 0;
}
