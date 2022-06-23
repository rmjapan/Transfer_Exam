/**
*    author:  shosei
*    created: 27.04.2021 22:45:23
**/
#include <stdio.h>
#include <math.h>
#define N 1000000.0                   //分割数
#define f(x) (sqrt(4 - (x) * (x))) // 被積分関数
int main()
{
  double a, b;
  double h;
  double sum;
  printf("[a,b] = ");
  scanf("%lf %lf", &a, &b);
  h = (b - a) / N;

  sum = (f(a) + f(b)) / 2;
  for (int i = 1; i <= N - 1; i++)
    sum += f(a + i * h);
  sum *= h;
  printf("integral = %lf\n", sum);
  return 0;
}
