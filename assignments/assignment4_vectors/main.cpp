#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

class Student {

private:
    string name;
    int age;
    vector<int> scores{}; 

public:  
    
    /* 
    * Member-initialized list which constructs  
    * private data members using parameter values 
    */
    Student(const string& n, int a, const vector<int>& s) 
     : name(n), age(a), scores(s) {}  
    
    /* 
    * Method which returns a double to calculate 
    * average score. Initializes total assignment
    * score as 0, then iterates through the scores 
    * vector, given its size. 
    */
    double calcAverage() {
        double totalScore = 0.00;
    
        // for loop which iterates through 
        // scores vector 
        for (int i = 0; i < scores.size(); i++) {
            totalScore += scores[i];
        }
        return totalScore / scores.size();
    } 
   
    /* 
    * Method which returns the letter grade 
    * as a char type. 
    * 
    * We only check the upper bounds of the
    * returned average, since if it fails it 
    * is guaranteed to fail the respective case 
    */
    char calcLetterGrade() { 
        double average = calcAverage();
        if (average >= 90)  {
            return 'A';
        } else if (average >= 80) {
            return 'B';
        } else if (average >= 70) {
            return 'C';
        } else if (average >= 60) {
            return 'D';
        } else  
            return 'F';
    };

    // method to display student output 
    void display() {
        cout << "\nName: " << name << ","
             << " Age: " << age << ","
             << " Average: " << calcAverage() << "," 
             << " Grade: " << calcLetterGrade(); 
    }
};

int main() { 
    int numOfStudents; 
    int numOfSubjects; 

    cout << "Enter number of students: ";
    cin >> numOfStudents;
    cout << " Enter number of subjects: ";
    cin >> numOfSubjects; 

    // Vector of type Students created
    vector<Student> students;   
   

    /*
    * Outer for-loop which iterates each student 
    * to collect their respective details & 
    * build their object 
    */
    for (int i = 0; i < numOfStudents; i++) {
        string tempName = ""; 
        int tempAge = 0; 
        vector<int> scores; 
        
        cout << "\nEnter name of student " << (i + 1) << ": ";   
        cin >> tempName; 

        cout << " Enter age of student " << (i + 1) << ": ";
        cin >> tempAge; 

        cout << " Enter scores in " << numOfSubjects << " subjects:  ";

        // Inner loop which reads user input of scores across all subjects 
        for (int j = 0; j < numOfSubjects; j++) {
            int singleScore = 0;
            cin >> singleScore;
            scores.push_back(singleScore);
        } 

        // Student object created 
        Student currentStudent(tempName, tempAge, scores); 
        // Student object pushed back to main vector 
        students.push_back(currentStudent);
    }


    cout << "\n\n--- Student Report ---\n";

    /* 
    *  For loop to iterate through vector 
    *  containing student objects and 
    *  call displayDetail method 
    */
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
    cout << endl; 
    return 0;
}
