/**
 *    author:  shosei
 *    created: 29.01.2022 18:36:41
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

#define f(x) (sqrt(4 - (x) * (x))) //半円
#define N 50000                    //分割数
int main()
{
  double a, b, h, sum;
  printf("積分区間(a<b):");
  scanf("%lf %lf", &a, &b);

  h = (b - a) / N;
  sum = (f(a) + f(b)) / 2;
  for (int k = 1; k < N; k++) //かっこの内側から計算
    sum += f(a + k * h);
  sum *= h;

  printf("%lf\n", sum);
  return 0;
}