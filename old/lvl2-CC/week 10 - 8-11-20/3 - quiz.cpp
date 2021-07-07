#include<bits/stdc++.h>
using namespace std; 

int main() {
    int n, l;
    cin >> n >> l;
    string arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i = n-1; i >= 0; i--) cout << arr[i];
}