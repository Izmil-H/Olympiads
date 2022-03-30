#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, T, adj[302][302];
int main(){
    scanf("%d %d %d", &N, &M, &T);
    memset(adj, 0x3f, sizeof(adj));
    for(int i=1, u, v, w; i<=M; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
    for(int i=1, u, v; i<=T; i++){
        scanf("%d %d", &u, &v);
        printf("%d\n", adj[u][v]==INF? -1: adj[u][v]);
    }
}