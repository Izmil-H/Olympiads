#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e7+3;
int n, dif[MM], ans = 0;
int main(){
    cin >> n;
    for(int i=0, s, e; i<n; i++){
        cin >> s >> e;
        dif[s]++; dif[e]--;
    }
    for(int i=1; i<MM; i++){
        dif[i] += dif[i-1];
        ans = max(dif[i], ans);
    }
    cout << ans << endl;
}