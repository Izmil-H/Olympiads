#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; double sum;
    cin >> a >> b >> c >> d >> sum;
    int count = 0, least = sum;
    for (int i = 0; i <= ceil(sum/a); i++) {
        for (int j = 0; j <= ceil(sum/b); j++) {
            for (int k = 0; k <= ceil(sum/c); k++) {
                for (int l = 0; l <= ceil(sum/d); l++) {
                    int comb = i*a + j*b + k*c + l*d;
                    if (comb == sum) {
                        least = min(least, i+j+k+l);
                        count++;
                        cout << "# of PINK is " << i 
                             << " # of GREEN is " << j 
                             << " # of RED is " << k 
                             << " # of ORANGE is " << l << endl;
                    }
                }   
            }
        }
    }
    cout << "Total combinations is " << count << "." << endl
         << "Minimum number of tickets to print is " << least << ".";
}