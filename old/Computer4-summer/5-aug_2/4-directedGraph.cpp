#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define v(t) vector<t>
#define pii pair<int,int>
#define mii map<int,int>
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}

int n, m;
map<int,v(int)> g;
map<int,bool> vis;
map<int,int> bestY;

void bfs(int par, int cur) {
    vis[cur] = 1;
    for (int child: g[cur]) {
        if (!vis[child]) {
            bestY[child] = par;
            bfs(par, child);
        }
    }
}


int main() {
    cin >> n >> m;
    fo(i,m) {
        int a, b;
        cin >> a >> b;
        g[b].PB(a);
    }
    for (int i = n; i > 0; i--) bfs(i, i);
    
    if (bestY.empty()) cout << -1 << endl;
    else{
        map<int,int>::iterator itr;
        itr = bestY.end(); itr--;
        cout << itr->F << " " << itr->S << endl;
    }
}