#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2, INF = 0x3f3f3f3f;
int N, M, J, t[MM], ans[MM], sol = INF;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> J;
    memset(ans, 0x3f, sizeof(ans));  ans[0] = 0;
    memset(t, 0x3f, sizeof(t));  t[0] = 0;
    for(int i=0, a, b; i<M; i++) {
        cin >> a >> b;   t[a] = b;
    }
    deque<int> q; q.push_back(0);
    for(int i=1; i<=N; i++) {
        while(!q.empty() && q[0] + J < i) q.pop_front();
        ans[i] = max(ans[q[0]], t[i]);
        while(!q.empty() && ans[q.back()] >= ans[i]) q.pop_back();
        q.push_back(i);
    }
    for(int i=N-J+1; i<=N; i++) sol = min(sol, ans[i]);
    cout << (sol == INF? -1 : sol) << endl;
}