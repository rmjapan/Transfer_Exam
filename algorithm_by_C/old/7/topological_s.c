/**
*    author:  shosei
*    created: 28.06.2021 23:54:08
**/
#include <stdio.h>
#include <stdlib.h>

#define N 8

int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, // 隣接行列
                       {0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 1, 0, 0, 0, 1, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0, 1, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 0}};
int v[N + 1], s[N + 1];
int sp = 1;
void visit(int);

int main()
{
    int i;

    for (i = 1; i <= N; i++)
        v[i] = 0;
    for (i = 1; i <= N; i++)
        if (v[i] == 0)
            visit(i);
    for (i = sp; i > 1; i--)
    {
        printf("%d ", s[i - 1]);
    }
    printf("\n");
    return 0;
}

void visit(int i)
{
    int j;
    v[i] = 1;
    for (j = 1; j <= N; j++)
    {
        if (a[i][j] && v[j] == 0)
            visit(j);
        if (a[i][j] && v[j] == 1)
        {
            printf("%d と %dの間にループがあります", i, j);
            exit(1);
        }
    }
    s[sp++] = i;
    v[i] = 2;
}
