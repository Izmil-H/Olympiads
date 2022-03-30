#include <bits/stdc++.h>
using namespace std;
int head[22] = {1, 2, 6, 3, 4, 5, 3, 4, 7, 3, 3, 8, 9, 9, 15, 12, 12, 11, 13, 16, 16, 18};
int tail[22] = {6, 6, 7, 6, 6, 6, 4, 5, 8, 5, 15, 9, 10, 12, 13, 13, 11,10, 14, 18, 17, 17};
int adj[50][50], x, y;  char op;
void insertEdge(int x, int y){
    adj[x][y] = adj[y][x] = 1;
}
void deleteEdge(int x, int y){
    adj[x][y] = adj[y][x] = 0;
}
void bfs(int st, int ed){
    int dis[50]; bool vis[50]; queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(st); vis[st] = 1;  dis[st] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v=1; v<50; v++)
            if(adj[u][v] == 1 && !vis[v]) {
                q.push(v); vis[v]=1; dis[v] = dis[u]+1;
            }
    }
    if(vis[ed]) cout << dis[ed] <<endl;
    else cout << "Not connected" << endl;
}
int main(){
    for(int i=0; i<22; i++)
        insertEdge(head[i], tail[i]);
    while( cin >> op && op != 'q'){
        if(op == 'i'){
            cin >> x >> y;    insertEdge(x, y);
        }else if(op == 'd'){
            cin >> x >> y;    deleteEdge(x, y);
        }else if(op == 'n'){
            cin >> x;   int sum = 0;
            for(int i=1; i<50; i++) sum += adj[x][i];
            cout << sum << endl;
        }else if(op == 'f'){
            cin >> x;  vector<int> f; set<int> s;
            for(int i=1; i<50; i++)
                if(adj[x][i] == 1) f.push_back(i);
            for(int y: f){
                for(int i=1; i<50; i++)
                    if(adj[y][i]==1 && adj[x][i]!=1  && x != i) s.insert(i);
            }
            cout << s.size() << endl;
        }else if(op == 's'){
            cin >> x >> y;  bfs(x, y);
        }
    }
}