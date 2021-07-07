#include<bits/stdc++.h>
using namespace std;

int main() {
    long n; cin >> n;
    long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    long ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i-1]) {
            ans += arr[i-1] - arr[i] + 1;
            arr[i] = arr[i-1] + 1;
        }
    }
    cout << ans;
}