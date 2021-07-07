#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] + arr[i-1] == arr[j]) ans++;
        }
    }
    if (ans == 0) cout << -1;
    else cout << ans;
}