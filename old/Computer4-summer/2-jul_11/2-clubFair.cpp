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
    int n, q, x, y, r, cnt = 1;
    cin >> n >> q;
    map<int,int> mp;
    vector<int> key, val;
    key.PB(-1); val.PB(0);

    fo(i,n) {
        cin >> x >> y;
        int dst = ceil(sqrt(x*x + y*y));
        mp[dst]++;
    }
    
    for(auto it: mp) {
        //cout << it.F << ":" << it.S << ", ";
        key.PB(it.F);
        val.PB(it.S);
        if (cnt > 0) val[cnt] += val[cnt-1];
        cnt++;
    }

    //cout << endl;
    //fo(i,key.size()) cout << key[i] << " "; cout << endl;
    //fo(i,val.size()) cout << val[i] << " "; cout << endl;
    fo(i,q) {
        cin >> r;
        int ind = lower_bound(key.begin(), key.end(), r) - key.begin();
        cout << (key[ind] == r? val[ind]: val[ind-1]) << endl;
    }
} 