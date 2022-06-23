#include <stdio.h>
#define N 12

long combi(int, int);

int main()
{
  int n, r, t;
  for (int n = 0; n <= N; n++)
  {
    for (t = 0; t < (N - n)*3; t++)
    {
      printf(" ");
    }
    for (int r = 0; r <= n; r++)
    {
      printf("%3ld   ", combi(n, r));
    }
    printf("\n");
  }
}

long combi(int n, int r)
{
  if (r > 0 && n != r)
  {
    return ((n - r + 1) * combi(n, r - 1) / r);
  }
  else if (n == r || r == 0)
  {
    return 1;
  }
}
