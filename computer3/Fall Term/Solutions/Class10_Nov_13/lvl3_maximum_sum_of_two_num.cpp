#include <bits/stdc++.h>
using namespace std;
int N, M, a[100002];
int main(){
    scanf("%d %d", &N, &M);  int ans  = 0;
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    sort(a, a+N);
    for(int i=1; i<N; i++){
        int p = upper_bound(a, a+i, M-a[i]) - a - 1;
        if(p >= 0) ans = max(ans, a[i] + a[p]);
    }
    printf("%d\n", ans);
}