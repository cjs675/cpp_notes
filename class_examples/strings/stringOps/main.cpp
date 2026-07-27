#include <iostream>
using namespace std;


// write program to perform any 5 string ops 


int main() {

    string s1 = "\nCOP 3003";
    string s2 = "Professor Devasenapathy.\n"; 
    string s3 = "Software Testing"; 
    string s4 = "During the Fall Semester";
    string s5 = " Is taught by: "; 

    cout << s1 << endl; 

    s1.append(s5).append(s2);
    cout << s1;

    s1.swap(s3); 
    
    s1.append(s5).append(s2);
    cout << s1;
    
    s3.append(s4); 
    s3.insert()

    return 0;
}
