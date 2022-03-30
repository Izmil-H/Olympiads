#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, p[MM]; char g[MM], c;
int fd(int d){ return p[d] == d? p[d]: p[d]=fd(p[d]); }
int main(){
    cin >> N >> M >> g+1;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1, u, v; i<N; i++) {
        cin >> u >> v;
        if(g[u] == g[v]) p[fd(u)] = fd(v);
    }
    string s;
    for(int i=1, u, v; i<=M; i++){
        cin >> u >> v >> c;
        if(fd(u) == fd(v) && g[u] != c) s.push_back('0');
        else s.push_back('1');
    }
    cout << s << endl;
}