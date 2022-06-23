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
    int a[N],i,j,gap,t;

    for(i=0;i<N;i++)        // Ｎ個の乱数
        a[i]=rand();
                            // Ｎより小さい範囲で最大のｇａｐを決める
    for (gap=1;gap<N/3;gap=3*gap+1)
        ;

    while (gap>0){
        for (i=gap;i<N;i++){
            for (j=i-gap;j>=0;j=j-gap){
                if (a[j]>a[j+gap]){
                    t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                }
                else
                    break;
            }
        }
        gap=gap/3;             // ギャップを１／３にする
    }

    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
}
