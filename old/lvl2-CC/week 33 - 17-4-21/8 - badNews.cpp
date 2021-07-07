#include<bits/stdc++.h>
using namespace std;

int n, q;
char grid[26][26];
bool vis[26][26];

void clr() {
    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i]+n, 0);
    }
}

bool srch(int r, int c, string s, int i) {
    if (i == s.length() - 1) return true;
    vis[r][c] = true;
    for (int dr = -1; dr <= 1; dr++) {  
        for (int dc = -1; dc <= 1; dc++) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] || grid[nr][nc] != s[i+1]) continue;
            if (srch(nr, nc, s, i+1)) return true;  
        }
    }
    vis[r][c] = false;
    return false;
}

bool lnchr(string s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == s[0]) {
                clr();
                if (srch(i, j, s, 0)) return true;
            }
        }
    }
    return false;
}


int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    string s;
    for (int i = 0; i < q; i++) {
        cin >> s;
        if (lnchr(s)) cout << "good puzzle!\n";
        else cout << "bad puzzle!\n";
    }    
}