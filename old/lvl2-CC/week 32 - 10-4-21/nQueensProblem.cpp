#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> row;
vector<bool> col, lft, rit;

void putQ(int r) {
    if (r == n) {
        cout << "================\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == row[i]) cout << "Q";
                else cout << ".";
            }
            cout << endl;
        }
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !lft[r+c] && !rit[r+n-1-c]) {
            row[r] = c;
            col[c] = lft[r+c] = rit[r+n-1-c] = 1;
            putQ(r+1);
            col[c] = lft[r+c] = rit[r+n-1-c] = 0;
        }
    }
}

int main() {
    cin >> n;
    row.resize(n);
    col.resize(n);
    lft.resize(2*n-1);
    rit.resize(2*n-1);

    putQ(0);
}