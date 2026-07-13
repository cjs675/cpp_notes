#include <iostream> 

class Stack {

private: 
    int stackStore[100];
    int SP; 

public:  
    Stack(void) {
        SP = 0;
    }
    void push(int value);
    int pop(void) {
        
        return stackStore[--SP];
    }
}; 

void Stack::push(int value) {
    stackStore[SP++] = value;
} 

class AddStack : Stack {
    private: 
        int sum;
    public:
        AddStack(void);
        void push(int value);
        int pop(void);
        int getSum(void);
}; 

// constructor 
AddStack::AddStack(void) : Stack() {
    sum = 0;
}

void AddStack::push(int value) {
    sum += value;
    Stack::push(value);
} 

int AddStack::pop(void) {
    int val = Stack::pop();
    sum -= val;
    
    return val;
} 

int AddStack::getSum(void) {
    return sum;
}





int main(void) {  
    AddStack superStack;

    for(int i = 1; i < 10; i++) {
        superStack.push(i);

    std::cout << superStack.getSum() << std::endl;

    for(int i = 1; i < 10; i++) 
        superStack.pop();

    std::cout << superStack.getSum() << std::endl;

    return 0;
    }
}


