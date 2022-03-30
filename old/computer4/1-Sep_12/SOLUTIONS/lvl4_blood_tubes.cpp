#include <bits/stdc++.h>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
typedef long long ll;
int N, bit[500005]; ll ans;
inline int sum(int x){
    int s = 0;
    for(; x; x-=x&-x)
        s += bit[x];
    return s;
}
inline void update(int x){
    for(; x<=N; x+=x&-x)
        bit[x]++;
}
int main(){
    scan(N);
    for(int i=0, x; i<N; i++){
        scan(x);
        int tmp = sum(x);
        ans += min(tmp, i-tmp);
        update(x);
    }
    printf("%lld\n", ans);
}