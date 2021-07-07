#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int pre[n] = {0}, suf[n] = {0};
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) pre[i] = 1;
        else pre[i] = pre[i-1] + 1;
    }
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] == arr[i+1]) suf[i] = 1;
        else suf[i] = suf[i+1] + 1;
    }
    pre[0] = suf[n-1] = 1;

    int lrg = 0, idx1, idx2;
    for (int i = 0; i < n; i++) {
        if (pre[i] > 0) {
            lrg = pre[i];
            idx1 = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == lrg) idx2 = i;
    }
    int ans = lrg;
    for (int i = idx1+1; i < n; i++) {
        if (i > idx1 + 1 && pre[i] == 1) break;
        else {
            ans -= pre[i-1];
            ans += pre[i];
        }
    }
    for (int i = idx2-1; i >= 0; i--) {
        if (i < idx2 - 1 && suf[i] == 1) break;
        else {
            ans -= suf[i+1];
            ans += suf[i];
        }
    }
    cout << ans;
}