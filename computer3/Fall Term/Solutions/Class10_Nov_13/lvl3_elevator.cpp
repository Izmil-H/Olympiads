#include <bits/stdc++.h>
using namespace std;
int N, T, M, ans = 0;
int main(){
    scanf("%d %d %d", &N, &T, &M);
    for(int i=1, t, s, d; i<=M; i++){
        scanf("%d %d %d", &t, &s, &d);
        if(s > d) {s = 2*N-s; d = 2*N-d;}
        while(t > s*T) t -= 2*N*T;
        ans += d*T - t;
    }
    printf("%d\n", ans);
}