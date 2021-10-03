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
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int n, k, cow[MS], ans[MS];
vector<int> pos[MS]; bool vis[MS];

int main() {
    cin >> n >> k;
    Fo(i,n) {
        cow[i] = i; pos[i].PB(i);
    }
    int a, b;
    Fo(i,k) {
        cin >> a >> b;
        pos[cow[a]].PB(b); pos[cow[b]].PB(a);
        swap(cow[a], cow[b]);
    }
    Fo(i,n) {
        if (vis[i]) continue;
        vector<int> cycle; int u = i;
        for( ; u != i || cycle.empty(); u = cow[u]) { 
            cycle.PB(u); vis[u] = 1;
        }
        unordered_set<int> st;
        for(int x: cycle) st.insert(pos[x].begin(), pos[x].end());
        for(int x: cycle) ans[x] = st.size();
    }
    Fo(i,n) {
        cout << ans[i] << endl;
    }
}

/*

cow: 2 4 3 1 5

i = 1, u = 1

1 != 1 false, cycle.empty true
cycle.pb(1); vis[1] = true; u = 2
cycle.pb(2); vis[2] = true; u = 4
cycle.pb(4); vis[4] = true; u = 1
u:1 == i:1 end loop
st.size() = 3
ans: 3 3 3 3 3 

i = 2, vis[2] = true, continue;
ans: 3 3 3 3 3

i = 3, u = 3
cycle.pb(3); vis[3] = true; u = 3;



*/