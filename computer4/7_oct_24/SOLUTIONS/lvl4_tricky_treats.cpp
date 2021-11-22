#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int n, m, t; vector<pi> a;
int main(){
    cin >> n >> m >> t;
    for(int i=0, p, c; i<n; i++) {
        cin >> p >> c;
        a.push_back({p, c});
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = 0, sum = 0;
    for(pi e : a) {
        int p = e.first, c = e.second;
        if(p * 2 + t > m) break;
        sum += c; q.push(c);
        int lmt = (m - p*2)/t;
        while(q.size() > lmt) {
            sum -= q.top(); q.pop();
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}