#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}



int main() {
    int t, n; string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<int> r(n+1), w(n+1);
        Fo(i,1,n+1,1) {
            r[i] = r[i-1] + (s[i-1] == 'R');
            w[i] = w[i-1] + (s[i-1] == 'W');
        }
        int mi = w[1] - r[1], ans = n+1;
        Fo(i,2,n,1) {
            ans = min(ans, w[n]-w[i]+r[i]+mi);
            mi = min(mi, w[i]-r[i]);
        }
        cout << ans << endl;
    }
}