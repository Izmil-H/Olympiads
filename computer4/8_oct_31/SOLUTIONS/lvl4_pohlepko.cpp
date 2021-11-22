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
const int mod = 1e9 + 7, MM = 2003;
int N, M, dis[MM][MM], mi[2*MM], r, c, dir[2][2]={{1,0}, {0, 1}}; char g[MM][MM]; queue<pi> q;
int main(){
//    freopen("test.txt", "r", stdin);
//    freopen("test_out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin >> g[i][j];
    cl(mi, 0x3f); cl(dis, -1);
    dis[1][1] = 0; mi[0] = g[1][1]; q.push({1, 1});
    while(!q.empty()) {
        tie(r, c) = q.front(); q.pop();
        int d = dis[r][c];
        if(mi[d] != g[r][c]) continue;
        for(int k=0; k<2; k++){
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if(nr <= N && nc <= M && dis[nr][nc] == -1){
                dis[nr][nc] = d+1;
                q.push({nr, nc});
                mi[d+1] = min(mi[d+1], (int)g[nr][nc]);
            }
        }
    }
    for(int i=0; i<N+M-1; i++) cout << (char)mi[i];
    cout << endl;
}