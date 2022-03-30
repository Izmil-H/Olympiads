#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mi map<int,int>
#define ml map<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define pb push_back
#define f first
#define s second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int n, gvn[7][7], tst[7][7];

int mutual(int a, int b) {
    int cnt = 0;
    fo(i,n) {
        if (gvn[a][i] && gvn[b][i]) cnt++;
    }
    return cnt;
}

bool works(ll x) {
    fo(i,n) {
        for(int j = i+1; j < n; j++) {
            tst[i][j] = (x & 1);
            tst[j][i] = (x & 1);
            x >>= 1;
        }
    }
    fo(i,n) {
        for(int j = i+1; j < n; j++) {
            if (mutual(i,j) != gvn[i][j]) return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;
    fo(i,n) {
        fo(j,n) cin >> gvn[i][j];
    }
    ll posb = 1 << (((n * (n-1)))/2);
    for(ll i = 0; i <= posb; i++) {
        if (works(i)) {
            vpi v;
            fo(j, n) {
                for(int k = i+1; k < n; k++) {
                    if (tst[i][j]) v.pb({i+1,j+1});
                }
            }
            cout << v.size() << endl;
            for(pi p: v) cout << p.f << " " << p.s << endl;
            return 0;
        }
    }
    cout << "Impossible\n";
}

x += 1