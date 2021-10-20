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

int x, y, h, v, t;

int main() {
    cin >> x >> y >> h >> v >> t;
    fo(b,t) {
        int a1 = (x-b)/2;
        int a2 = y-2*b; 
        int a = max(a1,a2), px = 2*a + b, py = a + 2*b;
        if (a + b < t && px >= x && px <= x + h && py >= y && py <= y + v) {
            cout << "YES\n"; return 0;
        }
    }
    cout << "NO\n";
}