#include <bits/stdc++.h>
using namespace std;
int n, a[55], odd, even, Max; long long s=0;
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        s += a[i]; Max = max(Max, a[i]);
        if(a[i] & 1) odd++;
        else even++;
    }
    if(odd & 1 || Max*2 > s) printf("NO\n");
    else printf("YES\n");
}