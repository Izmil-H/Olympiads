#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int ppl[n];
    for (int i = 0; i < n; ++i) cin >> ppl[i];
    int div[d];
    for (int i = 0; i < d; ++i) cin >> div[i];

    int start = 0;
    for (int i = 0; i < d; ++i) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; ++j) {
            if (j < div[i] + start) sum1 += ppl[j];
            else sum2 += ppl[j];
        }
        if (sum1 >= sum2) {
            for (int j = 0; j < div[i] + start; ++j) ppl[j] = 0;
            cout << sum1 << endl;
            start += div[i];
        } else {
            for (int j = div[i] + start; j < n; ++j) ppl[j] = 0;
            cout << sum2 << endl;
        }
    }
}