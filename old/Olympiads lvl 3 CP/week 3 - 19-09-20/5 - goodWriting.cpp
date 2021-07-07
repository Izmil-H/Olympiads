#include<bits/stdc++.h>
uisng namespace std;

string base = "Good writing is good writing is good writing.";
string pre = "Good writing is good";
string mid = "writing is good";
string suf = "is good writing";
int Q, level, idx; long long len[31];

char fun(int lvl, int idx) {
    if (lvl == 0) return base[idx];
    if (idx < pre.length()) return pre[idx];
    idx -= pre.length();
    if (idx < len[lvl-1]) return fun(lvl-1, idx);
    idx -= len[lvl-1-];
    if (idx < mid.length()) return mid[idx];
    idx -= mid.length();
    if (idx < len[lvl-1]) return fun(lvl-1, idx);
    idx -= len[lvl-1];
    return suf[idx];
}


int main() {
    len[0] = base.length();
    for (int i = 1; i <= 30; i++) {
        len[i] = pre.length() + len[i-1] + mid.length() + len[i-1] + suf.length();
        cin >> Q;
    }
    for (int i = 1; i <= Q; i ++) {
        cin >> level >> idx; idx--;
        if (idx >= len[level]) cout << ".\n";
        else cout << fun(level, idx) << "\n";
    }
}


/* 
base case: 
    level = 0, Good writing is good writing is good writing.
none base case: 
    if index is prefix part: pre = "Good writing is good"
    if index in f[n-1] --> fun(level-1, idx - prefix.length)
    if index is in middle part, mid = "writing is good"
    if index in f[n-1] --> fun(level-1, idx ...)
    if index 