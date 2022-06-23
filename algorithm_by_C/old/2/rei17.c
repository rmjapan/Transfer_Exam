/**
*    author:  shosei
*    created: 17.05.2021 21:33:14
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%f\n", ans);

#define N 7
#define M 5 //データ当てはめ次数
double ipow(double x, int k)
{
  double s = 1.0;
  for (int i = 1; i <= k; i++)
    s *= x;
  return s;
}

int main()
{
  double x[] = {-3, -2, -1, 0, 1, 2, 3},
         y[] = {5, -2, -3, -1, 1, 4, 5},
         s[2 * M + 1] = {0}, t[M + 1] = {0}, a[M + 1][M + 2];
  double d, p, px;
  int i, j, k;

  rep(k, 2 * M + 1)
      rep(j, N) s[k] += ipow(x[j], k);

  rep(k, M + 1)
      rep(j, N) t[k] += y[j] * ipow(x[j], k);

  for (int i = 0; i < M + 1; i++)
  {
    for (int j = 0; j < M + 1; j++)
      a[i][j] = s[i + j];
    a[i][M + 1] = t[i];
  }

  for (k = 0; k <= M; k++)
  {
    p = a[k][k];
    for (j = k; j <= M + 1; j++)
      a[k][j] = a[k][j] / p;
    for (i = 0; i <= M; i++)
    {
      if (i != k)
      {
        d = a[i][k];
        for (j = k; j <= M + 1; j++)
          a[i][j] = a[i][j] - d * a[k][j];
      }
    }
  }

  printf("   x    y\n");
  for (px = -3; px <= 3; px = px + .5)
  {
    p = 0;
    for (k = 0; k <= M; k++)
      p = p + a[k][M + 1] * ipow(px, k);

    printf("%5.1f%5.1f\n", px, p);
  }

  return 0;
}
