#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> row, col, lft, rit;


int main() {
    cin >> n >> m;
    row.resize(n);
    col.resize(n);
    lft.resize(2*n-1);
    rit.resize(2*n-1);

    for (int i = 0, r, c; i < m; i++) {
        cin >> r >> c; 
        r--; c--;
        row[r] = col[c] = lft[r+c] = rit[r+n-1-c] = true;
    }
    int ans = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (!row[r] && !col[c] && !lft[r+c] && !rit[r+n-1-c]) ans++;
        }
    }
    cout << ans;
}