#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll f(ll x){
    if(x > n) return 0;
    return f(10*x+2) + 1 + f(10*x+3);
}
int main() {
    cin >> n;
    cout << f(0) - 1 << endl;
}