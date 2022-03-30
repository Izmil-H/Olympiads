#include "bits/stdc++.h"
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
#define pb push_back
#define set(a, b) memset(a, b, sizeof(a));
#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<int, pair<int, int>> ppi;

bool OJ = true; int cases = -1; //-1: No input cases. 0: Read cases.
const int maxN = 50001, mod = 1e9+7;

void solve(int caseNum) {
    int n, k; cin >> n >> k; int cnt = 0; vector<string> vec(n);
    for(int i=0; i<n; i++) cin >> vec[i];
    for(int i = 0; i < n; i++){
        string s = vec[i];
        if(cnt+s.size() <= k){
            if(cnt != 0) cout << " ";
            cout << s;  cnt += s.size();
        }
        else{
            cout << endl; cnt = 0; i--;
        }
    }
    if(cnt) cout << endl;
}


int32_t main(void) {
    cin.tie(0)->sync_with_stdio(0);
    if(!OJ){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    if(cases == -1) {solve(-1); return 0;}
    if(cases == 0) cin >> cases;
    for(int t = 1; t <= cases; t++) solve(t);
}