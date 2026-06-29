#include <iostream> 
#include <memory> 
#include <string> 

// a simple class to help track when memory is created 
class HeavyResource {
public: 
    std::string name;

    HeavyResource(std::string n) : name(n) {
        std::cout << "[Heap] Allocated: " << name << "\n"; 
    }

    ~HeavyResource() {
        std::cout << "[Heap] Destroyed: " << name << "\n";
    }

    void doWork() {
        std::cout << "Working with " << name << "...\n";
    }
};

int main() {
    std::cout << "--- std::move Example ---\n\n";
    
    // 1. resource allocated on heap - ptr1 owns it 
    std::unique_ptr<HeavyResource> ptr1 = std::make_unique<HeavyResource>("My Massive Data");

    // 2. the ERROR: if the following line is uncommented, build will fail 
    // unique pointers cannot be copied 
    //  std::unique_ptr<HeavyResource> ptr2 = ptr1;

    // 3. the fix: aggressively transfer ownership to ptr3
    std::cout << "\nTransferring ownership...\n";
    std::unique_ptr<HeavyResource> ptr3 = std::move(ptr1);
    // 3. checking aftermath 
    if (!ptr1) {
        std::cout << "ptr1 is now empty (nullptr).\n";
    }

    if (ptr3) {
        std::cout << "ptr3 is the new owner.\n";
        ptr3 -> doWork();
    }

    std::cout << "\nEnding program. Watch the cleanup:\n";
    return 0; // ptr3 goes out of scope here & auto cleans up the heap
} 

