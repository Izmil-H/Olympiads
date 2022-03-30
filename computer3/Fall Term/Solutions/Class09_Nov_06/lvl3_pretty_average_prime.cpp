#include <bits/stdc++.h>
using namespace std;
int T, n;
bool is_prime(int n){
    if(n <= 1) return false;
    for(int i=2; i*i <=n; i++)
        if(n % i == 0) return false;
    return true;
}
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n;
        for(int a=2; a<=n+1; a++){
            int b = 2*n - a;
            if(is_prime(a) && is_prime(b)){
                cout << a << " " << b << "\n";
                break;
            }
        }
    }
}