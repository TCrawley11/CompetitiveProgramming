#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int main() {
    int n; // number of integers in array
    int q; // number of queries
    std::string toPrint;
    std::cin >> n;
    std::vector<int> v(n); // vector with n integers
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::cin>>q; // queries
    std::sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int x; // user input num for lower bound
        std::cin >> x;

        auto res = find(v.begin(), v.end(), x);
        // Number was not found
        if (res == v.end()) {
            toPrint += "No ";
            toPrint += std::to_string(std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1);
            toPrint += '\n';
        } else { // Number found
            toPrint += "Yes ";
            toPrint += std::to_string(res - v.begin() +1);
            toPrint += '\n';
        }
    }
    std::cout << toPrint;
}