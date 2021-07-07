#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool board[n][n];
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        for (int j = 0; j < n; ++j) {
            board[r][j] = 1;
            board[j][c] = 1;
            if (r-j >= 0) {
                if (c-j >= 0) board[r-j][c-j] = 1;
                if (c+j < n) board[r-j][c+j] = 1;
            }
            if (r+j < n) {
                if (c-j >= 0) board[r+j][c-j] = 1;
                if (c+j < n) board[r+j][c+j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //cout << board[i][j] << " ";
            if (board[i][j] == 1) count++;
        }
        //cout << endl;
    }
    cout << n*n - count;

    /*
    bool row[n] = {0}, col[n] = {0}, diagR[2*n-1] {0}, diagL[2*n-1] = {0};
    
    int count = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (row[r] == 1 || col[c] == 1) {
                count+= ;
                cout << 'i';
            } else if (diagR[r+c-2] == 1; diagL[n-c+r-1] == 1) {
        }
    }
    cout << n*n - count;
    */
}
