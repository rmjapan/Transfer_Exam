/**
*    author:  shosei
*    created: 05.07.2021 01:30:20
**/
#include <stdio.h>
#define N 8

void calc(int a[N + 1][N + 1])
{
    int sum_row, sum_column, sum_diagonal;
    int i, j;
    sum_row = sum_column = sum_diagonal = 0;
    //row
    for (j = 1; j <= N; j++)
        sum_row += a[1][j];

    //column
    for (i = 1; i <= N; i++)
        sum_column += a[i][1];

    for (int j = i = 1; i <= N && j <= N; j++, i++)
    {
        sum_diagonal += a[i][j];
    }
    printf("sum_r = %d\nsum_column = %d\nsum_diagonal = %d\n", sum_row, sum_column, sum_diagonal);
}

void printer(int a[N + 1][N + 1])
{
    int i, j;
    printf("     4N魔法陣 (N=%d)\n", N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int hojin[N + 1][N + 1] = {0}, i, j;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (j % 4 == i % 4 || (j + i) % 4 == 1)
            {
                hojin[i][j] = N * (N - i + 1) - j + 1;
                printer(hojin);
            }
            else
            {
                hojin[i][j] = j + N * (i - 1);
                printer(hojin);
            }
        }
    }
    
    // for (j = 1; j <= N; j++)
    // {
    //     for (i = 1; i <= N; i++)
    //     {
    //         if (j % 4 == i % 4 || (j % 4 + i % 4) % 4 == 1)
    //         {
    //             hojin[i][j] = (N + 1 - i) * N - j + 1;
    //             printer(hojin);
    //         }
    //         else
    //         {
    //             hojin[i][j] = (i - 1) * N + j;
    //             printer(hojin);
    //         }
    //     }
    // }
    printer(hojin);
    calc(hojin);
    return 0;
}
