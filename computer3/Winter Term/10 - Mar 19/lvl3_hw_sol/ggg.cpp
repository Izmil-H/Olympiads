#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int n, m, pos[MM]; vector<int> lis;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1, x; i<=n; i++){
        cin >> x; pos[x] = i;
    }
    cin >> m;
    for(int i=1, x; i<=m; i++) {
        cin >> x;  x = pos[x];
        if(x == 0) continue;
        if(lis.empty() || x > lis.back()) lis.push_back(x);
        else *lower_bound(lis.begin(), lis.end(), x) = x;
    }
    cout << lis.size() << "\n";
}