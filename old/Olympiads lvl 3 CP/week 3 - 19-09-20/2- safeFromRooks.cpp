#include<bits/stdc++.h>
using namespace std; 

int main() {
    for (int t = 0; t < 5; ++t) {
        int r, c, n;
        cin >> r >> c >> n;
        set<int> row, col;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            row.insert(x); col.insert(y);
        }
        cout << r*c - row.size()*c - col.size()*r + row.size()*col.size() << endl;
    }
}

/* int main() {
    for (int t = 0; t < 5; ++t) {
        long long int r, c, ro;
        cin >> r >> c >> ro;
        long long int row[r] = {0}, col[c] = {0};
        for (long long int i = 0; i < ro; ++i) {
            long long int x, y;
            cin >> x >> y;
            x-=1; y-=1;
            row[x] = col[y] = 1;
        }
        
        long long int numR = 0, numC = 0;
        for (long long int i = 0; i < r; ++i) {
            if (row[i]) {
                numR++;
            }
        }
        for (long long int i = 0; i < c; ++i) {
            if (col[i]) {
                numC++;
            }
        }
        cout <<  r*c - r*numR - c*numC + numR*numC << endl;
    }
}
*/