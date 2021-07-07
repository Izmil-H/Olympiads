#include<bits/stdc++.h>
using namespace std; 

int main () {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int idx = lower_bound(arr, arr+n, t)-arr; 
        cout << n-idx << endl;
    }
}