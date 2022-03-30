#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int inf = 0x3f3f3f3f;
int N, M, a, b, c, ans = inf;
vector <pi> arr1[20030];
vector <pi> arr2[20030];
int dis1[20030], dis2[20030];

void dijkstra(int st, int dis[], vector <pi> arr[]){
    priority_queue< pi, vector<pi>, greater<pi> > Q;
    for(int i=0; i<=N; i++) dis[i] = inf;
    dis[st] = 0; Q.push({0, st});
    while(!Q.empty()){
        int d = Q.top().first; int u = Q.top().second; Q.pop();
        if(d > dis[u]) continue;
        for(pi e: arr[u]){
            int v=e.first; int w=e.second;
            if(dis[v] > dis[u]+w){ dis[v]=dis[u]+w; Q.push({dis[v], v}); }
        }
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> a >> b >> c; a--; b--;
        arr1[a].push_back({b, c});
        arr2[b].push_back({a, c});
    }
    dijkstra(0, dis1, arr1);
    dijkstra(N-1, dis2, arr2);
    int t = dis1[N-1];
    if (t == inf) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < N; i++){
        for (auto j : arr1[i]){
            int dist = dis1[i] + j.second + dis2[j.first];
            if (dist > t){
                ans = min(ans, dist);
            }
        }
    }
    if (ans == inf) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}