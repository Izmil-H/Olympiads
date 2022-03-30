#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, nxt[MM]; bool vis[MM];
int main(){
    cin >> n;
    for(int i=1, a, b; i<=n; i++){
        cin >> a >> b; nxt[a] = b;
    }
    while(true){
        int x, y;
        cin >> x >> y;
        if(!x && !y) return 0;
        memset(vis, 0, sizeof(vis));
        int dis = 0, cur = x;
        while(cur != y && !vis[cur]) {
            vis[cur] = true; dis ++;
            cur = nxt[cur];
        }
        if(cur == y) cout << "Yes " << dis-1 << "\n";
        else cout << "No" << "\n";
    }
}