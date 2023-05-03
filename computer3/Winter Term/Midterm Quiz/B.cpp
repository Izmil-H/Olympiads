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

int N, K, x, cols, ans;
mi mp;
vpi v;

int main() {
    cin >> N >> K;
    fo(i,N) {
        cin >> x;
        if (!mp[x]) cols++;
        mp[x]++;
    }

    for(pi p: mp) v.pb({p.s, p.f});

    sort(v.begin(), v.end());

    for(int i = 0; i < cols-K; i++) ans += v[i].f;

    cout << ans;
}