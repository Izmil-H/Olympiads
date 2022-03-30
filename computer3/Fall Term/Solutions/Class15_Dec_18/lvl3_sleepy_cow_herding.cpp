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
int a[3];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    int mi = 2, mx = max(a[2] - a[1], a[1] - a[0]) - 1;
    if(a[1] - a[0] == 1 && a[2] - a[1] == 1) mi = 0;
    else if(a[1] - a[0] == 2 || a[2] - a[1] == 2) mi = 1;
    cout << mi << "\n" << mx << "\n";
}