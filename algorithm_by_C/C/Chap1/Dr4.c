/*
 * ------------------------------------
 *      ランダムな順列（改良版）      *
 * ------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

void main(void)
{
    int i, j, d, a[N + 1];

    for (i = 1; i <=N; i++)
        a[i] = i;

    for (i = N; i > 0; i--)
    {
        j = irnd(i - 1);
        d = a[j];
        a[j] = a[i];
        a[i] = d;
    }

    for (i = 1; i <= N; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int irnd(int n) // １～ｎの乱数
{
    return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}
