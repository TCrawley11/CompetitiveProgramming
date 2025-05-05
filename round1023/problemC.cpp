#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll NEG_INF = -1000000000000000000LL;  // –1e18

    int T;
    cin >> T;
    while(T--){
        int n;
        ll K;
        cin >> n >> K;

        string s;
        cin >> s;

        vector<ll> A(n+2), B(n+2);
        // read A[1..n], build B = A for knowns, 0 for unknowns
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            B[i] = (s[i-1]=='1' ? A[i] : 0LL);
        }

        // 1) compute M0 = max-subarray-sum of B with Kadane
        ll M0 = 0, cur = 0;
        for(int i = 1; i <= n; i++){
            cur = max(0LL, cur + B[i]);
            M0 = max(M0, cur);
        }
        if(M0 > K){
            // even without filling any unknowns you already exceed K
            cout << "No\n";
            continue;
        }
        if(M0 == K){
            // we already hit exactly K; now just make every unknown super-negative
            cout << "Yes\n";
            for(int i = 1; i <= n; i++){
                if(s[i-1]=='1') 
                    cout << A[i] << " ";
                else 
                    cout << NEG_INF << " ";
            }
            cout << "\n";
            continue;
        }

        // 2) M0 < K: we want to boost the max-subarray-sum by D = K - M0,
        //    placing that boost at exactly one unknown position i.
        ll D = K - M0;

        // build dpL[i] = max subarray sum ending at i  (allowing empty → 0)
        // and dpR[i] = max subarray sum starting at i
        vector<ll> dpL(n+2), dpR(n+2);
        dpL[0] = 0;
        for(int i = 1; i <= n; i++){
            dpL[i] = max(0LL, dpL[i-1] + B[i]);
        }
        dpR[n+1] = 0;
        for(int i = n; i >= 1; i--){
            dpR[i] = max(0LL, dpR[i+1] + B[i]);
        }

        // find any zero‐slot i where dpL[i-1] + dpR[i+1] == M0
        int where = -1;
        for(int i = 1; i <= n; i++){
            if(s[i-1]=='0' && dpL[i-1] + dpR[i+1] == M0){
                where = i;
                break;
            }
        }
        if(where < 0){
            // no unknown sits inside *any* max‐sum segment → you cannot bump
            cout << "No\n";
            continue;
        }

        // 3) build the answer: put the entire boost D at `where`,
        //    keep other unknowns zero, and leave knowns as is.
        cout << "Yes\n";
        for(int i = 1; i <= n; i++){
            if(s[i-1]=='1'){
                // remembered slot
                cout << A[i] << " ";
            } else {
                // forgotten slot
                if(i == where) 
                    cout << D << " ";
                else 
                    cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
