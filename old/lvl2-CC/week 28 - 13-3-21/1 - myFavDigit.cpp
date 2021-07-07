#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 5;
    while (t--) {
        int n, ans = 0; cin >> n;
        while (n) {
            ans = max(ans, n%10);
            n /= 10;
        }
        cout << ans << endl;
    }
}