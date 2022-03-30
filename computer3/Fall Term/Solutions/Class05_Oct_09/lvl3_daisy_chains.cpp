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
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7;
int n, a[102], cnt;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        int sum = a[i];
        for(int j=i+1; j<=n; j++){
            sum += a[j];  bool flag = false;
            for(int k=i; k<=j; k++){
                if(a[k]*(j-i+1) == sum) flag = true;
            }
            if(flag) cnt++;
        }
    }
    cout << cnt + n << endl;
}