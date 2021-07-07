#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 5;
    while (t--) {
        int n; cin >> n;
        int ans[n];
        bool used[n+1] = {0}, flag = false;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            int card = n - x;
            while (used[card]) card--;
            used[card] = true;
            if (card <= 0) {flag = true; break;}
            ans[i] = card;
        }
        if (flag) cout << "IMPOSSIBLE";
        else {
            for (auto i: ans) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}