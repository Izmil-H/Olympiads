#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, Q, pre[MM], suf[MM]; string s; bool vis[26];
void fun(string &s, int cnt[]){
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=N; i++){
        int c = s[i-1] - 'A';
        if(vis[c]) {
            cnt[i] = cnt[i-1];
        }else{
            cnt[i] = cnt[i-1] + 1;
        }
        vis[c] = true;
        for(int j=c+1; j<26; j++) vis[j] = false;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q >> s;
    fun(s, pre);
    reverse(s.begin(), s.end());
    fun(s, suf);
    reverse(suf+1, suf+N+1);
    for(int i=1, x, y; i<=Q; i++){
        cin >> x >> y;
        cout << pre[x-1] + suf[y+1] << "\n";
    }
}