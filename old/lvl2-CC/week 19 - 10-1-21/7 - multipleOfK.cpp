#include<bits/stdc++.h>
using namespace std;

/*
int main() {
    int n, k;
    cin >> n >> k;
    int sum[n+1] = {0};
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        sum[i] = (sum[i-1] + a)%k;
    }
    
    int lngst = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            if (sum[i] == sum[j]) {
                lngst = max(lngst, j-i);
                break;
            }
            //cout << i << ":" << j << " " << sum[i] << " " << lngst << endl;
        }
    }
    cout << lngst;
}
*/
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