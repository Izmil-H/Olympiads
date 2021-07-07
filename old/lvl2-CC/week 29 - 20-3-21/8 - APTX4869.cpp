#include<bits/stdc++.h>
using namespace std;

class elem {
public:
    string name = "";
    string scount = "";
    int count = 1;
};

class bracket {
public:
    int l, r;
    string smult = "";
};

int main() {
    string s; cin >> s;
    vector<elem> elms; 
    stack<int> brkt; bool cls = 0;
    vector<bracket> brks;
    for (auto c: s) {
        if (cls) {
            if (isdigit(c)) {
                brks.back().smult += c;
                continue;
            } else cls = 0;
        }
        if (isdigit(c)) {
            elms.back().scount += c;
        } else if (isalpha(c)) {
            if (isupper(c)) {
                elem temp;
                elms.push_back(temp);
            } 
            elms.back().name += c;
        } else if (c == '(') {
            brkt.push(elms.size());
        } else {
            cls = 1;
            bracket temp;
            brks.push_back(temp);
            brks.back().l = brkt.top(); brkt.pop();
            brks.back().r = elms.size();
        }
    }
    for (auto brk: brks) {
        //cout << brk.l << " " << brk.r << " " << brk.smult << endl;
        int n = stoi(brk.smult);
        for (int i = brk.l; i < brk.r; i++) {
            elms[i].count *= n;
        }
    }
    map<string, int> mp;
    for (auto el: elms) {
        if (el.scount.size()) el.count *= stoi(el.scount);
        mp[el.name] += el.count;
        //cout << el.name << " " << el.scount << " " << el.count << endl;
    }
    for (auto x: mp) {
        cout << x.first;
        if (x.second > 1) cout << x.second;
    }
}