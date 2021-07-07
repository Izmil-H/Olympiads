#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int t = 0; t < 5; ++t) {
        bool primes[10001] = {0}; primes[0] = primes[1] = 1;
        int count = 0;
        for (int i = 2; i*i <= 1001; i++) {
            if (primes[i] == 0){
                for (int j = i*i; j < 1001; j+=i) primes[j] = 1;
            }
        }
        
        int n; cin >> n;
        bool semiPrime = false;
        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                if (primes[i] == 0 && primes[n/i] == 0) {
                    semiPrime = true;
                }
            }
        }
        if (semiPrime) cout << "semiprime" << endl;
        else cout << "not" << endl;
    }
}