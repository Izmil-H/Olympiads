#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
const int MM=1000002;
string str; int K, val[MM<<1];
struct state { int len = 0, fa = -1; map<char, int> nxt;  };
struct SAM {
    vector<state> st; int last = 0;
    void extend(int c){
        int np = st.size(), p=last; st.eb();
        st[np].len = st[p].len + 1;
        for(; p!=-1 && !st[p].nxt.count(c); p=st[p].fa) st[p].nxt[c] = np;
        if(p == -1) st[np].fa = 0;
        else {
            int q = st[p].nxt[c];
            if(st[p].len + 1==st[q].len) st[np].fa = q;
            else {
                int cl = st.size(); st.pb(st[q]);
                st[cl].len = st[p].len + 1;
                for(; p!=-1 &&st[p].nxt[c] == q; p=st[p].fa) st[p].nxt[c] = cl;
                st[q].fa = st[np].fa = cl;
            }
        }
        last = np;
    }
    void init(string s){ st.eb(); for(char c: s) extend(c); }
    int dfs(int u) {
        if(val[u]) return val[u];
        val[u] = 1;
        for(auto &e: st[u].nxt)
            val[u] = max(val[u], dfs(e.second)+1);
        return val[u];
    }
    void solve() {
        dfs(0);
        for(int cur=0; K>0; K--){
            for(auto &e: st[cur].nxt){
                if(val[e.second]>=K){
                    putchar(e.first); cur = e.second; break;
                }
            }
        }
        putchar('\n');
    }
};

int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> str >> K; SAM sam;
    sam.init(str); sam.solve();

}