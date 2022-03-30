#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, p[20], cnt, pre, pos;
int main(){
    cin >> n; p[1] = 9; pre = 9;
    for(int i=2; i<=18; i++){
        if(i % 2) { pre*=100; p[i] = p[i-1] + pre; }
        else p[i] = p[i-1];
    }
    if(n < 10) { cout << n << endl; return 0;}
    string s = to_string(n);
    if((int)s.size() & 1){
        cnt += n - stoll(string((int)s.size()-1, '9'));
    }
    cnt += p[(int)s.size()-1];
    cout << cnt << endl;
}