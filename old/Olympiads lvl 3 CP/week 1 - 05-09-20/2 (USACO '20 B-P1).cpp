#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int n, k;
   cin >> n >> k;
   vector<string> lines;
   string s;
   cin >> s;
   int count = s.length();
   lines.push_back(s);
   for (int i = 1; i < n; ++i) {
       cin >> s;
       if (count + s.length() > k) {
           count = s.length();
           lines.push_back(s);
       } else {
           count += s.length();
           lines.back() += " " + s;
       }
   }
    for (int i = 0; i < lines.size(); ++i) {
        cout << lines.front() << endl;
        lines.erase(lines.begin());
        i-=1;
    }
}