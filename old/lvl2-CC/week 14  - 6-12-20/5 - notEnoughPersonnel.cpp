#include<bits/stdc++.h>
using namespace std;

struct veteran {
    string name; int s, id;
}v[500];

bool comp (veteran x, veteran y) {
    return x.s < y.s || (x.s == y.s && x.id < y.id);
}

int main(){
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].s; v[i].id = i;
    }
    sort(v, v+n, comp);
    cin >> q;
    for (int i = 0, skill, d, j; i < q; i++) {
        cin >> skill >> d;
        for (j = 0; j < n; j++) {
            if (v[j].s >= skill && v[j].s <= skill+d){
                cout << v[j].name << endl;
                break;
            }
        }
        if (j == n) cout << "No suitable teacher!" << endl;
    }
}

/*
int main() {
    int n; cin >> n;
    int s[n]; string name[n];
    for(int i = 0; i < n; i++) {
        cin >> name[i] >> s[i];
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int skill, d, best = INT_MAX; string ans="";
        cin >> skill >> d;
        for(int j = 0; j < n; j++) {
            if (skill <= s[j] && s[j] <= skill+d) {
                if (s[j] - skill < best) {
                    best = s[j] - skill;
                    ans = name[j];
                }
            }
        }
        if (best == INT_MAX) cout << "No suitable teacher!" << endl;
        else cout << ans << endl;
    }
}
*/


/*
bool compare(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) return 0;
    return a.second < b.second;
}

int main() {
    int n; cin >> n;
    pair<string, int> vet[n];
    for (int i = 0; i < n; i++) cin >> vet[i].first >> vet[i].second;
    sort(vet, vet+n, compare);
    //for (int i = 0; i < n; i++) cout << vet[i].first << " " << vet[i].second << endl;
    int q; cin >> q;
    int noob[q][2]; 
    for (int i = 0; i < q; i++) {
        cin >> noob[i][0] >> noob[i][1];
        for (int j = 0; j < n; ++j) {
            if (noob[i][0] <= vet[j].second && vet[j].second <= noob[i][0] + noob[i][1]){
                cout << vet[j].first << endl;
                break;
            }
            if (j == n-1) cout << "No suitable teacher!" << endl;
        }
    }  
}
*/