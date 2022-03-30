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
int N, K, p; char s[26], c; bool vis[102];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K; cl(s, '?');
    for(int i=0, x; i<K; i++) {
        cin >> x >> c;
        p = (p + x)%N;
        if((s[p]!='?' || vis[c]) && s[p] != c) {
            cout << "!\n"; return 0;
        }
        s[p] = c; vis[c] = 1;
    }
    for(int i=0, j=p; i<N; i++, j--){
        if(j < 0) j+=N;
        cout << s[j];
    }
    cout << endl;
}