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
const int mod = 1e9 + 7, MM = 1e4+2;
int N, a[MM];
ll qry(int i, int j){
    ll t;
    cout << "? " << i << " " << j << "\n" << flush;
    cin >> t; return t;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N; ll x = qry(1, 2), y = qry(1, 2);
    a[2] = y/2;  a[1] = x + a[2];
    ll t = 2*a[1];
    for(int i=3; i<=N; i++){
        x = qry(1, i);
        a[i] = t - x;  t += a[i];
    }
    cout << "! ";
    for(int i=1; i<=N; i++)
        cout << a[i] << " \n"[i==N];
}