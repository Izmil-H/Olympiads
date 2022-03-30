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

int n, k, x; char a[25+2];
map<char, int> freq;

int main() {
    cin >> n >> k;
    fo(i,k) {
        int pos; char c; 
        cin >> pos >> c; x += pos; x %= n;
        if (a[x] == 0 || a[x] == c) { a[x] = c; }
        else { cout << '!'; return 0; }
    }  
    //fo(i,n) cout << a[i] << "."; cout << endl;
    fo(i,n+1) {
        if (++freq[a[i]] > 1 && a[i] != 0) {cout << '!'; return 0;}
    }
    int cur = x+1;
    fo(i,n) {
        cur = --cur%n; if (cur < 0) cur = n-1;
        if (a[cur] == 0) cout << '?';
        else cout << a[cur];
    }
}