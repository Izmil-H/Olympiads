#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 2;
int N, M, a[MM]; long long bit[MM], freq[MM]; char op;
void update(long long bit[], int pos, int val){
    for(int i=pos; i<MM; i+= i&-i)
        bit[i] += val;
}
long long query(long long bit[], int pos){
    long long sum = 0;
    for(int i=pos; i>0; i-= i&-i) sum += bit[i];
    return sum;
}
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> a[i]; update(bit, i, a[i]); update(freq, a[i], 1);
    }
    for(int i=1, x, y, v; i<=M; i++){
        cin >> op >> x;
        if(op == 'C'){
            cin >> v;  update(bit, x, -a[x] + v); update(freq, a[x], -1);
            a[x] = v;  update(freq, v, 1);
        }else if(op == 'S'){
            cin >> y;
            cout << query(bit, y) - query(bit, x-1) << "\n";
        }else if(op == 'Q'){
            cout << query(freq, x) << "\n";
        }
    }
}