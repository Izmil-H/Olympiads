#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    GCD(b, a%b);
}

int fact(int x) {
    if (x == 1) {
        return 1;
    }
    return x * fact(x-1);
}

int add(int y) {
    if (y == 1) {
        return 1;
    }
    return y + add(y-1);
}

string reverse(string s, int idx) {
    if (idx == 0) {
        return s[0];
    }
}

int main() {
    cout << add(2);
}
