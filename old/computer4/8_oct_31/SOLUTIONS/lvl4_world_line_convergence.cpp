#include <bits/stdc++.h>
using namespace std;
const int M=200002, MOD=1000000007;
int N, rt, ord[M], sol[M], bit[M], tot; vector<int> g[M]; pair<int, int> s[M];
void update(int x, int v){
    for(int i=x; i<M; i+=i&-i){
        bit[i] += v;
        if(bit[i] >= MOD) bit[i]-=MOD;
    }
}
int query(int x){
    int ans = 0;
    for(int i=x; i; i-=i&-i){
        ans += bit[i];
        if(ans >= MOD) ans-=MOD;
    }
    return ans;
}
void solve(int u){
    sol[u] = query(ord[u]);
    for(int v: g[u]) solve(v);
    sol[u] = query(ord[u])-sol[u]+1;
    if(sol[u] < 0) sol[u]+=MOD;
    update(ord[u], sol[u]);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=1, x; i<=N; i++){
        scanf("%d", &x);
        g[x].push_back(i);
    }
    for(int i=1, x; i<=N; i++){
        scanf("%d", &x); ord[x] = i;
    }
    solve(g[0][0]);
    for(int i=1; i<=N; i++)
        printf("%d ", sol[i]);
}