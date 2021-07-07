#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    
    // idea from internet hehe :(
    string vow = "aaaeeeeiiiiioooooouuuuuuuu";
                //abcdefghijklmnopqrstuvwxyz
    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        ans += s[i];
        if(vow.find(s[i]) == string::npos) {
            char cons = char(s[i]+1);;
            if (s[i] == 'z') cons = 'z';
            else if (vow.find(cons) != string::npos) cons = char(cons+1);
            ans += vow[s[i] - 'a'];
            ans += cons;
        }
    }
    cout << ans;
}


    // original attempt
    /*
    string s; cin >> s;
    int vowel[26] = {0};
    string alph = "abcdefghijklmnopqrstuv";
    vowel[0] = vowel[4] = vowel[8] = vowel[14] = vowel[20] = 1;
    for (int i = 0; i < s.length(); ++i) {
        int idx = s[i] - 'a'; 
        cout << i << " " << s[i] << " idx: " << endl;
        if (vowel[idx] != 1) {
            int dist[5];
            dist[0] = abs('a' - s[i]);
            dist[1] = abs('e' - s[i]);
            dist[2] = abs('i' - s[i]);
            dist[3] = abs('o' - s[i]);
            dist[4] = abs('u' - s[i]);
            for (int j = 0; j < 5; ++j) cout << dist[j] << " ";
            cout << endl;
            sort(dist, dist+5);
            char vow;
            if (dist[0] == dist[1]) vow = alph[min(int(dist[0]), int(dist[1]))];
            else vow = alph[dist[0]];
            char cons;
            if (s[i] == 'z') cons = 'z';
            if (vowel[idx+1] == 1) cons = alph[idx+2];
            cout << vow << " " << cons << endl;
            s.insert(i, 1, vow); s.insert(i+1, 1, cons);
        }
    }
    cout << s << endl;
    */


// a = 1
// e = 5
// i = 9
// o = 15
// u = 21