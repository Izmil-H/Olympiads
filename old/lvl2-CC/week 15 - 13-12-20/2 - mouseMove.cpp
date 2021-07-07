#include<bits/stdc++.h>
using namespace std;

int main() {
    int c, r;
    cin >> c >> r;
    int x = 0, y = 0;
    while (true) {
        int mX, mY;
        cin >> mX >> mY;
        if (mX == 0 && mY == 0) break;
        x += mX;
        y += mY;
        if (x < 0) x = 0;
        else if (x > c) x = c;
        if (y < 0) y = 0;
        else if (y > r) y = r;
        cout << x << " " << y << endl;
    }
}