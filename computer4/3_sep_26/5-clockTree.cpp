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
const int MS = 2505;

int n, val[MS], a[MS], ans; vi adj[MS];

void dfs(int u, int pa) {
    for(int v: adj[u]) {
        if (v == pa) continue;
        dfs(v,u);
        a[u] += 12 - a[v];
    }
    a[u] %= 12;
}

int main() {
    cin >> n;
    Fo(i,n) cin >> val[i];
    Fo(i,n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    Fo(i,n) {
        memcpy(a, val, sizeof(val));
        dfs(i,0);
        if (a[i] == 0 || a[i] == 1) ans++;
    }
    cout << ans << endl;
}