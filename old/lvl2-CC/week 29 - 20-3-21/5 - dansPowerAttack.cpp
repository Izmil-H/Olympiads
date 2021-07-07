#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, d, k;
    cin >> n >> d >> k;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h+n, greater<int>());
    long long ans = 0;
    for (int i = k; i < n; i++ ) {
        ans += ceil(h[i]/double(d));
    }
    cout << ans;
}