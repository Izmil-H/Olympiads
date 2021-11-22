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
int N, a[6][6], b[6][6];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> a[i][j];
    int m = N*(N-1)/2;
    for(int mask = 0; mask < (1<<m); mask++){
        cl(b, 0);
        for(int cnt=0, i=0; i<N; i++)
            for(int j=i+1; j<N; j++, cnt++)
                if(mask>>cnt & 1) b[i][j] = b[j][i] = 1;
        bool flag = true;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                int cnt = 0;
                for(int k=0; k<N; k++) cnt += b[i][k] && b[j][k];
                if(cnt != a[i][j])  flag = false;
            }
        }
        if(flag) {
            cout << __builtin_popcount(mask) << "\n";
            for(int cnt=0, i=0; i<N; i++)
                for(int j=i+1; j<N; j++, cnt++)
                    if(mask>>cnt & 1) cout << (i+1) << " " << (j+1) << "\n";
            return 0;
        }
    }
    cout << "Impossible\n";
}