#include <iostream>
#include <tuple>
#include <set>

int summer(int n) {
    std::set<std::tuple <std::string, std::string>> uniqueLeaves;
    std::string species;
    std::string color;
    for (int i = 0; i < n; i++) {
        std::cin >> species;
        std::cin >> color;
        std::tuple <std::string, std::string> leaf(species, color);
        uniqueLeaves.insert(leaf);
    }
    return size(uniqueLeaves);
}

int main() {
    int numLeaves;
    std::cin >> numLeaves;
    std::cout << summer(numLeaves) << std::endl;
    return 0;
}