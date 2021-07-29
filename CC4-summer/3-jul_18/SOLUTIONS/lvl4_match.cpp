#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+3, seed=131;
int N, tp, lft[MM], ans[MM], st[MM]; ll p[MM]={1}, hsh[MM], cur; char s[MM]; unordered_map<ll, int> w[26];
void fun(int l, int r){
    if(l > r) return;
    ans[l] = -1; int p = w[s[l]-'a'][hsh[r]];
    while(ans[p]) p = lft[p];
    ans[p] = 1;
    fun(p+1, r); fun(l+1, p-1);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf(" %s", s+1); N = strlen(s+1);
    for(int i=1; i<=N; i++){
        p[i] = p[i-1]*seed;
        if(tp && s[st[tp]] == s[i]){
            cur = cur - s[i]*p[tp-1];
            tp--;
        } else {
            st[++tp] = i;
            cur = cur + s[i]*p[tp-1];
        }
        hsh[i] = cur; lft[i] = w[s[i]-'a'][hsh[i]];
        w[s[i]-'a'][hsh[i]] = i;
    }
    if(hsh[N]) return 0*printf("-1\n");
    fun(1, N);
    for(int i=1; i<=N; i++) printf("%c", (ans[i]<0? '(':')'));
    printf("\n");
}