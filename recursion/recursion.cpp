
#include <iostream>

int fibonacci(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
    std::string testStr;
}

int main() {
    int f;
    std::cout << "WHich Nth value of the fibonacci sequence do u want to see?" << '\n';
    std:: cin >> f; 
    std::cout << fibonacci(f) << "\n";
}