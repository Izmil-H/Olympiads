#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
int N, a[MM], ans; multiset<int> st;
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    sort(a, a+N, greater<int>());
    for(int i=0; i<N; i++){
        auto it = st.upper_bound(a[i]);
        if(it == st.end()){
            ans += a[i];
            st.insert(a[i]);
        } else {
            st.erase(it); st.insert(a[i]);
        }
    }
    printf("%d\n", ans);
}