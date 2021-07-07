#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int row[n] = {0}; int col[n] = {0};
    int digL[2*n-1] = {0}; int digR[2*n-1] = {0};
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        r-=1; c-=1;
        row[r] = col[c] = 1;
        digL[r+c] = digR[n-1+r-c] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!row[i] && !col[j] && !digL[i+j] && !digR[n-1+i-j]) {
                ans++;
            }
        }
    }
    cout << ans;
}