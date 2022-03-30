#include <bits/stdc++.h>
using namespace std;
int n; string blk[4], word;
int main(){
    cin >> n;
    for(int i=0; i<4; i++) cin >> blk[i];
    for(int i=0; i<n; i++) {
        cin >> word;
        sort(blk, blk+4);
        bool found = false;
        do{
            bool flag = true;
            for(int k=0; k<word.size(); k++){
                if(blk[k].find(word[k]) == string::npos)
                    flag = false;
            }
            if(flag){ found = true; break;}
        }while(next_permutation(blk, blk+4));
        cout << (found? "YES\n" : "NO\n");
    }
}