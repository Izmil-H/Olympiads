#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define v(t) vector<t>
#define pii pair<int,int>
#define mii map<int,int>
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int inf = 0x3F3F3F3F;
const int MS = 2003;

int n, m, dis[MS][MS], row[MS], col[MS]; char g[MS][MS]; v(pii) adj[MS][MS];

int main() {
    cin >> n >> m;
    memset(dis, -1, sizeof(dis));
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
    fo(i,n) {
        cin >> g[i];
        fo(j,m) {
            if (g[i][j] == '.') continue;
            if (row[i] != -1) {
                int w = row[i] == j-1? inf: j - row[i] - 1;
                adj[i][row[i]].PB({i*m+j, w}); adj[i][j].PB({i*m+row[i], w});
            }
            if (col[j] != -1) {
                int w = col[j] == i-1? inf: i - col[j] - 1;
                adj[col[j]][j].PB({i*m+j, w}); adj[i][j].PB({col[j]*m+j, w});
            }
            row[i] = j; col[j] = i;
        }
    }
    priority_queue<pair<int,pii>> q;
    fo(i,m) {
        if (g[0][i] == '#') {
            dis[0][i] = inf;
            q.push({dis[0][i], {0,i}});
        }
    }
    while (!q.empty()) {
        pair<int,pii> e = q.top(); int d = e.F, r = e.S.F, c = e.S.S; q.pop();
        if (d < dis[r][c]) continue;
        for(auto &e2: adj[r][c]) {
            int nr = e2.F/m, nc = e2.F%m, w = e2.S;
            if (min(d,w) > dis[nr][nc]) {
                dis[nr][nc] = min(d,w); q.push({dis[nr][nc], {nr,nc}});
            }
        }
    }
    fo(i,m) cout << (dis[n-1][i] == inf? 0: dis[n-1][i]) << " ";
    cout << endl;
}