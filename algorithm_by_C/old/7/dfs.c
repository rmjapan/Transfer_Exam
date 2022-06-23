/**
*    author:  shosei
*    created: 28.06.2021 21:19:23
**/
#include <stdio.h>
#define N 8

int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, // 隣接行列
                       {0, 0, 1, 1, 0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 0, 1, 0, 0, 0},
                       {0, 0, 1, 0, 0, 1, 0, 0, 0},
                       {0, 0, 0, 1, 1, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 1, 1, 0}};

int v[N + 1];

void visit(int i)
{
    int j;

    v[i] = 1;
    printf("%d ", i);
    for (j = 1; j <= N; j++)
    {
        if (a[i][j] == 1 && v[j] == 0)
            visit(j);
    }
}

int main()
{
    int j, cnt = 1;
    for (j = 1; j <= N; j++)
        v[j] = 0;

    for (j = 1; j <= N; j++)
    {
        if (v[j] != 1)
        {
            printf("%d:", cnt++);
            visit(j);
            printf("\n");
        }
    }
    return 0;
}
