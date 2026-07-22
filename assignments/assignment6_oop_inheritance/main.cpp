/* Author: Chris Silva
* Date: July 21, 2026
*
* Course: COP 3003
* Description: This program demonstrates hybrid inheritance by
*              showing the relationship between different types of
*              faculty members and students
*/

#include <iostream>
#include <string>
// Ctime library used to use the instantaneous time
// the program is run as the start 'seed' for the random
// number generation.
// Otherwise, the random number would be the same each time.
#include <ctime>
#include <random>
using namespace std;

class Person {
protected:
    string name;
    string personalEmail;
    string uniEmail;
    int id = 0;

public:
    Person(const string& n, const string& uniEmail, const int id)
    : name(n), personalEmail(""), uniEmail(uniEmail),  id(id) {}

    /* Method that updates the person's
    * personal email
    */
    void updateContactInfo(const string& newEmail) {
        personalEmail = newEmail;
        cout << "Email Successfully Updated. New Email: " << personalEmail << "\n";
    }

    /* Method that generates a random number
    * 9-digits long, between 1,000,000 &
    * 999,999,999
    */
    void generateUniID() {
        id = (rand() % 900'000'000) + 100'000'000;
    }

    /* Method which generates an ID including
    * person's name, ID, and email which is
    * built using:
    * 'firstInitial' + 'lastName' +
    * random number + FGCU email domain
    */
    void generateIdBadge() {
        // check if ID does not exist yet
        if (id == 0) {
            generateUniID();
        }
        // Extract first 4 digits of the generated 9-digit school ID for the email
        string emailNum = to_string(id).substr(0, 4);

        // set firstInitial = to the first position
        // in the string array containing the name
        // & then set to lowercase
        char firstInitial = tolower(name[0]);

        string lastName = "";
        // find where the space is within the given name
        size_t spaceIndex = name.find(' ');

        // return the entirety of the last name if
        // a space is found
        if (spaceIndex != string::npos) {
            lastName = name.substr(spaceIndex + 1);
            // convert last name to all lowercase
            for (char& c : lastName) {
                c = tolower(c);
            }
        }
        uniEmail = string(1, firstInitial) + lastName + emailNum + "@eagle.fgcu.edu";

        cout << "--------------------------------------\n";
        cout << "     FGCU SWE Faculty / Student  \n";
        cout << "--------------------------------------\n";
        cout << " Name: " << name << "\n";
        cout << " ID: " << id << "\n";
        cout << " Email: " << uniEmail << "\n";
        cout << "--------------------------------------\n";
    }
};

/* Faculty inherits virtually from Person to prevent a new person
*  from being created.
*  This ensures we only have one Person class being inherited,
*  instead of multiple, individual ones.
*/
class Faculty : virtual public Person {
public:
    string department;
    double hourlyPay;
    double hoursWorked;

    Faculty(const string& n, const string& uniEmail, int id,
            const string& dept, double pay, double hours)
                : Person(n, uniEmail, id), department(dept), hourlyPay(pay), hoursWorked(hours) {}

    /* Logs working hours for the faculty member.
    * Validates that the input is a positive number.
    */
    void logHours(double hours) {
        if (hours > 0) {
            hoursWorked += hours;
            cout << "Hours Logged: " << hours << " for " << name << "\n";
            cout << "Total hours worked: " << hoursWorked << "\n";
        } else {
            cout << "Invalid Number of hours. Hours must be > 0\n";
        }
    }

    /* Calculates total pay based on the hourly rate and hours worked.
    * Resets the hours worked back to 0 after processing the paycheck.
    */
    double calculatePay() {
        double totalPay = hoursWorked * hourlyPay;
        cout << "Total Pay for: " << name << ": $" << totalPay << "\n";
        // reset hours worked for the week after payout gets processed
        hoursWorked = 0;
        return totalPay;
    }

    /* Displays a formatted profile containing all
    * faculty-specific details.
    */
    void displayFacultyInfo() {
        cout << "\n---- Faculty Profile for: " << name << " -----\n";
        cout << "Department: " << department << "\n";
        cout << "Hourly Pay: $" << hourlyPay << "\n";
        cout << "Hours Worked: " << hoursWorked << "\n";
        cout << "----------------------------------------------\n";
    }
};

/* Student inherits virtually from Person,
*  sharing a single Person instance with
*  Faculty when combined in the teacherAssistant class.
*/
class Student : virtual public Person {
public:
    double gpa;
    int totalCredits;
    bool gradEligibility;

    Student(const string& n, const string& uniEmail, int id,
            double gpa, int credits, bool grad)
                : Person(n, uniEmail, id), gpa(gpa), totalCredits(credits), gradEligibility(grad) {}

