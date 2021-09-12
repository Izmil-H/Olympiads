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
const int MS = 2e5+2;

const int mod = 1e9+7;
string s, t;
int fs[26], ft[26];
ll hsh[MS], pw[MS], hsh2[MS], pw2[MS];

bool checkFreq() {
    fo(i,26) {
        if (fs[i] != ft[i]) return false;
    }
    return true;
}
ll getHash(int l, int r) {
    ll v1 = (hsh[r] - hsh[l-1] * pw[r-l+1] % mod + mod) % mod;
    ll v2 = (hsh2[r] - hsh2[l-1] * pw2[r-l+1] % mod + mod) % mod;
    return (v1 << 31) | v2;
}

int main() {
    
    cin >> s >> t;
    int n = s.length(), m = t.length(), base = 131, base2 = 137;
    
    fo(i,n) fs[s[i]-'a']++;
    hsh[0] = 0; pw[0] = 1; hsh2[0] = 0; pw2[0] = 1;
    Fo(i,1,m+1,1) {
        hsh[i] = (hsh[i-1]*base + t[i-1]) % mod;
        pw[i] = (pw[i-1]*base) % mod;
        hsh2[i] = (hsh2[i-1]*base2 + t[i-1]) % mod;
        pw2[i] = (pw2[i-1]*base2) % mod;
    }    
    set<ll> st;
    Fo(i,1,m+1,1) {
        ft[t[i-1]-'a']++;
        if (i > n) ft[t[i-1-n]-'a']--;
        //if (i >= n) cout << t.substr(i-n,n) << endl;
        //fo(i,26) cout << fs[i] << " "; cout << endl;
        //fo(i,26) cout << ft[i] << " "; cout << endl;
        if (checkFreq()) {
            //cout << t.substr(i-n,n) << " " << getHash(i-n+1,i) << endl; 
            st.insert(getHash(i-n+1,i));
        }
    }
    cout << st.size();
}