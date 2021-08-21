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
const int MS = 1e6+2, base = 131;

char s[MS]; int k;
ll hsh[MS], pw[MS];

ll getSubHash(int l, int r) {
    return hsh[r] - hsh[l-1]*pw[r-l+1];
}

int main() {
    scanf("%s %d", s+1, &k); int n = strlen(s+1);
    pw[0] = 1;
    Fo(i,1,n+1,1) {
        pw[i] = pw[i-1] * base;
        hsh[i] = hsh[i-1] * base + s[i];
    }
    int pos = 1;
    
    for (int i = 2; i+k-1 <= n; i++) {
        if (s[i] < s[pos]) pos = i;
        else if (s[i] == s[pos]) {
            int lo = 0, hi = k-1, dif = 0;
            while (lo <= hi) {
                int m = (lo+hi)/2;
                if (getSubHash(pos, pos+m) == getSubHash(i, i+m)) lo = m+1;
                else { dif = m; hi = m-1; }
            }
            if (s[pos+dif] > s[i+dif]) pos = i;
        }
    }
    Fo(i,pos,pos+k,1) cout << s[i];
}