    /* Logs a new letter grade by converting it to a standard 4.0 scale.
    * Recalculates the cumulative GPA and updates total credits.
    */
    void logGrade(int credits, char grade) {
        double gradePoint = 0.0;

        switch (toupper(grade)) {
            case 'A' : gradePoint = 4.0; break;
            case 'B' : gradePoint = 3.0; break;
            case 'C' : gradePoint = 2.0; break;
            case 'D' : gradePoint = 1.0; break;
            case 'F' : gradePoint = 0.0; break;

            default:
                cout << "Invalid grade entered. Please use A, B, C, D, or F\n";
                return;
        }
        double totalPoints = (gpa * totalCredits) + (gradePoint * credits);
        totalCredits += credits;
        gpa = totalPoints / totalCredits;

        cout << "Grade: " << (char)toupper(grade) << " logged for: " << name << "\n";
        cout << "Updated GPA: " << gpa << " Total credits: " << totalCredits << "\n";
    }

    /* Checks if the student meets standard graduation requirements:
    * at least 120 credits and a GPA greater than 2.0.
    */
    void checkGradEligibility() {
        if (totalCredits >= 120 && gpa > 2.0) {
          gradEligibility = true;
            cout << name << " is eligible for graduation\n";
        } else {
            gradEligibility = false;
            cout << name << " is not yet eligible for graduation\n";
        } 
    } 
    
    /* Displays a formatted profile containing
    *  academic details.
    */
    void displayStudentInfo() {
        cout << "\n------ Student Profile for: " << name << "------\n";
        cout << "GPA: " << gpa << "\n";
        cout << "Total Credits: " << totalCredits << "\n";
        cout << "Graduation Eligibility: " << (gradEligibility ? "Yes" : "No") << "\n";
        cout << "--------------------------------------\n";
    }
};

/* The teacherAssistant class demonstrates multiple inheritance
 * by combining both Student and Faculty characteristics
*/
class teacherAssistant : public Student, public Faculty {
public:
    string assignedCourse;
    string room;

    teacherAssistant(const string& n, const string& uniEmail, int id,
                     // Faculty class properties
                     const string& dept, double pay, double hours,
                     // Student class properties
                     double gpa, int credits, bool grad,
                     // teacherAssistant class properties
                     const string& course, const string& room)

                     // Virtual base class (Person) initialized first
                     : Person(n, uniEmail, id),
                     // Initialize direct base classes
                     Faculty(n, uniEmail, id, dept, pay, hours),
                     Student(n, uniEmail, id, gpa, credits, grad),
                     // Initialize TA-specific properties
                     assignedCourse(course), room(room) {}
    
    // Updates the TA's assigned course and room
    void updateCourseAssignment(const string& course, const string& room) {
        assignedCourse = course;
        this -> room = room;
    }

    // Demonstrates calling a method inherited from the Faculty base class
    void hostOfficeHours(double hours) {
        cout << name << " is holding office hours for " << assignedCourse
             << " in room: " << room << " for " << hours << " hours \n";
        // Call to logHours method from Faculty class
        logHours(hours);
    } 
    
    // Displays a hybrid profile pulling data from both Faculty and Student base classes
    void displayTAInfo() {
        cout << "\n------- TA Profile for: " << name << " ----\n";
        cout << "Assigned Course: " << assignedCourse << " (" << room << ")\n";
        cout << "[Faculty] Department: " << department << "\n";
        cout << "[Student] Current GPA: " << gpa << "\n";
        cout << "[Student] Total Credits: " << totalCredits << "\n";
        cout << "[Student] Graduation Eligibility: " << (gradEligibility ? "Yes" : "No") << "\n";
    }
};

int main() {

    // Srand takes in current time which is different
    // each time the program is run, so IDs generated
    // are different after every run.
    srand(time(0));

    cout << "        [Faculty Class]     \n";
    Faculty prof_1("Grace Hopper", "", 0, "Computer Science", 42.50, 0.0);
    prof_1.generateIdBadge();
    prof_1.logHours(37);
    prof_1.calculatePay();
    prof_1.displayFacultyInfo();


    cout << "        [Student Class]     \n";
    Student student_1("May Franklin", "", 0, 3.9, 114, false);
    student_1.generateIdBadge();
    student_1.logGrade(5, 'A');
    student_1.checkGradEligibility();
    student_1.displayStudentInfo();

    cout << "           [TA Class]            \n";
    teacherAssistant ta_1("Mark Snyder", "", 0,
        "Software Engineering", 18.00, 0.0, 3.82,
        124, true, "CDA 3104", "Holmes Hall 237");
    ta_1.generateIdBadge();
    ta_1.hostOfficeHours(2.5);
    ta_1.calculatePay();
    ta_1.displayTAInfo();

    cout << "\n         UPDATED INFO      \n";
    cout << "        [Student Class]     \n";
    student_1.logGrade(5, 'B');
    student_1.checkGradEligibility();
    student_1.updateContactInfo("frankM452@icloud.com");
    student_1.displayStudentInfo();

    cout << "\n         UPDATED INFO      \n";
    cout <<"          [TA Class]            ";
    ta_1.updateCourseAssignment("COP 4610", "Holmes 324");
    ta_1.displayTAInfo();

    return 0;
}
