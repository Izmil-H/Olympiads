#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    bool ans = false;
    for (int i = 0; i <= x; i++) {
        int chkn = i*2;
        int rbt = y-chkn;
        if (rbt == (x-i)*4) ans = 1;
    }
    if (ans) cout << "Yes";
    else cout << "No";
}