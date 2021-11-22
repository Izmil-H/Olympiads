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

int n, x, ans; 
map<int, vi> adj;
bool vis[MS];

void dfs(int cur) {
    vis[cur] = 1;
    for(auto ch: adj[cur]) {
        if (!vis[ch]) dfs(ch);
    }
}

int main() {
    cin >> n; 
    Fo(i,n) {
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i); 
    }
    Fo(i,n) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
}