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

int cnt = 0;

void solve() {
    int G1 = 0;
    cout << 0 << endl << flush; cin >> G1; cnt++;
    if (G1 == 0 || G1 == -1) return;
    long long int mx = pow(2, G1);
    long long int guess = mx - 1;
    int res = -1;
    
    while(1) {
        cout << guess << endl << flush; cnt++;
        cin >> res;
        if (res == 0 || res == -1) break;
        guess -= pow(2, res / 2 - 1);
    }
}

int main() {
    long long n;
    cin >> n;
    fo(t,n) {
        solve();
    }
}