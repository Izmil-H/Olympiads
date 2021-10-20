#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5, LOG=19;
int N, node[MM], anc[LOG][MM], dep[MM]; char op;
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i=LOG-1; i>=0; i--)
        if(dep[anc[i][u]] >= dep[v]) u = anc[i][u];
    if(u == v) return u;
    for(int i=LOG-1; i>=0; i--)
        if(anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}
int main(){
    scanf("%d", &N);
    for(int i=1, u, v; i<=N; i++){
        scanf(" %c %d", &op, &u);
        if(op == 'a'){
            int t=node[u]; node[i] = i; anc[0][i]=t; dep[i] = dep[t]+1;
            for(int j=1; j<LOG; j++) anc[j][i] = anc[j-1][anc[j-1][i]];
        }else if(op == 'b'){
            int t=node[u]; printf("%d\n", t);
            node[i] = anc[0][t];
        }else{
            scanf("%d", &v); node[i] = node[u];
            printf("%d\n", dep[lca(node[u], node[v])]);
        }
    }
}