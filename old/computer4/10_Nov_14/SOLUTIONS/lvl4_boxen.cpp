#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+2;
int N, p[MM];
int fd(int d){ return d==p[d]? p[d]: p[d]=fd(p[d]);}
int main(){
    for(int k=1; k<=2; k++){
        cin >> N;  iota(p+1, p+N+1, 1); int cnt=0;
        for(int i=1, x; i<=N; i++){
            cin >> x;  int fi = fd(i), fx=fd(x);
            if(fi != fx) { cnt++; p[fi] = fx; }
        }
        cout << N - cnt << " ";
    }
}