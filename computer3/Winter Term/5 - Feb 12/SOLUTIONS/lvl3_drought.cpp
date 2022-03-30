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
const int mod = 1e9 + 7, MM = 1e5+5;
int T, N, a[MM], b[MM]; ll ans;
bool check(ll x){
    int last = 0; ans = 0;
    for(int i=1; i<=N; i++){
        a[i] -= last;  ans +=2LL*last;
        if(a[i] < x) return 0;
        last = a[i] - x;
    }
    return last == 0;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(cin >> T; T--; ){
        cin >> N;
        for(int i=1; i<=N; i++) cin >> a[i];
        if(N & 1){
            ll x = 0; int f = 1;
            for(int i=1; i<=N; i++) {
                x += a[i] * f;  f *= -1;
            }
            cout << (x >= 0 && check(x)? ans : -1) << endl;
        }else {
            ll x = inf, tmp = 0; int f = 1;
            for(int i=1; i<=N; i++){
                tmp += a[i] * f; f *= -1;
                if(i & 1) x = min(x, tmp);
            }
            cout << (x >= 0 && check(x)? ans : -1) << endl;
        }
    }
}