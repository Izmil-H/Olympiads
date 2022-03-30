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
const int MS = 1002;

int n; pi a[MS]; set<pi> st;

int main() {
    cin >> n;
    int p, x, y;
    a[1] = {0,0}; st.insert(a[0]);
    for(int i = 2; i <= n; i++) {
        cin >> p >> x >> y;
        a[i] = {a[p].f + x, a[p].s + y};
        st.insert(a[i]);
    }
    cout << st.size();
}