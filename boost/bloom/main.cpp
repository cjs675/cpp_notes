#include <boost/bloom/filter.hpp>
#include <iostream> 
#include <string> 

int main() 
{ 
    std::cout << "---- Boost Bloom Filter Test ----\n\n";
    // bloom filter of strings with 5 bits set per insertion 
    using filter = boost::bloom::filter<std::string, 5>;

    // create filter with a capacity of 1'000'000 **bits** 
    filter f(1000);

    std::cout << "1. Inserting elements..\n";
    f.insert("hello");
    f.insert("boost");
    f.insert("C++");
    std::cout << "  [ 'hello', 'boost', 'C++' ] inserted.\n\n";

    std::cout << "2. Checking inserted elements ( Should be true):\n";
    std::cout << "   Constains 'hello'? " << (f.may_contain("hello") ? "Yes" : "No") << "\n";
    std::cout << "   Contains 'boost'? " << (f.may_contain("boost") ? "Yes" : "No") << "\n"; 

    std::cout << "\n3. CHecking non-inserted elements:\n";
    std::cout << "  Contains 'bye'? " << (f.may_contain("bye") ? "Yes (false positive)" : "No") << "\n";



}
