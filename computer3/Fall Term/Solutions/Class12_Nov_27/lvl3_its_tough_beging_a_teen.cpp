#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 8

int arc[MAXN][MAXN];

void insertArc(int i, int j)
{
    arc[i][j] = 1;
}

int main()
{
    insertArc(1, 7);   insertArc(1, 4);   insertArc(2, 1);
    insertArc(3, 4);   insertArc(3, 5);
    while(1)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(!x && !y)
            break;
        insertArc(x, y);
    }
    int i, j, count = 0, taken[8], todo[8];
    memset(taken, 0, sizeof(taken));
    while(count < 7)
    {
        for(i=1; i<=7; i++)
        {
            if(taken[i])
                continue;
            int allzero = 1;
            for(j=1; j<=7; j++)
                if(arc[j][i])
                {
                    allzero = 0;
                    break;
                }
            if(allzero)
            {
                taken[i] = 1;
                todo[count] = i;
                count = count + 1;
                for(j=1; j<=7; j++)
                    arc[i][j] = 0;
                break;
            }
        }
        if(i>7)
        {
            printf("Cannot complete these tasks. Going to bed.\n");
            return 0;
        }
    }

    for(count=0; count<7; count++)
        printf("%d ", todo[count]);
    printf("\n");
    return 0;
}