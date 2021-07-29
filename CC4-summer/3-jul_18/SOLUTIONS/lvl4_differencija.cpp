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
const int mod = 1e9 + 7, MM = 3e5+5;
ll ans, fx[MM], fi[MM]; stack<int> mx, mi; int n, a[MM];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        while(!mx.empty() && a[i] >= a[mx.top()]) mx.pop();
        while(!mi.empty() && a[i] <= a[mi.top()]) mi.pop();
        int p = mx.empty()? 0:mx.top();
        fx[i] = fx[p] + 1LL*a[i]*(i-p);
        p = mi.empty()? 0:mi.top();
        fi[i] = fi[p] + 1LL*a[i]*(i-p);
        ans += fx[i] - fi[i]; mx.push(i); mi.push(i);
    }
    cout << ans << endl;
}