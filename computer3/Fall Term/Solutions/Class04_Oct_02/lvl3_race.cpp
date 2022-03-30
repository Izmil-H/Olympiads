#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5 + 5;
int K, N; ll x;
bool check1(int t){
    return (ll)(1+t)*t/2 + (ll)(x + t - 1)*(t-x)/2 >= K;
}
bool check2(int t){
    return (ll)(1+t)*t/2 + (ll)(x + t)*(t-x+1)/2 >= K;
}
bool check3(int t){
    return (ll)(1+t)*t/2 >= K;
}
int main(){
    //freopen("test.txt", "r", stdin);
    //freopen("test_out.txt", "w", stdout);
    scanf("%d %d", &K, &N);
    for(int i=1; i<=N; i++){
        scanf("%lld", &x);
        int lo = 1, hi = K, mid = 0, t1 = 0, t2 = 0, ans=0; ll d = (1+x)*x/2;
        if(d >= K){
            while(lo <= hi){
                mid = (lo + hi)/2;
                if(check3(mid)) {ans = mid; hi = mid-1;}
                else lo = mid+1;
            }
            printf("%d\n", ans); continue;
        }
        lo = 1; hi = K;
        while(lo <= hi){
            mid = (lo + hi)/2;
            if(check1(mid)) { t1 = mid; hi = mid - 1;}
            else lo = mid + 1;
        }
        lo = 1; hi = K; mid = 0;
        while(lo <= hi){
            mid = (lo + hi)/2;
            if(check2(mid)) { t2 = mid; hi = mid - 1;}
            else lo = mid + 1;
        }
        printf("%d\n", min(2*t1 - x, 2*t2 - x + 1));
    }
}