#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 rng(6926442069L);
int n, p; ll a;
int main(){
    cin >> n;
    for(int i=0; i<n; i++) {
        cout << 0 << endl;
        cin >> p;
        if(!p) continue;
        a = 1LL<<(p-1);
        ll lucky = rng() & ((1LL<<p-1) - 1);
        a |= lucky;
        while(true) {
            cout << a << endl;
            cin >> p;
            if(!p) break;
            p /= 2;
            a ^= 1LL<<(p-1);
        }
    }
}