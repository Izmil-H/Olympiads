#include<bits/stdc++.h>
using namespace std;

bool houses[int(1e5)+2];

int main() {
    int n, k, r;
    cin >> n >> k >> r;
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        houses[x] = 1;
    }
    
    int cur = 0, ans = 0;
    for (int i = 1; i <= r; i++) cur += houses[i];

    for (int i = r; i <= n; i++) {
        cur -= houses[i-r];
        cur += houses[i];
        while (cur < 2) {
            if (!houses[i]) { houses[i] = 1; cur++; ans++;}
            else if (!houses[i-1]) { houses[i-1] = 1; cur++; ans++;}
        }
    }
    cout << ans << endl;
}


     