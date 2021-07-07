#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
   string a, b;
   cin >> a >> b;
   long int sumA = 0;
   for (long int i = 0; i < a.length(); ++i) {
        a[i] = tolower(a[i]);
        int x = (a[i] - 'a' + 1)%10;
        int p = (i+1)%4;
        if (p == 0) {
            p = 4;
        } 
        float y = pow(x, p);
        y = (int)y%10;
        sumA += y;
   } 
   
    long int sumB = 0;
    for (long int i = 0; i < b.length(); ++i) {
        b[i] = tolower(b[i]);
        int x = (b[i] - 'a' + 1)%10;
        int p = (i+1)%4;
        if (p == 0) {
            p = 4;
        } 
        float y = pow(x, p);
        y = (int)y%10;
        sumB += y;
   } 
   if (sumA%10 == 0) {
       sumA = 10;
   } else {
       sumA = sumA%10;
   }
   if (sumB%10 == 0) {
       sumB = 10;
   } else {
       sumB = sumB%10;
   }
   cout << sumA + sumB;
}