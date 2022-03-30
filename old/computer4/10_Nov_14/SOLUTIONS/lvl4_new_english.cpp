#include <bits/stdc++.h>
using namespace std;
struct E{char c; int x, p;};
int N, M, freq[26], last[26]; vector<E> q; char c;
bool cmp(E a, E b){ return a.p < b.p; }
int main(){
    scanf("%d %d", &N, &M); string s(N, '#');
    for(int i=1, x, p; i<=M; i++){
        scanf(" %c %d %d", &c, &x, &p); q.push_back(E{c, x, p-1});
    }
    sort(q.begin(), q.end(), cmp);
    for(E& e: q){
        int c = e.c - 'a';
        if(freq[c] > e.x) return 0*printf("-1\n");
        else if(freq[c] < e.x) {
            for(int i=last[c]; i<=e.p && freq[c]<e.x; i++){
                if(s[i] == '#') { s[i]=e.c; freq[c]++; }
            }
            if(freq[c] < e.x) return 0*printf("-1\n");
        }
        last[c] = e.p + 1;
    }
    int id = -1, lft = N+1;
    for(int i=0; i<26; i++)
        if(last[i] < lft) lft = last[i], id = i;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '#'){
            if(i < lft) return 0*printf("-1\n");
            s[i] = (id+'a'); lft = i+1;
        }
    }
    cout << s << "\n";
}