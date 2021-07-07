#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string perm(string ans, int len) {
   if (ans.length() == len) {
      return ans;
   }
   ans += perm(ans, len, 'a');
   ans += perm(ans, len, 'b');
}

int main(){
   /*cout << i << ":" << idx + 1 << ":" << freq[idx] << endl;*/

   string ans = "";
   cout << perm(ans, 5, 'a');
}