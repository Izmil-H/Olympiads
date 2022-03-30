#include <iostream>
using namespace std;
int pow(int x, int n, int mod){
    if(n == 0) return 1;
    int t = pow(x, n/2, mod);
    if(n % 2 == 0) return t*t%mod;
    return t*t*x % mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int sa=0, sb=0;
    for(int i=0; i<a.length(); ++i){
        sa+=pow(tolower(a[i])-'a'+1, i+1, 10);
        sa=sa%10;
    }
    for(int i=0; i<b.length(); ++i){
        sb+=pow(tolower(b[i])-'a'+1, i+1, 10);
        sb=sb%10;
    }
    if(sa==0){
        sa=10;
    }
    if(sb==0){
        sb=10;
    }
    cout << sa+sb << "\n";
}