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
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int n, q, pre[MS], suf[MS];
string s;

void fun(int cnt[]) {
    stack<char> stk;
    Fo(i,n) {
        char c = s[i-1];
        while (!stk.empty() && c < stk.top()) stk.pop();
        if (stk.empty() || c > stk.top()) {
            cnt[i] = cnt[i-1] + 1;
            stk.push(c);
        } else {
            cnt[i] = cnt[i-1];
        }
    }
}

int main() {
    cin >> n >> q >> s;
    fun(pre);
    reverse(s.begin(), s.end());
    fun(suf);
    reverse(suf+1, suf+n+1);
    int a, b;
    Fo(i,q) {
        cin >> a >> b;
        cout << pre[a-1] + suf[b+1] << endl;
    } 
}