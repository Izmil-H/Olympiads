#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[4][4];
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> arr[i][j];
            if(i != j) {
                sum += arr[i][j];
            }
        }
    }
    bool tree = true;
    for (int i = 0; i < 4; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 4; ++j) {
            rowSum+= arr[i][j];
            if (arr[i][j] != arr[j][i]) {
                tree = false;
                break;
            }
            if (j == 3 && rowSum == 0) tree = false;
        }
    }
    if (sum != 6) tree = false;
    
    if (tree) cout << "Yes";
    else cout << "No";
}