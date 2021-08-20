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
int N;
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N; vi a(N), ord; string ans;
    for(int &i : a) cin >> i;
    sort(all(a));
    for(int l=0, r=N-1; l<=r; l++, r--){
        ord.pb(a[l]); ord.pb(a[r]);
        if(l != r) { ans.pb('B'); ans.pb('S'); }
        else ans.pb('E');
    }
    for(int i=0; i<N; i++) cout << ord[i] << " \n"[i==N-1];
    cout << ans << "\n";
}