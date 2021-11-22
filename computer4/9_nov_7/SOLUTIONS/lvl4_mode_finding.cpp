#include <bits/stdc++.h>
using namespace std;
int n, mx, ans; map<int, int> mp;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0, x; i<n; i++){
        cin >> x; mp[x]++;
    }
    for(auto e : mp){
        if(e.second > mx) {ans=e.first; mx = e.second; }
    }
    cout << ans << endl;
}