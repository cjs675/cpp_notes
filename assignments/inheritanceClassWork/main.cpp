#include <iostream>
#include <string> 
using namespace std;


class Staff { 
 
// protected specifier allows derived classes to access data directly 
// while keeping hidden from outside (like main)
protected:
    int id;
    string name;

public: 
    // parameterized constructor using member-initialized list 
    Staff(int staffNum, const string& staffName) 
    : id(staffNum), name(staffName) {}
    
    // 'const' guarantees this function will not modify object's state 
    // primarily for read-only functions 
    void displayDetails() const {
        cout << " | Name: " << name << " | ID: " << id; 
    }
};

// derived class 'Doctor' inherits publicly from 'Staff'
class Doctor : public Staff {

protected: 
    string specialization;
    int yearsOfExp;

public: 

    // derived constructor calls base class (Staff) to initialize inherited 
    // attributes (id, Name) before init. own attributes 
    Doctor(int id, const string& staffName, const string& spec, 
            int xp) : Staff(id, staffName), specialization(spec), yearsOfExp(xp) {}
   
    
    void displayDetails() const { 
        cout << "\nDoctor Details: \n";

        // call base class printer for shared attributes 
        Staff::displayDetails(); 
        
        cout << " | Specialization: " << specialization
             << " | Experience: " << yearsOfExp << " years" << endl;
    }
}; 

// derived class 'Nurse' inherits publicly from 'Staff'
class Nurse : public Staff {

protected: 
    string department;
    string shiftTiming;

public: 

    // constructor calls base staff constructor first to
    // handle 'id' & 'name'
    Nurse(int id, const string& staffName, 
          const string& dept, const string& shift) : 
          Staff(id, staffName), department(dept), shiftTiming(shift) {} 

    void displayDetails() const  { 
        cout << "\nNurse Details: \n";
        // call base class printer for shared attributes
        Staff::displayDetails();
        
        cout << " | Department: " << department
             << " | Shift: " << shiftTiming << endl;
    }
};

int main() {  
    
    // instances of derived class objects 
    Doctor doc_1(4322, "Dr. Lowe", "Cardiology", 17); 
    Nurse nurse_1(8902, "Janet Shores", "Pre-Natal", "Morning"); 

    // calls Doctor::displayDetails() --> calls Staff::displayDetails()
    doc_1.displayDetails();
    
    // calls Nurse::displayDetails() --> calls Staff::displayDetails()
    nurse_1.displayDetails();

    return 0;
}
