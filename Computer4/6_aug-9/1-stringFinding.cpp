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
pair<ll,ll> hT;
ll hsh[MS], pw[MS], base = 37, hsh2[MS], pw2[MS], base2 = 31, mod = 1e9+7; 

pair<ll,ll> getHash(int l, int r) {
    ll h1 = (hsh[r] - hsh[l-1] * pw[r-l+1]%mod + mod) % mod;
    ll h2 = (hsh2[r] - hsh2[l-1] * pw2[r-l+1]%mod + mod) % mod;
    return {h1,h2};
}

int main() {
    cin >> s >> t;    
    int n = s.length(), m = t.length();
    hsh[0] = 0; pw[0] = 1;
    hsh2[0] = 0; pw2[0] = 1;

    fo(i,m) {
        hT.F = (hT.F*base + t[i]) % mod;
        hT.S = (hT.S*base2 + t[i]) % mod;
    }


    Fo(i,1,n+1,1) {
        hsh[i] = (hsh[i-1]*base + s[i-1]) % mod;
        pw[i] = (pw[i-1]*base) % mod;
        
        hsh2[i] = ((hsh2[i-1]*base2 + s[i-1]) % mod + mod) % mod;
        pw2[i] = ((pw2[i-1]*base2) % mod + mod) % mod;
    }

    cout << hT.F << ", " << hT.S << endl;
    Fo(i,m-1,n+1,1) {
        int l = i-m+2, r = i+1;
        cout << l << " " << r << " " << getHash(l,r).F << ", " << getHash(l,r).S << endl;
        if (hT == getHash(l,r)) {
            cout << l-1 << endl; return 0;
        }
    }
    cout << -1;
}