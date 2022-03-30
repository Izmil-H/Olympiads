#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k, a, b, tim[30002], ans; bool vis[30002];
vector<int> adj[30002];
queue<int> Q;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf("%d", &a);
        Q.push(a); tim[a]=0; vis[a]=true;
    }
    while(!Q.empty()){
        int t=Q.front(); Q.pop();
        for(int i=0; i<adj[t].size(); i++){
            if(!vis[adj[t][i]]){
                tim[adj[t][i]]=tim[t]+1; ans=max(ans, tim[adj[t][i]]);
                vis[adj[t][i]]=true; Q.push(adj[t][i]);
            }
        }
    }
    printf("%d\n", ans);
}