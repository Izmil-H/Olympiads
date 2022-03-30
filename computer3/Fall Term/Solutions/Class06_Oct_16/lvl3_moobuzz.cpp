#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    int nl[] = {-1,1,2,4,7,8,11,13,14};
    int id = n%8;
    cout << n/8*15+nl[id];
}