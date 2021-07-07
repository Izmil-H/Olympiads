#include<bits/stdc++.h>
using namespace std; 

int main () {
    int n; cin >> n;
    int arr[n];
    int sum[n+1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }
    int lowest = INT_MAX;
    for (int l = 2; l < n; l++) {
        for (int r = l; r < n; r++) {
            int s1 = sum[l-1];
            int s2 = sum[r] - sum[l-1];
            int s3 = sum[n] - sum[r];
            int large = max(max(s1,s2), max(s1,s3));
            int small = min(min(s1, s2), min(s1, s3));
            lowest = min(lowest, large-small);
            //cout << l << " " << r << ": " << s1 << " " << s2 << " " << s3 << endl;
        }
    }
    cout << lowest;
}