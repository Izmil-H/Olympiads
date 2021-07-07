#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int sum = 0;
    for (int i = 1; i <= 100000; ++i) {
        sum += sqrt(i);
    }
    cout << sum;
}