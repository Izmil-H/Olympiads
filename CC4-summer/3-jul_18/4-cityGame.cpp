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




int t, n, m, ht[1001];

int maxRect(int m) {
    stack<int> stk; int area = 0;
    fo(i, m+1) {
        while (stk.size() && ht[i] <= ht[stk.top()]) {
            int idx = stk.top(); stk.pop();
            int left = (stk.empty()? -1: stk.top());
            area = max(area, ht[idx] * (i-left-1));
        }
        stk.push(i);
    }
    return area;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m; int ans = 0;
        memset(ht, 0, sizeof(ht));
        fo(i,n) {
            fo(j,m) {
                char c; cin >> c;
                if (c == 'F') ht[j]++;
                else ht[j] = 0;
            }
            ans = max(ans, maxRect(m));
        }
        cout << ans*3 << endl;
    }    
}