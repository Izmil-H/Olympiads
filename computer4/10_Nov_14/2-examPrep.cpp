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
const int MS = 1e6+2;

int n, q, val[MS];
map<int, vector<int>> adj;

void dfs(int nd, bool (&vis)[MS], int& sz, ll& sum) {
    vis[nd] = 1; sz++; sum += val[nd];
    for(auto ch: adj[nd]) {
        if (!vis[ch]) {
            dfs(ch, vis, sz, sum);
        }
    }
}

pi solve(int root){
    bool vis[MS] = {0}; int sz = 0; ll sum = 0;
    dfs(root, vis, sz, sum);
    return {sz, sum};
}


int main() {
    cin >> n >> q;
    Fo(i,n) {
        cin >> val[i];
    }

    int o, x, y;
    fo(i,q) {
        cin >> o >> x;
        if (o == 1) {
            cin >> y;
            adj[x].pb(y);
            adj[y].pb(x); 
        } else if (o == 2) {
            cout << solve(x).f << endl;
        } else {
            cout << solve(x).s << endl;
        }
    }
}