#include<bits/stdc++.h>
using namespace std;

int n, cSum = 0;
int flr[7], wt[7];
vector<int> comb; bool tkn[7];
long ans = LONG_MAX;

void solve(vector<int> comb, bool (&tkn)[7]) {
    if (comb.size() >= n) {
        int sum = cSum, cFlr = 101; long cur = 0;
        for (int i = 0; i < n; i++) {
            //cout << i << " " << flr[comb[i]] << " " << cFlr << " " << cur << " " << sum << " " << endl;
            cur += sum * (abs(flr[comb[i]] - cFlr) + 1);
            sum -= wt[comb[i]];
            cFlr = flr[comb[i]];
        }
        ans = min(ans, cur);
        //for (auto x: comb) cout << x << " "; cout << cur << endl << endl;
        //for (auto x: tkn) cout << x << " "; cout << endl << endl;
        return;
    }
     
    for (int i = 0; i < n; i++) {
        if (!tkn[i]) {
            comb.push_back(i); tkn[i] = 1;
            solve(comb, tkn);
            comb.pop_back(); tkn[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> flr[i] >> wt[i];
        cSum += wt[i];
    }
    solve(comb, tkn);
    cout << ans;
}