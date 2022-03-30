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
int N, M, C, ans; vi t;
bool check(int x){
    int cnt = 1, last = 0;
    for(int i=0; i<N; i++){
        if(i - last >= C || t[i] - t[last] > x) {
            cnt++; last = i;
        }
    }
    return cnt <= M;
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> C; t.resize(N);
    for(int i=0; i<N; i++) cin >> t[i];
    sort(all(t));
    int lo = 0, hi = t.back(), ans = 0;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(check(mid)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    cout << ans << endl;
}