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
const int mod = 1e9 + 7, MM = 1002;
int R, C, sr, sc, er, ec, r, c, dis[MM][MM]; char g[MM][MM]; bool vis[MM][MM]; queue<pi> q;
int d[12][2]={{-1,0},{1,0},{0,-1},{0,1},{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2, -1}, {2,1}};
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> R >> C >> sr >> sc >> er >> ec;
    sr--; sc--; er--; ec--;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin >> g[i][j];
    q.push({sr, sc}); vis[sr][sc]=1;
    while(!q.empty()) {
        tie(r, c) = q.front(); q.pop();
        for(int k=0; k<12; k++){
            int nr = r + d[k][0], nc = c + d[k][1];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || g[nr][nc]=='#' || vis[nr][nc]) continue;
            q.push({nr, nc}); vis[nr][nc]=1; dis[nr][nc] = dis[r][c] + 1;
        }
    }
    cout << (vis[er][ec]? dis[er][ec]:-1) << endl;
}