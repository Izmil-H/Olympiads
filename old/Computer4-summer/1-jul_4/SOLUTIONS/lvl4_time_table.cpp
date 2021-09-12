#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
int d[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, MOD=1000000007;
int C, R, M, x, y; ll p[503][503], s[503][503], dp[503][503];
pll solve(int r, int c){
    if(dp[r][c]) return {p[r][c], dp[r][c]};
    pll tmp;
    for(int i=0; i<4; i++){
        int nr=r+d[i][0], nc=c+d[i][1];
        if(nr<=0 || nc<=0 || nr>R || nc>C || s[nr][nc]<=s[r][c]) continue;
        tmp = max(tmp, solve(nr, nc));
    }
    dp[r][c]=tmp.second+s[r][c];
    p[r][c]=tmp.first+1;
    return {p[r][c], dp[r][c]};
}
int main(){
    //freopen("test.txt", "r", stdin);
    scan(C); scan(R); scan(M);
    for(int i=0, c, r, w, h, n; i<M; i++){
        scan(c); scan(r); scan(w); scan(h); scan(n);
        int r2=r+h, c2=c+w, nw=n*w, nh=n*h, nhw=n*h*w;
        p[r][c]+=n; p[r][c2]-=n; p[r2][c]-=n; p[r2][c2]+=n;
        p[r][c2]-=nw; p[r][c2+1]+=nw; p[r2][c2]+=nw; p[r2][c2+1]-=nw;
        p[r2][c]-=nh; p[r2+1][c]+=nh; p[r2][c2]+=nh; p[r2+1][c2]-=nh;
        p[r2][c2]+=nhw; p[r2+1][c2]-=nhw; p[r2][c2+1]-=nhw; p[r2+1][c2+1]+=nhw;
    }
    for(int r=1; r<=R; r++){
        for(int c=1; c<=C; c++){
            p[r][c] += p[r-1][c]+p[r][c-1]-p[r-1][c-1];
            s[r][c] = s[r-1][c]+s[r][c-1]-s[r-1][c-1]+p[r][c];
        }
    }
    memset(p, 0, sizeof(p));
    scan(x); scan(y);
    pll ans = solve(y, x);
    printf("%lld\n", ans.second % MOD);
}