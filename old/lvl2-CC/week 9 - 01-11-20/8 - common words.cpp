#include<bits/stdc++.h>
using namespace std;

bool sortByVal(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

void sortMap(map<string, int>& m, vector< pair<string, int> >& vec) {
    for (auto it: m) {
        vec.push_back(it);
    }
    sort(vec.begin(), vec.end(), sortByVal);
}


int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; ++t) {
        int m, k;
        cin >> m >> k;

        map<string, int> freq;
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            freq[s]++;
        }
        vector< pair<string, int> > vec;
        sortMap(freq, vec);

        //                  0     1     2     3     4     5     6     7     8     9
        string suff[10] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
        cout << k << (k%100>10 && k%100<20? "th": suff[k%10]) << " most common word(s):" << endl;
        if(k > m) {
            cout << endl;
        } else {
            int freqK = vec[k-1].second;

            for (int i = 0; i < m; ++i) {
                //cout << i << ": " << vec[i].first << " " << vec[i].second << endl;
                if (i < k-1 && vec[i].second <= freqK) {
                    //cout << "< freqK" << endl;
                    cout << endl;
                    break;
                } else if (i >= k-1) {
                    if (vec[i].second == freqK) {
                        cout << vec[i].first << endl;
                    } else {
                        //cout << "no more" << endl;
                        break;
                    }
                }
            }
        }
    }
}