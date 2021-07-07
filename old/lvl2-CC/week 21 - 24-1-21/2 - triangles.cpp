#include<bits/stdc++.h>
using namespace std;

int tri(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    if (a.second == b.second && a.first == c.first) {
        return (abs(a.first-b.first) * abs(a.second-c.second));
    } else if (a.second == c.second && a.first == b.first) {
        return (abs(a.first-c.first) * abs(a.second-b.second));
    } else return -1;
}

int main() {
    int n; cin >> n;
    pair<int,int> pts[n];
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    int ans = 0;
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = 0; k < n; k++) {
                ans = max(ans, tri(pts[i], pts[j], pts[k]));
            }
        }
    }
    cout << ans;
}