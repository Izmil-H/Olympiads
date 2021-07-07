#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; long long k;
    cin >> n >> m >> k;
    int rows[m] = {0};
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        for(int j = a-1; j < b; ++j) {
            rows[j]--;
        }
    }
    
    long sumArr[m+1] = {0};
    for(int i = 0; i < m; ++i) {
        rows[i] += m;
        if (i>0) sumArr[i] = sumArr[i-1] + rows[i];
    }

    int ans = INT_MAX;
    for(int l = 1, r = 1; r <=m; ++r) {
        while(sumArr[r] - sumArr[l-1] >= k) {
            ans = min(ans, r-l+1);
            l++;
        }
    }
    cout << (ans==INT_MAX? -1: ans);

    /* ---- attempt -----
    int n, m; long long k;
    cin >> n >> m >> k;
    bool arr[n][m] = {{0}};
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        for(int j = a-1; j < b; ++j) {
            arr[i][j] = 1;
        }
    }
    long long sums[n] = {0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            sums[i] += arr[i][j];
            //cout << arr[i][j] << " ";
        }
        sums[i] = m - sums[i];
        //cout << sums[i] << endl;
    }

    long long sum = 0;
    int l = 0, r = 0, len = n+1;
    while (r < n) {
        while (sum < k && r < n) {
            sum += sums[r++];
            //cout << l << " " << r << " " << sum << " " << len << endl;
        }
        while (sum >= k && l <= r) {
            len = min(len, r-l+1);
            sum -= sums[l]; l++; 
            //cout << l << " " << r << " " << sum << " " << len << " " << r-l+2 << endl;
        }
        len = min(len, r-l+1);
    }
    if (len > n) cout << -1;
    else cout << len;
    */
}
