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
const int MS = 25000;

int n; string s;
ll hsh[MS], pw[MS], base = 131;
ll rhsh[MS], rpw[MS];

ll getHash(int l, int r) {
    return hsh[r] - hsh[l-1]*pw[r-l+1];
}
ll getrHash(int l, int r){
    return rhsh[l] - rhsh[r+1]*pw[r-l+1];
}


int main() {
    cin >> n >> s;
    pw[0] = 1;
    fo(i,n) {
        hsh[i+1] = hsh[i]*base + s[i];
        pw[i+1] = pw[i]*base;

        rhsh[n-i] = rhsh[n-i+1]*base + s[n-i-1];
        rpw[n-i] = rpw[n-i+1]*base;
    }

    //fo(i,n+2) cout << hsh[i] << " "; cout << endl;
    //fo(i,n+2) cout << rhsh[i] << " "; cout << endl;

    pii ans = {1,1};
    for(int i = 1; i <= n; i++) {
        int lo = 0, hi = min(i-1,n-i); pii a = {0,0};
        while (lo <= hi) {
            int m = (lo+hi)/2;
            //cout << i << " " << lo << ":" << m << ":" << hi << " " << getHash(i-m,i) << " " << getrHash(i,i+m) << endl;
            if (getHash(i-m,i) == getrHash(i,i+m)) { 
                if (2*m > a.S-a.F){
                    a.F = i-m; a.S = i+m;
                }
                lo = m+1; 
            } else hi = m-1;
        }
        if (a.S-a.F > ans.S-ans.F) ans = a;
        //cout << s.substr(ans.F-1, ans.S-ans.F+1) << endl;
    }
    cout << s.substr(ans.F-1, ans.S-ans.F+1) << endl << ans.S-ans.F+1;
}
/*
0   1   2   3   4
    a   b   c   d

abeffgffecd

*/   
