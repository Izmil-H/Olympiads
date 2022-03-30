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

        //ans += stk.size(); stk.clear();
        //cout << "RELEASE ALL " << ans << endl;

        while (!stk[x].empty() && y < stk[x].back()) {
            //cout << "RELEASE " << stk[x].back() << " " << ans+1 << endl; 
            stk[x].pop_back(); ans++;
        }
        if (stk[x].empty() || stk[x].back() != y) {
            ans++; stk[x].pb(y);
            //cout << "ADD " << y << " " << ans << endl;
        }
    }
    cout << ans;
}