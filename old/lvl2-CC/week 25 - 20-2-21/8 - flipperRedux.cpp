#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;
    bool grid[n][n];
    for (int i= 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) cnt++;
        }
    }

    vector<string> ins;
    for (int i = 0; i < n; i++) {
        if (grid[0][i]) {
            string s = "C ";
            s += to_string(i+1);
            ins.push_back(s);
            for (int j = 0; j < n; j++) {
                if (grid[j][i]) cnt--;
                else cnt++;
                grid[j][i] = !grid[j][i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (grid[i][0]) {
            string s = "R ";
            s += to_string(i+1);
            ins.push_back(s);
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) cnt--;
                else cnt++;
                grid[i][j] = !grid[i][j];
            }
        }
    }

    if (cnt) cout << -1;
    else {
        cout << ins.size() << endl;
        for (auto s: ins) {
            cout << s << endl;
        }
    }
}