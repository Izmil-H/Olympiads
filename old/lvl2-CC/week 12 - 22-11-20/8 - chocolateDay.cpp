#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    long cup[n+2] = {0};
    for (int i = 0; i < t; ++i) {
        int a, b, c; cin >> a >> b >> c;
        cup[a] += c;
        cup[b + 1] -= c;
    }
    
    int sumA[n] = {0};
    for (int i = 1; i <= n; ++i) {
        cup[i] += cup[i-1]; 
        sumA[i] = sumA[i-1] + cup[i];
    }
    for(int i = 0; i < n+2; ++i) cout << cup[i] << " ";
    int lim; cin >> lim;
    int ans = 0;
    for (int l = 1, r = 1; r <= n; ++r) {
        while (sumA[r] - sumA[l-1] > lim) {
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
}