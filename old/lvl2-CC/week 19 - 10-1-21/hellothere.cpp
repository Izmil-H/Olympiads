#include<bits/stdc++.h>
using namespace std;

const int MM = 1e6+2;
int pos[MM];
int main() {
    int n, k;
    cin >> n >> k;
    long long sum[n+1] = {0}; 
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        sum[i] = (sum[i-1] + a)%k;
    }
    fill(pos, pos+MM, -1); pos[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[sum[i]] != -1) ans = max(ans, i - pos[sum[i]]);
        else pos[sum[i]] = i;
    }
    cout << ans;
}