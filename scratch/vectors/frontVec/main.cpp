#include <iostream>
#include <vector> 


int main() {
    std::vector<int> vec_1 = {10, 20, 30};
    
    std::cout << "\nInitial Vector List: " << std::endl; 

    for ( int i : vec_1) {
        std::cout << i << " ";
    }
    // always check if vec isnt empty first 
    if (!vec_1.empty()) {
        // method 1: .front() (recommended) 
        int first = vec_1.front();

        // method 2: indexing 
        int first_idx = vec_1[0];

        //  method 3: .at() (safe) 
        int first_at = vec_1.at(0); 


        std::cout << "\nFirst element (using .front()): " << first << std::endl; 
        std::cout << "\nFirst element (using indexing)): " << first_idx << std::endl; 
        std::cout << "\nFirst element (using .at()): " << first_at << std::endl;
    }
    return 0;
}
