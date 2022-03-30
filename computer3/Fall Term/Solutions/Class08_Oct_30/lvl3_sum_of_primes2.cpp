#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1e5+5;
bool f[MM]; ll psa[MM]; int Q;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i=2; i<MM; i++){
        psa[i] = psa[i-1];
        if(!f[i]){
            psa[i] += i;
            for(int j=2*i; j<MM; j+=i) f[j] = 1;
        }
    }
    cin >> Q;
    for(int i=0, l, r; i<Q; i++){
        cin >> l >> r;
        cout << psa[r] - psa[l-1] << endl;
    }
}