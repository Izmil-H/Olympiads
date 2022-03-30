#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, Q, p[MM]; char op;
int fd(int d) {
    if(d != p[d]) p[d] = fd(p[d]);
    return p[d];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1, x, y; i<=Q; i++){
        cin >> op >> x >> y;
        if(op == 'A') p[fd(x)] = fd(y);
        else cout << (fd(x) == fd(y)? "Y\n":"N\n");
    }
}