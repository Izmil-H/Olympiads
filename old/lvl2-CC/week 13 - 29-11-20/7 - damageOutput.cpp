#include<bits/stdc++.h>
using namespace std;

int main() {
    // --- bruce method -----
    int n; long m;
    cin >> n >> m;
    long sumArr[n+1] = {0};
    for(int i = 1; i < n; ++i) {
        int x; cin >> x;
        sumArr[i] = x + sumArr[i-1];
    }
    int ans = INT_MAX;
    for(int l = 1, r = 1; r <=n; ++r) {
        while(sumArr[r] - sumArr[l-1]>= m) {
            ans = min(ans, r-l+1);
            l++;
        }
    }
    cout << (ans==INT_MAX? -1: ans);
    

    /* ---- online method -------
    int n; long m;
    cin >> n >> m;
    int arr[n]; 
    for (int i = 0; i < n; ++i) cin >> arr[i];
    long long sum = 0;
    int l = 0, r = 0, len = n+1;
    while (r < n) {
        while (sum < m && r < n) {
            sum += arr[r++];
            //cout << l << " " << r << " " << sum << " " << len << endl;
        }
        while (sum >= m && l <= r) {
            len = min(len, r-l+1);
            sum -= arr[l]; l++; 
            //cout << l << " " << r << " " << sum << " " << len << " " << r-l+2 << endl;
        }
        len = min(len, r-l+1);
    }
    if (len > n) cout << -1;
    else cout << len;
    */
}