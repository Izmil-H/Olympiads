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
    int n, x;
    stack<pair<int,int>> stk;
    stk.push({0,int(1e6)+1});
    cin >> n;
    fo(i,n) {
        cin >> x;
        while (stk.size() && x >= stk.top().S) {
            stk.pop();
        }
        cout << i - stk.top().F << " ";
        stk.push({i,x});
    }
}
