#include<bits/stdc++.h>
using namespace std;

int main() {
    string p1, p2; int n;
    cin >> p1 >> p2 >> n;
    for (int q = 0; q < n; q++) {
        string s; cin >> s;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                if ( (islower(p1[i*2]) || islower(p1[i*2+1])) && (islower(p2[i*2]) || islower(p2[i*2+1])) ){

                } else {
                    flag = false;
                }

            } else {
                if ( isupper(p1[i*2]) || isupper(p1[i*2+1]) || isupper(p2[i*2]) || isupper(p2[i*2+1]) ){

                } else {
                    flag = false;
                }
            }
        }
        if (flag) cout << "Possible baby." << endl;
        else cout << "Not their baby!" << endl;
    }

    /*
    string par1, par2;
    cin >> par1 >> par2;
    int gene[5]; // 1 is dominant, 2 is recessive, 3 is both
    for (int i = 0; i < 5; i++) {
        // 2 dominant in at least 1 parent
        if ( (isupper(par1[i*2]) && isupper(par1[i*2+1])) || (isupper(par2[i*2]) && isupper(par2[i*2+1])) ) gene[i] = 1;
        // exactly 1 dominant in each parent
        else if ( (par1[i*2] != par1[i*2+1]) && (par2[i*2] != par2[i*2+1]) ) gene[i] = 1;
        // 2 recessive in each parent
        else if ( (islower(par1[i*2]) && islower(par1[i*2+1])) && (islower(par2[i*2]) && islower(par2[i*2+1]))) gene[i] = 2;
        // only one dominant combined
        else if ( ( (par1[i*2]!=par1[i*2+1]) && (islower(par2[i*2])&&islower(par2[i*2+1])) ) || ( (islower(par1[i*2])&&islower(par1[i*2+1]))&&(par2[i*2]!=par2[i*2+1])) )gene[i] = 3;
    } 
    //for (int i = 0; i < 5; ++i) cout << gene[i] << " ";cout << endl;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {
            if ( (isupper(s[j]) && gene[j] == 2) || (islower(s[j]) && gene[j] == 1) ) {
                cout << "Not their baby!" << endl;
                break;
            }
            if (j==4) cout << "Possible baby." << endl;
        }
    }
    */
}
