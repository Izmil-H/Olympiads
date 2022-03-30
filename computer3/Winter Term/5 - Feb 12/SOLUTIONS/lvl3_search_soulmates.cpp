#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7;
int T; ll x, y;
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(cin >> T; T--; ){
        cin >> x >> y;
        if(x == y){
            cout << 0 << endl; continue;
        }
        ll cnt = infl; vl ax, ay;
        while(y){
            ay.pb(y);
            if(y & 1) y--;
            else y/=2;
        }
        while(x){
            ax.pb(x);
            if(x == 1) break;
            if(x & 1) x++;
            else x/=2;
        }
        for(int i=0; i<ax.size(); i++){
            for(int j=0; j<ay.size(); j++){
                ll px = ax[i], py = ay[j];
                if(px > py) continue;
                cnt = min(cnt, i+ j + py - px);
            }
        }
        cout << cnt << endl;
    }

}