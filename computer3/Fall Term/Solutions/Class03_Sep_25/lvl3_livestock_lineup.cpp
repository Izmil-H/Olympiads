#include <bits/stdc++.h>
using namespace std;
vector<string> cow = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
int n; vector<string> a, b; string name;
int getIndex(string x){
    return find(cow.begin(), cow.end(), x) - cow.begin();
}
int main(){
    sort(cow.begin(), cow.end());
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> name;
        a.push_back(name);
        for(int j=0; j<5; j++) cin >> name;
        b.push_back(name);
    }
    do {
        bool flag = true;
        for(int i=0; i<n; i++) {
            string x = a[i], y = b[i];
            if(abs(getIndex(x) - getIndex(y)) != 1){ flag = false; break;}
        }
        if(flag) {
            for(string x: cow) cout << x << endl;
            break;
        }
    }while(next_permutation(cow.begin(), cow.end()));
}