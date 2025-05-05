#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];

        ll mn = *min_element(a.begin(), a.end());
        ll mx = *max_element(a.begin(), a.end());
        ll d = mx - mn;
        ll cntMax = count(a.begin(), a.end(), mx);

        // compute parity of sum
        ll S = 0;
        for(ll x : a) 
            S += x;

        bool safe;
        if (d > k + 1) {
            safe = false;
        } else if (d == k + 1 && cntMax > 1) {
            safe = false;
        } else {
            safe = true;
        }

        bool tomWins = safe && (S % 2 == 1);
        cout << (tomWins ? "Tom" : "Jerry") << "\n";
    }
    return 0;
}
