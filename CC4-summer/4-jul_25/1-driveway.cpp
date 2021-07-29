#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}


int main() {
    int n, m; string x, c; vector<string> crs;
    cin >> n >> m;
    fo(i,n) {
        cin >> x >> c;
        int idx;
        if (c == "in"){
            crs.PB(x);
            m++;
        } else {
            if (crs[0] == x && m > 0) crs.erase(crs.begin());
            else if (crs.back() == x) crs.erase(crs.end()-1);
            m--;
        }            
    }
    for(auto cr: crs) cout << cr << endl;
}