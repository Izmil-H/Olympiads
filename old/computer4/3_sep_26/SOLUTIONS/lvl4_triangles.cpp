#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define clr(a)  memset(a, 0, sizeof(a))
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+5, MV=1e4+2, mod = 1e9+7;
int n; pi p[MM]; ll ans, sx[2*MV], sy[2*MV], cx[2*MV], cy[2*MV], lx[2*MV], ly[2*MV];
void fun(){
    sort(p, p+n); clr(sx); clr(sy); clr(cx); clr(cy); clr(lx); clr(ly);
    for(int i=0; i<n; i++){
        int x = p[i].f + MV, y = p[i].s + MV;
        sx[x] = (sx[x] + cx[x]*(y - lx[x]))%mod;
        sy[y] = (sy[y] + cy[y]*(x - ly[y]))%mod;
        ans = (ans + sx[x] * sy[y])%mod;
        cx[x]++; cy[y]++; lx[x]=y; ly[y]=x;
    }
}
void rot(){
    for(int i=0; i<n; i++){ swap(p[i].f, p[i].s);  p[i].s *= -1; }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> p[i].f >> p[i].s;
    for(int k=1; k<=4; k++) { fun(); rot(); }
    cout << ans << endl;
}