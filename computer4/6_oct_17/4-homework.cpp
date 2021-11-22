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
const int MS = 1e6+2;

int n, d; vector<double> tsk[MS]; double v;

int main() {
    fo(t,10) {
        cin >> n;
        fo(i,MS) tsk[i].clear();
        double ans = 0.0; int mx = 0;
        fo(i,n) {
            cin >> d >> v;
            tsk[d].pb(v);
            mx = max(mx, d);
        }
        priority_queue<double> q;
        for(int i = mx; i >= 1; i--) {
            for(double v: tsk[i]) q.push(v);
            if (!q.empty()) {
                ans += q.top(); q.pop();
            }
        }
        cout << fixed << setprecision(4) << ans << endl;
    }
}

/*
5
1 1.0, 2.0
3 2.0, 3.0
7 10.0
*/