#include<bits/stdc++.h>
using namespace std;

int N, ans = INT_MAX;
vector< pair<int,int> > vec;

void comb(pair<int,int> a, int i, int s) {
    if (s) ans = min(ans, abs(a.first-a.second));
    if (i >= N) return;
    comb(a, i+1, s);
    a.first *= vec[i].first;
    a.second += vec[i].second;
    comb(a, i+1, s+1);
}

int main() {
    cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        vec.push_back({a,b});
    }
    comb({1,0}, 0, 0);
    cout << ans;
}