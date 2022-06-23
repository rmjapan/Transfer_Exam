/*
 * -----------------------
 *      ヒープの作成     *
 * -----------------------
 */

#include <stdio.h>

void main(void)
{
    int heap[100];
    int n,i,s,p,w;

    n=1;
    while (scanf("%d",&heap[n])!=EOF){      // ヒープの最後の要素に入れる
        s=n;
        p=s/2;          // 親の位置
        while (s>=2 && heap[p]>heap[s]){    // 上方移動
            w=heap[p];heap[p]=heap[s];heap[s]=w;
            s=p;p=s/2;
        }
        n++;
     }
     for (i=1;i<n;i++)
        printf("%d ",heap[i]);
     printf("\n");
}
