#include<bits/stdc++.h>
#include <cmath>
using namespace std;
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
}