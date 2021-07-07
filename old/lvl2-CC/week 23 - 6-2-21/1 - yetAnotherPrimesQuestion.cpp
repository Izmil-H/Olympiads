#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 5;
    while (t--) {
        int n; cin >> n;
        set<int> fctrs;
        for (int i = 2; i*i <= n; i++) {
            while (n%i == 0) {
                fctrs.insert(i);
                n /= i;
            }
        }
        int size = fctrs.size();
        if (n > 1) size++;
        
        if (size == 3) cout << "valid\n";
        else cout << "not\n";
    }
}