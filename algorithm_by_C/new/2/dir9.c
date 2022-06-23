/**
 *    author:  shosei
 *    created: 29.01.2022 19:10:26
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define f(x) (sqrt(4 - (x) * (x)))
#define N 50

int main()
{
  double a, b, h, f_o, f_e, sum;
  printf("積分区間(a<b):");
  scanf("%lf %lf", &a, &b);

  h = (b - a) / (2 * N);
  // fo,feを求める
  f_o = f_e = 0.0;
  for (int k = 1; k <= N - 1; k++)
  {
    f_e += f(a + 2 * k * h);
    f_o += f(a + (2 * k - 1) * h); // n-1個足す
  }
  f_o += f(a + (2 * N - 1) * h); //調整

  sum = h * (f(a) + f(b) + 4 * (f_o + f(b - h)) + 2 * f_e) / 3;
  printf("%lf\n", sum);

  return 0;
}