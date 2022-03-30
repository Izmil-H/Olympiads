#include <bits/stdc++.h>
using namespace std;
int n, tot;
void fun(int start, int sum, int n, vector<int> &a){
    if(sum == n){
        printf("%d=", n);
        for(int i=0; i<a.size()-1; i++) printf("%d+", a[i]);
        printf("%d\n", a.back()); tot++; return;
    }
    for(int i=start; i<n; i++){
        if(sum + i <= n) {
            a.push_back(i);
            fun(i, sum+i, n, a);
            a.pop_back();
        }
    }
}
int main(){
    vector<int> a;
    scanf("%d", &n);
    fun(1, 0, n, a);
    printf("total=%d\n", tot);
}