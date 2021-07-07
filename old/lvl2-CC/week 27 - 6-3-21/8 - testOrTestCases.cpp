#include<bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<char>> lst;
void fun(int id, string word, vector<string> ans) {
    if (id > n || word.length() == l) {
        ans.push_back(word);
        return;
    }
    for (auto x: lst[id]) {

    }
}

int main() {
    cin >> n >> l;
    for (int i = 0, m; i < n; i++) {
        cin >> m;
        vector<char> tmp;
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            tmp.push_back(c);
        }
        lst.push_back(tmp);
    }
}