#include<bits/stdc++.h>
using namespace std;

bool sorter(pair<string,long> a, pair<string,long> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<pair<string,long>> cmps;
    for (int i = 0; i < n; i++) {
        string name; int r, s, d;
        cin >> name >> r >> s >> d;
        cmps.push_back( {name,2*r + 3*s + d} );
    }
    sort(cmps.begin(), cmps.end(), sorter);
    cout << cmps.front().first;
    if (n > 1) {
        cmps.erase(cmps.begin());
        cout << endl << cmps.front().first;
    }
}