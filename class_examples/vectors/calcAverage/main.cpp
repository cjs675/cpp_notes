#include <iostream>
#include <vector> 
using namespace std;

class Scores {
private:
        vector<int> scores;

public:
        Scores(const vector <int>&  n) 
            : scores(n) {} 
       

        double calcAverage() {
            double totalScore = 0.00;

            for (int i = 0; i < scores.size(); i++) {
                totalScore += scores[i];
            } 
            cout << "\nScore Average: ";
            return totalScore / scores.size();
        } 
        // loop through all scores within the score vector 
        // given its size 
        void display() {
            cout << "\nOriginal Scores vector: ";
            for (int i = 0; i < scores.size(); i++) {
                cout << scores[i] << " ";
            }
            cout << "\n";
        }
};

int main() { 
    
    Scores myScores  { {100, 89, 95, 98, 84 } };    
    
    myScores.display();
    cout << myScores.calcAverage() << endl;  

    return 0;
}
