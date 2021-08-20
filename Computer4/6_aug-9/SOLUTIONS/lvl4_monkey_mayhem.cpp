#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M; ll ans; unordered_map<int, int> mp, mp2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, a; i<=N; i++){
        cin >> a;
        if(a != -1) mp[a-i]++;
    }
    for(int i=1, b; i<=M; i++){
        cin >> b;
        if(b != -1) mp2[b-i]++;
    }
    for(auto e: mp){
        ans += min(e.second, mp2[e.first]);
    }
    cout << ans << endl;
}