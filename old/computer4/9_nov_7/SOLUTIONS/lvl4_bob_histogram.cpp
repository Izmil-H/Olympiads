#include <bits/stdc++.h>
using namespace std;
int n, h[100], ans = 1e9;
int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> h[i];
    for(int t = -100; t<=100; t++) {
        int tot = 0;
        for(int i=0; i<n; i++) {
            tot += (h[i] - t)*(h[i] - t);
        }
        ans = min(ans, tot);
    }
    cout << ans << endl;
}