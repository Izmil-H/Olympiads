#include <iostream>

using namespace std;

#define ok "\n"

int t, g, a, b, sa, sb, s[5], r[6][2], out = 0;
bool p[5][5];

void func(int c) {
    if (c < 0) {
        for (int i = 1; i <= 4; i++) {
            if (i != t && s[i] >= s[t]) return;
        }
        out++; return;
    }
    int x = r[c][0], y = r[c][1];
    s[x] += 3;
    func(c - 1);
    s[x] -= 3;
    s[y] += 3;
    func(c - 1);
    s[y] -= 3;
    s[x] ++; s[y] ++;
    func(c - 1);
    s[x] --; s[y] --;
}

int main() {
    cin >> t >> g;
    for (int i = 0; i < g; i++) {
        cin >> a >> b >> sa >> sb;
        p[a][b] = 1; p[b][a] = 1;
        if (sa > sb) {
            s[a] += 3;
        }
        else if (sb > sa) {
            s[b] += 3;
        }
        else {
            s[a] ++; s[b] ++;
        }
    }
    int c = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = i+1; j <= 4; j++) {
            if (!p[i][j]) {
                r[c][0] = i;
                r[c][1] = j;
                c++;
                p[j][i] = 1;
            }
        }
    }
    func(c - 1);
    cout << out << ok;
}