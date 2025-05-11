#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        ll n, m, p, q;
        cin >> n >> m >> p >> q;
        
        // k = number of full p-blocks
        ll k = n/p;
        if (n % p == 0) {
            cout << (m == k * q ? "YES\n" : "NO\n");
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}