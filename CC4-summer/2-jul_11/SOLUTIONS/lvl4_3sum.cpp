#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5003, MV = 1e6+2;
int n, q, a[MM], f[2*MV]; ll psa[MM][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int k=i+1; k<=n; k++){
            int v = -a[i] - a[k] + MV;
            if(v >= 0 && v<2*MV) psa[i][k] += f[v];
            f[a[k]+MV]++;
        }
        for(int k=i+1; k<=n; k++) f[a[k]+MV]--;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    for(int i=1, l, r; i<=q; i++){
        cin >> l >> r; l--;
        cout << psa[r][r] - psa[r][l] - psa[l][r] + psa[l][l] << "\n";
    }
}