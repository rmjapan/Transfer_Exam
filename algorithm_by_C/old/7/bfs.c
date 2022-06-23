/**
*    author:  shosei
*    created: 28.06.2021 22:53:01
**/
#include <stdio.h>

#define N 8

int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, // 隣接行列
                       {0, 0, 1, 0, 0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 1, 1, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 1, 1},
                       {0, 0, 0, 1, 0, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 1, 1, 0}};

int v[N + 1];
int queue[100];
int head = 0, //先頭データのインデックス
    tail = 0; //終端データのインデックス
    
int main()
{
    int i, j, k;

    for (k = 1; k <= N; k++)
    {
        for (i = 1; i <= N; i++) //初期化
            v[i] = 0;
        head = tail = 0;
        queue[tail++] = k;
        v[k] = 1;
        do
        {
            i = queue[head++]; //取り出し
            for (j = 1; j <= N; j++)
            {
                if (a[i][j] == 1 && v[j] == 0)
                {
                    printf("%d->%d ", i, j);
                    queue[tail++] = j; //キューに入れる
                    v[j] = 1;
                }
            }
        } while (head != tail);
        printf("\n");
    }
    return 0;
}
