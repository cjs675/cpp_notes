#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class
class Employee {
// Accessibility level of: Protected so
// derived classes can access the data members
protected:
    string name;
    int id;
public:
    Employee() : name(""), id(0) {}
    Employee(string n, int id) : name(n), id(id) {}
};

class Account : virtual public Employee {
protected:
    double salary;
    double bonus;

public:
    Account() : salary(0.0), bonus(0.0) {}
    Account(double s, double b) : salary(s), bonus(b) {}
};

class Admin : virtual public Employee {
protected:
    int experience;
    string designation;
public:
    Admin() : experience(0), designation("") {}
    Admin(int xp, string des) : experience(xp), designation(des) {}
};

class Master : public Account, public Admin {
public:
    // inherits the default constructors from the base classes
    Master() {}

    // Method to enter details of an Employee
    void enterDetails() {
        // cin.ignore used to clear the stream buffer after the Enter key
        // has been pressed
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Salary: $";
        cin >> salary;

        cout << "Enter Bonus: $";
        cin >> bonus;

        cout << "Enter Years of Experience: ";
        cin >> experience;
        cin.ignore();

        cout << "Enter Designation (role): ";
        getline(cin, designation);
    }

    // Method to display details of a given employee
    void displayDetails() {
        cout << "\n=========== Employee Details =============" << endl;
        cout << "ID: " << id << "\nName: " << name
             << "\nSalary: $" << salary
             << "\nBonus: $" << bonus
             << "\nYears of Experience: " << experience
             << "\nDesignation: " << designation << "\n" << endl;
    }

    // Method to update employee details
    void updateDetails() {
        cout << "\n======= Updated Employee Details =========" << endl;
        cout << "Re-enter the updated info: " << endl;
        enterDetails();
    }

    // Getter to traverse the DB given an Employee ID
    int getID() {
        return id;
    }
};

int main() {
    vector<Master> employeeDB;
    int choice = 0;

    while (choice != 4) {
        cout << "\n----- Employee DB Menu -------" << endl;
        cout << "1. Enter New Employee" << endl;
        cout << "2. Display Employee Details" << endl;
        cout << "3. Update Employee Details" << endl;
        cout << "4. Exit Employee Database" << endl;
        cin >> choice;

        // 'Safety' loop in case user enters an invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input. Please enter a valid number" << endl;
            // Restart main menu while loop with buffer cleared
            continue;
        }

        if (choice == 1) {
            Master newEmployee;
            newEmployee.enterDetails();
            // Add new Employee object to vector made up of Master class
            employeeDB.push_back(newEmployee);
            cout << "\n Employee Saved successfully" << endl;
        }
        else if (choice == 2) {
            int searchID;
            cout << "Enter Employee ID to search: ";
            cin >> searchID;
            bool found = false;

            // loop from 0 up to DB size
            for (int i = 0; i < employeeDB.size(); i++) {
                // access a given employee using a specific index
                if (employeeDB[i].getID() == searchID) {
                    employeeDB[i].displayDetails();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Error: Employee ID not found" << endl;
        }
        else if (choice == 3) {
            int searchID;
            cout << "Enter Employee ID to update: ";
            cin >> searchID;
            bool found = false;

            for (int i = 0; i < employeeDB.size(); i++) {
                if (employeeDB[i].getID() == searchID) {
                    employeeDB[i].updateDetails();
                    cout << "Employee Updated Successfully" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Error: Employee ID not found" << endl;
        }
    }
    cout << "Exiting Session...." << endl;

    return 0;
}
