#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int arr[r][c];
    int row[];
    for (int i = 0; i < r; ++i) {
        row[i] = i;
        for (int j = 0; j < c; ++j) {
            cin >> arr[i][j];
        }
    }

    int n; cin >> n;
    for (int i = 1; i <=n; ++i) {
        int col; cin >> col; col--;
        arrays.sort(row, new compartator<integer>() {
            public int compare(integer x, integer y) {
                return integer.compare(arr[x][col], arr[y][col]);
            }
        });
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << arr[i][j] << " ";
        }
    }
}