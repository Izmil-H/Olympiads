#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    int a[n]; 
    int sl[n] = {0}, sr[n] = {0}; 
    for (int i = 0; i < n; ++i) { 
        cin >> a[i];
    }    
    sl[0] = 1; 
    for (int i = 1; i < n; ++i) { 
        if (a[i] != a[i-1]) { 
            sl[i] = sl[i-1] + 1; 
        } else { 
            sl[i] = 1; 
        }
    }
    sr[n-1] = 1; 
    for (int i = n - 2; i >= 0; --i) { 
        if (a[i + 1] != a[i]) { 
            sr[i] = sr[i+1] + 1; 
        } else { 
            sr[i] = 1; 
        }
    }
    
    int current = 1; 
    int ans = 1; 
    for (int i = 1; i < n; ++i) { 
        current++;
        if (a[i] == a[i-1]) { 
            current = 0;  
            int r = i;
            for (int j = i; j < n-1; j++) { 
                r = j; 
                current++;
                if (a[j] == a[j+1]) { 
                    break;
                }
            }
            //cout << sl[i-1] << ' ' << current << ' ' << sr[r] << "i|r" << i << ' ' << r << endl;
            if (r < n - 1) 
                current = sl[i-1] + current + sr[r+1];
            else 
                current = sl[i-1] + current;
            ans = max(ans, current); 
            current = 1;
        } 
        ans = max(ans, current); 
    }
    cout << min(2,ans);
}