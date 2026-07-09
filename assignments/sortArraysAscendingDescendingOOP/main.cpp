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
        for (int i = 0; i < 9; i++) {  
            for (int j = 0; j < 9 - i; j++) {
                if (scores[j] > scores[j + 1]) {
                    // swap values if score at index i > score at following index, [i + 1] 
                    // temp = temporary var holding value to be swapped "out" of original place 
                    int temp = scores[j + 1];
                    scores[j + 1] = scores[j];
                    scores[j] = temp;
                }
            }
        } 
        cout << "\nArray Sorted in Ascending Order: \n"; 
        for (int i = 0; i < 10; i++) {
            cout <<scores[i] << " ";
        } 
        cout << endl;
    }

    void sortDescending() {
        int temp;
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
    scoreList1.sortAscending();

}
