#include<bits/stdc++.h>
using namespace std;

int n;

void search(int c, int d, int& most, vector<pair<int,int>> (&node)[n], bool (&visited)[n]) {
    most = max(most, d);
    for (auto child: node[c]) {
        if (visited[child.first] == 0) {
            visited[child.first] = 1;
            search(child.first, d+child.second, most, node, visited);
        }
    }
}

int main() {
    int n1, q;
    cin >> n1 >> q;
    n = n1;
    vector<pair<int, int>> node[n];
    for (int a,b,c, i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        node[a-1].push_back({b-1, c});
        node[b-1].push_back({a-1, c});
    }
    
    for (int i = 0; i < q; i++) {
        int que; cin >> que;
        bool visited[n] = {0}; visited[que] = 1;
        int most = 0, dist = 0;
        search(que, dist, most, node, visited);
        cout << most << endl;
    }
}