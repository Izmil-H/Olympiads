#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q; string word; char g[25][25]; bool vis[25][25];
bool fun(int r, int c, int idx){
    if(idx == word.size()) return true;
    vis[r][c] = true;
    for(int dr=-1; dr<=1; dr++){
        for(int dc=-1; dc<=1; dc++){
            int nr = r + dr, nc = c + dc;
            if(nr < 0 || nr >= N || nc < 0 || nc>=N || vis[nr][nc] || g[nr][nc]!=word[idx]){
                continue;
            }
            if(fun(nr, nc, idx+1)) return true;
        }
    }
    vis[r][c] = false; return false;
}
int main(){
    cin >> N >> Q;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> g[i][j];
    for(int i=1; i<=Q; i++) {
        cin >> word;  bool found = false;
        memset(vis, 0, sizeof(vis));
        for(int r=0; r<N && !found; r++){
            for(int c=0; c<N && !found; c++){
                if(g[r][c] == word[0]) found = fun(r, c, 1);
            }
        }
        cout << (found? "good puzzle!\n": "bad puzzle!\n");
    }
}