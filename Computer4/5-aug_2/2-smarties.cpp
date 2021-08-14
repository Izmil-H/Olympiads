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
const int MS = 1e6+2;

int n, k, unq, ans, arr[MS], freq[MS];

int main() {    
    cin >> n >> k; aIN(n,arr);
    
    for (int l = 0, r = 0; r < n; r++) {
        if (++freq[arr[r]]) unq++;
        while (unq >= k) {
            ans += n - r;
            if (!(--freq[arr[l]])) unq--;
            l++;
        }
    }

    cout << ans;
}