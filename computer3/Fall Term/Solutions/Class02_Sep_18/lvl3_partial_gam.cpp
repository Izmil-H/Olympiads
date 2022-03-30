#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll d, a;
int main(){
    cin >> n;
    for(int i=1, x; i<=n; i++){
        cin >> x;
        if(x&1) a += (x+1)/2;
        else d += x/2;
    }
    cout << (d > a? "Duke" : "Alice") << endl;
}