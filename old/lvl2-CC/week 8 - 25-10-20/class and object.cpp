#include<bits/stdc++.h>
using namespace std;

class student {
public:
    string name;
    int grade, age;
    student(){};
    student(string s, int g, int a) {
        name = s; grade = g; age = a;
    }
};

int main() {
    student A ("Ismail", 10, 15);
    student B = student{"John", 8, 13}; // same as previous line
    cout << A.name << " " << A.grade << " " << A.age << endl;
    cout << B.name << " " << B.grade << " " << B.age << endl;
}