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
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];

        // 1) overall gcd
        ll g = a[0];
        for(int i = 1; i < n; i++) 
            g = gcd(g, a[i]);

        // 2) check if all equal to g
        bool all_eq = true;
        for(ll x : a) if (x != g) { all_eq = false; break; }
        if(all_eq){
            cout << "No\n";
            continue;
        }

        // 3) find any element != g and isolate it
        cout << "Yes\n";
        vector<int> answer(n, 2);
        for(int i = 0; i < n; i++){
            if(a[i] != g){
                answer[i] = 1;
                break;
            }
        }
        for(int x : answer) 
            cout << x << ' ';
        cout << "\n";
    }
    return 0;
}
