#include <bits/stdc++.h>
using namespace std;
int N, L; vector<string> ch[27], ans; string word;
void dfs(string s, int n){
    if(s.size()>=L || n>=N-1) {ans.push_back(s); return;}
    for(auto u: ch[n+1]) dfs(s+u, n+1);
    dfs(s, n+1);
}
int main(){
    cin >> N >> L;
    for(int i=0, M=0; i<N; i++){
        cin >> M;
        for(int j=0; j<M; j++){
            cin >> word;
            ch[i].push_back(word);
        }
    }
    for(auto u: ch[0]) dfs(u, 0);
    sort(ans.begin(), ans.end());
    for(auto u: ans) cout << u << endl;
}