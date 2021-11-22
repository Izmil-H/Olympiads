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
const int MS = 2000;

int n, m;
char brd[MS][MS];
string dp[MS];

int main() {
    cin >> n >> m;
    fo(i,n) {
        fo(j,m) cin >> brd[i][j];
    }
    dp[0] = brd[0][0];
    Fo(j,m-1) {
        dp[j] = dp[j-1];
        dp[j] += brd[0][j];
    }
    //fo(i,m) cout << dp[i] << " "; cout << endl;
    Fo(i,n-1) {
        fo(j,m) {
            if (!j) dp[j] += brd[i][j];
            else {
                dp[j] = min(dp[j-1], dp[j]);
                dp[j] += brd[i][j];
            }
            //cout << dp[j] << " ";
        }
        //cout << endl;
    }
    cout << dp[m-1];
}