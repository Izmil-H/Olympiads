#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
int main(){
    cin >> n >> a >> b;
    for(int i=1; i<=n; i++){
        if(i&1) ans += a;
        else ans += b;
    }
    cout << ans << endl;
}