/**
*    author:  shosei
*    created: 04.07.2021 18:12:10
**/
#include <stdio.h>
#define N 3

int main()
{
    int hojin[N + 1][N + 1], i, j, k;

    j = (N + 1) / 2;
    i = 0;
    for (k = 1; k <= N * N; k++)
    {
        if (k % N == 1)
            i++;
        else
        {
            i = N - (N - i + 1) % N; //i=1ならN,i=3なら2　，つまりi--をしている
            j = j % N + 1;           //j=N のときはみ出し，結果は１が格納される
        }
        hojin[i][j] = k;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            printf("%d ", hojin[i][j]);
        }
        printf("\n");
    }
    return 0;
}
