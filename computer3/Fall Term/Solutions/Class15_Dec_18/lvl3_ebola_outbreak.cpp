#include <bits/stdc++.h>
using namespace std;
const int MM=100002;
int rk[MM], p[MM], sz[MM], N, M, K, ans;
inline int Find(int x){
    if(x != p[x]) p[x]=Find(p[x]);
    return p[x];
}
inline void Merge(int x, int y){
    if(rk[x] < rk[y]){ p[x] = y; sz[y] += sz[x];}
    else { p[y]=x; sz[x]+=sz[y]; rk[x] += (rk[x]==rk[y]); }
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        rk[i]=0; p[i]=i; sz[i]=1;
    }
    for(int i=0, x, y; i<M; i++){
        scanf("%d %d", &K, &x);
        for(int j=1; j<K; j++){
            scanf("%d", &y);
            int fx = Find(x), fy = Find(y);
            if(fx!=fy) Merge(fx, fy);
            x = y;
        }
    }
    int f1 = Find(1);
    printf("%d\n", sz[f1]);
    for(int i=1; i<=N; i++)
        if(Find(i)==f1) printf("%d ", i);
}