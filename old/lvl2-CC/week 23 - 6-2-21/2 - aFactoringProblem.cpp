#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int,int> facts;

    for (int i = 2; i*i <= n; i++) {
        while (n%i == 0){ 
            facts[i]++;
            n /= i;
        }
    }
    if (n > 1) facts[n]++;

    int a = 1, b =1;
    for (auto i: facts) {
        a *= i.first;
        b *= i.second;
    }
    cout << a + b;
}