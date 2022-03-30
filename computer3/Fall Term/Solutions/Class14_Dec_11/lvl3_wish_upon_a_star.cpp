#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, M, p[MM], cnt;
int fd(int d) {
    if(d != p[d]) p[d] = fd(p[d]);
    return p[d];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1, x, y; i<=M; i++){
        cin >> x >> y;
        int fx = fd(x), fy = fd(y);
        if(fx != fy) p[fx] = fy;
        else cnt++;
    }
    cout << (cnt <= 1? "YES\n" : "NO\n");
}