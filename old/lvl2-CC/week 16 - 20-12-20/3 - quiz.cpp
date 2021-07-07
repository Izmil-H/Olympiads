#include<bits/stdc++.h>
using namespace std; 

/* -- FIRST -- 
int main () {
    long long n, k;
    cin >> n >> k;
    long long lowest;
    if (n >= k) {
        long long div = n/k;
        lowest = min(abs(n-div*k), abs((n-div*k)-k));
        //       min(n%k, k - n%k);
    } else {
        lowest = min(n, abs(n-k));
    }
    cout << lowest;
}
*/

// better
int main() {
    long long n, k;
    cin >> n >> k;
    cout << min(n%k, k-n%k);
}