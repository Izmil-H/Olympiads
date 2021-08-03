#include <bits/stdc++.h>
using namespace std;
int N, K, a[1000001], f[1000001], cnt; long long ans;
int main(){
    scanf("%d %d", &N, &K);
    for(int l=0, r=0; r<N; r++){
        scanf("%d", &a[r]);
        if(++f[a[r]] == 1) cnt++;
        while(cnt >= K){
            ans += N - r;
            if( -- f[a[l]] == 0) cnt--;
            l++;
        }
    }
    printf("%lld\n", ans);
}