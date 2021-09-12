#include <bits/stdc++.h>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
#define x first
#define y second
typedef long long ll;
typedef pair<int, int> pi;
int N, tmp[100002], lst[100002], cnt; char ans[1000002]; vector<string> v; string s;
int main(){
    //freopen("test.txt", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s; v.push_back(s);
    }
    for(int k=25; k>=0; ){
        bool fd = true; char i = 'a'+k;
        for(int j=0; j<N; j++){
            if( (tmp[j]= v[j].find(i, lst[j])) == string::npos ){
                fd = false; break;
            }
        }
        if(fd){
            ans[cnt++] = i;
            for(int j=0; j<N; j++) lst[j] = tmp[j]+1;
        }else k--;
    }
    if(cnt) printf("%s\n", ans);
    else printf("-1\n");
}