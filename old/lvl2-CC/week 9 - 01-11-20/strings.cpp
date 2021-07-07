#include<bits/stdc++.h>
using namespace std;

// substr(starting index, number of chars) --> makes substring 
// find(substring) --> finds index of first occurence of 'subtr'
// stoi(string) --> converts string to integer
// to_string(number) --> converts number to string
// a.compare(b) --> returns integer:
//          a < b: negative
//          a > b: positive
//          a == b: zero

int main() {
    string s = "abcde";
    for (int i = 0; i < s.length(); ++i) { // starting point
        for (int j = i; j <= s.length(); ++j) { // num chars
            cout << s.substr(i, j-i) << endl;
        }
    }
    cout << s.find('cd') << endl;
    
    string s2 = "abcdef";
    if (s < s2) cout << s2;


    // convert string to int:
    string s3 = "356";
    int a = stoi(s3);
    cout << a << endl;

    // convert int to string
    int a2 = 1234;
    string s4 = to_string(a2);

}