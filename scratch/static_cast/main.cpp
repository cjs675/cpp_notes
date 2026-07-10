#include <cstdlib>
#include <iostream> 

using namespace std;

int main() 
{
    float f = 3.5;

    // implicit type case 
    // float -> int 
    int a = f;
    cout << "\nThe value of a: " << a;

    // using static_cast for float -> int 
    int b = static_cast<int>(f);
    cout << "\nThe value of b: " << b; 

    return EXIT_SUCCESS;
}
