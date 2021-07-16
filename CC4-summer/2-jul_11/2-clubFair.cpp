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
    int n, q, x, y, r;
    map<int, int> mp;
    cin >> n >> q;
    fo(i,n) {
        cin >> x >> y;
        int dst = ceil(sqrt(x*x + y*y));
        mp[dst]++;
    }
    int temp[mp.size()], cnt = 0;
    for(auto it: mp) {
        temp[cnt] = it.S; 
        cnt++;
        cout << it.F << ":" << it.S << ":" << temp[cnt-1] << ", ";
    }
    cout << endl;
    cnt = 0;
    for(auto it: mp) { 
        temp[cnt] += temp[cnt-1]; 
        it.S = temp[cnt]; 
        cnt++;
    }

    fo(i,q) {
        cin >> r;
        cout << "#" << mp[r] << endl;
    }
    for(auto it: temp) cout << it << " "; cout << endl;
    for(auto it: mp) cout << it.F << ":" << it.S << ", ";
}