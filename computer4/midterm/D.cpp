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

int n, a[MS], ar[MS];
ll ans = 0;

ll f(int ar[]) {
    ll sum = 0;
    fo(i,n-1) {
        sum += abs(ar[i] - ar[i+1]);
    }
    return sum;
}

int main() {
    cin >> n;
    aIN(n, a); sort(a,a+n);

    int pos = n/2;
    ar[pos] = a[0];
    cout << pos << " " << n/2 << endl;
    for(int k = 1; k <= n/2; k++) {
        ar[pos+k] = a[n-k];
        ar[pos-k] = a[n-k-1];
    }
    fo(i,n) cout << ar[i] << " "; cout << endl;
    cout << ans;
}