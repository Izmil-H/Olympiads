#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+5;
int N, pre[MM]; vector<pi> vec, lis; vector<int> ans;
int main(){
    cin >> N;
    for(int i=0, x, y; i<N; i++){
        cin >> x >> y;  vec.push_back({x, -y});
    }
    sort(vec.begin(), vec.end());
    lis.push_back({-1e9, -1});
    for(int i=0; i<vec.size(); i++){
        int val = vec[i].second;
        int pos = upper_bound(lis.begin(), lis.end(), make_pair(val, i)) - lis.begin();
        if(pos == lis.size()) lis.push_back({val, i});
        else lis[pos] = {val, i};
        pre[i] = lis[pos-1].second;
    }
    cout << lis.size() - 1 << "\n";
    for(int i=lis.back().second; i!=-1; i=pre[i]) ans.push_back(i);
    reverse(ans.begin(), ans.end());
    for(int i: ans)
        cout << vec[i].first << " " << -vec[i].second << "\n";
}