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

int main() {
    int n; cin >> n;
    int arr[n]; aIN(n,arr);
    sort(arr, arr+n);
    string s = "";
    fo(i,(n+1)/2) {
        cout << arr[i];
        if (i < n-1-i) {
            cout << " " << arr[n-1-i];
            if (arr[n-1-i] > arr[i]) s += "BS";
            else s += "EE";
        } else {
            s += 'E';
        }
        if (i < (n+1)/2 - 1) cout << " ";
    }
    cout << endl << s << endl;
}

/*

2426 = 2624
2425 = 2524

1425 = 2415

1 2 5 6 7 9


*/