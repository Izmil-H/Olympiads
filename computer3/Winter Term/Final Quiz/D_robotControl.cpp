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

int n, m;
int a[MS], l[MS], r[MS];

int main() {
    cin >> n >> m;
    fo (i, m) {
        cin >> a[i];
    }
    sort(a, a+m);
    for (int i = 0; i < m; i++) {
        l[i] = abs(a[i] - a[i-1]);
        r[i] = abs(a[i] - a[i+1]);
    }
    if (m <= n) cout << 0 << endl;
    else {

    }
}

// 1  3 10 18 20 
//  2  7  8  2

// 