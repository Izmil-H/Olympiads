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

string s;
ll hsh[MS], pw[MS], base = 131;

ll getHash(int l, int r) {
    return hsh[r] - hsh[l-1]*pw[r-l+1];
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(hsh, 0, sizeof(hsh)); memset(pw, 0, sizeof(pw));
        cin >> s; int n = s.length();
        pw[0] = 1;
        fo(i,n) {
            hsh[i+1] = hsh[i]*base + s[i];
            pw[i+1] = pw[i]*base;
        }
        //fo(i,n+1) cout << hsh[i] << " "; cout << endl;
        for (int i = 1; i <= n; i++) {
            if (n%i) continue;
            ll curH = getHash(1,i);
            bool works = true;
            for (int j = i; j <= n-i; j+=i) {
                int l = j+1, r = j+i;  
                //cout << i << " " << l << " " << r << " " << getHash(l,r) << endl;
                if (curH != getHash(l,r)) {
                    works = 0; break;
                }
            }
            //cout << i << " " << works << endl;
            if (works) { cout << n/i << endl; break; }
        }
    }
}