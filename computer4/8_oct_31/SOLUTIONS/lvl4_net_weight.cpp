#include <bits/stdc++.h>
using namespace std;
int n, ans; priority_queue<int> q;
int main(){
    cin >> n;
    for(int i=1, x; i<=n; i++){
        cin >> x;
        if(x <= 100) q.push(x);
    }
    for(int i=0; i<2; i++){
        if(!q.empty()) {
            ans += q.top(); q.pop();
        }
    }
    cout << ans << endl;
}