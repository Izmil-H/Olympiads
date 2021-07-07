#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int odd = 0, even = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x%2 == 0) even++;
        else odd++;
    }

    if (even == odd) {
        cout << 2*odd;
    } else if (even > odd) {
        cout << 2*odd + 1;
    } else {
        int dif = (odd-even)%3;
        int ans = 2*even + 2*((odd-even)/3);
        if ( dif == 0) {
            cout << ans;
        } else if (dif == 2) {
            cout << ans + 1;
        } else {
            cout << ans - 1; 
        }
    }
}