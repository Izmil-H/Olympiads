#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, bit[MM], ord[MM]; vector<int> lst[MM]; ll ans;
void update(int pos, int val){
    for(int i=pos; i<=N; i+=i&-i) bit[i] += val;
}
int query(int pos) {
    int ret = 0;
    for(int i=pos; i>0; i-=i&-i) ret+=bit[i];
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1, d; i<=N; i++) {
        cin >> d; lst[d].push_back(i);
    }
    priority_queue<int> q;
    for(int i=N; i>=1; i--){
        for(int x : lst[i]) q.push(x);
        if(q.empty()) {
            cout << "-1\n"; return 0;
        }
        ord[i] = q.top(); q.pop();
    }
    for(int i=1; i<=N; i++){
        ans += (i-1) - query(ord[i]);
        update(ord[i], 1);
    }
    cout << ans << endl;
}