#include <iostream> 

using namespace std;

class StudentScores{

private: 
    int scores[10];
    int size ; 

public: 
    void getData() { 
        cout << "Enter 10 class scores: \n" << endl;
        for (int i = 0; i < 10; i++) {
            cin >> scores[i];
        }
        
    }

    void displayOriginal() { 
        cout << "\nOriginal Array of Scores: \n";
        for (int score : scores) { 
            cout << score << " ";  
        } 
        cout << endl;
    }

    void sortAscending() {

    }

    void sortDescending() {

    }

    void locateHigh() {

    }

    void locateLow() {

    }
};

int main() { 

    StudentScores scoreList1; 
    scoreList1.getData();
    scoreList1.displayOriginal();

}
