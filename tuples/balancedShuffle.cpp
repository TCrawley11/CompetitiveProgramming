#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
// prefix balance is defined as the number of opening paranthesis 
// minus the number of closing paranthesis before the current paranthesis

int main() {
    std::vector<std::tuple<int,int,char>> vals; // hold paranthesis and prefix balance
    std::string input; 
    std::string para; // inidividual paranthesis entry
    int position = 1;
    int prefix = 0;

    std::cin >> input; // grab user input

    for (char i : input) {
        vals.push_back(std::make_tuple(prefix, position, i)); // insert the pair

        if (i == '(') {
            prefix++;
        } else {
            prefix--;
        }
        position++;
    }

    // Print results
    /*
    std::cout << "Prefix balances and chars:" << std::endl;
    // go through the tuples in vals, the val in vals
    for (const auto& tuple : vals) {
        std::cout << "Balance: " << std::get<0>(tuple)  // Fixed: was val instead of tuple
                  << ", Pos: " << std::get<1>(tuple)    // Added position
                  << ", Char: '" << std::get<2>(tuple) << "'" << std::endl;
    }
    */
    
    // Custom sort: 
    // 1. Sort by balance ascending
    // 2. When balances equal, sort by position ascending
    std::sort(vals.begin(), vals.end(), 
            [](const auto& a, const auto& b) {
                if (std::get<0>(a) == std::get<0>(b)) {
                    return std::get<1>(a) > std::get<1>(b); // descending order - position
                }
                return std::get<0>(a) < std::get<0>(b); // ascending order - balance
            });
    /*
    std::cout << "After sorting:" << std::endl;
    for (const auto& tuple : vals) {
        std::cout << "Balance: " << std::get<0>(tuple)
                  << ", Pos: " << std::get<1>(tuple)
                  << ", Char: '" << std::get<2>(tuple) << "'" << std::endl;
    }
    */

    // print out just the paranthesis
    for (const auto& tuple : vals) {
        std::cout << std::get<2>(tuple);
    }

    return 0;
}
