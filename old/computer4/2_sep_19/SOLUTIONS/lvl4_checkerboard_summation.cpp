#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3003;
int M, N, op, r1, c1, r2, c2, x, a[MM][MM]; ll bit[MM][MM];
void update(int r, int c, int val){
    for(int i=r; i<=M; i+=i&-i)
        for(int j=c; j<=N; j+=j&-j)
            bit[i][j] += val;
}
ll query(int r, int c){
    ll sum = 0;
    for(int i=r; i>0; i-=i&-i)
        for(int j=c; j>0; j-=j&-j)
            sum += bit[i][j];
    return sum;
}
ll getSum(int r1, int c1, int r2, int c2){
    return query(r2, c2) - query(r1-1, c2) - query(r2, c1-1) + query(r1-1, c1-1);
}
int main(){
    cin >> M >> N;
    while(cin >> op && op){
        if(op == 1){
            cin >> r1 >> c1 >> x;
            if((r1 + c1) % 2 != 0){
                update(r1, c1, -a[r1][c1] + x); a[r1][c1] = x;
            } else {
                update(r1, c1, -a[r1][c1] - x); a[r1][c1] = -x;
            }
        }else {
            cin >> r1 >> c1 >> r2 >> c2;
            ll sum = getSum(r1, c1, r2, c2);
            if((r1 + c1) % 2 != 0)  cout << sum << "\n";
            else cout << -sum << "\n";
        }
    }
}