#include <bits/stdc++.h>
using namespace std;
int n; long long memo[64];
long long f(int n){
    if(n <= 1) return 1;
    if(memo[n] > 0) return memo[n];
    long long ret = 1;
    for(int i=n-2; i>=0; i-=2) ret += f(i);
    return memo[n] = ret;
}
int main(){
    cin >> n;
    cout << f(n) << endl;
}