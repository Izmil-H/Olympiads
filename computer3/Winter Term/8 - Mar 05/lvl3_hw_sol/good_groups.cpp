#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> ps;
int X, Y, G; vector<ps> x, y; unordered_map<string, unordered_set<string>> mp;
string a, b, c;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> X;
    for(int i=0; i<X; i++) {
        cin >> a >> b;   x.push_back({a, b});
    }
    cin >> Y;
    for(int i=0; i<Y; i++) {
        cin >> a >> b;   y.push_back({a, b});
    }
    cin >> G;
    for(int i=0; i<G; i++) {
        cin >> a >> b >> c;
        mp[a].insert(b); mp[a].insert(c);
        mp[b].insert(a); mp[b].insert(c);
        mp[c].insert(a); mp[c].insert(b);
    }
    int ans = 0;
    for(ps e : x) {
        if(!mp[e.first].count(e.second)) ans++;
    }
    for(ps e : y) {
        if(mp[e.first].count(e.second)) ans++;
    }
    cout << ans << endl;
}