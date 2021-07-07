#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cows[n], stalls[n];
    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < n; i++) cin >> stalls[i];
    
    sort(cows,cows+n, greater<int>());
    sort(stalls,stalls+n);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= n - (lower_bound(stalls,stalls+n, cows[i]) - stalls) - i;
    }
    cout << ans;
}