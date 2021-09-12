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
const int MS = 5002;

int n; pair<ll,ll> a[MS]; ll ans;


int main() {
    cin >> n;
    fo(i,n) {
        cin >> a[i].F >> a[i].S;
    }
    sort(a,a+n, greater<pair<ll,ll>>());
    ll ans = 0;
    fo(i,n) {
        ll v = a[i].S, ma = a[i].F, mi = a[i].F;
        Fo(j,i+1,n,1) {
            if (v+a[j].S-max(ma,a[j].F)+min(mi,a[j].F) > v-ma+mi) {
                v += a[j].S; ma = max(ma,a[j].F); mi = min(mi,a[j].F);
            }
        }
        ans = max(ans, v-ma+mi);
    }
    cout << ans;
}