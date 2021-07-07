// IN CLASS PRACTICE QUESTION.
// Given a sequence of words, sort them by length. If two 
// words have the same length, sort them alphabetically.

#include<bits/stdc++.h>
using namespace std;

int main() {

}









// My attempt: 
class word {
public:
    string name;
    int length, alph;
    word(){};
    word(string n) {
        name = n; length = n.length();
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += int(tolower(n[i]));
        }
        alph = sum;
    }
};


int main() {
    int n;
    cin >> n;
    word arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].name;
    }
}
