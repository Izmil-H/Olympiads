#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define v(t) vector<t>
#define pii pair<int,int>
#define mii map<int,int>
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}

int main() {
    int n, x, y; cin >> n;
    v(pii) a;
    fo(i,n) {
        cin >> x >> y;
        a.PB({x,y});
    }
    sort(a.begin(), a.end());
    stack<int> stk;
    for (pii e: a) {
        if (stk.empty() || e.S > stk.top()) stk.push(e.S);
        else {
            int top = stk.top(); stk.pop();
            while (stk.size() && e.S <= stk.top()) stk.pop();
            stk.push(top);
        }
    }
    cout << stk.size();
}