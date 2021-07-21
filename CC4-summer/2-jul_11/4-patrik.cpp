#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}


int main() {
    int n, x, ans = 0;
    cin >> n;
    stack<pair<int,int>> stk;

    fo(i,n) {
        cin >> x;
        while(stk.size() && x > stk.top().F) {
            ans += stk.top().S; 
            stk.pop();
        }
        if (stk.empty()) {
            stk.push({x,1});
        } else {
            if (stk.top().F == x) {
                ans += stk.top().S + (stk.size() > 1);
                stk.top().S++;
            } else {
                ans++;
                stk.push({x,1});
            }
        }
    } 
    cout << ans << endl;
}