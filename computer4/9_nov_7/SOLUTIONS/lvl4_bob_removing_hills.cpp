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
const int mod = 1e9 + 7, MM = 5003;
int n, a[MM], dp[MM][MM][2];
inline int cost(int x, int y){ return max(y-x+1, 0);}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cl(dp, 0x3f); dp[0][0][0]=0;  int half = (n+1)/2;
    for(int i=1; i<=n; i++) {
        for(int k=0; k<=(i+1)/2; k++) {
            dp[i][k][0] = min(dp[i-1][k][0], dp[i-1][k][1]);
            if(k) {
                if(i==1) dp[i][1][1] = cost(a[1], a[2]);
                else {
                    dp[i][k][1] = min(dp[i][k][1], dp[i-2][k-1][0] + cost(a[i], a[i-1]) + cost(a[i], a[i+1]));
                    dp[i][k][1] = min(dp[i][k][1], dp[i-2][k-1][1] + cost(a[i], min(a[i-1], a[i-2]-1)) + cost(a[i], a[i+1]));
                }
            }
        }
    }
    for(int i=1; i<=(n+1)/2; i++) cout << min(dp[n][i][0], dp[n][i][1]) << " ";

}