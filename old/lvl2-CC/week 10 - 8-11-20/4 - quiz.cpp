#include<bits/stdc++.h>
using namespace std; 

int main() {
    long long int x, y;
    int a, b;
    cin >> x >> y >> a >> b;

    /*
    int tot = 0;
    for (int i = x; i <=y; ++i) {
        if (i%a == 0) tot++;
        else if (i%b==0) tot++;
    }
    cout << tot;
    */

    int lcm;
    for (int i = max(a, b); ; i+= max(a, b)) {
        if (i % min(a, b) == 0) {
            lcm = i;
            break;
        }
    }
//    cout << lcm << endl;
//    cout << (y-x+1)/a << " " << (y-x+1)/b << " " << (y-x+1)/lcm << endl;
//    cout << y/a - (x-1)/a << " " << y/b - (x-1)/b << " " << y/lcm - (x-1)/lcm << endl;
    int tot = y/a - (x-1)/a; 
    tot += y/b - (x-1)/b;
    tot -= y/lcm - (x-1)/lcm;
    cout << tot;
}
