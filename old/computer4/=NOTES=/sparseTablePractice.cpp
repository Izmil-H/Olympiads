/* SPARSE TABLE PRACTICE */

/*  Sparse table IDEA:
    Precompute: O(nlongn)
    Query: O(1) 
    Essentially we can precompute a bunch of ranges,
    each a power of 2 in length. For any given range 
    we find 2 smaller ranges within it, each having 
    length of Log2(length of query range). The final
    step is to get the result (min/max/gcd) of those 
    two ranges.

    STEPS:
    1) Set sparse table level 0 to original array
    2) Precompute the ranges with 2 nested loops
        a) first loop goes through levels, because 
           each one needs the level before it to be fully completed
        b) second loop goes through indecies
        c) use formula: st[i][k] = min(st[i][k-1], st[i+(1<<k)+1][k-1])
            i) each of these is half the length of the current range we're finding
    3) Query
        a) find length of range given
        b) find largest power of 2 that fits in range: log2(len)
        c) use same formula as precompute but don't subtract the level
           This gets us 2 ranges of the same length that likely overlap
            i) first subrange starts at i
            ii) second subrange ENDS at i 
        d) find answer of the two ranges found (min/max/gcd)
*/

/*  QUESTION: given an array of N integers,
    answer Q queries asking for the minimum 
    between x and y.
*/

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

int n, q, a[MS]; const int LOG = 17;

int st[MS][LOG];
int query(int l, int r) {
    
    int len = r - l + 1;
    int k = log2(len);
    return min(st[l][k], st[l+(1<<k)+1][k]);
}
int main() {
    cin >> n;

    // input 
    fo(i,n) {
        cin >> a[i];
        st[i][0] = a[i]; // sparse table at length/level 0 is same as original array
    }
    
    // Preprocessing    O(nlogn)
    for(int k = 1; k < LOG; k++) {
        for(int i = 0; i + (1<<k) - 1 < n; i++) {
            st[i][k] = min(st[i][k-1], st[i+(1<<k)+1][k-1]);
        }
    }

    // queries  O(q)
    fo(i,q) {
        int l, r;
        cin >> l >> r;
        cout << query(l,r) << " ";
    }
}