#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int l = 0, r = 0; l < n; l++) {
        while (arr[r] - arr[l]) {
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
}