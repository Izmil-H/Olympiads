#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int s, t, r;
        cin >> s >> t >> r;
	    int rem = n % (s*t);
        cout << (n/(s*t) - (rem? 0:1)) *(t+r) + ((rem? rem:s*t) + s - 1)/s << "\n";
    }
    return 0;
}