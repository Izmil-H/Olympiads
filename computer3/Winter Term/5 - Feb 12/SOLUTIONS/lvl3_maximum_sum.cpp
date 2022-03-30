#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 100001
int n, data[M],dp[M];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d", &data[i]);
    dp[1]=data[1];
    for(int i=2; i<=n; i++)
        dp[i]=max(dp[i-2]+data[i], dp[i-1]);
    printf("%d\n", dp[n]);
}