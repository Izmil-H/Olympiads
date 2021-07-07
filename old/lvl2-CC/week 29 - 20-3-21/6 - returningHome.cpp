#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l; 
    cin >> n >> m >> l;
    
    string arr[n]; set<pair<int,int>> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        q.insert({l-1,r-l+1});
    }

    int cnt = n;
    
    for (int i = 0; i < n; i++) {
        for (auto x: q) {
            string s = arr[i].substr(x.first, x.second);
            string s2 = s;
            reverse(s.begin(), s.end());
            if (s != s2) {
                cnt--;
                break;
            }
        }
    }

    cout << cnt;
}