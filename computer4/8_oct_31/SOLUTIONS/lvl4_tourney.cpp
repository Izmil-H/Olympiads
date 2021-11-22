#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
int n, m, k; pi t[1<<21]; char op;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    n = 1<<n;  k = n - 1;
    for(int i=k+1; i<=k+n; i++){
        cin >> t[i].f; t[i].s = i - k;
    }
    for(int i=k; i>=1; i--)
        t[i] = max(t[2*i], t[2*i+1]);
    for(int j=1, x, y; j<=m; j++){
        cin >> op;
        if(op == 'W') cout << t[1].s << "\n";
        else if(op == 'S'){
            cin >> x;  int cnt = 0;
            for(int i=(k+x)/2; i>=1; i/=2){
                if(t[i].s == x) cnt++;
                else break;
            }
            cout << cnt << "\n";
        }else {
            cin >> x >> y;  x += k;
            t[x].f = y;
            for(int i=x/2; i>=1; i/=2)
                t[i] = max(t[2*i], t[2*i+1]);
        }
    }
}