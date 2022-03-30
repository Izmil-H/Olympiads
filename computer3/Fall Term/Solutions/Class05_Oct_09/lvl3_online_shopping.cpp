#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int T, N, M, K; string name;
int main(){
    for(cin >> T; T > 0; T--){
        cin >> N;   unordered_map<string, vector<pi> > mp;
        for(int i=1; i<=N; i++){
            cin >> M;
            for(int j=1, p, q; j<=M; j++){
                cin >> name >> p >> q;
                mp[name].push_back({p, q});
            }
        }
        cin >> K;  int cost = 0;
        for(int i=1, amount; i<=K; i++){
            cin >> name >> amount;
            sort(mp[name].begin(), mp[name].end());
            for(pi e: mp[name]){
                if(amount >= e.second) {
                    cost += e.first * e.second; amount -= e.second;
                }else {
                    cost += e.first * amount; break;
                }
            }
        }
        cout << cost << endl;
    }
}