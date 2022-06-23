/**
*    author:  shosei
*    created: 17.05.2021 23:09:37
**/
#include <stdio.h>
#include<stdlib.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define N 6

//flag=1→昇順,flag=2→降順
void bubble_sort(int a[], int flag)
{
  int t, i, j; //index
  switch (flag)
  {
  case 1:
    for (i = 0; i < N - 1; i++)
    {
      for (j = N - 1; j > i; j--)
      {
        if (a[j] > a[j - 1])
        {
          t = a[j - 1];
          a[j - 1] = a[j];
          a[j] = t;
        }
      }
    }
    break;
  case 2:
    for (i = 0; i < N - 1; i++)
    {
      for (j = N - 1; j > i; j--)
      {
        if (a[j] < a[j - 1])
        {
          t = a[j - 1];
          a[j - 1] = a[j];
          a[j] = t;
        }
      }
    }
    break;
  default:
    exit(-1);
    break;
  }
}

int main()
{
  int a[] = {80, 41, 35, 90, 40, 20};
  int t, i, j;
  bubble_sort(a, 1);
  rep(i, N) printf("%d ", a[i]);
  bubble_sort(a, 2);
  printf("\n");
  rep(i, N) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
