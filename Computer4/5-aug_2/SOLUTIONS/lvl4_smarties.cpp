#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000002;
int n, k, freq[MM], a[MM], cnt; ll ans;
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    for(int l=1, r=1; r<=n; r++){
        scanf("%d", &a[r]);
        if(++freq[a[r]]==1) cnt++;
        while(cnt >= k){
            if(--freq[a[l]] == 0) cnt--;
            l++;
        }
        ans += l-1;
    }
    printf("%lld\n", ans);
}