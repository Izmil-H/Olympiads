#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N, a[MM], b[MM]; ll ans, psa;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];
    sort(a, a+N); sort(b, b+N);
    if(a[N-1] != b[N-1]) { cout << -1 << endl; return 0; }
    for(int r=0, c=0; r<N; r++){
        while(c<N && b[c] <= a[r]) { psa += b[c]; c++; }
        ans += psa + 1LL*(N - c)*a[r];
    }
    cout << ans << endl;
}