#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<pi, pi> piii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MM = 200005;
int N, Q; ll bit[MM], ans[MM]; pi a[MM];
struct query{int l, r, k, id; } q[MM];
bool cmp(query x, query y){ return x.k < y.k;}
void upd(int pos, int val){
    for(int i=pos; i<MM; i+=i&-i) bit[i] += val;
}
ll qry(int pos){
    ll ret = 0;
    for(int i=pos; i; i-=i&-i) ret += bit[i];
    return ret;
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &Q);
    for(int i=1; i<=N; i++){
        scanf("%d", &a[i].f); a[i].s=i; upd(i, a[i].f);
    }
    for(int i=1, u, v, w; i<=Q; i++){
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k); q[i].id=i;
    }
    sort(a+1, a+N+1); sort(q+1, q+Q+1, cmp);
    for(int i=1, j=1; i<=Q; i++){
        while(j <= N && a[j].f < q[i].k){
            upd(a[j].s, -2LL*a[j].f);  j++;
        }
        ans[q[i].id] =qry(q[i].r) - qry(q[i].l-1);
    }
    for(int i=1; i<=Q; i++) printf("%lld\n", ans[i]);
}