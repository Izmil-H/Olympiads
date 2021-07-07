#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    int arr[k][n];
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
           cin >> arr[i][j]; 
        }
    }
    string freq[n];
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = arr[i][j] - 1;
            for (int k = j; k < n; ++k) {
                if (arr[i][k] != idx + 1) {
                    freq[idx] += '0' + arr[i][k];
                    
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (count(freq[i].begin(), freq[i].end(), '0' + arr[0][j]) == k) {
                ans++;
            }  
        }
    }
    cout << ans;
}