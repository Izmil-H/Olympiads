#include<bits/stdc++.h>
using namespace std;

int main() {
    bool arr[101] = {0}; 
    for (int i = 2; i <= 100; i++) {
        if (!arr[i]) {
            for (int j = i+i; j <= 100; j+=i) {
                arr[j] = 1;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= 100; i++) {
        if (!arr[i]) {
            primes.push_back(i);
        }
    }

    int t = 5, n;
    while(t--) {
        cin >> n;
        int x = 1; if (!arr[n]) x++;        
        int idx = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
        //+
        cout << idx << " " << primes.at(idx) << " " << primes.at(idx-2) << " " <<primes.at(idx+x) << ": ";

        
        if (abs(primes.at(idx-2) - n) < abs(primes.at(idx+x) - n)) {
            cout << primes.at(idx-2);
        } else {
            cout << primes.at(idx+x);
        }
        cout << endl;
        
    }
}