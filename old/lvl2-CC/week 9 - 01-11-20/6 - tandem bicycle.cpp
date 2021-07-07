#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    long long arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr+n);    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            if (arr[i] + arr[j] <= w) count++;
            else break;
        }
    }
    cout << count/2;
}