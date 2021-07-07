#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int cnt = 1; long sum = arr[0];
    for (int i = 1; i < n; i++) {
        if (sum <= arr[i]) {
            cnt++;
            sum += arr[i];
        }
    }
    cout << cnt;
}