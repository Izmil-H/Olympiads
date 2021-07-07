#include <iostream>
#include <cstdio>
using namespace std;
void Hanoi(char A, char B, char C, int n){
    if(n==1) printf("%c%c\n", A, C);
    else{
        Hanoi(A, C, B, n-1);
        printf("%c%c\n", A, C);
        Hanoi(B, A, C, n-1);
    }
}
int main()
{
    int n;
    cin >> n;
    Hanoi('A','B','C',n);
}