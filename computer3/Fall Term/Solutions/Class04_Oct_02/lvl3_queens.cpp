#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool row[n]={0}; bool col[n]={0}; bool lft[2*n-1]={0}; bool rit[2*n-1]={0};
    for(int i = 1; i <= m; i++) {
        int r; cin >> r; r-=1;
        int c; cin >> c; c-=1;
        row[r] = true; col[c] = true; lft[r+c] = true; rit[r+n-1-c] = true;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!row[i] && !col[j] && !lft[i+j] && !rit[i+n-1-j]) ans++;
        }
    }
    cout << ans;
}