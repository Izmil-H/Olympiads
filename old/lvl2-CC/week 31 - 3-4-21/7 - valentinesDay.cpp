#include<bits/stdc++.h>
using namespace std;

int n, m;
int cost[10], deals[10][10+1], qnt[10];
vector<int> comb;
int ans = INT_MAX;

void solve(vector<int> comb, int i) {
    if (i >= m) {
        //for (int i = 0; i < comb.size(); i++) {cout << comb[i]; if (i < comb.size() - 1) cout << " ";} cout << ":\n  ";
        int amnt[n] = {0}, cst = 0; 
        for (auto x: comb) {
            cst += deals[x][0];
            for (int j = 1; j <= n; j++) {
                amnt[j-1] += deals[x][j];
            }
        }
        for (int i = 0; i < n; i++) {
            if (amnt[i] > qnt[i]) return;
            cst += cost[i] * (qnt[i] - amnt[i]);
        }
        ans = min(ans, cst);
        //cout << cst << endl;
        return;
    }
    solve(comb, i+1);
    comb.push_back(i);
    solve(comb, i+1);
    comb.pop_back();
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < m; i++) for (int j = 0; j < n+1; j++) cin >> deals[i][j];
    for (int i = 0; i < n; i++) cin >> qnt[i];

    solve(comb, 0);
    cout << ans;
}