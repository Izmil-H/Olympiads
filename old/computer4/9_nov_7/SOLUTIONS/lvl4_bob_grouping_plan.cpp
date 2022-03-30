#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin >> n; m = 1;
    while(m*(m-1)<2*n) m++;
    if(m * (m-1) == 2*n) {
        cout << "Yes\n" << m << "\n";
        vector<int> adj[m+1];
        int edge = 0;
        for(int u=1; u<=m; u++) {
            for(int v=u+1; v<=m; v++) {
                edge++; adj[u].push_back(edge); adj[v].push_back(edge);
            }
        }
        for(int u=1; u<=m; u++) {
            cout << m-1 << " ";
            for(int x : adj[u]) cout << x << " ";
            cout << "\n";
        }
    }else {
        cout << "No\n";
    }
}