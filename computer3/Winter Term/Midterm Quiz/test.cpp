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

ll L, R, ans;

int main() {
    cin >> L >> R;
    for(ll i = L; i <= R; i++) {
        string fw = to_string(i);
        string bw = fw; reverse(bw.begin(), bw.end());
        if (fw == bw) {
            ans++;
            //if (stoll(fw) > 1e3) cout << fw << endl;
        }
    }
    cout << ans;
}
