/**
*    author:  shosei
*    created: 02.05.2021 22:25:38
**/
#include <stdio.h>
#include <math.h>

double f(double x){
  return (x)*(x)*(x) - (x) + 1;
}

int main()
{
  double low, high, EPS = 1e-8;
  double x;
  scanf("%lf %lf", &low, &high);
  while (1)
  {
    x = (low + high) / 2;
    if (f(x)> 0)
    {
      high = x;
    }
    else
    {
      low = x;
    }

    if (f(x) == 0 || fabs(high - low) < EPS * fabs(low))
    {
      printf("x = %lf\n", x);
      return 0;
    }
  }
}
