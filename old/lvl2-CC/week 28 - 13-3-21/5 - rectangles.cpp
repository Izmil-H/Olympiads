#include<bits/stdc++.h>
using namespace std;

int n;
map<int, vector<int>> x, y;

int main() {
    cin >> n;
    for (int i = 0, a , b; i < n; i++) {
        cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
    }   
    for (auto it: x) {
        sort(it.second.begin(), it.second.end());
        cout << it.first << ": ";
        for (auto p: it.second) cout << p << " ";
        cout << endl;
    }
    cout << "==========" << endl;
    for (auto it: y) {
        sort(it.second.begin(), it.second.end());
        cout << it.first << ": ";
        for (auto p: it.second) cout << p << " ";        
        cout << endl;
    }
    for (auto p: x) {
        vector<int> ys = p.second, xs;
        for (int i = 0; i < ys.size(); i++) {
            cout << p.first << "," << ys[i] << ":\n";    
            for (int j = i+1; j < ys.size(); j++) {
                xs = y[ys[j]];
                int idx = lower_bound(xs.begin(),xs.end(), ys[j])-xs.begin();
                for (int k = idx; k < xs.size(); k++) {
                    int tmp = lower_bound(x[xs[k]].begin(),x[xs[k]].end(), p.first)-x[xs[k]].begin();
                    if (x[xs[k]][tmp] == p.first) {
                        long area = abs(p.first-xs[k])*abs(ys[i]-ys[j]);
                        cout << "   " << p.first << "," << ys[i] << "   " << p.first << "," << ys[j] << "   " << xs[k] << "," << ys[j] << "  " << xs[k] << "," << x[xs[k]][tmp] << " " << area << endl;
                    }
                }
            } 
            cout << endl;
        }
    }
}