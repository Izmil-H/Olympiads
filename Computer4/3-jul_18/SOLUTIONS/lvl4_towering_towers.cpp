#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int n, h[MM]; stack<int> stk;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++) {
        while(!stk.empty() && h[i] >= h[stk.top()]){
            stk.pop();
        }
        if(stk.empty()) cout << i << " ";
        else cout << i - stk.top() << " ";
        stk.push(i);
    }
}