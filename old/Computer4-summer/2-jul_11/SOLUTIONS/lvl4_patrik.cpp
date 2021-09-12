#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
int n; stack<pi> stk; long long ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1, h; i<=n; i++){
        cin >> h;
        while(!stk.empty() && h > stk.top().f){
            ans += stk.top().s; stk.pop();
        }
        if(stk.empty()){
            stk.push({h, 1});
        }else {
            if(stk.top().f == h) {
                ans += stk.top().s + (stk.size() > 1);
                stk.top().s++;
            }else {
                ans++;
                stk.push({h, 1});
            }
        }
    }
    cout << ans << endl;
}