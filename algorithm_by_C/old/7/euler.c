/**
*    author:  shosei
*    created: 29.06.2021 22:13:18
**/
#include <stdio.h>

#define Node 4
#define Root 6  //辺の数
#define Start 1 //開始点
int a[Node + 1][Node + 1] = {{0, 0, 0, 0, 0},
                             {0, 0, 1, 0, 0},
                             {0, 0, 0, 1, 1},
                             {0, 0, 0, 0, 1},
                             {0, 1, 1, 0, 0}};
int v[Root + 1]; //経路を入れるスタック
int success,     //成功した数
    n;           //通過した辺の数

void visit(int i)
{
    int j;
    v[n] = i;
    if (n == 0 && i == Start)
    {
        printf("%d : ", ++success);
        for (j = 0; j <= Root; j++)
            printf("%d ", v[j]);
        printf("\n");
    }
    else
    {
        for (j = 1; j <= Node; j++)
            if (a[i][j] != 0)
            {
                a[i][j]--;
                // a[j][i]--;
                n--;
                visit(j);
                a[i][j]++;
                // a[j][i]++;
                n++;
            }
    }
}

int main()
{
    success = 0;
    n = Root;
    visit(Start);
    if (success == 0)
        printf("解なし\n");
    return 0;
}
