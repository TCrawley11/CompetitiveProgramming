#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

bool valid() {
    std::unordered_set<char> open;
    open.insert('(');
    open.insert('{');
    open.insert('[');

    std::unordered_set<char> close;
    close.insert(')');
    close.insert('}');
    close.insert(']');

    std::string user_input;
    std::cin >> user_input;

    std::stack<char> stk;

    char last = '\0';
    for (char c : user_input) {
        if (open.find(c) != open.end()) { // push opening bracket onto stack
            stk.push(c);
        } else if (close.find(c) != close.end()) { 
            if (stk.empty()) return false;
        }
        
        char last = stk.top();
        stk.pop();

        if ((last == '(' && c != ')') || 
            (last == '{' && c != '}') || 
            (last == '[' && c != ']')) {
                return false;
            }
    }
    return stk.empty();
}

int main () {
    std::cout << valid();
} 