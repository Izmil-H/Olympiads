#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pi;
const int MM = 1e5+5;
int N, st[MM], tp=-1; vector<pi> p;
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &N); p.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    sort(p.begin(), p.end());
    st[++tp] = -2e9;
    for(int i=N-1; i>=0; i--){
        if(st[tp] < p[i].y) st[++tp] = p[i].y;
        else {
            int tmp = st[tp--];
            while(tp>=0 && st[tp]>=p[i].y) tp--;
            st[++tp] = tmp;
        }
    }
    printf("%d\n", tp);
}