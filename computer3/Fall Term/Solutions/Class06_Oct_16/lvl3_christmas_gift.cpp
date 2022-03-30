#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
int N, B, ans;
int main(){
    cin >> N >> B; vector<pi> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i].f >> a[i].s;
    }
    for(int i=0; i<N; i++) {
        a[i].f /= 2;
        vector<pi> b = a; int cnt = 0, money = B;
        sort(b.begin(), b.end(), [](pi x, pi y){ return x.f+x.s <= y.f+y.s; });
        for(pi e : b){
            if(money >= e.f + e.s) {
                cnt ++; money -= e.f + e.s;
            }else break;
        }
        ans = max(ans, cnt);
        a[i].f *= 2;
    }
    cout << ans << endl;
}