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
int n, vis[26]; vector<string> t = {"***ABCDE", "FGHIJKLM", "NOPQRSTU", "VWXYZ***"}, dest; string s;
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s; dest.pb(s);
    }
    cin >> s;
    for(string &x : dest){
        if(x.size()> s.size() && x.substr(0, s.size()) == s){
            vis[x[s.size()]-'A'] = 1;
        }
    }
    for(string &x : t) {
        for(char c : x){
            if(c == '*' || !vis[c-'A']) cout << "*";
            else cout << c;
        }
        cout << endl;
    }
}