#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1e5+5;
int n, m, k, p[MM]; char s[MM];
int fd(int d){ return d==p[d]? p[d]: p[d]=fd(p[d]);}
int main(){
    scanf("%d %d %d %s", &n, &m, &k, s+1);
    for(int i=1; i<=n; i++) p[i] = i;
    for(int i=1, u, v; i<=m; i++){
        scanf("%d %d", &u, &v);
        if(s[u] == s[v]) p[fd(u)] = fd(v);
    }
    int ans = 0;
    for(int i=1, u, v; i<=k; i++){
        scanf("%d %d", &u, &v);
        ans += fd(u) == fd(v);
    }
    printf("%d\n", ans);
}