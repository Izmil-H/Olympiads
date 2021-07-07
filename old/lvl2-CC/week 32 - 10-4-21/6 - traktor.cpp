#include<bits/stdc++.h>
using namespace std;

int n, k;
const int sz = int(1e5);
int row[sz+3], col[sz+3], lft[2*sz+2], rit[2*sz+2];

int main() {
    cin >> n >> k;
    for (int t = 1, r, c; t <= n; t++) {
        cin >> r >> c;
        row[r]++; col[c]++; lft[r+c]++; rit[r+sz-c]++;
        if (row[r] == k || col[c] == k || lft[r+c] == k || rit[r+sz-c] == k) {
            cout << t;
            return 0;
        }
    }
}