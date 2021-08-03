#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
//ai*(x- Li)^2 +bi*(x - Li) + ci
//= a * (x^2 - 2*L*x + L^2) + b*(x - L) + c
//= a*x^2 - 2*L*a*x + a*L^2 + b*x - b*L + c
//= a*x^2 + (-2*L*a + b)*x + (a*L^2 - b*L + c)
int N, T, L, R, a, b, c; ll d2[MM], d1[MM], d0[MM];
int main(){
    cin >> N >> T;
    for(int i=1; i<=N; i++) {
        cin >> L  >> R >> a >> b >> c;
        d2[L] += a;  d2[R+1] -= a;
        ll val = -2LL*L*a + b;
        d1[L] += val; d1[R+1] -= val;
        val = 1LL*a*L*L - 1LL*b*L + c;
        d0[L] += val; d0[R+1] -= val;
    }
    for(int i=1; i<=T; i++){
        d2[i] += d2[i-1];
        d1[i] += d1[i-1];
        d0[i] += d0[i-1];
        cout << d2[i] * i * i + d1[i] * i + d0[i] << " ";
    }
}