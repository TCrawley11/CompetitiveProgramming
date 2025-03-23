#include <iostream>
#include <vector>

void dump(std::vector<int> v) {
    if (v.size() == 0) {
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << v[v.size() - 1] << std::endl;
}

int main() {
    int n; // number of arrays
    int q; // number of queries
    std::cin >> n >> q;
    std::vector<std::vector<int>> v(n); // array of n separate vectors
    for (int i = 0; i < q; i++) {
        int a; //first query parameter
        int b; //second query parameter
        std::cin >> a >> b;

        if(a == 0) {
            int c; // optional third paramter for query type 0
            std::cin >> c;
            v[b].push_back(c);
        } else if (a == 1) {
            dump(v[b]);
        } else if (a == 2) {
            v[b].clear();
        }
    }
    return 0;
}