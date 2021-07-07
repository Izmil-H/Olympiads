#include<bits/stdc++.h>
using namespace std;

long long large = 0;
long long largeAns = 0;
string largeS;
long long tot = 0;

int op = 0;
void combo(int len, string s) {
    if (s.length() == len) {
        op++;
        long long opr = 0;
        string s2 = s;
        //cout << s << " ";
        long long count = 0;
        for (int i = len-1; i >= 0; i--) {
            if (s[i] == '1')  {
                count++;
                for (int j = i; j >= 0; j--) {
                    tot++;
                    opr++;
                    if (s[j] == '1') s[j] = '0';
                    else s[j] = '1';
                }
            }   
        }
        if (opr > large){
            large = opr;
            largeS = s2;
        }
        if (count > largeAns) {
            largeAns = count;
            largeS = s2;
        }
        //cout << count << " " << opr << endl;
    } else {
        s += '1';
        combo(len, s);
        s.erase(s.length()-1, 1);
        s+= '0';
        combo(len, s);
    }
}

int main() {
    for (int i = 1; i <=5; i++) {
        cout << "---" << i << "---" << endl;
        string s = "";
        combo(1000, s);
        cout << largeAns << " " << largeS << endl;
        //cout << "---" << op << "--" << tot << "---" << endl;
    }
}