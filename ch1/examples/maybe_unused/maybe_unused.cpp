#include <iostream> 

int main() 
{
    [[maybe_unused]] double pi { 3.14159 };
//    [[maybe_unused]] double gravity { 9.8 };
    [[maybe_unused]] double phi { 1.61803 };
    double gravity { 9.8 };

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    return 0;
}
