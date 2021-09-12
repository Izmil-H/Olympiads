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

int n; ll ans; string s;

ll digSum(string s) {
    ll sum = 0;
    while (s.size()) {
        sum += s.back()-'0';
        s.pop_back();
    }
    return sum;
}


int main() {
    cin >> n;
    fo(i,n) {
        cin >> s;
        ans = max(ans, digSum(s));
    }
    cout << ans << endl;
}