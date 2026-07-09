#include <iostream> 

using namespace std;

class StudentScores{

private: 
    int scores[10];
    int size = 10 ; 

public: 
    void getData() { 
        cout << "\nEnter 10 class scores: \n" << endl;
        for (int i = 0; i < 10; i++) {
            cin >> scores[i];
        }
        
    }
    
    void displayOriginal() { 
        cout << "\nOriginal Array of Scores: \n\n";   
        /* 
        * for-each loop, traversing entire array
        * to output each element inside array 
        * consecutively 
        */
        for (int score : scores) { 
            cout << score << " ";  
        } 
        cout << endl;
    }
    
    /*
    * Method to sort array in ascending order  
    * using bubble-sort algorithm 
    */
    void sortAscending() {  
        // traverse array from index 0 to end (n-1) 
        // 10 elements (10-1 = 9)
        for (int i = 0; i < 9; i++) {  
            for (int j = 0; j < 9 - i; j++) {
                // check if value on left >  value on right 
                if (scores[j] > scores[j + 1]) {
                    // swap values if score at index i > score at following index, [i + 1] 
                    // temp = temporary var holding value to be swapped "out" of original place 
                    int temp = scores[j + 1];
                    scores[j + 1] = scores[j];
                    scores[j] = temp;
                }
            }
        } 
        cout << "\nArray Sorted in Ascending Order: \n\n"; 
        for (int i = 0; i < 10; i++) {
            cout << scores[i] << " ";
        } 
        cout << endl;
    } 

    
    /*
    *  Since the scores array is already sorted (low -> high)
    *  we output the value at the very end of the sorted array, 
    *  which is already the highest value - outputting the 
    *  element at the end (n - 1) = 9th place 
    */
    void locateHigh() {
        cout << "\nHighest Value: " << scores[size - 1] << endl;
    }

    /*
    * Method to sort scores array in descending order 
    * using bubble-sort algorithm 
    */
    void sortDescending() {  
        // traverse array from index 0 to end (n - 1) 
        for (int i = 0; i < 9; i++) {  
            for (int j = 0; j < 9 - i; j++) {
                // check if value on left <  value on right  
                // if value on left = smaller, swap positions with value on right 
                if (scores[j] < scores[j + 1]) {
                    // swap values if score at index i < score at following index, [i + 1] 
                    // temp = temporary var holding value to be swapped "out" of original place 
                    int temp = scores[j + 1];
                    scores[j + 1] = scores[j];
                    scores[j] = temp;
                }
            }
        } 
        cout << "\nArray Sorted in Descending Order: \n\n"; 
        for (int i = 0; i < 10; i++) {
            cout <<scores[i] << " ";
        } 
        cout << endl;
    }
    
    /* Since the scores array has now been sorted (high -> low) 
    *  we output the value at the very end of the array, 
    *  which after sorting is now the lowest 
    */
    void locateLow() {
        cout << "\nLowest Value: " << scores[size - 1] << endl;
    }
};

int main() { 

    StudentScores scoreList1; 
    
    scoreList1.getData();
    scoreList1.displayOriginal(); 
    
    scoreList1.sortAscending();   
    /* We call locateHigh() after the 
    *  array has been sorted from (low -> high) 
    *  to then simply output the last element (highest)
    */
    scoreList1.locateHigh();
    
    scoreList1.sortDescending();
    /* We call locateLow() after the 
    *  array has been sorted (high -> low) 
    *  to then simply output the last element (lowest)
    */
    scoreList1.locateLow();

    return 0;

}
