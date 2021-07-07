#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    float arr[n], sum[n+1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = arr[i] + sum[i];
    }
    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            float avg = (sum[r]-sum[l-1])/(r-l+1);
            for (int i = l; i <= r; i++) {
                if (arr[i-1] == avg) {
                    cnt++; break;
                }
                //cout << l-1 << ":" << r-1 << " " << avg << " " << arr[i-1] << " " << cnt << endl;
            }
        }
    }
    cout << cnt;;
}