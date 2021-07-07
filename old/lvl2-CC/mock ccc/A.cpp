#include<bits/stdc++.h>
using namespace std;

const int len = 1e6;
long sum[len];

int main() {
    int n, k; 
    cin >> n >> k; 
    pair<int, int> a[n]; 
    for (int i = 0; i < n; ++i) { 
        cin >> a[i].second >> a[i].first; 
    }
    sort(a, a+n); 
    int ans = 0; 
    int prev = 0; 
    ans += a[0].second;
    int current = ans; 
    for (int i = 1; i < n; ++i) { 
        if (a[i].first - a[prev].first > 2*k) { 
            while (a[i].first - a[prev].first > 2*k) { 
                current -= a[prev].second;
                ++prev;
            } 
        }
        current += a[i].second;
        ans = max(ans, current);
    }
    cout << ans << endl;
}
