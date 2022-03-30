#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 12;
char g[MM][MM]; int dis[MM][MM], sr, sc, tr, tc, d[4][2]={{-1,0}, {1,0},{0,-1}, {0,1}}; queue<pi> q; bool vis[MM][MM];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i=1; i<=10; i++) {
        for(int j=1; j<=10; j++){
            cin >> g[i][j];
            if(g[i][j] == 'L') sr = i, sc = j;
            if(g[i][j] == 'B') { tr = i; tc = j; g[i][j] = '.'; }
        }
    }
    q.push({sr, sc}); vis[sr][sc] = 1;
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nr = r + d[k][0], nc = c + d[k][1];
            if(vis[nr][nc] || g[nr][nc] != '.') continue;
            q.push({nr, nc}); dis[nr][nc] = dis[r][c]+1; vis[nr][nc] = 1;
        }
    }
    cout << dis[tr][tc] - 1 << endl;
}