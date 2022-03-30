#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef pair<int, int> pi;
int N, sum, best, p[MM], w[MM], d[MM]; vector<pi> vec; long long ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> p[i] >> w[i] >> d[i];  sum -= w[i];
        vec.push_back({p[i]-d[i], w[i]}); vec.push_back({p[i]+d[i], w[i]});
    }
    sort(vec.begin(), vec.end());
    for(pi e : vec) {
        sum += e.second;
        if(sum >= 0) { best = e.first; break;}
    }
    for(int i=0; i<N; i++){
        if(best < p[i] - d[i]) ans += (long long)(p[i] - d[i] - best) * w[i];
        if(best > p[i] + d[i]) ans += (long long)(best - p[i] - d[i]) * w[i];
    }
    cout << ans << endl;
}