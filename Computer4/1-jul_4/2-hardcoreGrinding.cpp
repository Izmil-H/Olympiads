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


int a[int(1e7)+3];

int main() {
    int n, s, f;
    cin >> n;
    fo(i,n) {
        cin >> s >> f;
        a[s]++;
        a[f]--;
    }
    int ans = 0;
    Fo(i,1,1e7+1,1) {
        a[i] += a[i-1];
        ans = max(ans, a[i]);
    }
    cout << ans;
}