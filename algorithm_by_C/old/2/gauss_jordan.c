/**
*    author:  shosei
*    created: 04.05.2021 21:30:29
**/

#include <stdio.h>
#define N 3 //元の数

int main()
{
  double a[N][N + 1];
  double p, d;
  int i, j, k;
  for (i = 0; i < N; i++)
    for (j = 0; j < N + 1; j++)
      scanf("%lf", &a[i][j]);

  //掃き出し
  for (k = 0; k < N; k++)
  {
    p = a[k][k];
    for (j = k; j < N + 1; j++)
      a[k][j] /= p;

    for (i = 0; i < N; i++)
    {
      if (i != k)
      {
        d = a[i][k];
        for (j = k; j < N + 1;j++)
          a[i][j] -= d * a[k][j];
      }
    }
  }
  for (k = 0; k < N; k++)
    printf("x%d = %lf\n", k + 1, a[k][N]);
  return 0;
}
