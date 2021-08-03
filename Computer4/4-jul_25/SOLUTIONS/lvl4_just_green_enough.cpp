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
const int mod = 1e9 + 7, MM = 503;
int n, a[MM][MM], b[MM][MM], row[MM][MM];
ll fun(int x[][MM]){
    cl(row, 0); ll ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            row[i][j] = x[i][j]? row[i][j-1] + 1 : 0;
    for(int j=1; j<=n; j++){
        stack<pi> stk; ll sum =0;
        for(int i=1; i<=n; i++){
            int h = 1;
            while(!stk.empty() && stk.top().f > row[i][j]) {
                pi tmp = stk.top(); stk.pop();
                sum -= 1LL*tmp.s * (tmp.f - row[i][j]);
                h += tmp.s;
            }
            sum += row[i][j]; ans += sum;
            stk.push({row[i][j], h});
        }
    }
    return ans;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1, x; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> x; a[i][j] = x >= 100; b[i][j] = x > 100;
        }
    }
    cout << fun(a) - fun(b) << endl;
}