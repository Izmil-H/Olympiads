#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
int T, N, M, K; unordered_map<string, vector<pi>> mp; string s;
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N; mp.clear(); int ans = 0;
        for(int i=1; i<=N; i++){
            cin >> M;
            for(int j=1, a, b; j<=M; j++){
                cin >> s >> a >> b; mp[s].push_back({a, b});
            }
        }
        cin >> K;
        for(int i=1, a; i<=K; i++){
            cin >> s >> a;
            sort(mp[s].begin(), mp[s].end());
            for(pi e: mp[s]){
                if(a <= e.s) { ans += a * e.f; break; }
                else { ans += e.f*e.s; a-=e.s; }
            }
        }
        cout << ans << "\n";
    }
}