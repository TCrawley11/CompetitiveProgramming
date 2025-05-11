#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;

        long long A1 = llabs(a[0]);
        int cnt_smaller = 0;
        for(int i = 0; i < n; i++){
            if (llabs(a[i]) < A1)
                cnt_smaller++;
        }
        // if at most floor(n/2) values have |a_i|<|a1|, it's YES
        if (cnt_smaller <= n/2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
