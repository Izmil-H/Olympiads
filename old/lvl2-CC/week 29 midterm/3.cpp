#include<bits/stdc++.h>
using namespace std;

double calc(double a, double b) {
    if (a-10 <= 0) return b*0.5;
    return (a-10) + b*0.5;
}

int main() {
    int n, q;
    cin >> n >> q;
    int sum[n+1];
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        sum[i+1] = sum[i] + x;
    }

    int l1, r1, l2, r2;
    for (int i = 0; i < q; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        double a = sum[r1] - sum[l1-1], b = sum[r2] - sum[l2-1];
        cout << fixed << setprecision(2) << a+b - min(calc(a,b), calc(b,a)) << endl;
    }

}