#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int diff[n+1] = {0};
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        diff[l-1]++; diff[r]--;
    }
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i-1];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (diff[i]%2 != 0) count++;
    }
    cout << count;
}