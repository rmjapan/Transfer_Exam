/**
*    author:  shosei
*    created: 29.04.2021 22:35:31
**/
#include <stdio.h>
#include <math.h>

double myexp(double x)
{
  double EPS = 1e-8;
  double s = 1.0, d, e = 1.0;
  double k;
  double y;
  y = fabs(x);
  for (k = 1; k <= 200; k++)
  {
    d = s;
    e = e * y / k;
    s += e;
    if (fabs(s - d) < EPS * fabs(d))
    {
      if(x > 0)
        return s;
      else
        return 1.0 / s;
    }
  }
  return 0.0;
}

int main()
{
  double x;
  printf("    x       myexp(x)       exp(x)\n");
  for (x = -40; x <= 40; x = x + 10)
    printf("%5.1f%14.6g%14.6g\n", x, myexp(x), exp(x));

  return 0;
}
