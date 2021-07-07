#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    int n, t;
    cin >> t >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n, compare);

    int current = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(arr[i] - current) <= t) {
            t -= abs(arr[i] - current);
            count += 1;
            current = arr[i];
            
        } else break;
    }
    cout << count;
}