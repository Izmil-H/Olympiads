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
const int MS = 1e5+2;

int n, x; vi v;
ll ans = 0;

ll f() {
    ll sum = 0;
    fo(i,n-1) {
        sum += abs(v[i] - v[i+1]);
    }
    return sum;
}

int main() {
    cin >> n;
    fo(i,n) {
        cin >> x; v.pb(x);
    }
    do {
        cout << f() << ": "; fo(i,n) cout << v[i] << " "; cout << endl;
        ans = max(ans, f());
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}