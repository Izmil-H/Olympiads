#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    stack<int> stk; int ans = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
    
        if (x == 0) {
            ans -= stk.top();
            stk.pop();
        } else {
            ans += x;
            stk.push(x);
        }
    }
    
    cout << ans;
}