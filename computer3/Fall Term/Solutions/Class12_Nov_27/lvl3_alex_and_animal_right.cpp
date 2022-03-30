#include <bits/stdc++.h>
using namespace std;
char g[40][60]; int R, C, cnt;
void dfs(int r, int c){
    g[r][c] = '#';
    if(r-1 >= 0 && g[r-1][c] != '#') dfs(r-1, c);
    if(c-1 >= 0 && g[r][c-1] != '#') dfs(r, c-1);
    if(r+1 < R && g[r+1][c] != '#') dfs(r+1, c);
    if(c+1 < C && g[r][c+1] != '#') dfs(r, c+1);
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin >> g[i][j];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(g[i][j] == 'M'){ cnt++; dfs(i, j); }
    cout << cnt << "\n";
}