#include<bits/stdc++.h>
using namespace std;

const int len = 1e5+1;
bool isP[len];

int main() {
    isP[0] = isP[1] = 1;
    for (int i = 2; i*i < len; i++) {
        if (!isP[i]) {
            for (int j = i+i; j < len; j += i) {
                isP[j] = 1;
            }
        }   
    }    
    
    vector<int> primes, psa;
    psa.push_back(0), primes.push_back(0);
    for (int i = 2; i < len; i++) {
        if (!isP[i]) {
            psa.push_back(psa.back()+i);
            primes.push_back(i);
        }
    }

    int q, a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        int iB = lower_bound(primes.begin(), primes.end(), b) - primes.begin(), iA = lower_bound(primes.begin(), primes.end(), a-1) - primes.begin();
        if (isP[a-1] && a > 1) iA--; if (isP[b]) iB--;
        //cout << iA << " " << iB << endl << psa.at(iA) << " " << psa.at(iB) << endl;
        cout << psa.at(iB) - psa.at(iA) << endl;
    }
}