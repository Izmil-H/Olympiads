#include <bits/stdc++.h>
using namespace std;
const int MV = 300003;
int st, ed, dis[MV]; queue<int> q; bool vis[MV];
int main(){
    cin >> st >> ed;
    q.push(st); vis[st]=1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == ed) { cout << dis[ed] << endl; return 0; }
        if(cur -1 >= 0 && !vis[cur-1]){
            q.push(cur-1); dis[cur-1] = dis[cur] + 1; vis[cur-1]=1;
        }
        if(cur -3 >= 0 && !vis[cur-3]){
            q.push(cur-3); dis[cur-3] = dis[cur] + 1; vis[cur-3]=1;
        }
        if(3*cur < MV && !vis[3*cur]){
            q.push(3*cur); dis[3*cur] = dis[cur] + 1; vis[3*cur]=1;
        }
        if(cur % 2 ==0 && !vis[cur/2]){
            q.push(cur/2); dis[cur/2] = dis[cur] + 1; vis[cur/2]=1;
        }
    }
}