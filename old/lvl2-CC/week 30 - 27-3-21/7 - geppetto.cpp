#include<bits/stdc++.h>
using namespace std;

int N, M, cnt = 0;
vector<int> comb;
bool arr[21][21];

void solve(vector<int> comb, int i) {
    if (i > N) {
        cnt++;
        return;
    }
    solve(comb, i+1);
    for (auto x: comb) {
        if (arr[x][i]) return;
    }
    comb.push_back(i);
    solve(comb, i+1);
    comb.pop_back();
}

int main() {
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        arr[a][b] = 1; arr[b][a] = 1;
    }
    solve(comb, 1);
    cout << cnt;
}