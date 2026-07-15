#include <iostream>
#include <string> 

using namespace std;


class Staff { 
  
protected:
    int id;
    string name;

public: 
    // parameterized list constructor 
    Staff(int staffNum, const string& staffName) 
    : id(staffNum), name(staffName) {}
    
    void displayDetails() const {
        cout << " | Name: " << name << " | ID: " << id; 
    }
};


class Doctor : public Staff {

protected: 
    string specialization;
    int yearsOfExp;

public: 
    Doctor(int id, const string& staffName, const string& spec, 
            int xp) : Staff(id, staffName), specialization(spec), yearsOfExp(xp) {}
    
    void displayDetails() { 
        cout << "\nDoctor Details: \n";
        // call base class printer for shared attributes 
        Staff::displayDetails(); 
        
        cout << " | Specialization: " << specialization
             << " | Experience: " << yearsOfExp << " years" << endl;
    }
}; 


class Nurse : public Staff {

protected: 
    string department;
    string shiftTiming;

public: 
    // constructor calls base staff constructor first 
    Nurse(int id, const string& staffName, 
          const string& dept, const string& shift) : 
          Staff(id, staffName), department(dept), shiftTiming(shift) {} 

    void displayDetails() const  { 
        cout << "\nNurse Details: \n";
        Staff::displayDetails();
        
        cout << " | Department: " << department
             << " | Shift: " << shiftTiming << endl;
    }
};



int main() {  

    Doctor doc_1(4322, "Dr. Lowe", "Cardiology", 17); 
    Nurse nurse_1(8902, "Janet Shores", "Pre-Natal", "Morning"); 

    doc_1.displayDetails();

    nurse_1.displayDetails();

    return 0;
}
