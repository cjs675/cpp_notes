#include <iostream> 
#include <string> 
using namespace std;


class Student {
    
 private:    
    int rollNo;
    string name;
    double scores[5]; 

 public: 
    // parameterized constructor which takes in 5 distinct scores as params 
    Student(int rollNo, const string& name, double s1, double s2, double s3, double s4, double s5) 
        : rollNo(rollNo), name(name) { 
            scores[0] = s1;
            scores[1] = s2;
            scores[2] = s3;
            scores[3] = s4;
            scores[4] = s5;
        }  
   // method to return average of the given array of scores 
    double calcAverage() {
        double total = 0;
        
        for (int i = 0; i < 5; i++) {
            total += scores[i];  
        } 
        return total / 5;
    } 
    // method to return letter grade given the average of scores 
    char calcGrade() {
        double avg = calcAverage();

        if (avg >= 90.00) {
            return 'A';
        } else if (avg >= 80) {
            return 'B'; 
        } else if (avg >= 70) {
            return 'C';
        } else if (avg >= 60) {
            return 'D';
        } else  {
            return 'F';
        } 
    }
    
    void displayStudentDetails() {
        cout << rollNo <<  " | Name: "
             << name << " | Avg: "
             << calcAverage() << " | Grade: "
             << calcGrade() << "\n";
    }
}; 

int main() { 

    /*  
    * Initialize student objects as an array of 5 elements
    */ 
    Student students[5] = {
        Student(1, "Ronald", 58, 92, 58, 100, 78),
        Student(2, "James", 89, 93, 91, 100, 74),
        Student(3, "Georgia", 81, 72, 55, 94, 68), 
        Student(4, "Rebekka", 95, 89, 77, 93, 100),
        Student(5, "George", 59, 92, 100, 68, 82),
    }; 

    // for-loop to display results for each student 
    for (int i = 0; i < 5; i++) {
        students[i].displayStudentDetails();
    } 

    return 0;
}

    

