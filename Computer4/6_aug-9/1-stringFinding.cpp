#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define v(t) vector<t>
#define pii pair<int,int>
#define mii map<int,int>
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e6+2;

string s, t;
ll hT, hsh[MS], pw[MS], base = 37, mod = 1e9+7;

ll getHash(int l, int r) {
    return (hsh[r] - hsh[l-1] * pw[r-l+1] % mod + mod) % mod;
}

int main() {
    cin >> s >> t;    
    int n = s.length(), m = t.length();
    hsh[0] = 0; pw[0] = 1;

    fo(i,m) {
        hT = (hT * base + t[i]) % mod;
    }

    Fo(i,1,n+1,1) {
        hsh[i] = (hsh[i-1] * base + s[i-1]) % mod;
        pw[i] = (pw[i-1]*base) % mod;
    }

    Fo(i,m-1,n+1,1) {
        int l = i-m+2, r = i+1;
        if (hT == getHash(l,r)) {
            cout << l-1 << endl; return 0;
        }
    }
    cout << -1;
}