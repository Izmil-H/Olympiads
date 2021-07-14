#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ans; bool d[10002][10002];
int main(){
    cin >> n >> m;
    for(int i=1, x, y, w, h; i<=m; i++){
        cin >> x >> y >> w >> h; x++; y++;
        d[x][y] ^= 1; d[x+w][y] ^= 1; d[x][y+h]^=1; d[x+w][y+h]^=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1;j <=n ;j++){
            d[i][j] ^= d[i-1][j] ^ d[i][j-1] ^ d[i-1][j-1];
            if(d[i][j]) ans++;
        }
    }
    cout << ans << endl;
}