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

int n, a[MS];

int main() {
    cin >> n;
    aIN(n, a);

    int x, l = 0, r = n-1;
    for (x = 1; x <= n/2 + 1; x++) {
        bool b1 = false, b2 = false;
        for (int i = l; i < r; i++) {
            if (a[i] == x) {
                l = i;
                b1 = true;
                break;
            }
        }
        for (int i = r; i > l; i--) {
            if (a[i] == x) {
                r = i;
                b2 = true;
                break;
            }
        }
        //cout << x << ":\n  L: " << l << "  R: " << r << endl;
        if (!b1 || !b2) break;
    }
    cout << x - 1;
}