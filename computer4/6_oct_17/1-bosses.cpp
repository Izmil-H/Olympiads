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

ll n, h, p, a[MS], tot, cnt, ans;

int main() {
    cin >> n >> h >> p;
    fo(i,n) {
        cin >> a[i];
        tot += a[i];
    }
    sort(a,a+n);

    ll cost = ans = p*tot;
    //cout << cnt << " " << tot << " " << cost << ":\n";
    fo(i,n) {
        tot -= (a[i]-cnt)*(n-i); cnt = a[i]; 
        ll cost = h*cnt + p*tot;
        //cout << cnt << " " << tot << " " << cost << " " << ans << endl;
        ans = min(ans, cost);
    }
    cout << ans << '\n';
}