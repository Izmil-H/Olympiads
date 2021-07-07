#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int lX = 0, sX = 100, lY = 0, sY = 100;
    
    for (int i= 0, x, y; i < n; i++) {
        cin >> x; cin.ignore(); cin >> y;
        lX = max(lX, x); sX = min(sX, x);
        lY = max(lY, y); sY = min(sY, y);
    }
    cout << --sX << ',' << --sY << endl << ++lX << ',' << ++lY;
}