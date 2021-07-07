#include<bits/stdc++.h>
using namespace std;

int main() {
    bool primes[501] = {0}; 
    primes[0] = primes[1] = 1;
    for(int i = 2; i <= 501; i++) {
        if (primes[i] == 0) {
            for(int j = i+i; j <= 500; j+=i) primes[j] = 1;
        }
    }

    int n;
    cin >> n;
    for (int t = 0; t < n; ++t) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        for (int i = a; i < b; i++) {
            if(primes[i] == 0) count++;
        }
        cout << count << endl;
    }
}