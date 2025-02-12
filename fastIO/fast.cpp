#include <iostream>
#include <vector>

using namespace std;

int main () {
    // Make cin and cout faster
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // grab number of outputs
    int a;
    cin >> a;

    //initialize array to hold them so we can mass print at the end
    vector<int> result;

    int i = 0;
    while (i < a) {
        int b; int c;
        cin >> b >> c;

        // Add result to result vector
        result.push_back(b * c);

        i+=1;
    }

    for (const auto& res : result) {
        cout << res << '\n';
    }

    return 0;
}