#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10000000

double irnd()
{
  return (double)rand() / (RAND_MAX + 0.1);
}

int main()
{
  srand((unsigned)time(NULL));
  double s, x, y;
  int in_n = 0;

  for (int i = 0; i < NUM; i++)
  {
    x = 2 * irnd();
    y = irnd();
    if ((x * x) / 4 + y * y <= 1)
    {
      in_n++;
    }
  }
  s = (double)4 * 2 * in_n / NUM;
  printf("%lf", s);
}
