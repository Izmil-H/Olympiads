#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mi map<int,int>
#define ml map<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define pb push_back
#define f first
#define s second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 100+2;

int n, a[MS], mn = IM, mx = INT_MIN; ll ans = LLM;

int main() {
    cin >> n;
    fo(i,n) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    for(int y = mn; y <= mx; y++) {
        ll cost = 0;
        fo(i,n) {
            cost += (a[i]-y)*(a[i]-y); 
        }
        ans = min(ans, cost);
    }
    cout << ans;
}