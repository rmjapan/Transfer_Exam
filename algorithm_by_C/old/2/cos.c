/**
*    author:  shosei
*    created: 29.04.2021 23:05:46
**/
#include <stdio.h>
#include <math.h>
#define pi 3.14159265

double mycos(double x)
{
  double s = 1.0, d, c = 1.0, EPS = 1e-08;
  double k;
  for (k = 1; k <= 200; k = k + 2)
  {
    d = s;
    c = -c * x * x / (k * (k + 1));
    s += c;
    if (fabs(s - d) < EPS * fabs(d))
      return s;
  }
  return 0.0;
}

int main()
{
  double x;
  printf("    x       mycos(x)        cos(x)\n");
  for (x = 0; x <= 180; x = x + 10)
  {
    printf("%5.1f%14.6g%14.6g\n", x, mycos(x * pi / 180), cos(x * pi / 180));
  }
  return 0;
}
