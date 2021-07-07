#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n+2], pre[n+2] = {0}, suf[n+2] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = __gcd(pre[i-1], arr[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = __gcd(suf[i+1], arr[i]);
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, __gcd(pre[i-1], suf[i+1]));
    }
    cout << ans;
}    