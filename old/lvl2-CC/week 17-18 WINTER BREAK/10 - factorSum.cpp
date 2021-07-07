#include<bits/stdc++.h>
using namespace std; 

void factorSum (long long n, int& count) {
    //cout << "--" << n << "--" << endl;
    set<long long> fact; fact.insert(1);
    for (long long j = 2; j*j <= n; j++) {
        if (n%j == 0) {
            fact.insert(j); fact.insert(n/j);
            //cout << j << ".";
        }
    }
    //cout << endl;
    long long sum = 0;
    for (long long it: fact) {
        //cout << it << ":" << sum << "  ";
        sum += it;
    }
    //cout << endl;

    if (sum == 1) {
        cout << n << " " << count << endl;
        return;
    }
    if (count >= 1000 || sum >= 1000000000000 || sum < 0) {
        cout << "INFINITY" << endl;
        return;
    }
    count++;
    //cout << n << " " << sum << " " << count << endl;
    factorSum(sum, count);
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long a; cin >> a;
        int count = 0;
        factorSum(a, count); 
    }
}