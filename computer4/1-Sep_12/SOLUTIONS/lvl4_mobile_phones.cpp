#include <bits/stdc++.h>
using namespace std;
int bit[1030][1030], n, op, val, a1, b1, a2, b2;
void update(int r, int c, int val){
    r++; c++;
    for(int i=r; i<=n; i+=i&-i)
        for(int j=c; j<=n; j+=j&-j)
            bit[i][j] += val;
}
int query(int r, int c){
    int sum = 0; r++; c++;
    for(int i=r; i>0; i-=i&-i)
        for(int j=c; j>0; j-=j&-j)
            sum += bit[i][j];
    return sum;
}
int main(){
    while(true){
        cin >> op;
        if(op == 3) break;
        if(op == 0) { cin>>n; }
        else if(op == 1) {
            cin >> a1 >> b1 >> val;
            update(a1, b1, val);
        }else if(op == 2){
            cin >> a1 >> b1 >> a2 >> b2;
            cout << query(a2, b2) - query(a1-1, b2) - query(a2, b1-1) + query(a1-1, b1-1) << "\n";
        }
    }
}