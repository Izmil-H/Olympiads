#include<bits/stdc++.h>
using namespace std;

char brd[6][6];
bool vis[6][6];

bool fun(int i, int r, int c, string s) {
    if (i == s.length() - 1) return 1;
    vis[r][c] = 1;
    for (int dr = -1; dr <= 1; dr++) { // delta r
        for (int dc = -1; dc <= 1; dc++) { //delta c
            int nr = r + dr, nc = c + dc;
            if (brd[nr][nc] != s[i+1]) continue;
            if (fun(i+1, nr, nc, s)) return true;       
        }
    }
    vis[r][c] = false; return false;
}

int getPoints(string s) {
    int l = s.length();
    if (l <= 4) return 1;
    if (l <= 7) return s.length() - 3;
    return 11;
}


int main() {
    for (int t = 0; t < 5; t++) {
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++) {
                cin >> brd[i][j];
            }
        }
        int n; cin >> n;
        set<string> st;
        int gd = 0, ts = 0, rp = 0, nf = 0, score = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s; bool found = false;

            if (s.length() < 3) { ts++; continue; }
            if (st.find(s) != st.end()) { rp++; continue; }
            
            for (int r = 1; r < 5 && !found; r++) {
                for (int c = 1; c < 5 && !found; c++) {
                    if (brd[r][c] == s[0]) found = fun(0,r,c,s);
                }
                if (found) {
                    gd++; score += getPoints(s);
                } else {
                    nf++;
                }
                st.insert(s);
            }
        }
        cout << "Your score: " << score << " (" << gd << " good, " 
             << nf << " not found, " << ts << " too short, " << rp << " repeated)\n";
    }
    
}