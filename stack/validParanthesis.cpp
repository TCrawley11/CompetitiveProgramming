#include <iostream>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> stk;
    
    for (char c : s) {
        // If it's an opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } 
        // If it's a closing bracket
        else {
            // If stack is empty, no matching opening bracket
            if (stk.empty()) {
                return false;
            }
            
            // Check if the top of stack matches the current closing bracket
            if ((c == ')' && stk.top() != '(') ||
                (c == '}' && stk.top() != '{') ||
                (c == ']' && stk.top() != '[')) {
                return false;
            }
            
            // Remove the matching opening bracket
            stk.pop();
        }
    }
    
    // Stack should be empty if all brackets are matched
    return stk.empty();
}

int main () {
    std:: string user_input;
    std::cin >> user_input;
    std::cout << isValid(user_input);
} 
