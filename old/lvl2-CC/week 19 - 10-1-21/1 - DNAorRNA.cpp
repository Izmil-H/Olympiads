#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;
    bool dna = 0, rna = 0, both = 0, other = 0;
    for (char c: s) {
        if (c == 'T') dna = 1;
        else if (c == 'U') rna = 1;
        else if (c == 'A' || c == 'C' || c == 'G') both = 1;
        else other = 1;
    }
    if (dna && rna || other) cout << "neither";
    else if (dna) cout << "DNA";
    else if (rna) cout << "RNA";
    else if (both) cout << "both";
}

