#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1000005;
int N, cnt, x[MM], rk[MM], id[MM], bit[MM],vir[MM]; char op[MM]; vector<pi> vec;
void update(int pos, int val){
    for(int i=pos; i<=cnt; i+=i&-i)
        bit[i] += val;
}
int find_k(int k){
    int pos = 0, tot = 0;
    for(int i=20; i>=0; i--){
        pos += (1<<i);
        if(pos >= cnt || tot + bit[pos] >= k) pos -= (1<<i);
        else tot += bit[pos];
    }
    return pos+1;
}
int main(){
    scanf("%d", &N);
    for(int i=0, r; i<N; i++){
        scanf(" %c %d", &op[i], &x[i]);
        if(op[i] != 'Q'){
            scanf("%d", &r); vec.push_back({r, i});
        }
    }
    sort(vec.begin(), vec.end(), greater<pi>());
    for(pi e: vec) vir[e.second] = ++cnt;
    for(int i=0; i<N; i++){
        if(op[i] == 'N'){
            update(vir[i], 1); rk[x[i]] = vir[i]; id[vir[i]] = x[i];
        }else if(op[i] == 'M'){
            update(rk[x[i]], -1); update(vir[i], 1); rk[x[i]]=vir[i]; id[vir[i]]=x[i];
        }else{
            int tmp = find_k(x[i]); printf("%d\n", id[tmp]);
        }
    }
}