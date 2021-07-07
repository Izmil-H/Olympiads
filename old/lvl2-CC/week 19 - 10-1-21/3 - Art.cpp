#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int bigX = 0, bigY = 0, smolX = 100, smolY = 100;
    while (n--) {
        int x, y; 
        cin >> x; cin.ignore(); cin >> y;
        bigX = max(bigX, x); bigY = max(bigY, y);
        smolX = min(smolX, x); smolY = min(smolY, y);
    }
    cout << smolX-1 << ',' << smolY-1 << endl << bigX+1 << ',' << bigY+1;
}