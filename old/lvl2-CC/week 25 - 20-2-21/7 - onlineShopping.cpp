#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<string, vector<pair<int,int>>> mp;
        for (int i= 0; i < n; i++) {
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                string s; int p, q;
                cin >> s >> p >> q;
                mp[s].push_back({p,q});
            }
        }
        int k, cost = 0; cin >> k;
        for (int i= 0; i < k; i++) {
            string s; int d;
            cin >> s >> d;
            sort(mp[s].begin(), mp[s].end(), comp);
            for (auto i: mp[s]) {
                cost += i.first * i.second;
                d -= i.second;
                if (d <= 0) {
                    cost -= abs(d) * i.first;
                    break;
                }
            }
        }
        cout << cost << endl;
    }
}