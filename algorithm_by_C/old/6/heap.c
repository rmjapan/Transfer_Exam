/**
*    author:  shosei
*    created: 27.06.2021 18:21:24
**/
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void shiftdown(int p, int m, int heap[])
{
    int s;
    s = 2 * p;
    while (s <= m)
    {
        if (s < m && heap[s + 1] > heap[s])
            s++;
        if (heap[p] >= heap[s])
            break;
        swap(&heap[p], &heap[s]);
        p = s;
        s = 2 * p;
    }
}

int main()
{
    int heap[100];
    int n, i, s, p, m;

    n = 1;
    while(scanf("%d",&heap[n])!=EOF)
        n++;
    //初期heapの作成
    m = n - 1;
    for (i = m / 2; i >= 1;i--)
        shiftdown(i, m, heap);

    while (m > 1)
    {
        swap(&heap[1], &heap[m]);
        m--;
        shiftdown(1, m, heap);
    }
    for (i = 1; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
    return 0;
}
