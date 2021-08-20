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
const int MS = 5e5+2;

int n, m; ll ans;
mii mr, mc;

int main() {
    cin >> n >> m; 
    Fo(i,1,n+1,1){
        int r; cin >> r; 
        if (r >= 0) mr[r-i]++;
    }
    Fo(j,1,m+1,1){
        int c; cin >> c;
        if (c >= 0) mc[c-j]++;
    }
    for (auto e: mr) {
        ans += min(e.S, mc[e.F]);
    }
    cout << ans << endl;
}

/*
r[i] + j == c[j] + i
r[i] - i == c[j] - j

r[i] == c[j] + i - j

*/