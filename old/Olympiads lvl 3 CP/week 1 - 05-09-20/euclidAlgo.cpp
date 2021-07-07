#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Euclid(int m, int n) {
    if (n==0) {
        return m;
    }        
    int rem = m%n;
    m = n;
    n = rem;
    return Euclid(m,n);
}
int fib(int n) {
    if (n <= 2) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
int main() {
    cout << Euclid(16, 32);
    cout << fib(5);
}