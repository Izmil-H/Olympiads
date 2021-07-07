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
    ll n, k, sum = 0, a, b;
    cin >> n >> k;

    fo(i,n) {
        cin >> a >> b;
        sum += a*b;
        sum %= k; 
    }
    
    cout << sum%k;
}