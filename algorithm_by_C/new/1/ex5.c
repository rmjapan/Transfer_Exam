/**
 *    author:  shosei
 *    created: 28.01.2022 17:02:07
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define N 100000000

double rnd(){
  return (double)rand() / (RAND_MAX + 0.1);
}

int main()
{
  srand((unsigned int)time(NULL));
  double x, y;
  double a = 0;
  for (int i = 0; i < N; i++)
  {
    x = rnd();
    y = rnd();
    if (x * x + y * y <= 1)
    {
      a++;
    }
  }

  printf("%lf\n", 4 * a / N);
  return 0;
}