#include <stdio.h>
#include <stdlib.h>

#define N 1000000000 //プロットする点の数
int main()
{
  double x, y, pi;
  int a = 0; //a:円の内部，b:円の外部かつ正方形の内部

  for (int i = 0; i < N; i++)
  {
    x = rand() / (double)RAND_MAX;
    y = rand() / (double)RAND_MAX;
    if (x * x + y * y <= 1)
    {
      a++;
    }
  }

  pi = (double)(4 * a) / N;
  printf("%3.10lf", pi);
  return 0;
}
