#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define v(t) vector<t>
#define pii pair<int,int>
#define mii map<int,int>
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int t, n, k, a, sum, ans;

int main() {
    cin >> t;
    fo(test, t) { 
        sum = ans = 0;
        cin >> n >> k;
        fo(i,n) {
            cin >> a;
            sum += a;
            if (sum >= k) {
                sum = 0; ans++;
            }
        }
        cout << ans << endl;
    }
}