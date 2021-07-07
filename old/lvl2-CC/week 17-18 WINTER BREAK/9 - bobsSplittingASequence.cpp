#include<bits/stdc++.h>
using namespace std; 

int main () {
    int n; cin >> n;
    int arr[n];
    long long sum[n+1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
        //cout << sum[i+1] << " ";
    }
    //cout << endl;

    long long lowest = INT_MAX;
    for (int l = 2; l < n; l++) {
        long long s1 = sum[l-1];
        int r = lower_bound(sum+l, sum+n-1, (sum[n]+s1)/2)-sum;
        long long s2 = sum[r] - sum[l-1];
        long long s3 = sum[n] - sum[r];
        long long large = max(max(s1,s2), max(s1,s3));
        long long small = min(min(s1,s2), min(s1,s3));
        lowest = min(lowest, abs(large-small));
        s1 = sum[l-1];
        //cout << sum[n]-s1 << " " << l << " " << r << ": " << s1 << " " << s2 << " " << s3 << endl;

        r = upper_bound(sum+l, sum+n-1, (sum[n]+s1)/2)-sum;
        s2 = sum[r] - sum[l-1];
        s3 = sum[n] - sum[r];
        large = max(max(s1,s2), max(s1,s3));
        small = min(min(s1,s2), min(s1,s3));
        lowest = min(lowest, abs(large-small));
        //cout << sum[n]-s1 << " " << l << " " << r << ": " << s1 << " " << s2 << " " << s3 << endl;
    }
    cout << lowest;
}
