#include <bits/stdc++.h>
using namespace std;
int N, K, ans, lmt, b[1003], rem[1003];
int main(){
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &b[i]); lmt = max(lmt, b[i]);
    }
    for(int i=1; i<=lmt; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++) cnt += b[j]/i;
        if(cnt < K/2) break;
        if(cnt >= K){ ans = max(ans, i*K/2); continue;}
        for(int j=1; j<=N; j++) rem[j] = b[j] % i;
        sort(rem+1, rem+N+1, greater<int>());
        int tmp = (cnt - K/2)*i;
        for(int j=1; j<=K-cnt; j++) tmp += rem[j];
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
}