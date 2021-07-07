#include<bits/stdc++.h>
using namespace std;

int main() {

    int q;
    cin >> q;

    bool primes[100001] = {0}; // false means unmarked (prime)
    primes[0] = primes[1] = 1;

    for (int i = 2; i*i <= 100000; ++i) {
        if (!primes[i]) {
            for (int j = i+i; j <= 100000; j += i) {
                primes[j] = 1;
            }
        }
    }

    long long int primeSum[100001] = {0};
    long long int sum = 0; 
    for (int i = 2; i <= 100000; ++i) {
        if (!primes[i]) sum += i;
        primeSum[i] = sum;
    }

    for (int t = 0; t < q; ++t) {
        int a, b;
        cin >> a >> b;
        int sum = primeSum[b] - primeSum[a-1];
        // cout << primeSum[a] << ":" << primeSum[b] << endl;
        cout << sum << endl;
    }
}




    /*
    int q;
    cin >> q;
    
    bool primes[100001] = {0};

    int l = INT_MAX;
    int r = INT_MIN;

    int ab[q][2];

    for (int i = 0; i < q; ++i) {
        cin >> ab[i][0] >> ab[i][1];
        if (ab[i][0] < l) l = ab[i][0];
        if (ab[i][1] > r) r = ab[i][1];
    }

    int sums[q] = {0};
    
    for (int i = l; i <= r; ++i) {
        if (i == 1) continue;
        bool prime = true;

        if (primes[i] == true) {
            cout << "exists" << endl;
            for (int j = 0; j < q; ++j) {
                if (i >= ab[j][0] && i <= ab[j][1]) sums[j] += i;
            }
        } else {
            for (int j = 2; j <= sqrt(i); ++j) {
                //cout << i << ":" << j << ":" << i % j << endl;
                if (i % j == 0)  {
                    //cout << "!prime" << endl;
                    prime = false;
                    break;
                }
            }
            if (prime) {
                primes[i] = true;
                for (int j = 0; j < q; ++j) {
                    if (i >= ab[j][0] && i <= ab[j][1]) sums[j] += i;
                }
            }
        }
    }

    for (int j = 0; j < q; ++j) {
        cout << sums[j] << endl;
    }
    */





    /*
    for (int i = 2; i <= 100000; ++i) {
        bool prime = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            //cout << i << ":" << j << ":" << i % j << endl;
            if (i % j == 0)  {
                //cout << "!prime" << endl;
                prime = false;
                break;
            }
        }
        if (prime) primes[i] = true;
    }
    */

   /*
    for(int t = 0; t < q; ++t) {
        int a,b;
        cin >> a >> b;

        int sum = 0;

        for (int i = a; i <= b; ++i) {
            if (i == 1) continue;
            bool prime = true;

            if (primes[i] == true) {
                sum += i;
            } else {
                for (int j = 2; j <= sqrt(i); ++j) {
                    //cout << i << ":" << j << ":" << i % j << endl;
                    if (i % j == 0)  {
                        //cout << "!prime" << endl;
                        prime = false;
                        break;
                    }
                }
                if (prime) {
                    primes[i] = true;
                    sum += i;
                }
            }
        }



        /*
        for (int i = a; i <= b; ++i) {
            if (primes[i] == true) sum += i;
        } 
        */
    /*
        cout << sum << endl;
        
    }
    */
    