#include <bits/stdc++.h>
using namespace std;
int T, N, id[5002], t[5002], s1, s2; bool dp[5002], f[502];
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &T, &N);
    dp[0] = 1; int tt = T;
    for(int i=1; i<=N; i++){
        scanf("%d", &t[i]);
        for(int j=T; j>=t[i]; j--){
            if(!dp[j] && dp[j-t[i]]){
                dp[j] = 1; id[j] = i;
            }
        }
    }
    for(tt=T; !dp[tt]; tt--);
    for(int p=id[tt]; p; tt-=t[p], p=id[tt])
        f[p] = 1;
    for(int i=1; i<=N; i++){
        if(f[i]){ printf("%d ", s1); s1+=t[i];}
        else { printf("%d ", s2); s2+=t[i]; }
    }
    printf("\n");
}