#include<bits/stdc++.h>
using namespace std;

int main() {
    // 60% Solution:
    /*
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (to_string(i).length() % 2 != 0) count++;
    }
    cout << count;
    */

    // Full Solution:
    long n;
    long cnt[19];
    cnt[1] = 9;
    for (int i = 3; i < 19; i+=2) {
        cnt[i] = 100*cnt[i-2];
    }
    int dig = to_string(n).length();
    long ans = 0;
    if (dig % 2 != 0) {
        long pre = 0;
        for (int i = 1; i < dig; ++i) pre = pre*10 +9;
        ans += n - pre;
    }
    for (int i = dig; i >= 0; i--) ans += cnt[i];
}