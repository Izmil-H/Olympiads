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
int N, P, ans; priority_queue<int> q[7];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> P;
    for(int i=1, x, y; i<=N; i++) {
        cin >> x >> y;
        if(q[x].empty() || q[x].top() < y){
            ans++; q[x].push(y);
        }else {
            while(!q[x].empty() && q[x].top() > y){
                ans++; q[x].pop();
            }
            if(q[x].top() == y) continue;
            ans++; q[x].push(y);
        }
    }
    cout << ans << endl;
}