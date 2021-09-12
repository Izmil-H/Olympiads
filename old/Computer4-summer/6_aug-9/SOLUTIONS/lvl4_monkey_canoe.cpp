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
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 2003;
int N, M, dis[MM][MM], row[MM], col[MM]; char g[MM][MM]; vii adj[MM][MM];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d %d", &N, &M); cl(dis, -1); cl(row, -1); cl(col, -1);
    for(int i=0; i<N; i++){
        scanf(" %s", g[i]);
        for(int j=0; j<M; j++){
            if(g[i][j] == '.') continue;
            if(row[i] != -1) {
                // if cell to the left is also ground? inf: dist to last ground
                // basically find horizontal length of puddle
                int w = row[i]==j-1? inf: j - row[i]-1;

                // build graph by adding current cell and puddle length (inf if 
                // no puddle) to previous ground cell and vice versa
                adj[i][row[i]].pb({i*M+j, w}); adj[i][j].pb({i*M+row[i], w});
            }
            if(col[j] != -1) {
                // same but vertically
                int w = col[j]==i-1? inf: i - col[j]-1;
                adj[col[j]][j].pb({i*M+j, w}); adj[i][j].pb({col[j]*M+j, w});
            }
            row[i] = j; col[j] = i;
        }
    }
    priority_queue<pii> q;
    for(int i=0; i<M; i++){
        if(g[0][i] == '#') { dis[0][i] = inf; q.push({dis[0][i], {0, i}}); }
    }
    while(!q.empty()){
        pii e= q.top(); int d = e.f, r=e.s.f, c=e.s.s; q.pop();
        if(d < dis[r][c]) continue;
        for(auto &e : adj[r][c]){
            int nr = e.f/M, nc = e.f%M, w = e.s;
            if(min(d, w) > dis[nr][nc]){
                dis[nr][nc] = min(d, w); q.push({dis[nr][nc], {nr, nc}});
            }
        }
    }
    for(int i=0; i<M; i++)
        printf("%d%c", dis[N-1][i]==inf? 0:dis[N-1][i], i==M-1? '\n':' ');
}