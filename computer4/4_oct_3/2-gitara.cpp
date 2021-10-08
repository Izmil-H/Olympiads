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

int n, p, ans;
map<int, vector<int>> stk;

int main() {
    cin >> n >> p;
    int x, y, prev = NULL;
    fo(i,n) {
        cin >> x >> y;
        if (x != prev) {
            prev = x;
            //ans += stk.size(); stk.clear();
            //cout << "RELEASE ALL " << ans << endl;
            ans++; stk.pb(y);
            cout << "ADD " << y << " " << ans << endl;
            continue;
        }
        while (!stk.empty() && y < stk.back()) {
            cout << "RELEASE " << stk.back() << " " << ans+1 << endl; 
            stk.pop_back(); ans++;
        }
        if (stk.back() != y) {
            ans++; stk.pb(y);
            cout << "ADD " << y << " " << ans << endl;
        }
    }
    cout << ans;
}