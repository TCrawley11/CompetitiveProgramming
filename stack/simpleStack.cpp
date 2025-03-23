#include <iostream>
#include <vector>
#include <string>

struct simpleStack {
    std::vector<int> values;  // Added int type parameter
    
    void push(int n) {
        this->values.push_back(n);
        std::cout << "ok" << std::endl;
    }
    
    void pop() {
        if (values.empty()) {
            std::cout << "error" << std::endl;  // Handle empty stack case
            return;
        }
        int val = values.back();
        values.pop_back();
        std::cout << val << std::endl;
    }
    
    void back() {
        if (values.empty()) {
            std::cout << "error" << std::endl;  // Handle empty stack case
            return;
        }
        std::cout << values.back() << std::endl;
    }
    
    void size() {
        std::cout << values.size() << std::endl;  // No need for std::to_string
    }
    
    void clear() {
        this->values.clear();
        std::cout << "ok" << std::endl;
    }
    
    void exit() {
        std::cout << "bye" << std::endl;
        std::exit(0); // exit program
    }
};

int main() {
    simpleStack stack;  // No need for dynamic allocation
    std::string cmd;
    
    // Process commands until exit is called
    while (std::cin >> cmd) {
        if (cmd == "push") {
            int z;
            std::cin >> z;
            stack.push(z);
        } else if (cmd == "pop") {
            stack.pop();
        } else if (cmd == "back") {
            stack.back();
        } else if (cmd == "size") {
            stack.size();
        } else if (cmd == "clear") {
            stack.clear();
        } else if (cmd == "exit") {
            stack.exit();
        } else {
            // Handle unknown command
            std::cout << "error" << std::endl;
        }
    }
    
    return 0;
}