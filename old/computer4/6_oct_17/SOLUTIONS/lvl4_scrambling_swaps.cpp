#include <bits/stdc++.h>
using namespace std;
const int MM = 302;
int n, q, a[MM], p[MM], tmp[MM], ans[MM]; char op;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        a[i] = i; p[i] = i;
    }
    for(int i=1, x, y; i<=q; i++) {
        cin >> op;
        if(op == 'E') {
            cin >> x >> y;
            swap(p[a[x]], p[a[y]]);
            swap(a[x], a[y]);
        }else if(op == 'B') {
            cin >> x >> y;
            swap(a[p[x]], a[p[y]]);
            swap(p[x], p[y]);
        }else {
            for(int i=1; i<=n; i++) {
                cin >> tmp[i];
                ans[a[i]] = tmp[i];
            }
            for(int i=1; i<=n; i++) {
                cout << ans[i] << (i==n? '\n': ' ');
            }
        }
    }
}