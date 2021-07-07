#include<bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double hrs = a/40000.0 + b/60000.0 + c/70000.0;
    cout << fixed << setprecision(2) << hrs*60;
}