#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr+n);
    int split = n/2 - 1;
    if (n%2 != 0) split++;

    cout << arr[split] << " ";
    for (int i = 1; i <= n/2; ++i) {
        cout << arr[split+i] << " ";
        if (n%2 == 0 && i == n/2) break;
        cout << arr[split-i] << " ";
    }
}