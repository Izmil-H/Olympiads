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
const int MS = 1e5;

int n, k, a[MS+2]; ll psa[2*MS], ans = LLONG_MIN;

int main() {
    cin >> n >> k;
    aIN(n,a); psa[0] = a[0];
    Fo(i,1,n+k,1) {
        psa[i] = psa[i-1] + a[i%n];
    }

    deque<ll> mi;
    for (int i = 0; i < n+k; i++) {
        if (mi.front() < i-k) mi.pop_front();
        while (mi.size() && psa[i] <= psa[mi.back()]) mi.pop_back();
        mi.PB(i);
        ans = max(ans, psa[i] - psa[mi.front()]);  
    }
    cout << ans;
}