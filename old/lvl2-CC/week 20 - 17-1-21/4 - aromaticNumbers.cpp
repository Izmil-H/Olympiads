#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> rom = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
    string s; cin >> s;
    pair<int, int> nums[s.length()/2];
    for (int i = 0; i < s.length(); i+=2) {
        nums[i/2] = {s[i] - '0', rom[s[i+1]]};
        //cout << nums[i/2].first << " " << nums[i/2].second << endl;
    }
    int sum = 0;
    for (int i = 0; i < s.length()/2; i++) {
        int term = nums[i].first * nums[i].second;
        if(i < s.length()/2 - 1) {
            if (nums[i+1].second > nums[i].second) sum -= term;
            else sum += term;
        } else sum += term;
        //cout << term << " " << sum << endl;
    }
    cout << sum;
}