#include <bits/stdc++.h>
using namespace std;
vector<string> name= {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
int N; vector<string> a, b; string s;
int main(){
    sort(name.begin(), name.end());
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> s; a.push_back(s);
        for(int j=1; j<=4; j++) cin >> s;
        cin >> s; b.push_back(s);
    }
    do {
        bool flag = 1;
        for(int i=0; i<N; i++){
            int pos = find(name.begin(), name.end(), a[i]) - name.begin();
            if((pos==0 && name[1] != b[i]) || (pos==7 && name[6] != b[i]) ||
               (pos >0 && pos < 7 && name[pos-1] != b[i] && name[pos+1] != b[i])){
                flag = false; break;
               }
        }
        if(flag){
            for(int i=0; i<name.size(); i++) cout << name[i] << "\n";
            return 0;
        }
    }while(next_permutation(name.begin(), name.end()));
}