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

    Staff(int staffNum, const string& staffName) {
        id = staffNum;
        name = staffName;
    }
    
    
    void displayDetails() const {
        cout << "Worker ID: " << id << "\nName: " << name;
    }
};

class Doctor : public Staff {

protected: 
    string specialization;
    int yearsOfExp;

public: 
    Doctor(int id, const string& staffName, const string& spec, 
            int xp) : Staff(id, staffName), specialization(spec), yearsOfExp(exp) {}
    
    void displayDetails() {
        cout << " [Doctor] ";
        // call base class printer for shared attributes 
        Staff::displayDetails(); 
        
        cout << "| Specialization: " << specialization
             << "| Experience: " << yearsOfExp << " years" << endl;
    }
}; 

class Nurse : public Staff {

protected: 
    string department;
    string shiftTiming;

public: 
    // constructor calls base staff constructor first 
    Nurse(const string& id, const string& staffName, 
          const string& dept, const string& shift) : 
          Staff(id, staffName), department(dept), shiftTiming(shift) {} 

    void printDetails() const override {
        cout << " [Nurse] ";
        printDetails();
        Staff::displayDetails();
        
        cout << " | Department: " << department
             << " | Shift: " << shiftTiming << endl;
    }
};



int main() { 

    Doctor one("101", "Joel" "12", 2);
    one.displayDetails();
    
    return 0;
}
