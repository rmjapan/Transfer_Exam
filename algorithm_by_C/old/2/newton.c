/**
*    author:  shosei
*    created: 02.05.2021 23:32:05
**/
#include <stdio.h>
#include <math.h>
#define f(x) ((x) * (x) * (x) - (x) + 1)
#define EPS 1e-8

int main()
{
  double x = 10, pre_x;
  int k = 0;
  double dif_f;
  int check = 0;
  dif_f = f(x);
  
  while (1)
  {
    pre_x = x;
    x = x - f(x) / dif_f;
    dif_f = f(x) / x;
    if (fabs(x - pre_x) < EPS * fabs(pre_x))
    {
      printf("x = %lf", x);
      return 0;
    }
    check++;
    if (check > 100)
      return 1;
  }
}
