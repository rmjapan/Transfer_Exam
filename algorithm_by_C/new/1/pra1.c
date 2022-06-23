#include <stdio.h>

double a[] = {1, 2, 3, 4, 5};
double fn1(double x, int n)
{
  double p;
  p = a[n];
  for (int i = 1; i <= n; i++)
  {
    p = p * x + a[n - i];
  }
  return p;
}

double fn2(double x, int n, int i)
{
  if (i == 0)
  {
    return a[n];
  }
  return fn2(x, n, i - 1) * x + a[n - i];
}

int main()
{

  double x;
  for (x = 1; x <= 5; x++)
  {
    printf("%lf\n", fn2(x, 4, 4));
  }
}