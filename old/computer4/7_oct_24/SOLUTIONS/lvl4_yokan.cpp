#include <bits/stdc++.h>
using namespace std;
const int NUM=40;
int M, N, Q, v[200002]; vector<int> pos[200002];
int main(){
    //freopen("test.txt", "r", stdin);
    srand (time(NULL));
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        scanf("%d", &v[i]);
        pos[v[i]].push_back(i);
    }
    scanf("%d", &Q);
    for(int i=1, l, r; i<=Q; i++){
        scanf("%d %d", &l, &r);
        int L = r - l + 1, length = 0, color = 0;
        if(L <= 3){
            printf("YES\n"); continue;
        }else{
            for(int i=0; i<NUM && length < 2; i++){
                int x = rand()%L+l;
                if(v[x] == color) continue;
                int cnt = upper_bound(pos[v[x]].begin(), pos[v[x]].end(),r)
                    -lower_bound(pos[v[x]].begin(), pos[v[x]].end(), l);
                if(cnt * 3 >= L * 2){ length=2; break; }
                else if(cnt * 3 >= L ){ length++; color = v[x];}
            }
            if(length < 2) printf("NO\n");
            else printf("YES\n");
        }
    }
}