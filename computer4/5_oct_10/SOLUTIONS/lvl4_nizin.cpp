#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans; deque<ll> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0, x; i<n; i++){
        cin >> x;  q.push_back(x);
    }
    while(q.size() > 1){
        if(q.front() == q.back()){
            q.pop_front(); q.pop_back();
        }else if(q.front() < q.back()) {
            ll x = q.front();  q.pop_front();
            q.front() += x;  ans++;
        }else {
            ll x = q.back();  q.pop_back();
            q.back() += x; ans++;
        }
    }
    cout << ans << endl;
}