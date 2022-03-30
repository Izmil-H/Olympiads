#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int N, T, ans; vector<pi> a;
int main(){
    cin >> N >> T;
    for(int i=1, x, y; i<=T; i++) {
        cin >> x >> y; a.push_back({x, y});
    }
    a.push_back({0, 0}); a.push_back({N+1, N+1});
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            int lft = min(a[i].first, a[j].first), rit = max(a[i].first, a[j].first);
            int wid = rit - lft - 1;
            vector<int> mid = {0, N+1};
            for(int k=0; k<a.size(); k++){
                if(a[k].first > lft && a[k].first < rit){
                    mid.push_back(a[k].second);
                }
            }
            sort(mid.begin(),  mid.end());
            for(int k=1; k<mid.size(); k++){
                int height = mid[k] - mid[k-1] - 1;
                ans = max(ans, min(wid, height));
            }
        }
    }
    cout << ans << endl;
}