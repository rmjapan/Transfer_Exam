/*
 * ---------------------
 *      基本挿入法     *
 * ---------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   // データ数

void main(void)
{
    int a[N+1],i,j,t;

    for(i=1;i<=N;i++)        // Ｎ個の乱数
        a[i]=rand();

    a[0]=-9999;              // 番兵
    for (i=2;i<=N;i++){
        t=a[i];
        for (j=i-1;a[j]>t;j--)
            a[j+1]=a[j];
        a[j+1]=t;
    }

    for (i=1;i<=N;i++)
        printf("%8d",a[i]);
    printf("\n");
}
