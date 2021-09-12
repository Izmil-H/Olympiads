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
const int MS = 1e6+2;

int n, k, arr[MS], freq[MS], unq; ll ans;

int main() {
    cin >> n >> k; 
    aIN(n,arr);
   
    for (int l = 0, r = 0; r < n; r++) {
        if (++freq[arr[r]] == 1) unq++;
        while(unq >= k) {
            ans += n - r;
            freq[arr[l]]--;
            if (!freq[arr[l]]) unq--;
            l++;
        }
    }
    cout << ans << endl;
}