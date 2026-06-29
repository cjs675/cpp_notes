#include <iostream>
using namespace std;

int main() 
{


    for ( char c = 'a'; c <= 'e'; ++c) // outer loop on letters 
    { 
	    cout << c; // print our letter first 

	    for (int i=0; i < 3; ++i) // inner loop on all numbers 
		    cout << i;
		    cout << endl;
    } 
return 0;
}
