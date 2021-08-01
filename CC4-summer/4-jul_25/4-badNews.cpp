#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}

int n, q;
char grd[27][27];
bool vis[27][27];

bool bfs(string s, int r, int c, int idx) {
    if (idx == s.size() - 1) return true;
    vis[r][c] = true;
    Fo(i, r-1, r+2, 1) {
        Fo(j, c-1, c+2, 1) {
            if (!vis[i][j] && grd[i][j] == s[idx+1]) {
                if (bfs(s, i, j, idx+1)) return true;
            }
        }
    }
    vis[r][c] = false;
    return false;
}

bool solve(string s) {
    Fo(i,1,n+1,1) {
        Fo(j,1,n+1,1) {
            if (grd[i][j] == s[0]) {
                memset(vis, 0, sizeof(vis[0][0]*27*27));
                if (bfs(s, i, j, 0)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> q;
    fo(i,n) {
        fo(j,n) cin >> grd[i+1][j+1];
    }
    string s;
    fo(i,q) {        
        cin >> s;
        if (solve(s)) cout << "good puzzle!\n";
        else cout << "bad puzzle!\n";
    }
}