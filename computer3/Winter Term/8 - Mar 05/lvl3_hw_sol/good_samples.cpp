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
int N, M, last; ll K; deque<int> q; vi ans;
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    if( K < N) { cout << -1 << "\n"; return 0;}
    K -= N; q.pb(1); ans.pb(1); last = 1;
    for(int i=1; i<N && K; i++){
        if(K >= q.size()) {
            last++;
            if(last <= M) {
                K-=q.size(); q.pb(last);  ans.pb(last);
            }else{
                K-=(int)q.size()-1; q.pb(q.front()); ans.pb(q.front()); q.pop_front();
            }
        }else {
            int pos = (int)q.size() - K - 1, val = q[pos];
            q.pb(val);  ans.pb(val); K = 0;
        }
    }
    if(K) { cout << -1 << "\n"; return 0;}
    while(ans.size() != N) ans.pb(ans.back());
    for(int x : ans) cout << x << " ";
}