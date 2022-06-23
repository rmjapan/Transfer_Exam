/*
 * ----------------------------------------
 *      シェル・ソート（改良挿入法 ）     *
 * ----------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   // データ数

void main(void)
{
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        // Ｎ個の乱数
        a[i]=rand();

    gap=N/2;                // ギャップの初期値
    while (gap>0){
        for (k=0;k<gap;k++){    // ギャプとびの部分数列のソート
            for (i=k+gap;i<N;i=i+gap){
                for (j=i-gap;j>=k;j=j-gap){
                    if (a[j]>a[j+gap]){
                        t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                    }
                    else
                        break;
                }
            }
        }
        gap=gap/2;             // ギャップを半分にする
    }

    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
}
