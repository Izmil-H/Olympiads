#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i= 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    vector<pair<int,int>> vec;
    for (auto it: mp) {
        vec.push_back(it);
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[0].second + vec[1].second << endl;
}