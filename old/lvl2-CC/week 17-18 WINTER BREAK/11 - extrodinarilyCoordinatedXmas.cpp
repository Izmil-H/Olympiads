#include<bits/stdc++.h>
using namespace std; 
vector<vector<pair<int, int>>> nodes; 
set<int> visited; 
map<int, int> mem; 
int curMax = 0; 
bool flag = false;
void dfs(int c, int d) {
    if (!flag)
        curMax = max(curMax, d);
    
    visited.insert(c);
    if (mem.count(c) != 0) { 
       curMax = mem[c] + d; 
       flag = true;
    } else { 
        for (int i = 0; i < nodes[c].size(); ++i) { 
            if (visited.count((nodes[c][i].first)) == 0)
                dfs(nodes[c][i].first, d + nodes[c][i].second);
        }    
    }
}

int main() {
    int n, q; 
    cin >> n >> q;
    vector<pair<int, int>> temp; 
    for (int i = 0; i < n; ++i) nodes.push_back(temp);
    for (int a,b,c, i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        nodes[a-1].push_back({b-1, c});
        nodes[b-1].push_back({a-1, c});
    }
    
    for (int x, i = 0; i < q; i++) {
        cin >> x;
        curMax = 0;
        visited.clear();
        flag = false;
        dfs(x-1, 0);
        mem[x-1] = curMax;
        cout << curMax << endl;
    }
    for (int i = 0; i < nodes.size(); ++i) { 
        cout << i << ":" << endl;
        for (int j = 0; j < nodes[i].size(); ++j) { 
            cout << "\t" << nodes[i][j].first<< " " << nodes[i][j].second << endl;
        }
    }
}
